#include "StdAfx.h"
#define _USE_MATH_DEFINES //or M_PI doesn't get defined
#include "JoystickManagement.h"
#include <sixense.h>
#include <sstream>
#include <vector>
#include "ControllerMapping.h"
#include "PPJIoctl.h" //PP Joy IOCTL (i/o control?)
#include <cmath>


std::wstring JoystickManagement::GetDefaultIniFilename(const bool left)
{
	wchar_t dir[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, dir);
	return std::wstring(dir) + (left ? L"/settingsLeft.ini" :  L"/settingsRight.ini");
}

std::wstring JoystickManagement::GetDefaultIniFilename(int side)
{
	return GetDefaultIniFilename(side == LEFT_CONTROLLER ? true : false);
}

namespace
{
	const bool IniReadFloat(const wchar_t* category, const wchar_t* key, const wchar_t* defaultvalue, const wchar_t* filename, float& result)
	{
		//GetPrivateProfileString() may truncate, but such long strings are most likely invalid anyway
		wchar_t buffer[64];
		if(!GetPrivateProfileString(category, key, defaultvalue, buffer, 64, filename)) return false;
		std::wstringstream wss;
		wss << buffer;
		wss >> result;
		return true;
	}

	const bool IniReadVec3f(const wchar_t* category, const wchar_t* filename, float* result)
	{
		return IniReadFloat(category, L"x", L"0", filename, result[0]) &&
				IniReadFloat(category, L"y", L"0", filename, result[1]) &&
				IniReadFloat(category, L"z", L"0", filename, result[2]);
	}

	const bool IniWriteFloat(const wchar_t* category, const wchar_t* key, float value, const wchar_t* filename)
	{
		std::wstringstream wss;
		wss<<value;
		return WritePrivateProfileString(category, key, wss.str().c_str(), filename) == TRUE;
	}

	const bool IniWriteVec3f(const wchar_t* category, float* value, const wchar_t* filename)
	{
		return IniWriteFloat(category, L"x", value[0], filename) &&
				IniWriteFloat(category, L"y", value[1], filename) &&
				IniWriteFloat(category, L"z", value[2], filename);
	}
}

JoystickManagement::JoystickManagement()
{
	for(int cont = 0; cont < 2; ++cont)
	{
		for(int dim = 0; dim < 3; ++dim)
		{
			this->mOrigins[cont][dim] = 0.0f;
		}
	}
	this->mControllerIndices[0] = -1;
	this->mControllerIndices[1] = -1;
}

JoystickManagement::~JoystickManagement(void)
{
}

const bool JoystickManagement::InitialLoad()
{
	return	mControllerMappings[LEFT_CONTROLLER].Load(GetDefaultIniFilename(LEFT_CONTROLLER), L"0") &&
			mControllerMappings[RIGHT_CONTROLLER].Load(GetDefaultIniFilename(RIGHT_CONTROLLER), L"1") &&
			LoadOrigin(LEFT_CONTROLLER) &&
			LoadOrigin(RIGHT_CONTROLLER);
}

const bool JoystickManagement::SetBase(std::string& error)
{
	for(int i = 0; i < sixenseGetMaxBases(); ++i)
	{
		if(sixenseIsBaseConnected(i))
		{
			sixenseSetActiveBase(i);
			return true;
		}
	}
#ifdef _DEBUG
	// In debug mode I want it to work even without a Hydra - because I don't have one yet.
	sixenseSetActiveBase(0);
	return true;
#endif
	error = "Base disconnected!";
	return false;
}

