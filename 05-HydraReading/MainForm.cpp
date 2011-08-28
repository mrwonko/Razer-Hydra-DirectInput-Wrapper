/*
===========================================================================
Copyright (C) 2011 Willi Schinmeyer

This file is part of the Razer Hydra DirectInput Wrapper source code.

Razer Hydra DirectInput Wrapper source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Razer Hydra DirectInput Wrapper source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Razer Hydra DirectInput Wrapper source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/

#include "stdafx.h"
#define _USE_MATH_DEFINES //or M_PI doesn't get defined
#include "MainForm.h"
#include <Windows.h>
#include <sstream>
#include "ControllerMapping.h"
#include "AboutForm.h"
#include "SetOriginForm.h"
#include "PPJIoctl.h" //PP Joy IOCTL (i/o control?)
#include "JoystickState.h"
#include <cmath>

#include <fstream>

namespace My05HydraReading
{
	namespace
	{
		std::wstring GetDefaultIniFilename(const bool left)
		{
			wchar_t dir[MAX_PATH];
			GetCurrentDirectory(MAX_PATH, dir);
			return std::wstring(dir) + (left ? L"/settingsLeft.ini" :  L"/settingsRight.ini");
		}

		std::wstring GetDefaultIniFilename(int side)
		{
			return GetDefaultIniFilename(side == MainForm::LEFT_CONTROLLER ? true : false);
		}

		// "Joy X" selection - width: 50
		void InitJoystickComboBox(System::Windows::Forms::ComboBox^ box)
		{
			box->Items->Clear();
			box->Items->Add("none");
			box->Items->Add("Joy 1");
			box->Items->Add("Joy 2");
			box->Items->Add("Joy 3");
			box->Items->Add("Joy 4");
			box->SelectedIndex = 1;
		}

		// "Button X" selection - width: 70
		void InitButtonComboBox(System::Windows::Forms::ComboBox^ box)
		{
			box->Items->Clear();
			box->Items->Add("Button 1");
			box->Items->Add("Button 2");
			box->Items->Add("Button 3");
			box->Items->Add("Button 4");
			box->Items->Add("Button 5");
			box->Items->Add("Button 6");
			box->Items->Add("Button 7");
			box->Items->Add("Button 8");
			box->Items->Add("Button 9");
			box->Items->Add("Button 10");
			box->Items->Add("Button 11");
			box->Items->Add("Button 12");
			box->Items->Add("Button 13");
			box->Items->Add("Button 14");
			box->Items->Add("Button 15");
			box->Items->Add("Button 16");
			box->SelectedIndex = 0;
		}

		// "Axis X" selection - width: ?
		void InitAxisComboBox(System::Windows::Forms::ComboBox^ box)
		{
			box->Items->Clear();
			box->Items->Add("Axis 1");
			box->Items->Add("Axis 2");
			box->Items->Add("Axis 3");
			box->Items->Add("Axis 4");
			box->Items->Add("Axis 5");
			box->Items->Add("Axis 6");
			box->Items->Add("Axis 7");
			box->Items->Add("Axis 8");
			/*box->Items->Add("Axis 9");
			box->Items->Add("Axis 10");
			box->Items->Add("Axis 11");
			box->Items->Add("Axis 12");
			box->Items->Add("Axis 13");
			box->Items->Add("Axis 14");
			box->Items->Add("Axis 15");
			box->Items->Add("Axis 16");*/
			box->SelectedIndex = 0;
		}

		std::wstring ToWideString( String ^ s)
		{
			std::wstring os;
			using namespace Runtime::InteropServices;
			const wchar_t* chars = (const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
			return os;
		}

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

	MainForm::MainForm(void) :
		mInitialized(false),
		mIgnoreBindingChanges(true),
		mControllerIndices(new int[2]),
		mControllerMappings(new ControllerMapping[2]),
		mOrigins(new float*[2]),
		mSetOriginForm(nullptr),
		mJoyHandles(new HANDLE[NUM_VIRTUAL_JOYSTICKS]),
		mJoyStates(new JoystickState[NUM_VIRTUAL_JOYSTICKS])
	{
		this->mOrigins[0] = new float[3];
		this->mOrigins[1] = new float[3];
		for(int cont = 0; cont < 2; ++cont)
		{
			for(int dim = 0; dim < 3; ++dim)
			{
				this->mOrigins[cont][dim] = 0.0f;
			}
		}
		this->mControllerIndices[0] = -1;
		this->mControllerIndices[1] = -1;
		this->InitializeComponent();

		//    Combo Box Initialization
		this->InitComboBoxes();
	}

	MainForm::~MainForm()
	{
		this->!MainForm();
	}

	MainForm::!MainForm()
	{
		if (components)
		{
			delete components;
		}
		if(this->mControllerIndices)
		{
			delete[] this->mControllerIndices;
		}
		if(this->mControllerMappings)
		{
			delete[] this->mControllerMappings;
		}
		if(this->mOrigins)
		{
			delete[] this->mOrigins[LEFT_CONTROLLER];
			delete[] this->mOrigins[RIGHT_CONTROLLER];
			delete[] this->mOrigins;
		}
		if(this->mJoyHandles) delete[] this->mJoyHandles;
		if(this->mJoyStates) delete[] this->mJoyStates;
	}

	//This doesn't work if I put it in the finalizer - seems that gets called at a time where stuff essential for the STL is not available anymore.
	System::Void MainForm::OnClose(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{
		if(this->mInitialized)
		{
			this->mControllerMappings[LEFT_CONTROLLER].Save(GetDefaultIniFilename(LEFT_CONTROLLER));
			this->mControllerMappings[RIGHT_CONTROLLER].Save(GetDefaultIniFilename(RIGHT_CONTROLLER));
		}
	}

	void MainForm::InitComboBoxes()
	{
		//  Controller Selection
		//let's prevent myself from screwing this up with the visual editor.
		this->mControllerChoice->Items->Clear();
		this->mControllerChoice->Items->Add("left controller");
		this->mControllerChoice->Items->Add("right controller");
		//for some reason I can't set this in the Visual Editor thingy.
		this->mControllerChoice->SelectedIndex = 0; //0: left, 1: right

		//  Buttons

		//Button 1
		InitJoystickComboBox(this->mButton1Joy);
		InitButtonComboBox(this->mButton1Button);

		//Button 2
		InitJoystickComboBox(this->mButton2Joy);
		InitButtonComboBox(this->mButton2Button);

		//Button 3
		InitJoystickComboBox(this->mButton3Joy);
		InitButtonComboBox(this->mButton3Button);

		//Button 4
		InitJoystickComboBox(this->mButton4Joy);
		InitButtonComboBox(this->mButton4Button);

		//Joystick Button
		InitJoystickComboBox(this->mButtonJoystickJoy);
		InitButtonComboBox(this->mButtonJoystickButton);

		//Start Button
		InitJoystickComboBox(this->mButtonStartJoy);
		InitButtonComboBox(this->mButtonStartButton);

		//Bumper Button
		InitJoystickComboBox(this->mButtonBumperJoy);
		InitButtonComboBox(this->mButtonBumperButton);

		//  Axes

		//X
		InitJoystickComboBox(this->mAxisXJoy);
		InitAxisComboBox(this->mAxisXAxis);
		
		//Y
		InitJoystickComboBox(this->mAxisYJoy);
		InitAxisComboBox(this->mAxisYAxis);

		//Z
		InitJoystickComboBox(this->mAxisZJoy);
		InitAxisComboBox(this->mAxisZAxis);

		//Pitch
		InitJoystickComboBox(this->mAxisPitchJoy);
		InitAxisComboBox(this->mAxisPitchAxis);
		
		//Yaw
		InitJoystickComboBox(this->mAxisYawJoy);
		InitAxisComboBox(this->mAxisYawAxis);

		//Roll
		InitJoystickComboBox(this->mAxisRollJoy);
		InitAxisComboBox(this->mAxisRollAxis);

		// Analog Stick
		//X
		InitJoystickComboBox(this->mJoystickXAxisJoy);
		InitAxisComboBox(this->mJoystickXAxisAxis);
		InitJoystickComboBox(this->mJoystickXButtonMinJoy);
		InitButtonComboBox(this->mJoystickXButtonMinButton);
		InitJoystickComboBox(this->mJoystickXButtonMaxJoy);
		InitButtonComboBox(this->mJoystickXButtonMaxButton);
		//Y
		InitJoystickComboBox(this->mJoystickYAxisJoy);
		InitAxisComboBox(this->mJoystickYAxisAxis);
		InitJoystickComboBox(this->mJoystickYButtonMinJoy);
		InitButtonComboBox(this->mJoystickYButtonMinButton);
		InitJoystickComboBox(this->mJoystickYButtonMaxJoy);
		InitButtonComboBox(this->mJoystickYButtonMaxButton);

		// Trigger
		InitJoystickComboBox(this->mTriggerJoy);
		InitAxisComboBox(this->mTriggerAxis);
		InitButtonComboBox(this->mTriggerButton);
	}

	System::Void MainForm::OnOpen(System::Object^  sender, System::EventArgs^  e)
	{
		this->mTimer = gcnew System::Windows::Forms::Timer();
		this->mTimer->Tick += gcnew System::EventHandler(this, &MainForm::OnTimerTick);
		this->mTimer->Interval = System::Convert::ToInt32(this->mUpdateInterval->Value);
		this->mTimer->Enabled = true;
		
		//has to be called after the other comboboxes have been set up, otherwise it might try to change an uninitialized combobox.
		this->mControllerChoice->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::SelectedControllerChanged);
		this->SelectedControllerChanged(sender, e); //force update

		if( !mControllerMappings[LEFT_CONTROLLER].Load(GetDefaultIniFilename(LEFT_CONTROLLER), L"0") ||
			!mControllerMappings[RIGHT_CONTROLLER].Load(GetDefaultIniFilename(RIGHT_CONTROLLER), L"1") ||
			!LoadOrigin(LEFT_CONTROLLER) ||
			!LoadOrigin(RIGHT_CONTROLLER)
		    )
		{
			Error("Could not load settings!");
			return;
		}
		ApplySettings();

		
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
				this->Error(ss.str().c_str());
				return;
			}

			/* Initialise the IOCTL data structure */
			mJoyStates[joyIndex].Signature = JOYSTICK_STATE_V1;
			mJoyStates[joyIndex].NumAnalog = NUM_ANALOG;
			mJoyStates[joyIndex].NumDigital = NUM_DIGITAL;
		}

		this->mInitialized = true;
	}

	void MainForm::Error(const std::string& message)
	{
		this->mTimer->Enabled = false; //IMPORTANT!
		this->Hide();
		MessageBox::Show(gcnew System::String(message.c_str()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		this->Close();
	}

	void MainForm::DisplayBaseMessage(const bool display)
	{
		//ordinary stuff: hidden when base message displayed.
		this->mControlGroup->Visible = !display;
		this->mButtonsGroup->Visible = !display;
		this->mJoystickGroup->Visible = !display;
		this->mPositionGroup->Visible = !display;
		this->mRotationGroup->Visible = !display;
		this->mTriggerGroup->Visible = !display;
		this->mUpdateIntervalLabel->Visible = !display;
		this->mUpdateInterval->Visible = !display;

		//base message
		this->mLabelBase->Visible = display;
	}

	const bool MainForm::SetBase()
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
		this->Error("Base disconnected!");
		return false;
	}

	const bool MainForm::SetControllerIndices()
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
			this->Error("Not enough controllers connected! (2)");
			return false;
#else
			//In debug mode, I'd like to be able to continue even if no controllers are connected.
			mControllerIndices[0] = 0;
			mControllerIndices[1] = 1;
			return true;
#endif
		}
		//poll controller information - it seems inefficient to do that multiple times though
		sixenseControllerData data[2];
		if( sixenseGetNewestData(connectedControllers[0], data) != SIXENSE_SUCCESS ||
			sixenseGetNewestData(connectedControllers[1], data+1) != SIXENSE_SUCCESS )
		{
			this->Error("Could not poll data!");
			return false;
		}

		// initialized?
		if(data[0].which_hand == 0 || data[1].which_hand == 0)
		{
			this->mLabelBase->Text = "Please place the controllers in the base.";
			DisplayBaseMessage(true);
			return false;
		}
		// different hands?
		if(data[0].which_hand == data[1].which_hand)
		{
			this->mLabelBase->Text = "Please place the controllers in different base docks.";
			DisplayBaseMessage(true);
			return false;
		}
		//yay, both are initialized and they correspond to different hands!
		//let's set up the variables
		DisplayBaseMessage(false);
		if(data[0].which_hand == 1) // 1 is left, 2 is right.
		{
			assert(data[1].which_hand == 2);
			mControllerIndices[LEFT_CONTROLLER]  = connectedControllers[0];
			mControllerIndices[RIGHT_CONTROLLER] = connectedControllers[1];
		}
		else
		{
			assert(data[0].which_hand == 2);
			assert(data[1].which_hand == 1);
			mControllerIndices[LEFT_CONTROLLER]  = connectedControllers[1];
			mControllerIndices[RIGHT_CONTROLLER] = connectedControllers[0];
		}

		return true;
	}

	System::Void MainForm::UpdateBindings(System::Object^  sender, System::EventArgs^  e)
	{ 
		//if this is called during initialization, it's because the initial values are set. We don't need to save those, in fact it'd probably cause bugs.
		//it would also get called a lot during setting loading, which I'd rather avoid
		if(mIgnoreBindingChanges) return;

		ControllerMapping& mapping = mControllerMappings[this->mControllerChoice->SelectedIndex]; //0 = left, 1 = right

		//get out buttons/axis settings
		ProcessRadioButtons();

		//      save all the settings.

		
		//  Buttons
		//1
		mapping.Buttons[ControllerMapping::eButton1].Set(mButton1Joy->SelectedIndex, mButton1Button->SelectedIndex);
		//2
		mapping.Buttons[ControllerMapping::eButton2].Set(mButton2Joy->SelectedIndex, mButton2Button->SelectedIndex);
		//3
		mapping.Buttons[ControllerMapping::eButton3].Set(mButton3Joy->SelectedIndex, mButton3Button->SelectedIndex);
		//4
		mapping.Buttons[ControllerMapping::eButton4].Set(mButton4Joy->SelectedIndex, mButton4Button->SelectedIndex);
		//Analog Stick
		mapping.Buttons[ControllerMapping::eButtonJoystick].Set(mButtonJoystickJoy->SelectedIndex, mButtonJoystickButton->SelectedIndex);
		//Start
		mapping.Buttons[ControllerMapping::eButtonStart].Set(mButtonStartJoy->SelectedIndex, mButtonStartButton->SelectedIndex);
		//Bumper
		mapping.Buttons[ControllerMapping::eButtonBumper].Set(mButtonBumperJoy->SelectedIndex, mButtonBumperButton->SelectedIndex);
		
		//  Position
		//X
		mapping.Position[0].Set(mAxisXJoy->SelectedIndex, mAxisXAxis->SelectedIndex, System::Convert::ToInt32(mAxisXRange->Value), mAxisXInvert->Checked);
		//Y
		mapping.Position[1].Set(mAxisYJoy->SelectedIndex, mAxisYAxis->SelectedIndex, System::Convert::ToInt32(mAxisYRange->Value), mAxisYInvert->Checked);
		//Z
		mapping.Position[2].Set(mAxisZJoy->SelectedIndex, mAxisZAxis->SelectedIndex, System::Convert::ToInt32(mAxisZRange->Value), mAxisZInvert->Checked);

		//  Rotation
		//Pitch
		mapping.Rotation[ControllerMapping::ePitch].Set(mAxisPitchJoy->SelectedIndex, mAxisPitchAxis->SelectedIndex, System::Convert::ToInt32(mAxisPitchRange->Value), mAxisPitchInvert->Checked);
		//Yaw
		mapping.Rotation[ControllerMapping::eYaw].Set(mAxisYawJoy->SelectedIndex, mAxisYawAxis->SelectedIndex, System::Convert::ToInt32(mAxisYawRange->Value), mAxisYawInvert->Checked);
		//Roll
		mapping.Rotation[ControllerMapping::eRoll].Set(mAxisRollJoy->SelectedIndex, mAxisRollAxis->SelectedIndex, System::Convert::ToInt32(mAxisRollRange->Value), mAxisRollInvert->Checked);

		//  Analog Stick X
		mapping.JoystickXIsAxis = mJoystickXTypeAxis->Checked;
		if(mapping.JoystickXIsAxis)
		{
			mapping.JoystickXAxis.Set(mJoystickXAxisJoy->SelectedIndex, mJoystickXAxisAxis->SelectedIndex);
		}
		else
		{
			mapping.JoystickXButtons.Min.Set(mJoystickXButtonMinJoy->SelectedIndex, mJoystickXButtonMinButton->SelectedIndex);
			mapping.JoystickXButtons.Max.Set(mJoystickXButtonMaxJoy->SelectedIndex, mJoystickXButtonMaxButton->SelectedIndex);
		}

		//  Analog Stick Y
		mapping.JoystickYIsAxis = mJoystickYTypeAxis->Checked;
		if(mapping.JoystickYIsAxis)
		{
			mapping.JoystickYAxis.Set(mJoystickYAxisJoy->SelectedIndex, mJoystickYAxisAxis->SelectedIndex);
		}
		else
		{
			mapping.JoystickYButtons.Min.Set(mJoystickYButtonMinJoy->SelectedIndex, mJoystickYButtonMinButton->SelectedIndex);
			mapping.JoystickYButtons.Max.Set(mJoystickYButtonMaxJoy->SelectedIndex, mJoystickYButtonMaxButton->SelectedIndex);
		}

		//  Trigger
		mapping.TriggerIsAxis = mTriggerTypeAxis->Checked;
		if(mapping.TriggerIsAxis)
		{
			mapping.TriggerAxis.Set(mTriggerJoy->SelectedIndex, mTriggerAxis->SelectedIndex);
		}
		else
		{
			mapping.TriggerButton.Set(mTriggerJoy->SelectedIndex, mTriggerButton->SelectedIndex);
		}

		if(!mapping.Save(GetDefaultIniFilename(this->mControllerChoice->SelectedIndex)))
		{
			Error("Could not save settings!");
			return;
		}
	}

	System::Void MainForm::SelectedControllerChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if(!mInitialized) return;
		ApplySettings();
	}

	const bool MainForm::LoadSettings(const std::wstring& filename)
	{
		if(!mControllerMappings[this->mControllerChoice->SelectedIndex].Load(filename, (this->mControllerChoice->SelectedIndex == 0 ? L"0" : L"1"))) return false;
		ApplySettings();
		return true;
	}
	
	const bool MainForm::SaveSettings(const std::wstring& filename)
	{
		return mControllerMappings[this->mControllerChoice->SelectedIndex].Save(filename);
	}

	void MainForm::ProcessRadioButtons()
	{
		//trigger 
		this->mTriggerAxis->Enabled = this->mTriggerTypeAxis->Checked;
		this->mTriggerButton->Enabled = !this->mTriggerTypeAxis->Checked;
		//grey out unavailable analog stick x settings
		this->mJoystickXAxisJoy->Enabled         =  this->mJoystickXTypeAxis->Checked;
		this->mJoystickXAxisAxis->Enabled        =  this->mJoystickXTypeAxis->Checked;
		this->mJoystickXButtonMinJoy->Enabled    = !this->mJoystickXTypeAxis->Checked;
		this->mJoystickXButtonMinButton->Enabled = !this->mJoystickXTypeAxis->Checked;
		this->mJoystickXButtonMaxJoy->Enabled    = !this->mJoystickXTypeAxis->Checked;
		this->mJoystickXButtonMaxButton->Enabled = !this->mJoystickXTypeAxis->Checked;
		//grey out unavailable analog stick y settings
		this->mJoystickYAxisJoy->Enabled         =  this->mJoystickYTypeAxis->Checked;
		this->mJoystickYAxisAxis->Enabled        =  this->mJoystickYTypeAxis->Checked;
		this->mJoystickYButtonMinJoy->Enabled    = !this->mJoystickYTypeAxis->Checked;
		this->mJoystickYButtonMinButton->Enabled = !this->mJoystickYTypeAxis->Checked;
		this->mJoystickYButtonMaxJoy->Enabled    = !this->mJoystickYTypeAxis->Checked;
		this->mJoystickYButtonMaxButton->Enabled = !this->mJoystickYTypeAxis->Checked;
	}

	void MainForm::ApplySettings()
	{
		this->mIgnoreBindingChanges = true;
		ControllerMapping& mapping = mControllerMappings[this->mControllerChoice->SelectedIndex];
		
		//  Buttons
		//1
		mButton1Joy->SelectedIndex    = mapping.Buttons[ControllerMapping::eButton1].Joy + 1;
		mButton1Button->SelectedIndex = mapping.Buttons[ControllerMapping::eButton1].Button;
		//2
		mButton2Joy->SelectedIndex    = mapping.Buttons[ControllerMapping::eButton2].Joy + 1;
		mButton2Button->SelectedIndex = mapping.Buttons[ControllerMapping::eButton2].Button;
		//3
		mButton3Joy->SelectedIndex    = mapping.Buttons[ControllerMapping::eButton3].Joy + 1;
		mButton3Button->SelectedIndex = mapping.Buttons[ControllerMapping::eButton3].Button;
		//4
		mButton4Joy->SelectedIndex    = mapping.Buttons[ControllerMapping::eButton4].Joy + 1;
		mButton4Button->SelectedIndex = mapping.Buttons[ControllerMapping::eButton4].Button;
		//Analog Stick
		mButtonJoystickJoy->SelectedIndex    = mapping.Buttons[ControllerMapping::eButtonJoystick].Joy + 1;
		mButtonJoystickButton->SelectedIndex = mapping.Buttons[ControllerMapping::eButtonJoystick].Button;
		//Start
		mButtonStartJoy->SelectedIndex    = mapping.Buttons[ControllerMapping::eButtonStart].Joy + 1;
		mButtonStartButton->SelectedIndex = mapping.Buttons[ControllerMapping::eButtonStart].Button;
		//Bumper
		mButtonBumperJoy->SelectedIndex    = mapping.Buttons[ControllerMapping::eButtonBumper].Joy + 1;
		mButtonBumperButton->SelectedIndex = mapping.Buttons[ControllerMapping::eButtonBumper].Button;
		
		//  Position
		//X
		mAxisXJoy->SelectedIndex  = mapping.Position[0].Joy + 1;
		mAxisXAxis->SelectedIndex = mapping.Position[0].Axis;
		mAxisXRange->Value        = mapping.Position[0].Range;
		mAxisXInvert->Checked     = mapping.Position[0].Inverted;
		//Y
		mAxisYJoy->SelectedIndex  = mapping.Position[1].Joy + 1;
		mAxisYAxis->SelectedIndex = mapping.Position[1].Axis;
		mAxisYRange->Value        = mapping.Position[1].Range;
		mAxisYInvert->Checked     = mapping.Position[1].Inverted;
		//Z
		mAxisZJoy->SelectedIndex  = mapping.Position[2].Joy + 1;
		mAxisZAxis->SelectedIndex = mapping.Position[2].Axis;
		mAxisZRange->Value        = mapping.Position[2].Range;
		mAxisZInvert->Checked     = mapping.Position[2].Inverted;

		//  Rotation
		//Pitch
		mAxisPitchJoy->SelectedIndex  = mapping.Rotation[ControllerMapping::ePitch].Joy + 1;
		mAxisPitchAxis->SelectedIndex = mapping.Rotation[ControllerMapping::ePitch].Axis;
		mAxisPitchRange->Value        = mapping.Rotation[ControllerMapping::ePitch].Range;
		mAxisPitchInvert->Checked     = mapping.Rotation[ControllerMapping::ePitch].Inverted;
		//Yaw
		mAxisYawJoy->SelectedIndex  = mapping.Rotation[ControllerMapping::eYaw].Joy + 1;
		mAxisYawAxis->SelectedIndex = mapping.Rotation[ControllerMapping::eYaw].Axis;
		mAxisYawRange->Value        = mapping.Rotation[ControllerMapping::eYaw].Range;
		mAxisYawInvert->Checked     = mapping.Rotation[ControllerMapping::eYaw].Inverted;
		//Roll
		mAxisRollJoy->SelectedIndex  = mapping.Rotation[ControllerMapping::eRoll].Joy + 1;
		mAxisRollAxis->SelectedIndex = mapping.Rotation[ControllerMapping::eRoll].Axis;
		mAxisRollRange->Value        = mapping.Rotation[ControllerMapping::eRoll].Range;
		mAxisRollInvert->Checked     = mapping.Rotation[ControllerMapping::eRoll].Inverted;

		//  Analog Stick X
		mJoystickXTypeAxis->Checked    =  mapping.JoystickXIsAxis;
		mJoystickXTypeButtons->Checked = !mapping.JoystickXIsAxis;
		if(mapping.JoystickXIsAxis)
		{
			mJoystickXAxisJoy->SelectedIndex  = mapping.JoystickXAxis.Joy + 1;
			mJoystickXAxisAxis->SelectedIndex = mapping.JoystickXAxis.Axis;
		}
		else
		{
			mJoystickXButtonMinJoy->SelectedIndex    = mapping.JoystickXButtons.Min.Joy + 1;
			mJoystickXButtonMinButton->SelectedIndex = mapping.JoystickXButtons.Min.Button;
			mJoystickXButtonMaxJoy->SelectedIndex    = mapping.JoystickXButtons.Max.Joy + 1;
			mJoystickXButtonMaxButton->SelectedIndex = mapping.JoystickXButtons.Max.Button;
		}

		//  Analog Stick Y
		mJoystickYTypeAxis->Checked    =  mapping.JoystickYIsAxis;
		mJoystickYTypeButtons->Checked = !mapping.JoystickYIsAxis;
		if(mapping.JoystickYIsAxis)
		{
			mJoystickYAxisJoy->SelectedIndex = mapping.JoystickYAxis.Joy + 1;
			mJoystickYAxisAxis->SelectedIndex = mapping.JoystickYAxis.Axis;
		}
		else
		{
			mJoystickYButtonMinJoy->SelectedIndex = mapping.JoystickYButtons.Min.Joy + 1;
			mJoystickYButtonMinButton->SelectedIndex = mapping.JoystickYButtons.Min.Button;
			mJoystickYButtonMaxJoy->SelectedIndex = mapping.JoystickYButtons.Max.Joy + 1;
			mJoystickYButtonMaxButton->SelectedIndex = mapping.JoystickYButtons.Max.Button;
		}

		//  Trigger
		mTriggerTypeAxis->Checked   =  mapping.TriggerIsAxis;
		mTriggerTypeButton->Checked = !mapping.TriggerIsAxis;
		if(mapping.TriggerIsAxis)
		{
			mTriggerJoy->SelectedIndex = mapping.TriggerAxis.Joy + 1;
			mTriggerAxis->SelectedIndex = mapping.TriggerAxis.Axis;
		}
		else
		{
			mTriggerJoy->SelectedIndex = mapping.TriggerButton.Joy + 1;
			mTriggerButton->SelectedIndex = mapping.TriggerButton.Button;
		}

		ProcessRadioButtons();
		this->mIgnoreBindingChanges = false;
	}

	System::Void MainForm::mSaveButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		SaveFileDialog^ saveFileDialog1 = gcnew System::Windows::Forms::SaveFileDialog;
		saveFileDialog1->Filter = "ini files (*.ini)|*.ini|All files (*.*)|*.*";
		saveFileDialog1->FilterIndex = 1;
		saveFileDialog1->RestoreDirectory = true;
		saveFileDialog1->Title = (this->mControllerChoice->SelectedIndex == LEFT_CONTROLLER ? "Save left controller settings" : "Save right controller settings");

		if ( saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
		{
			SaveSettings(ToWideString(saveFileDialog1->FileName));
		}
	}

	System::Void MainForm::mLoadButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		//openFileDialog1->InitialDirectory = "c:\\";
		openFileDialog1->Filter = "ini files (*.ini)|*.ini|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 1;
		openFileDialog1->RestoreDirectory = true;
		openFileDialog1->Title = (this->mControllerChoice->SelectedIndex == LEFT_CONTROLLER ? "Load left controller settings" : "Load right controller settings");

		if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
		{
			LoadSettings(ToWideString(openFileDialog1->FileName));
		}
	}

	const bool MainForm::LoadOrigin(int side)
	{
		return IniReadVec3f(L"origin", GetDefaultIniFilename(side).c_str(), mOrigins[side]);
	}
	
	const bool MainForm::SaveOrigin(int side)
	{
		return IniWriteVec3f(L"origin", mOrigins[side], GetDefaultIniFilename(side).c_str());
	}

	System::Void MainForm::OnAboutClicked(System::Object^  sender, System::EventArgs^  e)
	{
		//if(!mAboutForm)
		//{
			AboutForm^ mAboutForm = gcnew AboutForm();
		//}
		mAboutForm->ShowDialog();
	}

	System::Void MainForm::OnSetOriginClicked(System::Object^  sender, System::EventArgs^  e)
	{
		mSetOriginForm = gcnew SetOriginForm();
		mSetOriginForm->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::OnSetOriginClosed);
		mSetOriginForm->ShowDialog();
	}

	System::Void MainForm::OnSetOriginClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
	{
		mSetOriginForm = nullptr;
	}

	namespace
	{
		void SetDigital(JoystickState joyStates[], ButtonMapping& bm, bool pressed)
		{
			if(bm.Joy == -1) return;
			joyStates[bm.Joy].Digital[bm.Button] = pressed;
		}

		void Clamp(float min, float& val, float max)
		{
			if(val < min) val = min;
			if(val > max) val = max;
		}

		//works for position & rotation
		void SetAnalogPosRot(JoystickState joyStates[], AxisMapping& am, float position)
		{
			if(am.Joy == -1) return;
			Clamp(-float(am.Range), position, float(am.Range));
			if(am.Inverted) position = -position;
			joyStates[am.Joy].Analog[am.Axis] = (PPJOY_AXIS_MIN+PPJOY_AXIS_MAX)/2 + long(float(PPJOY_AXIS_MIN+PPJOY_AXIS_MAX)/2 * (position/am.Range));
		}

		void SetAnalogOther(JoystickState joyStates[], AxisMapping& am, float position)
		{
			if(am.Joy == -1) return;
			joyStates[am.Joy].Analog[am.Axis] = (PPJOY_AXIS_MIN+PPJOY_AXIS_MAX)/2 + long(float(PPJOY_AXIS_MIN+PPJOY_AXIS_MAX)/2 * position);
		}
	}

	System::Void MainForm::OnTimerTick(System::Object^  sender, System::EventArgs^  e)
	{
		//set correct base index
		if(!this->SetBase())
		{
			return;
		}
		//set correct controller indices
		if(!this->SetControllerIndices())
		{
			return;
		}
		
		int controllerToQuery = this->mControllerIndices[this->mControllerChoice->SelectedIndex];
		float* origin = this->mOrigins[this->mControllerChoice->SelectedIndex];
		ControllerMapping& mapping = this->mControllerMappings[this->mControllerChoice->SelectedIndex];

		sixenseControllerData data;
		if( sixenseGetNewestData(controllerToQuery, &data) != SIXENSE_SUCCESS )
		{
			this->Error("Could not poll data!");
			return;
		}

		if(mSetOriginForm) //Set Origin Window currently open?
		{
			//any key pressed?
			if(data.buttons & (SIXENSE_BUTTON_1 | SIXENSE_BUTTON_2 | SIXENSE_BUTTON_3 | SIXENSE_BUTTON_4 | SIXENSE_BUTTON_START | SIXENSE_BUTTON_BUMPER | SIXENSE_BUTTON_JOYSTICK) )
			{
				//apply origin on any key press
				SaveOrigin(this->mControllerChoice->SelectedIndex);
				for(int dim = 0; dim < 3; ++dim)
				{
					origin[dim] = data.pos[dim];
				}
				//And save it.
				//Also close the form, obviously.
				mSetOriginForm->Close();
			}
			//that's it.
			return;
		}
				
		//input sending time!

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
			SetAnalogOther(mJoyStates, mapping.TriggerAxis, float(data.trigger)/255);
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
			float position = float(data.joystick_y - 127)/128;
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
					this->Error(ss.str().c_str());
					return;
				}
				std::stringstream ss;
				ss << "Error " << rc << " updating virtual joystick " << joyIndex+1;
				this->Error(ss.str().c_str());
				return;
			}
		}
	}

}