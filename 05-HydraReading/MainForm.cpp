#include "stdafx.h"
#include "MainForm.h"
#ifdef _DEBUG
#include <Windows.h>
#endif
#include <sstream>
#include "ControllerMapping.h"

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
			box->Items->Add("Axis 9");
			box->Items->Add("Axis 10");
			box->Items->Add("Axis 11");
			box->Items->Add("Axis 12");
			box->Items->Add("Axis 13");
			box->Items->Add("Axis 14");
			box->Items->Add("Axis 15");
			box->Items->Add("Axis 16");
			box->SelectedIndex = 0;
		}
	}

	MainForm::MainForm(void) :
		mInitialized(false),
		mIgnoreBindingChanges(true),
		mControllerIndices(new int[2]),
		mControllerMappings(new ControllerMapping[2])
	{
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
	}

	//This doesn't work if I put it in the finalizer - seems that gets called at a time where stuff essential for the STL is not available anymore.
	System::Void MainForm::OnClose(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{
		if(this->mInitialized)
		{
			this->mControllerMappings[LEFT_CONTROLLER].Save(GetDefaultIniFilename(true));
			this->mControllerMappings[RIGHT_CONTROLLER].Save(GetDefaultIniFilename(false));
		}
	}

	System::Void MainForm::OnAboutClicked(System::Object^  sender, System::EventArgs^  e)
	{
		if(!mAboutForm)
		{
			mAboutForm = gcnew AboutForm();
		}
		mAboutForm->ShowDialog();
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
		this->mTimer->Interval = 16;
		this->mTimer->Enabled = true;

		
		//has to be called after the other comboboxes have been set up, otherwise it might try to change an uninitialized combobox.
		this->mControllerChoice->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::SelectedControllerChanged);
		this->SelectedControllerChanged(sender, e); //force update

		if(!mControllerMappings[LEFT_CONTROLLER].Load(GetDefaultIniFilename(true), L"0") || !mControllerMappings[RIGHT_CONTROLLER].Load(GetDefaultIniFilename(false), L"1"))
		{
			Error("Could not load settings!");
			return;
		}
		ApplySettings();
		this->mInitialized = true;
		this->mIgnoreBindingChanges = false;
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
		
		int controllerToQuery = mControllerIndices[this->mControllerChoice->SelectedIndex];
		sixenseControllerData data;
		if( sixenseGetNewestData(controllerToQuery, &data) != SIXENSE_SUCCESS )
		{
			this->Error("Could not poll data!");
			return;
		}

		{
			static int i = 0;
			std::stringstream ss;
			//ss<<++i;
			//ss<<mControllerChoice->SelectedIndex;
			//ss << data.pos[0];
			float x = data.pos[0];
			ss << " - " << x;
			//this->mLabelXAxisValue->Text = gcnew String(ss.str().c_str());
			//this->mTriggerGroup->Text = gcnew String(ss.str().c_str());
		}
		{
			std::stringstream ss;
			if(data.buttons & SIXENSE_BUTTON_1) ss << "1 ";
			if(data.buttons & SIXENSE_BUTTON_2) ss << "2 ";
			if(data.buttons & SIXENSE_BUTTON_3) ss << "3 ";
			if(data.buttons & SIXENSE_BUTTON_4) ss << "4 ";
			if(data.buttons & SIXENSE_BUTTON_START) ss << "Start ";
			if(data.buttons & SIXENSE_BUTTON_BUMPER) ss << "Bumper ";
			if(data.buttons & SIXENSE_BUTTON_JOYSTICK) ss << "Joystick ";
			//this->mPressedButtonsLabel->Text = gcnew String(ss.str().c_str());
		}
		
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

		if(!mapping.Save(GetDefaultIniFilename(this->mControllerChoice->SelectedIndex == LEFT_CONTROLLER)))
		{
			Error("Could not save settings!");
			return;
		}
	}

	System::Void MainForm::SelectedControllerChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if(!mInitialized) return;
		const bool prev = mIgnoreBindingChanges;
		mIgnoreBindingChanges = true;
		ApplySettings();
		mIgnoreBindingChanges = prev;
	}

	const bool MainForm::LoadSettings(const std::wstring& filename)
	{
		return mControllerMappings[this->mControllerChoice->SelectedIndex].Load(filename, (this->mControllerChoice->SelectedIndex == 0 ? L"0" : L"1"));
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
	}
}