const JoystickManagement::returnValue JoystickManagement::SetControllerIndices(std::string& message)
{
	//which controllers are connected?
	std::vector<int> connectedControllers;
	for(int i = 0; i < sixenseGetMaxControllers(); ++i)
	{
		if(sixenseIsControllerEnabled(i))
		{
			connectedControllers.push_back(i);
		}
	}
	//are there at least 2 controllers connected?
	if(connectedControllers.size() < 2)
	{
#ifndef _DEBUG
		message = "Not enough controllers connected! (2)";
		return eError;
#else
		//In debug mode, I'd like to be able to continue even if no controllers are connected.
		mControllerIndices[0] = 0;
		mControllerIndices[1] = 1;
		return eSuccess;
#endif
	}
	//poll controller information - it seems inefficient to do that multiple times though
	sixenseControllerData data[2];
	if( sixenseGetNewestData(connectedControllers[0], data) != SIXENSE_SUCCESS ||
		sixenseGetNewestData(connectedControllers[1], data+1) != SIXENSE_SUCCESS )
	{
		message = "Could not poll data!";
		return eError;
	}

	// initialized?
	if(data[0].which_hand == 0 || data[1].which_hand == 0)
	{
		message = "Please place the controllers in the base.";
		return eMessage;
	}
	// different hands?
	if(data[0].which_hand == data[1].which_hand)
	{
		message = "Please place the controllers in different base docks.";
		return eMessage;
	}
	//yay, both are initialized and they correspond to different hands!
	//let's set up the variables
	if(data[0].which_hand == 1) // 1 is left, 2 is right.
	{
		if(data[1].which_hand != 2)
        {
            message = "Internal logic error - second controller is not the right one.";
            return eError;
        }
		mControllerIndices[LEFT_CONTROLLER]  = connectedControllers[0];
		mControllerIndices[RIGHT_CONTROLLER] = connectedControllers[1];
	}
	else
	{
		if(data[0].which_hand != 2 ||
		   data[1].which_hand != 1)
        {
            message = "Internal logic error during controller side determination.";
            return eError;
        }
		mControllerIndices[LEFT_CONTROLLER]  = connectedControllers[1];
		mControllerIndices[RIGHT_CONTROLLER] = connectedControllers[0];
	}

	return eSuccess;
}

const bool JoystickManagement::InitDevices(std::string& error)
{
	//Initialize PPJoy Handles

	static const wchar_t* DeviceNames[NUM_VIRTUAL_JOYSTICKS] =
	{
		L"\\\\.\\PPJoyIOCTL1",
		L"\\\\.\\PPJoyIOCTL2",
		L"\\\\.\\PPJoyIOCTL3",
		L"\\\\.\\PPJoyIOCTL4"
	};
	for(unsigned int joyIndex = 0; joyIndex < NUM_VIRTUAL_JOYSTICKS; ++joyIndex)
	{
		/* Open a handle to the control device for the virtual joystick. */
		mJoyHandles[joyIndex] = CreateFile(DeviceNames[joyIndex],GENERIC_WRITE,FILE_SHARE_WRITE,NULL,OPEN_EXISTING,0,NULL);

		/* Make sure we could open the device! */
		if (mJoyHandles[joyIndex] == INVALID_HANDLE_VALUE)
		{
			std::stringstream ss;
			ss << "Could not find virtual joystick " << joyIndex+1 <<" - Make sure you've set up Virtual Joystick 1 - 4 in PPJoy!";
			error = ss.str();
			return false;
		}

		/* Initialise the IOCTL data structure */
		mJoyStates[joyIndex].Signature = JOYSTICK_STATE_V1;
		mJoyStates[joyIndex].NumAnalog = NUM_ANALOG;
		mJoyStates[joyIndex].NumDigital = NUM_DIGITAL;
	}
	return true;
}

const bool JoystickManagement::LoadOrigin(int side)
{
	return IniReadVec3f(L"origin", GetDefaultIniFilename(side).c_str(), mOrigins[side]);
}

const bool JoystickManagement::SaveOrigin(int side)
{
	return IniWriteVec3f(L"origin", mOrigins[side], GetDefaultIniFilename(side).c_str());
}

namespace
{
	void SetDigital(JoystickState joyStates[], ButtonMapping& bm, bool pressed)
	{
		if(bm.Joy == -1) return;
		joyStates[bm.Joy].Digital[bm.Button] = pressed;
	}

