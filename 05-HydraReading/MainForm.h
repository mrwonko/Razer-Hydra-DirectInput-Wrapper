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

#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <Windows.h>

class JoystickManagement;

namespace My05HydraReading
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class MainForm; //designer displays first class in header -.-
	ref class SetOriginForm;

	/// <summary>
	/// Zusammenfassung für MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void);

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~MainForm();
		!MainForm();

	private:
		
		/// \brief Timer for periodically polling the Hydra
		System::Windows::Forms::Timer^ mTimer;
		
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
	private: System::ComponentModel::IContainer^  components;


		
		
		//  General
		System::Windows::Forms::Label^  mLabelBase; // General messages displayed instead of ordinary content
		System::Windows::Forms::ComboBox^  mControllerChoice; // The Controller Dropdown Menu
		System::Windows::Forms::NumericUpDown^  mUpdateInterval;
		System::Windows::Forms::Label^  mUpdateIntervalLabel;

		//  Buttons
		//1
		System::Windows::Forms::ComboBox^  mButton1Joy;
		System::Windows::Forms::ComboBox^  mButton1Button;
		//2
		System::Windows::Forms::ComboBox^  mButton2Joy;
		System::Windows::Forms::ComboBox^  mButton2Button;
		//3
		System::Windows::Forms::ComboBox^  mButton3Joy;
		System::Windows::Forms::ComboBox^  mButton3Button;
		//4
		System::Windows::Forms::ComboBox^  mButton4Joy;
		System::Windows::Forms::ComboBox^  mButton4Button;
		//Analog Stick
		System::Windows::Forms::ComboBox^  mButtonJoystickJoy;
		System::Windows::Forms::ComboBox^  mButtonJoystickButton;
		//Start
		System::Windows::Forms::ComboBox^  mButtonStartJoy;
		System::Windows::Forms::ComboBox^  mButtonStartButton;
		//Bumper
		System::Windows::Forms::ComboBox^  mButtonBumperJoy;
		System::Windows::Forms::ComboBox^  mButtonBumperButton;
		
		//  Analog Stick X
		System::Windows::Forms::RadioButton^	mJoystickXTypeAxis;
		System::Windows::Forms::RadioButton^	mJoystickXTypeButtons;
		System::Windows::Forms::ComboBox^		mJoystickXAxisJoy;
		System::Windows::Forms::ComboBox^		mJoystickXAxisAxis;
		System::Windows::Forms::ComboBox^		mJoystickXButtonMinJoy;
		System::Windows::Forms::ComboBox^		mJoystickXButtonMinButton;
		System::Windows::Forms::ComboBox^		mJoystickXButtonMaxJoy;
		System::Windows::Forms::ComboBox^		mJoystickXButtonMaxButton;

		//  Analog Stick Y
		System::Windows::Forms::RadioButton^	mJoystickYTypeAxis;
		System::Windows::Forms::RadioButton^	mJoystickYTypeButtons;
		System::Windows::Forms::ComboBox^		mJoystickYAxisJoy;
		System::Windows::Forms::ComboBox^		mJoystickYAxisAxis;
		System::Windows::Forms::ComboBox^		mJoystickYButtonMaxJoy;
		System::Windows::Forms::ComboBox^		mJoystickYButtonMaxButton;
		System::Windows::Forms::ComboBox^		mJoystickYButtonMinJoy;
		System::Windows::Forms::ComboBox^		mJoystickYButtonMinButton;




		//  Trigger
		System::Windows::Forms::RadioButton^	mTriggerTypeAxis;
		System::Windows::Forms::RadioButton^	mTriggerTypeButton;
		System::Windows::Forms::ComboBox^		mTriggerJoy;
		System::Windows::Forms::ComboBox^		mTriggerAxis;
		System::Windows::Forms::ComboBox^		mTriggerButton;
		System::Windows::Forms::CheckBox^		mTriggerAxisInvert;
		System::Windows::Forms::CheckBox^		mTriggerFullAxis;

		//  Position
		//X
		System::Windows::Forms::ComboBox^		mAxisXJoy;
		System::Windows::Forms::ComboBox^		mAxisXAxis;
		System::Windows::Forms::NumericUpDown^  mAxisXRange;
		System::Windows::Forms::CheckBox^		mAxisXInvert;
		//Y
		System::Windows::Forms::ComboBox^		mAxisYJoy;
		System::Windows::Forms::ComboBox^		mAxisYAxis;
		System::Windows::Forms::NumericUpDown^  mAxisYRange;
		System::Windows::Forms::CheckBox^		mAxisYInvert;
		//Z
		System::Windows::Forms::ComboBox^		mAxisZJoy;
		System::Windows::Forms::ComboBox^		mAxisZAxis;
		System::Windows::Forms::NumericUpDown^  mAxisZRange;
		System::Windows::Forms::CheckBox^		mAxisZInvert;

		//  Rotation
		//Pitch
		System::Windows::Forms::ComboBox^		mAxisPitchJoy;
		System::Windows::Forms::ComboBox^		mAxisPitchAxis;
		System::Windows::Forms::NumericUpDown^  mAxisPitchRange;
		System::Windows::Forms::CheckBox^		mAxisPitchInvert;
		//Yaw
		System::Windows::Forms::ComboBox^		mAxisYawJoy;
		System::Windows::Forms::ComboBox^		mAxisYawAxis;
		System::Windows::Forms::NumericUpDown^  mAxisYawRange;
		System::Windows::Forms::CheckBox^		mAxisYawInvert;
		//Roll
		System::Windows::Forms::ComboBox^		mAxisRollJoy;
		System::Windows::Forms::ComboBox^		mAxisRollAxis;
		System::Windows::Forms::NumericUpDown^  mAxisRollRange;
		System::Windows::Forms::CheckBox^		mAxisRollInvert;

		//  Groups
		System::Windows::Forms::GroupBox^  mPositionGroup;
		System::Windows::Forms::GroupBox^  mButtonsGroup;
		System::Windows::Forms::GroupBox^  mJoystickGroup;
		System::Windows::Forms::GroupBox^  mControlGroup;
		System::Windows::Forms::GroupBox^  mRotationGroup;
		 System::Windows::Forms::GroupBox^  mTriggerGroup;

		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::Button^  mSaveButton;
			System::Windows::Forms::Button^  mLoadButton;
			System::Windows::Forms::Button^  mOriginButton;
			System::Windows::Forms::Button^  mAboutButton;
			System::Windows::Forms::PictureBox^  mButton1Image;
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			System::Windows::Forms::PictureBox^  mButton2Image;
			System::Windows::Forms::PictureBox^  mButton3Image;
			System::Windows::Forms::PictureBox^  mButtonBumperImage;
			System::Windows::Forms::PictureBox^  mButtonJoystickImage;
			System::Windows::Forms::PictureBox^  mButtonStartImage;
			System::Windows::Forms::Label^  mButton1Label;
			System::Windows::Forms::Label^  mButton2Label;
			System::Windows::Forms::Label^  mButton3Label;
			System::Windows::Forms::Label^  mButton4Label;
			System::Windows::Forms::Label^  mButtonJoystickLabel;
			System::Windows::Forms::Label^  mButtonStartLabel;
			System::Windows::Forms::Label^  mButtonBumperLabel;
			System::Windows::Forms::PictureBox^  mJoystickXImage;
			System::Windows::Forms::GroupBox^  mJoystickXGroup;
			System::Windows::Forms::Label^  label14;
			System::Windows::Forms::Label^  label13;
			System::Windows::Forms::PictureBox^  mButton4Image;
			System::Windows::Forms::PictureBox^  pictureBox1;
			System::Windows::Forms::Label^  label1;
			System::Windows::Forms::Label^  label2;
			System::Windows::Forms::Label^  label3;
			System::Windows::Forms::Label^  label4;
			System::Windows::Forms::PictureBox^  pictureBox2;
			System::Windows::Forms::Label^  label5;
			System::Windows::Forms::Label^  label6;
			System::Windows::Forms::PictureBox^  pictureBox3;
			System::Windows::Forms::PictureBox^  pictureBox4;
			System::Windows::Forms::PictureBox^  pictureBox5;
			System::Windows::Forms::Label^  label7;
			System::Windows::Forms::Label^  label8;
			System::Windows::Forms::Label^  label9;
			System::Windows::Forms::PictureBox^  pictureBox6;
			System::Windows::Forms::Label^  label10;
			System::Windows::Forms::Label^  label11;
			System::Windows::Forms::Label^  label12;
			System::Windows::Forms::ToolTip^  ToolTip;
			System::Windows::Forms::GroupBox^  groupBox1;
			System::Windows::Forms::PictureBox^  pictureBox7;
			System::Windows::Forms::Label^  label15;
			System::Windows::Forms::Label^  label16;
			System::Windows::Forms::PictureBox^  pictureBox8;
			this->mJoystickXTypeAxis = (gcnew System::Windows::Forms::RadioButton());
			this->mJoystickXTypeButtons = (gcnew System::Windows::Forms::RadioButton());
			this->mJoystickXAxisAxis = (gcnew System::Windows::Forms::ComboBox());
			this->mJoystickXAxisJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mJoystickXButtonMinButton = (gcnew System::Windows::Forms::ComboBox());
			this->mJoystickXButtonMaxButton = (gcnew System::Windows::Forms::ComboBox());
			this->mJoystickXButtonMinJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mJoystickXButtonMaxJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mControllerChoice = (gcnew System::Windows::Forms::ComboBox());
			this->mButton1Joy = (gcnew System::Windows::Forms::ComboBox());
			this->mButton2Joy = (gcnew System::Windows::Forms::ComboBox());
			this->mButton3Joy = (gcnew System::Windows::Forms::ComboBox());
			this->mButton4Joy = (gcnew System::Windows::Forms::ComboBox());
			this->mButtonJoystickJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mButtonStartJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mButtonBumperJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisZJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisYJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisZAxis = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisXJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisYAxis = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisXAxis = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisRollJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisPitchJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisRollAxis = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisYawJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisPitchAxis = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisYawAxis = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisZRange = (gcnew System::Windows::Forms::NumericUpDown());
			this->mAxisYRange = (gcnew System::Windows::Forms::NumericUpDown());
			this->mAxisXRange = (gcnew System::Windows::Forms::NumericUpDown());
			this->mAxisRollRange = (gcnew System::Windows::Forms::NumericUpDown());
			this->mAxisPitchRange = (gcnew System::Windows::Forms::NumericUpDown());
			this->mAxisYawRange = (gcnew System::Windows::Forms::NumericUpDown());
			this->mAxisZInvert = (gcnew System::Windows::Forms::CheckBox());
			this->mAxisYInvert = (gcnew System::Windows::Forms::CheckBox());
			this->mAxisXInvert = (gcnew System::Windows::Forms::CheckBox());
			this->mAxisRollInvert = (gcnew System::Windows::Forms::CheckBox());
			this->mAxisPitchInvert = (gcnew System::Windows::Forms::CheckBox());
			this->mAxisYawInvert = (gcnew System::Windows::Forms::CheckBox());
			this->mJoystickYAxisAxis = (gcnew System::Windows::Forms::ComboBox());
			this->mTriggerButton = (gcnew System::Windows::Forms::ComboBox());
			this->mUpdateIntervalLabel = (gcnew System::Windows::Forms::Label());
			this->mUpdateInterval = (gcnew System::Windows::Forms::NumericUpDown());
			this->mJoystickYTypeAxis = (gcnew System::Windows::Forms::RadioButton());
			this->mJoystickYTypeButtons = (gcnew System::Windows::Forms::RadioButton());
			this->mJoystickYAxisJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mJoystickYButtonMinButton = (gcnew System::Windows::Forms::ComboBox());
			this->mJoystickYButtonMaxButton = (gcnew System::Windows::Forms::ComboBox());
			this->mJoystickYButtonMinJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mJoystickYButtonMaxJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mTriggerTypeButton = (gcnew System::Windows::Forms::RadioButton());
			this->mLabelBase = (gcnew System::Windows::Forms::Label());
			this->mButton1Button = (gcnew System::Windows::Forms::ComboBox());
			this->mButton2Button = (gcnew System::Windows::Forms::ComboBox());
			this->mButton3Button = (gcnew System::Windows::Forms::ComboBox());
			this->mButton4Button = (gcnew System::Windows::Forms::ComboBox());
			this->mButtonJoystickButton = (gcnew System::Windows::Forms::ComboBox());
			this->mButtonStartButton = (gcnew System::Windows::Forms::ComboBox());
			this->mButtonBumperButton = (gcnew System::Windows::Forms::ComboBox());
			this->mPositionGroup = (gcnew System::Windows::Forms::GroupBox());
			this->mButtonsGroup = (gcnew System::Windows::Forms::GroupBox());
			this->mJoystickGroup = (gcnew System::Windows::Forms::GroupBox());
			this->mControlGroup = (gcnew System::Windows::Forms::GroupBox());
			this->mRotationGroup = (gcnew System::Windows::Forms::GroupBox());
			this->mTriggerGroup = (gcnew System::Windows::Forms::GroupBox());
			this->mTriggerAxisInvert = (gcnew System::Windows::Forms::CheckBox());
			this->mTriggerTypeAxis = (gcnew System::Windows::Forms::RadioButton());
			this->mTriggerAxis = (gcnew System::Windows::Forms::ComboBox());
			this->mTriggerJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mTriggerFullAxis = (gcnew System::Windows::Forms::CheckBox());
			mSaveButton = (gcnew System::Windows::Forms::Button());
			mLoadButton = (gcnew System::Windows::Forms::Button());
			mOriginButton = (gcnew System::Windows::Forms::Button());
			mAboutButton = (gcnew System::Windows::Forms::Button());
			mButton1Image = (gcnew System::Windows::Forms::PictureBox());
			mButton2Image = (gcnew System::Windows::Forms::PictureBox());
			mButton3Image = (gcnew System::Windows::Forms::PictureBox());
			mButtonBumperImage = (gcnew System::Windows::Forms::PictureBox());
			mButtonJoystickImage = (gcnew System::Windows::Forms::PictureBox());
			mButtonStartImage = (gcnew System::Windows::Forms::PictureBox());
			mButton1Label = (gcnew System::Windows::Forms::Label());
			mButton2Label = (gcnew System::Windows::Forms::Label());
			mButton3Label = (gcnew System::Windows::Forms::Label());
			mButton4Label = (gcnew System::Windows::Forms::Label());
			mButtonJoystickLabel = (gcnew System::Windows::Forms::Label());
			mButtonStartLabel = (gcnew System::Windows::Forms::Label());
			mButtonBumperLabel = (gcnew System::Windows::Forms::Label());
			mJoystickXImage = (gcnew System::Windows::Forms::PictureBox());
			mJoystickXGroup = (gcnew System::Windows::Forms::GroupBox());
			label14 = (gcnew System::Windows::Forms::Label());
			label13 = (gcnew System::Windows::Forms::Label());
			mButton4Image = (gcnew System::Windows::Forms::PictureBox());
			pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			label1 = (gcnew System::Windows::Forms::Label());
			label2 = (gcnew System::Windows::Forms::Label());
			label3 = (gcnew System::Windows::Forms::Label());
			label4 = (gcnew System::Windows::Forms::Label());
			pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			label5 = (gcnew System::Windows::Forms::Label());
			label6 = (gcnew System::Windows::Forms::Label());
			pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			label7 = (gcnew System::Windows::Forms::Label());
			label8 = (gcnew System::Windows::Forms::Label());
			label9 = (gcnew System::Windows::Forms::Label());
			pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			label10 = (gcnew System::Windows::Forms::Label());
			label11 = (gcnew System::Windows::Forms::Label());
			label12 = (gcnew System::Windows::Forms::Label());
			ToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			label15 = (gcnew System::Windows::Forms::Label());
			label16 = (gcnew System::Windows::Forms::Label());
			pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButton1Image))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButton2Image))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButton3Image))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButtonBumperImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButtonJoystickImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButtonStartImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mJoystickXImage))->BeginInit();
			mJoystickXGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButton4Image))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisZRange))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisYRange))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisXRange))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisRollRange))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisPitchRange))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisYawRange))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mUpdateInterval))->BeginInit();
			groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(pictureBox8))->BeginInit();
			this->mPositionGroup->SuspendLayout();
			this->mButtonsGroup->SuspendLayout();
			this->mJoystickGroup->SuspendLayout();
			this->mControlGroup->SuspendLayout();
			this->mRotationGroup->SuspendLayout();
			this->mTriggerGroup->SuspendLayout();
			this->SuspendLayout();
			mSaveButton->Location = System::Drawing::Point(139, 19);
			mSaveButton->Name = L"mSaveButton";
			mSaveButton->Size = System::Drawing::Size(50, 23);
			mSaveButton->TabIndex = 1;
			mSaveButton->Text = L"Save";
			ToolTip->SetToolTip(mSaveButton, L"Saves the layout of the current controller (not both!) to a file.");
			mSaveButton->UseVisualStyleBackColor = true;
			mSaveButton->Click += gcnew System::EventHandler(this, &MainForm::mSaveButton_Click);
			mLoadButton->Location = System::Drawing::Point(195, 19);
			mLoadButton->Name = L"mLoadButton";
			mLoadButton->Size = System::Drawing::Size(50, 23);
			mLoadButton->TabIndex = 2;
			mLoadButton->Text = L"Load";
			ToolTip->SetToolTip(mLoadButton, L"Loads the layout of the current controller (not both!) from a file.");
			mLoadButton->UseVisualStyleBackColor = true;
			mLoadButton->Click += gcnew System::EventHandler(this, &MainForm::mLoadButton_Click);
			mOriginButton->Location = System::Drawing::Point(251, 19);
			mOriginButton->Name = L"mOriginButton";
			mOriginButton->Size = System::Drawing::Size(75, 23);
			mOriginButton->TabIndex = 3;
			mOriginButton->Text = L"Set Origin";
			ToolTip->SetToolTip(mOriginButton, L"Sets the origin of the current controller, i.e. the point at which the position a" 
				L"xes are in the middle position.");
			mOriginButton->UseVisualStyleBackColor = true;
			mOriginButton->Click += gcnew System::EventHandler(this, &MainForm::OnSetOriginClicked);
			mAboutButton->Location = System::Drawing::Point(519, 19);
			mAboutButton->Name = L"mAboutButton";
			mAboutButton->Size = System::Drawing::Size(46, 23);
			mAboutButton->TabIndex = 4;
			mAboutButton->Text = L"About";
			mAboutButton->UseVisualStyleBackColor = true;
			mAboutButton->Click += gcnew System::EventHandler(this, &MainForm::OnAboutClicked);
			mButton1Image->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButton1Image.Image")));
			mButton1Image->Location = System::Drawing::Point(6, 19);
			mButton1Image->Name = L"mButton1Image";
			mButton1Image->Size = System::Drawing::Size(40, 50);
			mButton1Image->TabIndex = 10;
			mButton1Image->TabStop = false;
			mButton2Image->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButton2Image.Image")));
			mButton2Image->Location = System::Drawing::Point(6, 75);
			mButton2Image->Name = L"mButton2Image";
			mButton2Image->Size = System::Drawing::Size(40, 50);
			mButton2Image->TabIndex = 11;
			mButton2Image->TabStop = false;
			mButton3Image->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButton3Image.Image")));
			mButton3Image->Location = System::Drawing::Point(6, 131);
			mButton3Image->Name = L"mButton3Image";
			mButton3Image->Size = System::Drawing::Size(40, 50);
			mButton3Image->TabIndex = 12;
			mButton3Image->TabStop = false;
			mButtonBumperImage->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButtonBumperImage.Image")));
			mButtonBumperImage->Location = System::Drawing::Point(6, 355);
			mButtonBumperImage->Name = L"mButtonBumperImage";
			mButtonBumperImage->Size = System::Drawing::Size(40, 50);
			mButtonBumperImage->TabIndex = 14;
			mButtonBumperImage->TabStop = false;
			mButtonJoystickImage->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButtonJoystickImage.Image")));
			mButtonJoystickImage->Location = System::Drawing::Point(6, 243);
			mButtonJoystickImage->Name = L"mButtonJoystickImage";
			mButtonJoystickImage->Size = System::Drawing::Size(40, 50);
			mButtonJoystickImage->TabIndex = 15;
			mButtonJoystickImage->TabStop = false;
			mButtonStartImage->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButtonStartImage.Image")));
			mButtonStartImage->Location = System::Drawing::Point(6, 299);
			mButtonStartImage->Name = L"mButtonStartImage";
			mButtonStartImage->Size = System::Drawing::Size(40, 50);
			mButtonStartImage->TabIndex = 16;
			mButtonStartImage->TabStop = false;
			mButton1Label->AutoSize = true;
			mButton1Label->Location = System::Drawing::Point(52, 19);
			mButton1Label->Name = L"mButton1Label";
			mButton1Label->Size = System::Drawing::Size(47, 13);
			mButton1Label->TabIndex = 17;
			mButton1Label->Text = L"Button 1";
			mButton2Label->AutoSize = true;
			mButton2Label->Location = System::Drawing::Point(52, 75);
			mButton2Label->Name = L"mButton2Label";
			mButton2Label->Size = System::Drawing::Size(47, 13);
			mButton2Label->TabIndex = 18;
			mButton2Label->Text = L"Button 2";
			mButton3Label->AutoSize = true;
			mButton3Label->Location = System::Drawing::Point(52, 131);
			mButton3Label->Name = L"mButton3Label";
			mButton3Label->Size = System::Drawing::Size(47, 13);
			mButton3Label->TabIndex = 19;
			mButton3Label->Text = L"Button 3";
			mButton4Label->AutoSize = true;
			mButton4Label->Location = System::Drawing::Point(52, 187);
			mButton4Label->Name = L"mButton4Label";
			mButton4Label->Size = System::Drawing::Size(47, 13);
			mButton4Label->TabIndex = 20;
			mButton4Label->Text = L"Button 4";
			mButtonJoystickLabel->AutoSize = true;
			mButtonJoystickLabel->Location = System::Drawing::Point(52, 243);
			mButtonJoystickLabel->Name = L"mButtonJoystickLabel";
			mButtonJoystickLabel->Size = System::Drawing::Size(101, 13);
			mButtonJoystickLabel->TabIndex = 21;
			mButtonJoystickLabel->Text = L"Analog Stick Button";
			mButtonStartLabel->AutoSize = true;
			mButtonStartLabel->Location = System::Drawing::Point(52, 299);
			mButtonStartLabel->Name = L"mButtonStartLabel";
			mButtonStartLabel->Size = System::Drawing::Size(63, 13);
			mButtonStartLabel->TabIndex = 22;
			mButtonStartLabel->Text = L"Start Button";
			mButtonBumperLabel->AutoSize = true;
			mButtonBumperLabel->Location = System::Drawing::Point(52, 355);
			mButtonBumperLabel->Name = L"mButtonBumperLabel";
			mButtonBumperLabel->Size = System::Drawing::Size(70, 13);
			mButtonBumperLabel->TabIndex = 23;
			mButtonBumperLabel->Text = L"Front Bumper";
			mJoystickXImage->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mJoystickXImage.Image")));
			mJoystickXImage->Location = System::Drawing::Point(6, 19);
			mJoystickXImage->Name = L"mJoystickXImage";
			mJoystickXImage->Size = System::Drawing::Size(40, 50);
			mJoystickXImage->TabIndex = 40;
			mJoystickXImage->TabStop = false;
			ToolTip->SetToolTip(mJoystickXImage, L"Moving the Analog Stick to the left/right.");
			mJoystickXGroup->Controls->Add(this->mJoystickXTypeAxis);
			mJoystickXGroup->Controls->Add(this->mJoystickXTypeButtons);
			mJoystickXGroup->Controls->Add(this->mJoystickXAxisAxis);
			mJoystickXGroup->Controls->Add(this->mJoystickXAxisJoy);
			mJoystickXGroup->Controls->Add(this->mJoystickXButtonMinButton);
			mJoystickXGroup->Controls->Add(this->mJoystickXButtonMaxButton);
			mJoystickXGroup->Controls->Add(this->mJoystickXButtonMinJoy);
			mJoystickXGroup->Controls->Add(this->mJoystickXButtonMaxJoy);
			mJoystickXGroup->Controls->Add(mJoystickXImage);
			mJoystickXGroup->Controls->Add(label14);
			mJoystickXGroup->Controls->Add(label13);
			mJoystickXGroup->Location = System::Drawing::Point(6, 19);
			mJoystickXGroup->Name = L"mJoystickXGroup";
			mJoystickXGroup->Size = System::Drawing::Size(180, 143);
			mJoystickXGroup->TabIndex = 24;
			mJoystickXGroup->TabStop = false;
			mJoystickXGroup->Text = L"X Axis";
			this->mJoystickXTypeAxis->AutoSize = true;
			this->mJoystickXTypeAxis->Checked = true;
			this->mJoystickXTypeAxis->Location = System::Drawing::Point(52, 19);
			this->mJoystickXTypeAxis->Name = L"mJoystickXTypeAxis";
			this->mJoystickXTypeAxis->Size = System::Drawing::Size(44, 17);
			this->mJoystickXTypeAxis->TabIndex = 24;
			this->mJoystickXTypeAxis->TabStop = true;
			this->mJoystickXTypeAxis->Text = L"Axis";
			this->mJoystickXTypeAxis->UseVisualStyleBackColor = true;
			this->mJoystickXTypeAxis->CheckedChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mJoystickXTypeButtons->AutoSize = true;
			this->mJoystickXTypeButtons->Location = System::Drawing::Point(102, 19);
			this->mJoystickXTypeButtons->Name = L"mJoystickXTypeButtons";
			this->mJoystickXTypeButtons->Size = System::Drawing::Size(61, 17);
			this->mJoystickXTypeButtons->TabIndex = 25;
			this->mJoystickXTypeButtons->Text = L"Buttons";
			this->mJoystickXTypeButtons->UseVisualStyleBackColor = true;
			this->mJoystickXAxisAxis->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mJoystickXAxisAxis->FormattingEnabled = true;
			this->mJoystickXAxisAxis->Location = System::Drawing::Point(104, 58);
			this->mJoystickXAxisAxis->Name = L"mJoystickXAxisAxis";
			this->mJoystickXAxisAxis->Size = System::Drawing::Size(70, 21);
			this->mJoystickXAxisAxis->TabIndex = 27;
			ToolTip->SetToolTip(this->mJoystickXAxisAxis, L"The desired Axis. Not all games support axes 7 and 8, even less axes 9 and up.");
			this->mJoystickXAxisAxis->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mJoystickXAxisJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mJoystickXAxisJoy->FormattingEnabled = true;
			this->mJoystickXAxisJoy->Location = System::Drawing::Point(48, 58);
			this->mJoystickXAxisJoy->Name = L"mJoystickXAxisJoy";
			this->mJoystickXAxisJoy->Size = System::Drawing::Size(50, 21);
			this->mJoystickXAxisJoy->TabIndex = 26;
			this->mJoystickXAxisJoy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mJoystickXButtonMinButton->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mJoystickXButtonMinButton->Enabled = false;
			this->mJoystickXButtonMinButton->FormattingEnabled = true;
			this->mJoystickXButtonMinButton->Location = System::Drawing::Point(104, 85);
			this->mJoystickXButtonMinButton->Name = L"mJoystickXButtonMinButton";
			this->mJoystickXButtonMinButton->Size = System::Drawing::Size(70, 21);
			this->mJoystickXButtonMinButton->TabIndex = 29;
			this->mJoystickXButtonMinButton->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mJoystickXButtonMaxButton->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mJoystickXButtonMaxButton->Enabled = false;
			this->mJoystickXButtonMaxButton->FormattingEnabled = true;
			this->mJoystickXButtonMaxButton->Location = System::Drawing::Point(104, 112);
			this->mJoystickXButtonMaxButton->Name = L"mJoystickXButtonMaxButton";
			this->mJoystickXButtonMaxButton->Size = System::Drawing::Size(70, 21);
			this->mJoystickXButtonMaxButton->TabIndex = 31;
			this->mJoystickXButtonMaxButton->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mJoystickXButtonMinJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mJoystickXButtonMinJoy->Enabled = false;
			this->mJoystickXButtonMinJoy->FormattingEnabled = true;
			this->mJoystickXButtonMinJoy->Location = System::Drawing::Point(48, 85);
			this->mJoystickXButtonMinJoy->Name = L"mJoystickXButtonMinJoy";
			this->mJoystickXButtonMinJoy->Size = System::Drawing::Size(50, 21);
			this->mJoystickXButtonMinJoy->TabIndex = 28;
			this->mJoystickXButtonMinJoy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mJoystickXButtonMaxJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mJoystickXButtonMaxJoy->Enabled = false;
			this->mJoystickXButtonMaxJoy->FormattingEnabled = true;
			this->mJoystickXButtonMaxJoy->Location = System::Drawing::Point(48, 112);
			this->mJoystickXButtonMaxJoy->Name = L"mJoystickXButtonMaxJoy";
			this->mJoystickXButtonMaxJoy->Size = System::Drawing::Size(50, 21);
			this->mJoystickXButtonMaxJoy->TabIndex = 30;
			this->mJoystickXButtonMaxJoy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			label14->AutoSize = true;
			label14->Location = System::Drawing::Point(6, 115);
			label14->Name = L"label14";
			label14->Size = System::Drawing::Size(32, 13);
			label14->TabIndex = 20;
			label14->Text = L"Right";
			label13->AutoSize = true;
			label13->Location = System::Drawing::Point(6, 88);
			label13->Name = L"label13";
			label13->Size = System::Drawing::Size(25, 13);
			label13->TabIndex = 20;
			label13->Text = L"Left";
			mButton4Image->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButton4Image.Image")));
			mButton4Image->Location = System::Drawing::Point(6, 187);
			mButton4Image->Name = L"mButton4Image";
			mButton4Image->Size = System::Drawing::Size(40, 50);
			mButton4Image->TabIndex = 13;
			mButton4Image->TabStop = false;
			pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			pictureBox1->Location = System::Drawing::Point(6, 19);
			pictureBox1->Name = L"pictureBox1";
			pictureBox1->Size = System::Drawing::Size(40, 50);
			pictureBox1->TabIndex = 38;
			pictureBox1->TabStop = false;
			ToolTip->SetToolTip(pictureBox1, L"Left/Right position of the controller.");
			label1->AutoSize = true;
			label1->Location = System::Drawing::Point(52, 19);
			label1->Name = L"label1";
			label1->Size = System::Drawing::Size(67, 13);
			label1->TabIndex = 17;
			label1->Text = L"left(-)/right(+)";
			ToolTip->SetToolTip(label1, L"Left/Right position of the controller.");
			label2->AutoSize = true;
			label2->Location = System::Drawing::Point(52, 71);
			label2->Name = L"label2";
			label2->Size = System::Drawing::Size(59, 13);
			label2->TabIndex = 17;
			label2->Text = L"range (mm)";
			ToolTip->SetToolTip(label2, L"How many millimeters away from the origin the controller has to be for this axis " 
				L"to be at its maximum/minimum.");
			label3->AutoSize = true;
			label3->Location = System::Drawing::Point(52, 95);
			label3->Name = L"label3";
			label3->Size = System::Drawing::Size(71, 13);
			label3->TabIndex = 17;
			label3->Text = L"up(+)/down(-)";
			ToolTip->SetToolTip(label3, L"Up/down position of the controller.");
			label4->AutoSize = true;
			label4->Location = System::Drawing::Point(52, 147);
			label4->Name = L"label4";
			label4->Size = System::Drawing::Size(59, 13);
			label4->TabIndex = 17;
			label4->Text = L"range (mm)";
			ToolTip->SetToolTip(label4, L"How many millimeters away from the origin the controller has to be for this axis " 
				L"to be at its maximum/minimum.");
			pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			pictureBox2->Location = System::Drawing::Point(6, 95);
			pictureBox2->Name = L"pictureBox2";
			pictureBox2->Size = System::Drawing::Size(40, 50);
			pictureBox2->TabIndex = 38;
			pictureBox2->TabStop = false;
			ToolTip->SetToolTip(pictureBox2, L"Up/down position of the controller.");
			label5->AutoSize = true;
			label5->Location = System::Drawing::Point(52, 171);
			label5->Name = L"label5";
			label5->Size = System::Drawing::Size(78, 13);
			label5->TabIndex = 17;
			label5->Text = L"front(-)/back(+)";
			ToolTip->SetToolTip(label5, L"Front/back position of the controller.");
			label6->AutoSize = true;
			label6->Location = System::Drawing::Point(52, 223);
			label6->Name = L"label6";
			label6->Size = System::Drawing::Size(59, 13);
			label6->TabIndex = 17;
			label6->Text = L"range (mm)";
			ToolTip->SetToolTip(label6, L"How many millimeters away from the origin the controller has to be for this axis " 
				L"to be at its maximum/minimum.");
			pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox3.Image")));
			pictureBox3->Location = System::Drawing::Point(6, 171);
			pictureBox3->Name = L"pictureBox3";
			pictureBox3->Size = System::Drawing::Size(40, 50);
			pictureBox3->TabIndex = 38;
			pictureBox3->TabStop = false;
			ToolTip->SetToolTip(pictureBox3, L"Front/back position of the controller.");
			pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox4.Image")));
			pictureBox4->Location = System::Drawing::Point(6, 171);
			pictureBox4->Name = L"pictureBox4";
			pictureBox4->Size = System::Drawing::Size(40, 50);
			pictureBox4->TabIndex = 38;
			pictureBox4->TabStop = false;
			ToolTip->SetToolTip(pictureBox4, L"Rotation around the front/back axis.");
			pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox5.Image")));
			pictureBox5->Location = System::Drawing::Point(6, 95);
			pictureBox5->Name = L"pictureBox5";
			pictureBox5->Size = System::Drawing::Size(40, 50);
			pictureBox5->TabIndex = 38;
			pictureBox5->TabStop = false;
			ToolTip->SetToolTip(pictureBox5, L"Rotation around the left/right axis.");
			label7->AutoSize = true;
			label7->Location = System::Drawing::Point(52, 223);
			label7->Name = L"label7";
			label7->Size = System::Drawing::Size(81, 13);
			label7->TabIndex = 17;
			label7->Text = L"range (degrees)";
			ToolTip->SetToolTip(label7, L"How many degrees the controller has to be rotated for this axis to be at its maxi" 
				L"mum/minimum.");
			label8->AutoSize = true;
			label8->Location = System::Drawing::Point(52, 147);
			label8->Name = L"label8";
			label8->Size = System::Drawing::Size(81, 13);
			label8->TabIndex = 17;
			label8->Text = L"range (degrees)";
			ToolTip->SetToolTip(label8, L"How many degrees the controller has to be rotated for this axis to be at its maxi" 
				L"mum/minimum.");
			label9->AutoSize = true;
			label9->Location = System::Drawing::Point(52, 171);
			label9->Name = L"label9";
			label9->Size = System::Drawing::Size(20, 13);
			label9->TabIndex = 17;
			label9->Text = L"roll";
			ToolTip->SetToolTip(label9, L"Rotation around the front/back axis.");
			pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox6.Image")));
			pictureBox6->Location = System::Drawing::Point(6, 19);
			pictureBox6->Name = L"pictureBox6";
			pictureBox6->Size = System::Drawing::Size(40, 50);
			pictureBox6->TabIndex = 38;
			pictureBox6->TabStop = false;
			ToolTip->SetToolTip(pictureBox6, L"Rotation around the up/down axis.");
			label10->AutoSize = true;
			label10->Location = System::Drawing::Point(52, 95);
			label10->Name = L"label10";
			label10->Size = System::Drawing::Size(82, 13);
			label10->TabIndex = 17;
			label10->Text = L"pitch (up/down)";
			ToolTip->SetToolTip(label10, L"Rotation around the left/right axis.");
			label11->AutoSize = true;
			label11->Location = System::Drawing::Point(52, 71);
			label11->Name = L"label11";
			label11->Size = System::Drawing::Size(81, 13);
			label11->TabIndex = 17;
			label11->Text = L"range (degrees)";
			ToolTip->SetToolTip(label11, L"How many degrees the controller has to be rotated for this axis to be at its maxi" 
				L"mum/minimum.");
			label12->AutoSize = true;
			label12->Location = System::Drawing::Point(52, 19);
			label12->Name = L"label12";
			label12->Size = System::Drawing::Size(74, 13);
			label12->TabIndex = 17;
			label12->Text = L"yaw (left/right)";
			ToolTip->SetToolTip(label12, L"Rotation around the up/down axis.");
			this->mControllerChoice->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mControllerChoice->FormattingEnabled = true;
			this->mControllerChoice->Location = System::Drawing::Point(7, 20);
			this->mControllerChoice->Name = L"mControllerChoice";
			this->mControllerChoice->Size = System::Drawing::Size(126, 21);
			this->mControllerChoice->TabIndex = 0;
			ToolTip->SetToolTip(this->mControllerChoice, L"Changes the current controller - every other setting is for the current controlle" 
				L"r.");
			this->mButton1Joy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButton1Joy->FormattingEnabled = true;
			this->mButton1Joy->Location = System::Drawing::Point(52, 35);
			this->mButton1Joy->Name = L"mButton1Joy";
			this->mButton1Joy->Size = System::Drawing::Size(50, 21);
			this->mButton1Joy->TabIndex = 5;
			ToolTip->SetToolTip(this->mButton1Joy, L"The virtual joystick to which this input is mapped.");
			this->mButton1Joy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mButton2Joy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButton2Joy->FormattingEnabled = true;
			this->mButton2Joy->Location = System::Drawing::Point(52, 91);
			this->mButton2Joy->Name = L"mButton2Joy";
			this->mButton2Joy->Size = System::Drawing::Size(50, 21);
			this->mButton2Joy->TabIndex = 7;
			ToolTip->SetToolTip(this->mButton2Joy, L"The virtual joystick to which this input is mapped.");
			this->mButton2Joy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mButton3Joy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButton3Joy->FormattingEnabled = true;
			this->mButton3Joy->Location = System::Drawing::Point(52, 147);
			this->mButton3Joy->Name = L"mButton3Joy";
			this->mButton3Joy->Size = System::Drawing::Size(50, 21);
			this->mButton3Joy->TabIndex = 9;
			ToolTip->SetToolTip(this->mButton3Joy, L"The virtual joystick to which this input is mapped.");
			this->mButton3Joy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mButton4Joy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButton4Joy->FormattingEnabled = true;
			this->mButton4Joy->Location = System::Drawing::Point(52, 203);
			this->mButton4Joy->Name = L"mButton4Joy";
			this->mButton4Joy->Size = System::Drawing::Size(50, 21);
			this->mButton4Joy->TabIndex = 11;
			ToolTip->SetToolTip(this->mButton4Joy, L"The virtual joystick to which this input is mapped.");
			this->mButton4Joy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mButtonJoystickJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButtonJoystickJoy->FormattingEnabled = true;
			this->mButtonJoystickJoy->Location = System::Drawing::Point(52, 259);
			this->mButtonJoystickJoy->Name = L"mButtonJoystickJoy";
			this->mButtonJoystickJoy->Size = System::Drawing::Size(50, 21);
			this->mButtonJoystickJoy->TabIndex = 13;
			ToolTip->SetToolTip(this->mButtonJoystickJoy, L"The virtual joystick to which this input is mapped.");
			this->mButtonJoystickJoy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mButtonStartJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButtonStartJoy->FormattingEnabled = true;
			this->mButtonStartJoy->Location = System::Drawing::Point(52, 315);
			this->mButtonStartJoy->Name = L"mButtonStartJoy";
			this->mButtonStartJoy->Size = System::Drawing::Size(50, 21);
			this->mButtonStartJoy->TabIndex = 15;
			ToolTip->SetToolTip(this->mButtonStartJoy, L"The virtual joystick to which this input is mapped.");
			this->mButtonStartJoy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mButtonBumperJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButtonBumperJoy->FormattingEnabled = true;
			this->mButtonBumperJoy->Location = System::Drawing::Point(52, 371);
			this->mButtonBumperJoy->Name = L"mButtonBumperJoy";
			this->mButtonBumperJoy->Size = System::Drawing::Size(50, 21);
			this->mButtonBumperJoy->TabIndex = 17;
			ToolTip->SetToolTip(this->mButtonBumperJoy, L"The virtual joystick to which this input is mapped.");
			this->mButtonBumperJoy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisZJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisZJoy->FormattingEnabled = true;
			this->mAxisZJoy->Location = System::Drawing::Point(52, 194);
			this->mAxisZJoy->Name = L"mAxisZJoy";
			this->mAxisZJoy->Size = System::Drawing::Size(50, 21);
			this->mAxisZJoy->TabIndex = 49;
			ToolTip->SetToolTip(this->mAxisZJoy, L"The virtual joystick to which this input is mapped.");
			this->mAxisZJoy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisYJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisYJoy->FormattingEnabled = true;
			this->mAxisYJoy->Location = System::Drawing::Point(52, 118);
			this->mAxisYJoy->Name = L"mAxisYJoy";
			this->mAxisYJoy->Size = System::Drawing::Size(50, 21);
			this->mAxisYJoy->TabIndex = 45;
			ToolTip->SetToolTip(this->mAxisYJoy, L"The virtual joystick to which this input is mapped.");
			this->mAxisYJoy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisZAxis->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisZAxis->FormattingEnabled = true;
			this->mAxisZAxis->Location = System::Drawing::Point(108, 194);
			this->mAxisZAxis->Name = L"mAxisZAxis";
			this->mAxisZAxis->Size = System::Drawing::Size(70, 21);
			this->mAxisZAxis->TabIndex = 50;
			ToolTip->SetToolTip(this->mAxisZAxis, L"The desired Axis. Not all games support axes 7 and 8, even less axes 9 and up.");
			this->mAxisZAxis->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisXJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisXJoy->FormattingEnabled = true;
			this->mAxisXJoy->Location = System::Drawing::Point(52, 42);
			this->mAxisXJoy->Name = L"mAxisXJoy";
			this->mAxisXJoy->Size = System::Drawing::Size(50, 21);
			this->mAxisXJoy->TabIndex = 41;
			ToolTip->SetToolTip(this->mAxisXJoy, L"The virtual joystick to which this input is mapped.");
			this->mAxisXJoy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisYAxis->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisYAxis->FormattingEnabled = true;
			this->mAxisYAxis->Location = System::Drawing::Point(108, 118);
			this->mAxisYAxis->Name = L"mAxisYAxis";
			this->mAxisYAxis->Size = System::Drawing::Size(70, 21);
			this->mAxisYAxis->TabIndex = 46;
			ToolTip->SetToolTip(this->mAxisYAxis, L"The desired Axis. Not all games support axes 7 and 8, even less axes 9 and up.");
			this->mAxisYAxis->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisXAxis->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisXAxis->FormattingEnabled = true;
			this->mAxisXAxis->Location = System::Drawing::Point(108, 42);
			this->mAxisXAxis->Name = L"mAxisXAxis";
			this->mAxisXAxis->Size = System::Drawing::Size(70, 21);
			this->mAxisXAxis->TabIndex = 42;
			ToolTip->SetToolTip(this->mAxisXAxis, L"The desired Axis. Not all games support axes 7 and 8, even less axes 9 and up.");
			this->mAxisXAxis->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisRollJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisRollJoy->FormattingEnabled = true;
			this->mAxisRollJoy->Location = System::Drawing::Point(52, 194);
			this->mAxisRollJoy->Name = L"mAxisRollJoy";
			this->mAxisRollJoy->Size = System::Drawing::Size(50, 21);
			this->mAxisRollJoy->TabIndex = 61;
			ToolTip->SetToolTip(this->mAxisRollJoy, L"The virtual joystick to which this input is mapped.");
			this->mAxisRollJoy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisPitchJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisPitchJoy->FormattingEnabled = true;
			this->mAxisPitchJoy->Location = System::Drawing::Point(52, 118);
			this->mAxisPitchJoy->Name = L"mAxisPitchJoy";
			this->mAxisPitchJoy->Size = System::Drawing::Size(50, 21);
			this->mAxisPitchJoy->TabIndex = 57;
			ToolTip->SetToolTip(this->mAxisPitchJoy, L"The virtual joystick to which this input is mapped.");
			this->mAxisPitchJoy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisRollAxis->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisRollAxis->FormattingEnabled = true;
			this->mAxisRollAxis->Location = System::Drawing::Point(108, 194);
			this->mAxisRollAxis->Name = L"mAxisRollAxis";
			this->mAxisRollAxis->Size = System::Drawing::Size(70, 21);
			this->mAxisRollAxis->TabIndex = 62;
			ToolTip->SetToolTip(this->mAxisRollAxis, L"The desired Axis. Not all games support axes 7 and 8, even less axes 9 and up.");
			this->mAxisRollAxis->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisYawJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisYawJoy->FormattingEnabled = true;
			this->mAxisYawJoy->Location = System::Drawing::Point(52, 42);
			this->mAxisYawJoy->Name = L"mAxisYawJoy";
			this->mAxisYawJoy->Size = System::Drawing::Size(50, 21);
			this->mAxisYawJoy->TabIndex = 53;
			ToolTip->SetToolTip(this->mAxisYawJoy, L"The virtual joystick to which this input is mapped.");
			this->mAxisYawJoy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisPitchAxis->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisPitchAxis->FormattingEnabled = true;
			this->mAxisPitchAxis->Location = System::Drawing::Point(108, 118);
			this->mAxisPitchAxis->Name = L"mAxisPitchAxis";
			this->mAxisPitchAxis->Size = System::Drawing::Size(70, 21);
			this->mAxisPitchAxis->TabIndex = 58;
			ToolTip->SetToolTip(this->mAxisPitchAxis, L"The desired Axis. Not all games support axes 7 and 8, even less axes 9 and up.");
			this->mAxisPitchAxis->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisYawAxis->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisYawAxis->FormattingEnabled = true;
			this->mAxisYawAxis->Location = System::Drawing::Point(108, 42);
			this->mAxisYawAxis->Name = L"mAxisYawAxis";
			this->mAxisYawAxis->Size = System::Drawing::Size(70, 21);
			this->mAxisYawAxis->TabIndex = 54;
			ToolTip->SetToolTip(this->mAxisYawAxis, L"The desired Axis. Not all games support axes 7 and 8, even less axes 9 and up.");
			this->mAxisYawAxis->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisZRange->Location = System::Drawing::Point(133, 221);
			this->mAxisZRange->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->mAxisZRange->Name = L"mAxisZRange";
			this->mAxisZRange->Size = System::Drawing::Size(45, 20);
			this->mAxisZRange->TabIndex = 51;
			ToolTip->SetToolTip(this->mAxisZRange, L"How many millimeters away from the origin the controller has to be for this axis " 
				L"to be at its maximum/minimum.");
			this->mAxisZRange->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, 0});
			this->mAxisZRange->ValueChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisYRange->Location = System::Drawing::Point(133, 145);
			this->mAxisYRange->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->mAxisYRange->Name = L"mAxisYRange";
			this->mAxisYRange->Size = System::Drawing::Size(45, 20);
			this->mAxisYRange->TabIndex = 47;
			ToolTip->SetToolTip(this->mAxisYRange, L"How many millimeters away from the origin the controller has to be for this axis " 
				L"to be at its maximum/minimum.");
			this->mAxisYRange->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, 0});
			this->mAxisYRange->ValueChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisXRange->Location = System::Drawing::Point(133, 69);
			this->mAxisXRange->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->mAxisXRange->Name = L"mAxisXRange";
			this->mAxisXRange->Size = System::Drawing::Size(45, 20);
			this->mAxisXRange->TabIndex = 43;
			ToolTip->SetToolTip(this->mAxisXRange, L"How many millimeters away from the origin the controller has to be for this axis " 
				L"to be at its maximum/minimum.");
			this->mAxisXRange->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, 0});
			this->mAxisXRange->ValueChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisRollRange->Location = System::Drawing::Point(133, 221);
			this->mAxisRollRange->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {180, 0, 0, 0});
			this->mAxisRollRange->Name = L"mAxisRollRange";
			this->mAxisRollRange->Size = System::Drawing::Size(45, 20);
			this->mAxisRollRange->TabIndex = 63;
			ToolTip->SetToolTip(this->mAxisRollRange, L"How many degrees the controller has to be rotated for this axis to be at its maxi" 
				L"mum/minimum.");
			this->mAxisRollRange->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {45, 0, 0, 0});
			this->mAxisRollRange->ValueChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisPitchRange->Location = System::Drawing::Point(133, 145);
			this->mAxisPitchRange->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {180, 0, 0, 0});
			this->mAxisPitchRange->Name = L"mAxisPitchRange";
			this->mAxisPitchRange->Size = System::Drawing::Size(45, 20);
			this->mAxisPitchRange->TabIndex = 59;
			ToolTip->SetToolTip(this->mAxisPitchRange, L"How many degrees the controller has to be rotated for this axis to be at its maxi" 
				L"mum/minimum.");
			this->mAxisPitchRange->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {45, 0, 0, 0});
			this->mAxisPitchRange->ValueChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisYawRange->Location = System::Drawing::Point(133, 69);
			this->mAxisYawRange->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {180, 0, 0, 0});
			this->mAxisYawRange->Name = L"mAxisYawRange";
			this->mAxisYawRange->Size = System::Drawing::Size(45, 20);
			this->mAxisYawRange->TabIndex = 55;
			ToolTip->SetToolTip(this->mAxisYawRange, L"How many degrees the controller has to be rotated for this axis to be at its maxi" 
				L"mum/minimum.");
			this->mAxisYawRange->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {45, 0, 0, 0});
			this->mAxisYawRange->ValueChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisZInvert->AutoSize = true;
			this->mAxisZInvert->Location = System::Drawing::Point(128, 171);
			this->mAxisZInvert->Name = L"mAxisZInvert";
			this->mAxisZInvert->Size = System::Drawing::Size(52, 17);
			this->mAxisZInvert->TabIndex = 48;
			this->mAxisZInvert->Text = L"invert";
			ToolTip->SetToolTip(this->mAxisZInvert, L"Whether or not this axis should be inverted.");
			this->mAxisZInvert->UseVisualStyleBackColor = true;
			this->mAxisZInvert->CheckStateChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisYInvert->AutoSize = true;
			this->mAxisYInvert->Location = System::Drawing::Point(128, 95);
			this->mAxisYInvert->Name = L"mAxisYInvert";
			this->mAxisYInvert->Size = System::Drawing::Size(52, 17);
			this->mAxisYInvert->TabIndex = 44;
			this->mAxisYInvert->Text = L"invert";
			ToolTip->SetToolTip(this->mAxisYInvert, L"Whether or not this axis should be inverted.");
			this->mAxisYInvert->UseVisualStyleBackColor = true;
			this->mAxisYInvert->CheckStateChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisXInvert->AutoSize = true;
			this->mAxisXInvert->Location = System::Drawing::Point(128, 19);
			this->mAxisXInvert->Name = L"mAxisXInvert";
			this->mAxisXInvert->Size = System::Drawing::Size(52, 17);
			this->mAxisXInvert->TabIndex = 40;
			this->mAxisXInvert->Text = L"invert";
			ToolTip->SetToolTip(this->mAxisXInvert, L"Whether or not this axis should be inverted.");
			this->mAxisXInvert->UseVisualStyleBackColor = true;
			this->mAxisXInvert->CheckStateChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisRollInvert->AutoSize = true;
			this->mAxisRollInvert->Location = System::Drawing::Point(133, 170);
			this->mAxisRollInvert->Name = L"mAxisRollInvert";
			this->mAxisRollInvert->Size = System::Drawing::Size(52, 17);
			this->mAxisRollInvert->TabIndex = 60;
			this->mAxisRollInvert->Text = L"invert";
			ToolTip->SetToolTip(this->mAxisRollInvert, L"Whether or not this axis should be inverted.");
			this->mAxisRollInvert->UseVisualStyleBackColor = true;
			this->mAxisRollInvert->CheckStateChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisPitchInvert->AutoSize = true;
			this->mAxisPitchInvert->Location = System::Drawing::Point(133, 94);
			this->mAxisPitchInvert->Name = L"mAxisPitchInvert";
			this->mAxisPitchInvert->Size = System::Drawing::Size(52, 17);
			this->mAxisPitchInvert->TabIndex = 56;
			this->mAxisPitchInvert->Text = L"invert";
			ToolTip->SetToolTip(this->mAxisPitchInvert, L"Whether or not this axis should be inverted.");
			this->mAxisPitchInvert->UseVisualStyleBackColor = true;
			this->mAxisPitchInvert->CheckStateChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mAxisYawInvert->AutoSize = true;
			this->mAxisYawInvert->Location = System::Drawing::Point(133, 18);
			this->mAxisYawInvert->Name = L"mAxisYawInvert";
			this->mAxisYawInvert->Size = System::Drawing::Size(52, 17);
			this->mAxisYawInvert->TabIndex = 52;
			this->mAxisYawInvert->Text = L"invert";
			ToolTip->SetToolTip(this->mAxisYawInvert, L"Whether or not this axis should be inverted.");
			this->mAxisYawInvert->UseVisualStyleBackColor = true;
			this->mAxisYawInvert->CheckStateChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mJoystickYAxisAxis->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mJoystickYAxisAxis->FormattingEnabled = true;
			this->mJoystickYAxisAxis->Location = System::Drawing::Point(104, 58);
			this->mJoystickYAxisAxis->Name = L"mJoystickYAxisAxis";
			this->mJoystickYAxisAxis->Size = System::Drawing::Size(70, 21);
			this->mJoystickYAxisAxis->TabIndex = 35;
			ToolTip->SetToolTip(this->mJoystickYAxisAxis, L"The desired Axis. Not all games support axes 7 and 8, even less axes 9 and up.");
			this->mJoystickYAxisAxis->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mTriggerButton->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mTriggerButton->Enabled = false;
			this->mTriggerButton->FormattingEnabled = true;
			this->mTriggerButton->Location = System::Drawing::Point(184, 42);
			this->mTriggerButton->Name = L"mTriggerButton";
			this->mTriggerButton->Size = System::Drawing::Size(70, 21);
			this->mTriggerButton->TabIndex = 23;
			ToolTip->SetToolTip(this->mTriggerButton, L"The desired Axis. Not all games support axes 7 and 8, even less axes 9 and up.");
			this->mTriggerButton->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mUpdateIntervalLabel->AutoSize = true;
			this->mUpdateIntervalLabel->Location = System::Drawing::Point(427, 547);
			this->mUpdateIntervalLabel->Name = L"mUpdateIntervalLabel";
			this->mUpdateIntervalLabel->Size = System::Drawing::Size(101, 13);
			this->mUpdateIntervalLabel->TabIndex = 53;
			this->mUpdateIntervalLabel->Text = L"Update interval (ms)";
			ToolTip->SetToolTip(this->mUpdateIntervalLabel, resources->GetString(L"mUpdateIntervalLabel.ToolTip"));
			this->mUpdateInterval->Location = System::Drawing::Point(534, 545);
			this->mUpdateInterval->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->mUpdateInterval->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->mUpdateInterval->Name = L"mUpdateInterval";
			this->mUpdateInterval->Size = System::Drawing::Size(49, 20);
			this->mUpdateInterval->TabIndex = 54;
			ToolTip->SetToolTip(this->mUpdateInterval, resources->GetString(L"mUpdateInterval.ToolTip"));
			this->mUpdateInterval->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {16, 0, 0, 0});
			this->mUpdateInterval->ValueChanged += gcnew System::EventHandler(this, &MainForm::OnUpdateIntervalChanged);
			groupBox1->Controls->Add(this->mJoystickYTypeAxis);
			groupBox1->Controls->Add(this->mJoystickYTypeButtons);
			groupBox1->Controls->Add(this->mJoystickYAxisAxis);
			groupBox1->Controls->Add(this->mJoystickYAxisJoy);
			groupBox1->Controls->Add(this->mJoystickYButtonMinButton);
			groupBox1->Controls->Add(this->mJoystickYButtonMaxButton);
			groupBox1->Controls->Add(this->mJoystickYButtonMinJoy);
			groupBox1->Controls->Add(this->mJoystickYButtonMaxJoy);
			groupBox1->Controls->Add(pictureBox7);
			groupBox1->Controls->Add(label15);
			groupBox1->Controls->Add(label16);
			groupBox1->Location = System::Drawing::Point(192, 19);
			groupBox1->Name = L"groupBox1";
			groupBox1->Size = System::Drawing::Size(182, 143);
			groupBox1->TabIndex = 32;
			groupBox1->TabStop = false;
			groupBox1->Text = L"Y Axis";
			this->mJoystickYTypeAxis->AutoSize = true;
			this->mJoystickYTypeAxis->Checked = true;
			this->mJoystickYTypeAxis->Location = System::Drawing::Point(52, 19);
			this->mJoystickYTypeAxis->Name = L"mJoystickYTypeAxis";
			this->mJoystickYTypeAxis->Size = System::Drawing::Size(44, 17);
			this->mJoystickYTypeAxis->TabIndex = 32;
			this->mJoystickYTypeAxis->TabStop = true;
			this->mJoystickYTypeAxis->Text = L"Axis";
			this->mJoystickYTypeAxis->UseVisualStyleBackColor = true;
			this->mJoystickYTypeAxis->CheckedChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mJoystickYTypeButtons->AutoSize = true;
			this->mJoystickYTypeButtons->Location = System::Drawing::Point(102, 19);
			this->mJoystickYTypeButtons->Name = L"mJoystickYTypeButtons";
			this->mJoystickYTypeButtons->Size = System::Drawing::Size(61, 17);
			this->mJoystickYTypeButtons->TabIndex = 33;
			this->mJoystickYTypeButtons->Text = L"Buttons";
			this->mJoystickYTypeButtons->UseVisualStyleBackColor = true;
			this->mJoystickYAxisJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mJoystickYAxisJoy->FormattingEnabled = true;
			this->mJoystickYAxisJoy->Location = System::Drawing::Point(48, 58);
			this->mJoystickYAxisJoy->Name = L"mJoystickYAxisJoy";
			this->mJoystickYAxisJoy->Size = System::Drawing::Size(50, 21);
			this->mJoystickYAxisJoy->TabIndex = 34;
			this->mJoystickYAxisJoy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mJoystickYButtonMinButton->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mJoystickYButtonMinButton->Enabled = false;
			this->mJoystickYButtonMinButton->FormattingEnabled = true;
			this->mJoystickYButtonMinButton->Location = System::Drawing::Point(104, 85);
			this->mJoystickYButtonMinButton->Name = L"mJoystickYButtonMinButton";
			this->mJoystickYButtonMinButton->Size = System::Drawing::Size(70, 21);
			this->mJoystickYButtonMinButton->TabIndex = 37;
			this->mJoystickYButtonMinButton->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mJoystickYButtonMaxButton->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mJoystickYButtonMaxButton->Enabled = false;
			this->mJoystickYButtonMaxButton->FormattingEnabled = true;
			this->mJoystickYButtonMaxButton->Location = System::Drawing::Point(104, 112);
			this->mJoystickYButtonMaxButton->Name = L"mJoystickYButtonMaxButton";
			this->mJoystickYButtonMaxButton->Size = System::Drawing::Size(70, 21);
			this->mJoystickYButtonMaxButton->TabIndex = 39;
			this->mJoystickYButtonMaxButton->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mJoystickYButtonMinJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mJoystickYButtonMinJoy->Enabled = false;
			this->mJoystickYButtonMinJoy->FormattingEnabled = true;
			this->mJoystickYButtonMinJoy->Location = System::Drawing::Point(48, 85);
			this->mJoystickYButtonMinJoy->Name = L"mJoystickYButtonMinJoy";
			this->mJoystickYButtonMinJoy->Size = System::Drawing::Size(50, 21);
			this->mJoystickYButtonMinJoy->TabIndex = 36;
			this->mJoystickYButtonMinJoy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mJoystickYButtonMaxJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mJoystickYButtonMaxJoy->Enabled = false;
			this->mJoystickYButtonMaxJoy->FormattingEnabled = true;
			this->mJoystickYButtonMaxJoy->Location = System::Drawing::Point(48, 112);
			this->mJoystickYButtonMaxJoy->Name = L"mJoystickYButtonMaxJoy";
			this->mJoystickYButtonMaxJoy->Size = System::Drawing::Size(50, 21);
			this->mJoystickYButtonMaxJoy->TabIndex = 38;
			this->mJoystickYButtonMaxJoy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox7.Image")));
			pictureBox7->Location = System::Drawing::Point(6, 19);
			pictureBox7->Name = L"pictureBox7";
			pictureBox7->Size = System::Drawing::Size(40, 50);
			pictureBox7->TabIndex = 40;
			pictureBox7->TabStop = false;
			label15->AutoSize = true;
			label15->Location = System::Drawing::Point(6, 115);
			label15->Name = L"label15";
			label15->Size = System::Drawing::Size(35, 13);
			label15->TabIndex = 20;
			label15->Text = L"Down";
			label16->AutoSize = true;
			label16->Location = System::Drawing::Point(6, 88);
			label16->Name = L"label16";
			label16->Size = System::Drawing::Size(21, 13);
			label16->TabIndex = 20;
			label16->Text = L"Up";
			pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox8.Image")));
			pictureBox8->Location = System::Drawing::Point(6, 19);
			pictureBox8->Name = L"pictureBox8";
			pictureBox8->Size = System::Drawing::Size(40, 50);
			pictureBox8->TabIndex = 14;
			pictureBox8->TabStop = false;
			this->mTriggerTypeButton->AutoSize = true;
			this->mTriggerTypeButton->Location = System::Drawing::Point(102, 19);
			this->mTriggerTypeButton->Name = L"mTriggerTypeButton";
			this->mTriggerTypeButton->Size = System::Drawing::Size(56, 17);
			this->mTriggerTypeButton->TabIndex = 20;
			this->mTriggerTypeButton->Text = L"Button";
			this->mTriggerTypeButton->UseVisualStyleBackColor = true;
			this->mLabelBase->AutoSize = true;
			this->mLabelBase->Location = System::Drawing::Point(12, 9);
			this->mLabelBase->Name = L"mLabelBase";
			this->mLabelBase->Size = System::Drawing::Size(195, 13);
			this->mLabelBase->TabIndex = 0;
			this->mLabelBase->Text = L"Please place the controllers in the base.";
			this->mLabelBase->Visible = false;
			this->mButton1Button->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButton1Button->FormattingEnabled = true;
			this->mButton1Button->Location = System::Drawing::Point(108, 35);
			this->mButton1Button->Name = L"mButton1Button";
			this->mButton1Button->Size = System::Drawing::Size(70, 21);
			this->mButton1Button->TabIndex = 6;
			this->mButton1Button->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mButton2Button->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButton2Button->FormattingEnabled = true;
			this->mButton2Button->Location = System::Drawing::Point(108, 91);
			this->mButton2Button->Name = L"mButton2Button";
			this->mButton2Button->Size = System::Drawing::Size(70, 21);
			this->mButton2Button->TabIndex = 8;
			this->mButton2Button->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mButton3Button->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButton3Button->FormattingEnabled = true;
			this->mButton3Button->Location = System::Drawing::Point(108, 147);
			this->mButton3Button->Name = L"mButton3Button";
			this->mButton3Button->Size = System::Drawing::Size(70, 21);
			this->mButton3Button->TabIndex = 10;
			this->mButton3Button->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mButton4Button->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButton4Button->FormattingEnabled = true;
			this->mButton4Button->Location = System::Drawing::Point(108, 203);
			this->mButton4Button->Name = L"mButton4Button";
			this->mButton4Button->Size = System::Drawing::Size(70, 21);
			this->mButton4Button->TabIndex = 12;
			this->mButton4Button->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mButtonJoystickButton->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButtonJoystickButton->FormattingEnabled = true;
			this->mButtonJoystickButton->Location = System::Drawing::Point(108, 259);
			this->mButtonJoystickButton->Name = L"mButtonJoystickButton";
			this->mButtonJoystickButton->Size = System::Drawing::Size(70, 21);
			this->mButtonJoystickButton->TabIndex = 14;
			this->mButtonJoystickButton->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mButtonStartButton->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButtonStartButton->FormattingEnabled = true;
			this->mButtonStartButton->Location = System::Drawing::Point(108, 315);
			this->mButtonStartButton->Name = L"mButtonStartButton";
			this->mButtonStartButton->Size = System::Drawing::Size(70, 21);
			this->mButtonStartButton->TabIndex = 16;
			this->mButtonStartButton->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mButtonBumperButton->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButtonBumperButton->FormattingEnabled = true;
			this->mButtonBumperButton->Location = System::Drawing::Point(108, 371);
			this->mButtonBumperButton->Name = L"mButtonBumperButton";
			this->mButtonBumperButton->Size = System::Drawing::Size(70, 21);
			this->mButtonBumperButton->TabIndex = 18;
			this->mButtonBumperButton->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mPositionGroup->Controls->Add(this->mAxisZInvert);
			this->mPositionGroup->Controls->Add(this->mAxisZJoy);
			this->mPositionGroup->Controls->Add(this->mAxisYInvert);
			this->mPositionGroup->Controls->Add(this->mAxisYJoy);
			this->mPositionGroup->Controls->Add(this->mAxisZRange);
			this->mPositionGroup->Controls->Add(this->mAxisXInvert);
			this->mPositionGroup->Controls->Add(this->mAxisYRange);
			this->mPositionGroup->Controls->Add(this->mAxisZAxis);
			this->mPositionGroup->Controls->Add(this->mAxisXJoy);
			this->mPositionGroup->Controls->Add(this->mAxisYAxis);
			this->mPositionGroup->Controls->Add(pictureBox3);
			this->mPositionGroup->Controls->Add(this->mAxisXRange);
			this->mPositionGroup->Controls->Add(pictureBox2);
			this->mPositionGroup->Controls->Add(label6);
			this->mPositionGroup->Controls->Add(this->mAxisXAxis);
			this->mPositionGroup->Controls->Add(label4);
			this->mPositionGroup->Controls->Add(label5);
			this->mPositionGroup->Controls->Add(pictureBox1);
			this->mPositionGroup->Controls->Add(label3);
			this->mPositionGroup->Controls->Add(label2);
			this->mPositionGroup->Controls->Add(label1);
			this->mPositionGroup->Location = System::Drawing::Point(203, 242);
			this->mPositionGroup->Name = L"mPositionGroup";
			this->mPositionGroup->Size = System::Drawing::Size(186, 249);
			this->mPositionGroup->TabIndex = 40;
			this->mPositionGroup->TabStop = false;
			this->mPositionGroup->Text = L"Position";
			this->mButtonsGroup->Controls->Add(mButton1Image);
			this->mButtonsGroup->Controls->Add(mButton2Image);
			this->mButtonsGroup->Controls->Add(mButton3Image);
			this->mButtonsGroup->Controls->Add(mButton4Image);
			this->mButtonsGroup->Controls->Add(mButtonBumperImage);
			this->mButtonsGroup->Controls->Add(this->mButtonBumperButton);
			this->mButtonsGroup->Controls->Add(mButtonJoystickImage);
			this->mButtonsGroup->Controls->Add(this->mButtonBumperJoy);
			this->mButtonsGroup->Controls->Add(mButtonStartImage);
			this->mButtonsGroup->Controls->Add(this->mButtonStartButton);
			this->mButtonsGroup->Controls->Add(mButton1Label);
			this->mButtonsGroup->Controls->Add(this->mButtonStartJoy);
			this->mButtonsGroup->Controls->Add(mButton2Label);
			this->mButtonsGroup->Controls->Add(this->mButtonJoystickButton);
			this->mButtonsGroup->Controls->Add(mButton3Label);
			this->mButtonsGroup->Controls->Add(this->mButtonJoystickJoy);
			this->mButtonsGroup->Controls->Add(mButton4Label);
			this->mButtonsGroup->Controls->Add(this->mButton4Button);
			this->mButtonsGroup->Controls->Add(mButtonJoystickLabel);
			this->mButtonsGroup->Controls->Add(this->mButton4Joy);
			this->mButtonsGroup->Controls->Add(mButtonStartLabel);
			this->mButtonsGroup->Controls->Add(this->mButton3Button);
			this->mButtonsGroup->Controls->Add(mButtonBumperLabel);
			this->mButtonsGroup->Controls->Add(this->mButton3Joy);
			this->mButtonsGroup->Controls->Add(this->mButton1Joy);
			this->mButtonsGroup->Controls->Add(this->mButton2Button);
			this->mButtonsGroup->Controls->Add(this->mButton1Button);
			this->mButtonsGroup->Controls->Add(this->mButton2Joy);
			this->mButtonsGroup->Location = System::Drawing::Point(12, 68);
			this->mButtonsGroup->Name = L"mButtonsGroup";
			this->mButtonsGroup->Size = System::Drawing::Size(185, 412);
			this->mButtonsGroup->TabIndex = 5;
			this->mButtonsGroup->TabStop = false;
			this->mButtonsGroup->Text = L"Buttons";
			this->mJoystickGroup->Controls->Add(groupBox1);
			this->mJoystickGroup->Controls->Add(mJoystickXGroup);
			this->mJoystickGroup->Location = System::Drawing::Point(203, 68);
			this->mJoystickGroup->Name = L"mJoystickGroup";
			this->mJoystickGroup->Size = System::Drawing::Size(380, 168);
			this->mJoystickGroup->TabIndex = 47;
			this->mJoystickGroup->TabStop = false;
			this->mJoystickGroup->Text = L"Analog Stick";
			this->mControlGroup->Controls->Add(this->mControllerChoice);
			this->mControlGroup->Controls->Add(mSaveButton);
			this->mControlGroup->Controls->Add(mLoadButton);
			this->mControlGroup->Controls->Add(mOriginButton);
			this->mControlGroup->Controls->Add(mAboutButton);
			this->mControlGroup->Location = System::Drawing::Point(12, 12);
			this->mControlGroup->Name = L"mControlGroup";
			this->mControlGroup->Size = System::Drawing::Size(571, 50);
			this->mControlGroup->TabIndex = 1;
			this->mControlGroup->TabStop = false;
			this->mControlGroup->Text = L"Control";
			this->mRotationGroup->Controls->Add(this->mAxisRollInvert);
			this->mRotationGroup->Controls->Add(this->mAxisRollJoy);
			this->mRotationGroup->Controls->Add(this->mAxisPitchInvert);
			this->mRotationGroup->Controls->Add(this->mAxisPitchJoy);
			this->mRotationGroup->Controls->Add(this->mAxisRollRange);
			this->mRotationGroup->Controls->Add(this->mAxisYawInvert);
			this->mRotationGroup->Controls->Add(this->mAxisPitchRange);
			this->mRotationGroup->Controls->Add(this->mAxisRollAxis);
			this->mRotationGroup->Controls->Add(this->mAxisYawJoy);
			this->mRotationGroup->Controls->Add(this->mAxisPitchAxis);
			this->mRotationGroup->Controls->Add(pictureBox4);
			this->mRotationGroup->Controls->Add(this->mAxisYawRange);
			this->mRotationGroup->Controls->Add(pictureBox5);
			this->mRotationGroup->Controls->Add(label7);
			this->mRotationGroup->Controls->Add(this->mAxisYawAxis);
			this->mRotationGroup->Controls->Add(label8);
			this->mRotationGroup->Controls->Add(label9);
			this->mRotationGroup->Controls->Add(pictureBox6);
			this->mRotationGroup->Controls->Add(label10);
			this->mRotationGroup->Controls->Add(label11);
			this->mRotationGroup->Controls->Add(label12);
			this->mRotationGroup->Location = System::Drawing::Point(395, 242);
			this->mRotationGroup->Name = L"mRotationGroup";
			this->mRotationGroup->Size = System::Drawing::Size(188, 249);
			this->mRotationGroup->TabIndex = 52;
			this->mRotationGroup->TabStop = false;
			this->mRotationGroup->Text = L"Rotation";
			this->mTriggerGroup->Controls->Add(this->mTriggerFullAxis);
			this->mTriggerGroup->Controls->Add(this->mTriggerAxisInvert);
			this->mTriggerGroup->Controls->Add(this->mTriggerTypeAxis);
			this->mTriggerGroup->Controls->Add(pictureBox8);
			this->mTriggerGroup->Controls->Add(this->mTriggerAxis);
			this->mTriggerGroup->Controls->Add(this->mTriggerJoy);
			this->mTriggerGroup->Controls->Add(this->mTriggerTypeButton);
			this->mTriggerGroup->Controls->Add(this->mTriggerButton);
			this->mTriggerGroup->Location = System::Drawing::Point(12, 497);
			this->mTriggerGroup->Name = L"mTriggerGroup";
			this->mTriggerGroup->Size = System::Drawing::Size(283, 74);
			this->mTriggerGroup->TabIndex = 19;
			this->mTriggerGroup->TabStop = false;
			this->mTriggerGroup->Text = L"Trigger";
			this->mTriggerAxisInvert->AutoSize = true;
			this->mTriggerAxisInvert->Location = System::Drawing::Point(164, 19);
			this->mTriggerAxisInvert->Name = L"mTriggerAxisInvert";
			this->mTriggerAxisInvert->Size = System::Drawing::Size(52, 17);
			this->mTriggerAxisInvert->TabIndex = 48;
			this->mTriggerAxisInvert->Text = L"invert";
			this->mTriggerAxisInvert->UseVisualStyleBackColor = true;
			this->mTriggerAxisInvert->CheckStateChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mTriggerTypeAxis->AutoSize = true;
			this->mTriggerTypeAxis->Checked = true;
			this->mTriggerTypeAxis->Location = System::Drawing::Point(52, 19);
			this->mTriggerTypeAxis->Name = L"mTriggerTypeAxis";
			this->mTriggerTypeAxis->Size = System::Drawing::Size(44, 17);
			this->mTriggerTypeAxis->TabIndex = 19;
			this->mTriggerTypeAxis->TabStop = true;
			this->mTriggerTypeAxis->Text = L"Axis";
			this->mTriggerTypeAxis->UseVisualStyleBackColor = true;
			this->mTriggerTypeAxis->CheckedChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mTriggerAxis->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mTriggerAxis->FormattingEnabled = true;
			this->mTriggerAxis->Location = System::Drawing::Point(108, 42);
			this->mTriggerAxis->Name = L"mTriggerAxis";
			this->mTriggerAxis->Size = System::Drawing::Size(70, 21);
			this->mTriggerAxis->TabIndex = 22;
			this->mTriggerAxis->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mTriggerJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mTriggerJoy->FormattingEnabled = true;
			this->mTriggerJoy->Location = System::Drawing::Point(52, 42);
			this->mTriggerJoy->Name = L"mTriggerJoy";
			this->mTriggerJoy->Size = System::Drawing::Size(50, 21);
			this->mTriggerJoy->TabIndex = 21;
			this->mTriggerJoy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			this->mTriggerFullAxis->AutoSize = true;
			this->mTriggerFullAxis->Location = System::Drawing::Point(222, 19);
			this->mTriggerFullAxis->Name = L"mTriggerFullAxis";
			this->mTriggerFullAxis->Size = System::Drawing::Size(60, 17);
			this->mTriggerFullAxis->TabIndex = 49;
			this->mTriggerFullAxis->Text = L"full axis";
			this->mTriggerFullAxis->UseVisualStyleBackColor = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(595, 577);
			this->Controls->Add(this->mUpdateInterval);
			this->Controls->Add(this->mUpdateIntervalLabel);
			this->Controls->Add(this->mTriggerGroup);
			this->Controls->Add(this->mControlGroup);
			this->Controls->Add(this->mJoystickGroup);
			this->Controls->Add(this->mButtonsGroup);
			this->Controls->Add(this->mRotationGroup);
			this->Controls->Add(this->mPositionGroup);
			this->Controls->Add(this->mLabelBase);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"Razer Hydra PPJoy DirectInput Wrapper";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::OnClose);
			this->Shown += gcnew System::EventHandler(this, &MainForm::OnOpen);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButton1Image))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButton2Image))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButton3Image))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButtonBumperImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButtonJoystickImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButtonStartImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mJoystickXImage))->EndInit();
			mJoystickXGroup->ResumeLayout(false);
			mJoystickXGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButton4Image))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisZRange))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisYRange))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisXRange))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisRollRange))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisPitchRange))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisYawRange))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mUpdateInterval))->EndInit();
			groupBox1->ResumeLayout(false);
			groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(pictureBox8))->EndInit();
			this->mPositionGroup->ResumeLayout(false);
			this->mPositionGroup->PerformLayout();
			this->mButtonsGroup->ResumeLayout(false);
			this->mButtonsGroup->PerformLayout();
			this->mJoystickGroup->ResumeLayout(false);
			this->mControlGroup->ResumeLayout(false);
			this->mRotationGroup->ResumeLayout(false);
			this->mRotationGroup->PerformLayout();
			this->mTriggerGroup->ResumeLayout(false);
			this->mTriggerGroup->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		/** \brief Called when the Form is first opened. Initializes.
		**/
		System::Void OnOpen(System::Object^  sender, System::EventArgs^  e);

		/**	\brief This is where The Magicks happen :)
			
			Called periodically. Retrieves Data from the Hydra and uses it.
		**/
		System::Void OnTimerTick(System::Object^  sender, System::EventArgs^  e);

		//AboutForm^ mAboutForm;
		System::Void OnAboutClicked(System::Object^  sender, System::EventArgs^  e);
		
		bool mInitialized;
		bool mIgnoreBindingChanges; //For automatically setting all the bindings - I don't want to save the file 50 times.

		/** \brief Called whenever a setting is changed - updates the bindings.
		**/
		System::Void UpdateBindings(System::Object^  sender, System::EventArgs^  e);

		/** \brief Called whenever the selected Controller is changed - updates the displayed bindings.
		**/
		System::Void SelectedControllerChanged(System::Object^  sender, System::EventArgs^  e);

		void InitComboBoxes();

		const bool IsCurrentControllerLeft() { return this->mControllerChoice->SelectedIndex == 0; }

		System::Void OnClose(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);

		void ApplySettings();
		void ProcessRadioButtons();
		System::Void mSaveButton_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void mLoadButton_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void OnUpdateIntervalChanged(System::Object^  sender, System::EventArgs^  e)
		{
			this->mTimer->Interval = System::Convert::ToInt32(this->mUpdateInterval->Value);
		}

		SetOriginForm^ mSetOriginForm;

		System::Void OnSetOriginClicked(System::Object^  sender, System::EventArgs^  e);
		System::Void OnSetOriginClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);

		/** \brief Displays an Error and exits.
		**/
		void Error(const std::string& message);

		/** \brief Changes visibility to either display "Put controllers in Base" or the actual stuff.
			\note Needs to be updated when new elements get added, obviously.
		**/
		void DisplayBaseMessage(const bool display);

		/** \brief Loads the given file into the currently active controller.
		**/
		const bool LoadSettings(const std::wstring& filename);
		
		/** \brief Saves the currently active controller to the given file.
		**/
		const bool SaveSettings(const std::wstring& filename);

		JoystickManagement* mJoystickManagement;
	};
}

