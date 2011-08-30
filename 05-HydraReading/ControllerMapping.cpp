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

#include "StdAfx.h"
#include "ControllerMapping.h"
#include "JoystickState.h"
#include <Windows.h>
#include <sstream>

ControllerMapping::ControllerMapping() :
	TriggerIsAxis(true),
	JoystickXIsAxis(true),
	JoystickYIsAxis(true)
{
	//unfortunately I can't give ButtonMapping a constructor to do this since it wouldn't be POD anymore and I couldn't use unions anymore - not that I needed to...
	for(ButtonMapping* bm = Buttons; bm != Buttons + 7; ++bm)
	{
		bm->Joy = -1;
		bm->Button = 0;
	}
	for(AxisMapping* am = Position; am != Position + 3; ++am)
	{
		am->Joy = -1;
		am->Axis = 0;
	}
	for(AxisMapping* am = Rotation; am != Rotation + 3; ++am)
	{
		am->Joy = -1;
		am->Axis = 0;
	}

	TriggerAxis.Joy = -1;
	TriggerAxis.Axis = 0;
	TriggerAxis.Inverted = false;
	TriggerAxis.Range = 255;

	JoystickXAxis.Joy = -1;
	JoystickXAxis.Axis = 0;
	JoystickXAxis.Inverted = false;

	JoystickYAxis.Joy = -1;
	JoystickYAxis.Axis = 0;
	JoystickYAxis.Inverted = false;
}

namespace
{
	const bool ReadInt(const wchar_t* category, const wchar_t* key, const wchar_t* defaultvalue, const wchar_t* filename, int& result, int min, int max)
	{
		//GetPrivateProfileString() may truncate, but such long strings are most likely invalid anyway
		wchar_t buffer[64];
		if(!GetPrivateProfileString(category, key, defaultvalue, buffer, 64, filename)) return false;
		std::wstringstream wss;
		wss << buffer;
		wss >> result;
		if(result < min || result > max) result = min;
		return true;
	}
	
	const bool ReadBool(const wchar_t* category, const wchar_t* key, const wchar_t* defaultvalue, const wchar_t* filename, bool& result)
	{
		//GetPrivateProfileString() may truncate, but such long strings are most likely invalid anyway
		wchar_t buffer[64];
		if(!GetPrivateProfileString(category, key, defaultvalue, buffer, 64, filename)) return false;
		result = (buffer[0] == L't' && buffer[1] == L'r' && buffer[2] == L'u' && buffer[3] == L'e' && buffer[4] == L'\0');
		return true;
	}

	const bool WriteInt(const wchar_t* category, const wchar_t* key, int value, const wchar_t* filename)
	{
		std::wstringstream wss;
		wss<<value;
		return WritePrivateProfileString(category, key, wss.str().c_str(), filename) == TRUE;
	}

	const bool WriteBool(const wchar_t* category, const wchar_t* key, bool value, const wchar_t* filename)
	{
		return WritePrivateProfileString(category, key, (value ? L"true" : L"false"), filename) == TRUE;
	}
}

