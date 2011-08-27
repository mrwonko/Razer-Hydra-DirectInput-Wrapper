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
	int Range;
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

