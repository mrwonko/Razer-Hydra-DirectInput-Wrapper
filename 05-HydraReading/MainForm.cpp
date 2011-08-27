#include "stdafx.h"
#include "MainForm.h"
#include <Windows.h>
#include <sstream>

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
			box->Items->Add("Joy 1");
			box->Items->Add("Joy 2");
			box->Items->Add("Joy 3");
			box->Items->Add("Joy 4");
			box->SelectedIndex = 0;
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
		mLeftControllerIndex(-1),
		mRightControllerIndex(-1),
		mInitialized(false)
	{
		InitializeComponent();
	}

	MainForm::~MainForm()
	{
		if (components)
		{
			delete components;
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

	System::Void MainForm::OnOpen(System::Object^  sender, System::EventArgs^  e)
	{
		this->mTimer = gcnew System::Windows::Forms::Timer();
		this->mTimer->Tick += gcnew System::EventHandler(this, &MainForm::OnTimerTick);
		this->mTimer->Interval = 16;
		this->mTimer->Enabled = true;

		//    Combo Box Initialization
		
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
		
		//has to be called after the other comboboxes have been set up, otherwise it might try to change an uninitialized combobox.
		this->mControllerChoice->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::SelectedControllerChanged);
		SelectedControllerChanged(sender, e); //force update

		if(!LoadSettings(GetDefaultIniFilename(true), true) || !LoadSettings(GetDefaultIniFilename(false), false) )
		{
			Error("Could not load settings!");
			return;
		}
		mInitialized = true;
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

		this->mTestGroup->Visible = !display;

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
				mLeftControllerIndex = 0;
				mRightControllerIndex = 1;
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
				mLeftControllerIndex = connectedControllers[0];
				mRightControllerIndex = connectedControllers[1];
			}
			else
			{
				assert(data[0].which_hand == 2);
				assert(data[1].which_hand == 1);
				mLeftControllerIndex = connectedControllers[1];
				mRightControllerIndex = connectedControllers[0];
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
		int controllerToQuery = (this->mControllerChoice->SelectedIndex == 0 ? mLeftControllerIndex : mRightControllerIndex);
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
			ss << data.pos[0];
			this->mLabelXAxisValue->Text = gcnew String(ss.str().c_str());
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
			this->mPressedButtonsLabel->Text = gcnew String(ss.str().c_str());
		}
	}

	System::Void MainForm::UpdateBindings(System::Object^  sender, System::EventArgs^  e)
	{
		if(!mInitialized) return; //if this is called during initialization, it's because the initial values are set. We don't need to save those, in fact it'd probably cause bugs.

		//TODO
	}

	System::Void MainForm::SelectedControllerChanged(System::Object^  sender, System::EventArgs^  e)
	{
		//do stuff with this->mControllerChoice->SelectedIndex;
		
		// TODO
	}

	const bool MainForm::SaveSettings(const std::wstring& filename, const bool left)
	{
		//TODO

		if(!WritePrivateProfileString(L"section", L"key", L"value", filename.c_str()))
		{
			return false;
		}
		return true;
	}

	const bool MainForm::LoadSettings(const std::wstring& filename, const bool left)
	{
		wchar_t buffer[64];
#ifdef _DEBUG
		if(GetPrivateProfileString(L"debug", L"bDisplayBaseMessage", L"false", buffer, 64, filename.c_str()) == 0) //may truncate
		{
			return false;
		}
		std::wstring bDisplayBaseMessage(buffer);
		if(bDisplayBaseMessage == L"true")
		{
			DisplayBaseMessage(true);
		}
#endif

		//TODO

		return true;
	}
}