const bool ControllerMapping::Save(const std::wstring& filename) const
{
	const wchar_t* filename_c = filename.c_str();
	//buttons
	if(!WriteInt(L"button_1", L"joystick", Buttons[eButton1].Joy,    filename_c)) return false;
	if(!WriteInt(L"button_1", L"button",   Buttons[eButton1].Button, filename_c)) return false;

	if(!WriteInt(L"button_2", L"joystick", Buttons[eButton2].Joy,    filename_c)) return false;
	if(!WriteInt(L"button_2", L"button",   Buttons[eButton2].Button, filename_c)) return false;

	if(!WriteInt(L"button_3", L"joystick", Buttons[eButton3].Joy,    filename_c)) return false;
	if(!WriteInt(L"button_3", L"button",   Buttons[eButton3].Button, filename_c)) return false;

	if(!WriteInt(L"button_4", L"joystick", Buttons[eButton4].Joy,    filename_c)) return false;
	if(!WriteInt(L"button_4", L"button",   Buttons[eButton4].Button, filename_c)) return false;

	if(!WriteInt(L"button_start", L"joystick", Buttons[eButtonStart].Joy,    filename_c)) return false;
	if(!WriteInt(L"button_start", L"button",   Buttons[eButtonStart].Button, filename_c)) return false;

	if(!WriteInt(L"button_bumper", L"joystick", Buttons[eButtonBumper].Joy,    filename_c)) return false;
	if(!WriteInt(L"button_bumper", L"button",   Buttons[eButtonBumper].Button, filename_c)) return false;

	if(!WriteInt(L"button_analog_stick", L"joystick", Buttons[eButtonJoystick].Joy,    filename_c)) return false;
	if(!WriteInt(L"button_analog_stick", L"button",   Buttons[eButtonJoystick].Button, filename_c)) return false;

	//  axes

	//position
	if(!WriteInt(L"axis_x", L"joystick", Position[0].Joy,      filename_c)) return false;
	if(!WriteInt(L"axis_x", L"axis",     Position[0].Axis,     filename_c)) return false;
	if(!WriteBool(L"axis_x",L"inverted", Position[0].Inverted, filename_c)) return false;
	if(!WriteInt(L"axis_x", L"range",    Position[0].Range,    filename_c)) return false;

	if(!WriteInt(L"axis_y", L"joystick", Position[1].Joy,      filename_c)) return false;
	if(!WriteInt(L"axis_y", L"axis",     Position[1].Axis,     filename_c)) return false;
	if(!WriteBool(L"axis_y",L"inverted", Position[1].Inverted, filename_c)) return false;
	if(!WriteInt(L"axis_y", L"range",    Position[1].Range,    filename_c)) return false;

	if(!WriteInt(L"axis_z", L"joystick", Position[2].Joy,      filename_c)) return false;
	if(!WriteInt(L"axis_z", L"axis",     Position[2].Axis,     filename_c)) return false;
	if(!WriteBool(L"axis_z",L"inverted", Position[2].Inverted, filename_c)) return false;
	if(!WriteInt(L"axis_z", L"range",    Position[2].Range,    filename_c)) return false;

	//rotation
	if(!WriteInt(L"axis_pitch", L"joystick", Rotation[ePitch].Joy,      filename_c)) return false;
	if(!WriteInt(L"axis_pitch", L"axis",     Rotation[ePitch].Axis,     filename_c)) return false;
	if(!WriteBool(L"axis_pitch",L"inverted", Rotation[ePitch].Inverted, filename_c)) return false;
	if(!WriteInt(L"axis_pitch", L"range",    Rotation[ePitch].Range,    filename_c)) return false;

	if(!WriteInt(L"axis_yaw",   L"joystick", Rotation[eYaw].Joy,        filename_c)) return false;
	if(!WriteInt(L"axis_yaw",   L"axis",     Rotation[eYaw].Axis,       filename_c)) return false;
	if(!WriteBool(L"axis_yaw",  L"inverted", Rotation[eYaw].Inverted,   filename_c)) return false;
	if(!WriteInt(L"axis_yaw",   L"range",    Rotation[eYaw].Range,      filename_c)) return false;

	if(!WriteInt(L"axis_roll",  L"joystick", Rotation[eRoll].Joy,       filename_c)) return false;
	if(!WriteInt(L"axis_roll",  L"axis",     Rotation[eRoll].Axis,      filename_c)) return false;
	if(!WriteBool(L"axis_roll", L"inverted", Rotation[eRoll].Inverted,  filename_c)) return false;
	if(!WriteInt(L"axis_roll",  L"range",    Rotation[eRoll].Range,     filename_c)) return false;

	//trigger
	if(!WriteBool(L"trigger", L"isAxis", TriggerIsAxis, filename_c)) return false;
	if(TriggerIsAxis)
	{
		if(!WriteInt(L"trigger", L"joystick", TriggerAxis.Joy,      filename_c)) return false;
		if(!WriteInt(L"trigger", L"axis",     TriggerAxis.Axis,     filename_c)) return false;
		if(!WriteBool(L"trigger",L"inverted", TriggerAxis.Inverted, filename_c)) return false;
		if(!WriteBool(L"trigger",L"useFullAxis",TriggerUseFullAxis, filename_c)) return false;
	}
	else
	{
		if(!WriteInt(L"trigger", L"joystick", TriggerButton.Joy,    filename_c)) return false;
		if(!WriteInt(L"trigger", L"button",   TriggerButton.Button, filename_c)) return false;
	}

	//analog stick X
	if(!WriteBool(L"analog_stick_x", L"isAxis", JoystickXIsAxis, filename_c)) return false;
	if(JoystickXIsAxis)
	{
		if(!WriteInt(L"analog_stick_x", L"joystick", JoystickXAxis.Joy,      filename_c)) return false;
		if(!WriteInt(L"analog_stick_x", L"axis",     JoystickXAxis.Axis,     filename_c)) return false;
	}
	else
	{
		if(!WriteInt(L"analog_stick_x", L"joystick_left", JoystickXButtons.Min.Joy,    filename_c)) return false;
		if(!WriteInt(L"analog_stick_x", L"button_left",   JoystickXButtons.Min.Button, filename_c)) return false;
		if(!WriteInt(L"analog_stick_x", L"joystick_right", JoystickXButtons.Max.Joy,    filename_c)) return false;
		if(!WriteInt(L"analog_stick_x", L"button_right",   JoystickXButtons.Max.Button, filename_c)) return false;
	}

	//analog stick Y
	if(!WriteBool(L"analog_stick_y", L"isAxis", JoystickYIsAxis, filename_c)) return false;
	if(JoystickYIsAxis)
	{
		if(!WriteInt(L"analog_stick_y", L"joystick", JoystickYAxis.Joy,      filename_c)) return false;
		if(!WriteInt(L"analog_stick_y", L"axis",     JoystickYAxis.Axis,     filename_c)) return false;
	}
	else
	{
		if(!WriteInt(L"analog_stick_y", L"joystick_left", JoystickYButtons.Min.Joy,    filename_c)) return false;
		if(!WriteInt(L"analog_stick_y", L"button_left",   JoystickYButtons.Min.Button, filename_c)) return false;
		if(!WriteInt(L"analog_stick_y", L"joystick_right", JoystickYButtons.Max.Joy,    filename_c)) return false;
		if(!WriteInt(L"analog_stick_y", L"button_right",   JoystickYButtons.Max.Button, filename_c)) return false;
	}

	return true;
}

