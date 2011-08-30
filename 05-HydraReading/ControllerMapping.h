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

#pragma once

#include <string>

struct ButtonMapping
{
	int Joy; //0-3
	int Button; //0-15

	void Set(int joy, int button)
	{
		Joy = joy - 1;
		Button = button;
	}
	/*
	void ApplyTo(int& out_joy, int& out_button)
	{
		out_joy = Joy + 1;
		out_button = Button;
	}
	*/
};

struct AxisMapping
{
	int Joy; //0-3
	int Axis; //0-15
	int Range; //how far off the center is maximum?
	bool Inverted;

	void Set(int joy, int axis, int range = -1, bool inverted = false)
	{
		Joy = joy - 1;
		Axis = axis;
		Inverted = inverted;
		Range = range;
	}
	/*
	void ApplyTo(int& out_joy, int& out_axis)
	{
		out_joy = Joy + 1;
		out_axis = Axis;
	}

	void ApplyTo(int& out_joy, int& out_axis, int& out_range, bool& out_inverted)
	{
		ApplyTo(out_joy, out_axis);
		out_range = Range;
		out_inverted = Inverted;
	}
	*/
};

struct MinMaxButtonMapping
{
	ButtonMapping Min;
	ButtonMapping Max;
};

struct ControllerMapping
{
	ControllerMapping();
	const bool Save(const std::wstring& filename) const;
	const bool Load(const std::wstring& filename,  const wchar_t* defaultJoystick);

	enum ButtonIndices
	{
		eButton1 = 0,
		eButton2,
		eButton3,
		eButton4,
		eButtonStart,
		eButtonJoystick,
		eButtonBumper,
	};
	ButtonMapping Buttons[7];

	AxisMapping Position[3];

	enum RotationIndices
	{
		ePitch = 0,
		eYaw,
		eRoll,
	};
	AxisMapping Rotation[3];

	bool TriggerIsAxis;
	bool TriggerUseFullAxis;
	union
	{
		AxisMapping TriggerAxis;
		ButtonMapping TriggerButton;
	};

	bool JoystickXIsAxis;
	union
	{
		AxisMapping JoystickXAxis;
		MinMaxButtonMapping JoystickXButtons;
	};
	
	bool JoystickYIsAxis;
	union
	{
		AxisMapping JoystickYAxis;
		MinMaxButtonMapping JoystickYButtons;
	};
};