	template<typename T> void Clamp(T min, T& val, T max)
	{
		if(val < min) val = min;
		if(val > max) val = max;
	}

	//for position & rotation we take range & inverted into account.
	void SetAnalogPosRot(JoystickState joyStates[], AxisMapping& am, float position)
	{
		if(am.Joy == -1) return;
		Clamp(-float(am.Range), position, float(am.Range));
		if(am.Inverted) position = -position;
		joyStates[am.Joy].Analog[am.Axis] += long(float(PPJOY_AXIS_MIN+PPJOY_AXIS_MAX)/2 * (position/am.Range));
		Clamp(long(PPJOY_AXIS_MIN), joyStates[am.Joy].Analog[am.Axis], long(PPJOY_AXIS_MAX));
	}

	void SetAnalogOther(JoystickState joyStates[], AxisMapping& am, float position)
	{
		if(am.Joy == -1) return;
		joyStates[am.Joy].Analog[am.Axis] += long(float(PPJOY_AXIS_MIN+PPJOY_AXIS_MAX)/2 * position);
		Clamp(long(PPJOY_AXIS_MIN), joyStates[am.Joy].Analog[am.Axis], long(PPJOY_AXIS_MAX));
	}
}

const bool JoystickManagement::Update(std::string& error)
{
	//clearing the joy states in case the mapping was changed and there's still old values in there
	for(unsigned int joyIndex = 0; joyIndex < NUM_VIRTUAL_JOYSTICKS; ++joyIndex)
	{
		for(unsigned int analogIndex = 0; analogIndex < NUM_ANALOG; ++analogIndex)
		{
			mJoyStates[joyIndex].Analog[analogIndex] = (PPJOY_AXIS_MIN+PPJOY_AXIS_MAX)/2;
		}
		for(unsigned int digitalIndex = 0; digitalIndex < NUM_DIGITAL; ++digitalIndex)
		{
			mJoyStates[joyIndex].Digital[digitalIndex] = 0;
		}
	}

	//this needs to be done for every controller - of course.
	for(unsigned int controllerIndex = 0; controllerIndex < 2; ++controllerIndex)
	{
		int controllerToQuery = this->mControllerIndices[controllerIndex];
		float* origin = this->mOrigins[controllerIndex];
		ControllerMapping& mapping = this->mControllerMappings[controllerIndex];

		sixenseControllerData data;
		if( sixenseGetNewestData(controllerToQuery, &data) != SIXENSE_SUCCESS )
		{
			error = "Could not poll data!";
			return false;
		}

		//input sending time!

		//filling the joy states

		//Buttons
		SetDigital(mJoyStates, mapping.Buttons[ControllerMapping::eButton1], (data.buttons & SIXENSE_BUTTON_1) != 0);
		SetDigital(mJoyStates, mapping.Buttons[ControllerMapping::eButton2], (data.buttons & SIXENSE_BUTTON_2) != 0);
		SetDigital(mJoyStates, mapping.Buttons[ControllerMapping::eButton3], (data.buttons & SIXENSE_BUTTON_3) != 0);
		SetDigital(mJoyStates, mapping.Buttons[ControllerMapping::eButton4], (data.buttons & SIXENSE_BUTTON_4) != 0);
		SetDigital(mJoyStates, mapping.Buttons[ControllerMapping::eButtonStart], (data.buttons & SIXENSE_BUTTON_START) != 0);
		SetDigital(mJoyStates, mapping.Buttons[ControllerMapping::eButtonJoystick], (data.buttons & SIXENSE_BUTTON_JOYSTICK) != 0);
		SetDigital(mJoyStates, mapping.Buttons[ControllerMapping::eButtonBumper], (data.buttons & SIXENSE_BUTTON_BUMPER) != 0);

		//Position
		SetAnalogPosRot(mJoyStates, mapping.Position[0], data.pos[0]-origin[0]);
		SetAnalogPosRot(mJoyStates, mapping.Position[1], data.pos[1]-origin[1]);
		SetAnalogPosRot(mJoyStates, mapping.Position[2], data.pos[2]-origin[2]);

		//Rotation

		//thanks, http://www.paulbourke.net/geometry/eulerangle/
		//still I'm not quite sure if this is correct... needs verifying.
		//okay, thanks to Opadong it's now verified.

		float pitch = asin(data.rot_mat[2][1]);
		SetAnalogPosRot(mJoyStates, mapping.Rotation[ControllerMapping::ePitch], pitch * float(180.0 / M_PI));

		float yaw = atan2(-data.rot_mat[2][0], data.rot_mat[2][2]);
		SetAnalogPosRot(mJoyStates, mapping.Rotation[ControllerMapping::eYaw], yaw * float(180.0 / M_PI));

		float roll = atan2(data.rot_mat[0][1], data.rot_mat[1][1]);
		SetAnalogPosRot(mJoyStates, mapping.Rotation[ControllerMapping::eRoll], roll * float(180.0 / M_PI));

		//Trigger

		if(mapping.TriggerIsAxis)
		{
			if(mapping.TriggerUseFullAxis)
			{
				AxisMapping& am = mapping.TriggerAxis;
				if(am.Joy != -1)
				{
					const long offset = long(float(PPJOY_AXIS_MAX - PPJOY_AXIS_MIN) * float(data.trigger)/am.Range);
					if(!am.Inverted)
					{
						mJoyStates[am.Joy].Analog[am.Axis] = PPJOY_AXIS_MIN + offset;
					}
					else
					{
						mJoyStates[am.Joy].Analog[am.Axis] = PPJOY_AXIS_MAX - offset;
					}
				}
			}
			else
			{
				SetAnalogPosRot(mJoyStates, mapping.TriggerAxis, float(data.trigger));
			}
		}
		else
		{
			if(mapping.TriggerButton.Joy != -1)
			{
				mJoyStates[mapping.TriggerButton.Joy].Digital[mapping.TriggerButton.Button] = (data.trigger > 127 ? 1 : 0);
			}
		}

		//Analog Stick X

		{
			float position = float(data.joystick_x - 127)/128;
			if(mapping.JoystickXIsAxis)
			{
				SetAnalogOther(mJoyStates, mapping.JoystickXAxis, (mapping.JoystickXAxis.Inverted ? - position : position));
			}
			else
			{
				SetDigital(mJoyStates, mapping.JoystickXButtons.Min, position < -0.5f);
				SetDigital(mJoyStates, mapping.JoystickXButtons.Max, position > 0.5f);
			}
		}

		//Analog Stick Y

		{
			float position = -float(data.joystick_y - 127)/128; //reportedly flipped
			if(mapping.JoystickYIsAxis)
			{
				SetAnalogOther(mJoyStates, mapping.JoystickYAxis, (mapping.JoystickYAxis.Inverted ? - position : position));
			}
			else
			{
				SetDigital(mJoyStates, mapping.JoystickYButtons.Min, position < -0.5f);
				SetDigital(mJoyStates, mapping.JoystickYButtons.Max, position > 0.5f);
			}
		}

		//send it to the joystick
		for(unsigned int joyIndex = 0; joyIndex < NUM_VIRTUAL_JOYSTICKS; ++joyIndex)
		{
			DWORD retSize;
			if (!DeviceIoControl(mJoyHandles[joyIndex],IOCTL_PPORTJOY_SET_STATE,mJoyStates+joyIndex,sizeof(JoystickState),NULL,0,&retSize,NULL))
			{
				DWORD rc = GetLastError();
				if (rc==2)
				{
					std::stringstream ss;
					ss << "Virtual joystick " << joyIndex+1 << " removed. Exiting.";
					error = ss.str();
					return false;
				}
				std::stringstream ss;
				ss << "Error " << rc << " updating virtual joystick " << joyIndex+1;
				error = ss.str();
				return false;
			}
		}
	}
	return true;
}