const bool ControllerMapping::Load(const std::wstring& filename, const wchar_t* defaultJoystick)
{
	const wchar_t*& joy = defaultJoystick; //shorter so it fits into the layout
	const wchar_t* filename_c = filename.c_str();
	//buttons
	if(!ReadInt(L"button_1",			L"joystick", joy,  filename_c, Buttons[eButton1].Joy,    -1, 3)) return false;
	if(!ReadInt(L"button_1",			L"button",   L"0", filename_c, Buttons[eButton1].Button, 0, NUM_DIGITAL-1)) return false;

	if(!ReadInt(L"button_2",			L"joystick", joy,  filename_c, Buttons[eButton2].Joy,    -1, 3)) return false;
	if(!ReadInt(L"button_2",			L"button",   L"1", filename_c, Buttons[eButton2].Button, 0, NUM_DIGITAL-1)) return false;

	if(!ReadInt(L"button_3",			L"joystick", joy,  filename_c, Buttons[eButton3].Joy,    -1, 3)) return false;
	if(!ReadInt(L"button_3",			L"button",   L"2", filename_c, Buttons[eButton3].Button, 0, NUM_DIGITAL-1)) return false;

	if(!ReadInt(L"button_4",			L"joystick", joy,  filename_c, Buttons[eButton4].Joy   , -1, 3)) return false;
	if(!ReadInt(L"button_4",			L"button",   L"3", filename_c, Buttons[eButton4].Button, 0, NUM_DIGITAL-1)) return false;

	if(!ReadInt(L"button_start",		L"joystick", joy,  filename_c, Buttons[eButtonStart].Joy,    -1, 3)) return false;
	if(!ReadInt(L"button_start",		L"button",   L"7", filename_c, Buttons[eButtonStart].Button, 0, NUM_DIGITAL-1)) return false;

	if(!ReadInt(L"button_analog_stick",	L"joystick", joy,  filename_c, Buttons[eButtonJoystick].Joy,    -1, 3)) return false;
	if(!ReadInt(L"button_analog_stick",	L"button",   L"6", filename_c, Buttons[eButtonJoystick].Button, 0, NUM_DIGITAL-1)) return false;

	if(!ReadInt(L"button_bumper",		L"joystick", joy,  filename_c, Buttons[eButtonBumper].Joy,    -1, 3)) return false;
	if(!ReadInt(L"button_bumper",		L"button",   L"4", filename_c, Buttons[eButtonBumper].Button, 0, NUM_DIGITAL-1)) return false;

	//  axes

	//position
	if(!ReadInt(L"axis_x", L"joystick", joy,      filename_c, Position[0].Joy,  -1, 3)) return false;
	if(!ReadInt(L"axis_x", L"axis",     L"0",     filename_c, Position[0].Axis, 0, NUM_ANALOG-1)) return false;
	if(!ReadBool(L"axis_x",L"inverted", L"false", filename_c, Position[0].Inverted)) return false;
	if(!ReadInt(L"axis_x", L"range",    L"100",   filename_c, Position[0].Range, 0, 180)) return false;

	if(!ReadInt(L"axis_y", L"joystick", joy,      filename_c, Position[1].Joy,  -1, 3)) return false;
	if(!ReadInt(L"axis_y", L"axis",     L"1",     filename_c, Position[1].Axis, 0, NUM_ANALOG-1)) return false;
	if(!ReadBool(L"axis_y",L"inverted", L"false", filename_c, Position[1].Inverted)) return false;
	if(!ReadInt(L"axis_y", L"range",    L"100",   filename_c, Position[1].Range, 0, 180)) return false;

	if(!ReadInt(L"axis_z", L"joystick", joy,      filename_c, Position[2].Joy,  -1, 3)) return false;
	if(!ReadInt(L"axis_z", L"axis",     L"2",     filename_c, Position[2].Axis, 0, NUM_ANALOG-1)) return false;
	if(!ReadBool(L"axis_z",L"inverted", L"false", filename_c, Position[2].Inverted)) return false;
	if(!ReadInt(L"axis_z", L"range",    L"100",   filename_c, Position[2].Range, 0, 180)) return false;

	//rotation
	if(!ReadInt(L"axis_pitch", L"joystick", joy,      filename_c, Rotation[ePitch].Joy,  -1, 3)) return false;
	if(!ReadInt(L"axis_pitch", L"axis",     L"3",     filename_c, Rotation[ePitch].Axis, 0, NUM_ANALOG-1)) return false;
	if(!ReadBool(L"axis_pitch",L"inverted", L"false", filename_c, Rotation[ePitch].Inverted)) return false;
	if(!ReadInt(L"axis_pitch",   L"range",    L"45",  filename_c, Rotation[ePitch].Range, 0, 180)) return false;

	if(!ReadInt(L"axis_yaw",   L"joystick", joy,      filename_c, Rotation[eYaw].Joy,    -1, 3)) return false;
	if(!ReadInt(L"axis_yaw",   L"axis",     L"4",     filename_c, Rotation[eYaw].Axis,   0, NUM_ANALOG-1)) return false;
	if(!ReadBool(L"axis_yaw",  L"inverted", L"false", filename_c, Rotation[eYaw].Inverted)) return false;
	if(!ReadInt(L"axis_yaw",   L"range",    L"45",    filename_c, Rotation[eYaw].Range, 0, 180)) return false;

	if(!ReadInt(L"axis_roll",  L"joystick", joy,      filename_c, Rotation[eRoll].Joy,   -1, 3)) return false;
	if(!ReadInt(L"axis_roll" , L"axis",     L"5",     filename_c, Rotation[eRoll].Axis,  0, NUM_ANALOG-1)) return false;
	if(!ReadBool(L"axis_roll", L"inverted", L"false", filename_c, Rotation[eRoll].Inverted)) return false;
	if(!ReadInt(L"axis_roll",  L"range",    L"45",    filename_c, Rotation[eRoll].Range, 0, 180)) return false;

	//trigger
	if(!ReadBool(L"trigger", L"isAxis", L"false", filename_c, TriggerIsAxis)) return false;
	if(TriggerIsAxis)
	{
		if(!ReadInt(L"trigger", L"joystick", joy,      filename_c, TriggerAxis.Joy,  -1, 3)) return false;
		if(!ReadInt(L"trigger", L"axis",     L"7",     filename_c, TriggerAxis.Axis, 0, NUM_ANALOG-1)) return false;
		if(!ReadBool(L"trigger",L"inverted", L"false", filename_c, TriggerAxis.Inverted)) return false;
		if(!ReadBool(L"trigger",L"useFullAxis", L"false",filename_c,TriggerUseFullAxis)) return false;
	}
	else
	{
		if(!ReadInt(L"trigger", L"joystick", joy,  filename_c, TriggerButton.Joy,    -1, 3)) return false;
		if(!ReadInt(L"trigger", L"button",   L"5", filename_c, TriggerButton.Button, 0, NUM_DIGITAL-1)) return false;
	}
	
	//analog stick X
	if(!ReadBool(L"analog_stick_x", L"isAxis", L"true", filename_c, JoystickXIsAxis)) return false;
	if(JoystickXIsAxis)
	{
		if(!ReadInt(L"analog_stick_x", L"joystick", joy,      filename_c, JoystickXAxis.Joy,  -1, 3)) return false;
		if(!ReadInt(L"analog_stick_x", L"axis",     L"6",     filename_c, JoystickXAxis.Axis, 0, NUM_ANALOG-1)) return false;
	}
	else
	{
		if(!ReadInt(L"analog_stick_x", L"joystick_left", joy,  filename_c, JoystickXButtons.Min.Joy,    -1, 3)) return false;
		if(!ReadInt(L"analog_stick_x", L"button_left",   L"9", filename_c, JoystickXButtons.Min.Button, 0, NUM_DIGITAL-1)) return false;
		if(!ReadInt(L"analog_stick_x", L"joystick_right", joy,   filename_c, JoystickXButtons.Max.Joy,    -1, 3)) return false;
		if(!ReadInt(L"analog_stick_x", L"button_right",   L"10", filename_c, JoystickXButtons.Max.Button, 0, NUM_DIGITAL-1)) return false;
	}
	
	//analog stick Y
	if(!ReadBool(L"analog_stick_y", L"isAxis", L"true", filename_c, JoystickYIsAxis)) return false;
	if(JoystickXIsAxis)
	{
		if(!ReadInt(L"analog_stick_y", L"joystick", joy,      filename_c, JoystickYAxis.Joy, -1, 3)) return false;
		if(!ReadInt(L"analog_stick_y", L"axis",     L"7",     filename_c, JoystickYAxis.Axis, 0, NUM_ANALOG-1)) return false;
	}
	else
	{
		if(!ReadInt(L"analog_stick_y", L"joystick_left", joy,   filename_c, JoystickYButtons.Min.Joy, -1, 3)) return false;
		if(!ReadInt(L"analog_stick_y", L"button_left",   L"11", filename_c, JoystickYButtons.Min.Button, 0, NUM_DIGITAL-1)) return false;
		if(!ReadInt(L"analog_stick_y", L"joystick_right", joy,   filename_c, JoystickYButtons.Max.Joy, -1, 3)) return false;
		if(!ReadInt(L"analog_stick_y", L"button_right",   L"12", filename_c, JoystickYButtons.Max.Button, 0, NUM_DIGITAL-1)) return false;
	}

	return true;
}