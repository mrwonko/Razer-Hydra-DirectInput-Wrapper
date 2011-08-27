#pragma once

#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <sixense.h>
#include "AboutForm.h"

namespace My05HydraReading
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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

	private:

		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;
		
		//  automatically generated form elements

		//General

		System::Windows::Forms::Label^  mLabelBase; // General messages displayed instead of ordinary content
		System::Windows::Forms::ComboBox^  mControllerChoice; // The Controller Dropdown Menu

		//Buttons
		System::Windows::Forms::ComboBox^  mButton1Joy;
		System::Windows::Forms::ComboBox^  mButton1Button;
		System::Windows::Forms::ComboBox^  mButton2Button;
		System::Windows::Forms::ComboBox^  mButton2Joy;
		System::Windows::Forms::ComboBox^  mButton3Button;
		System::Windows::Forms::ComboBox^  mButton3Joy;
		System::Windows::Forms::ComboBox^  mButton4Button;
		System::Windows::Forms::ComboBox^  mButton4Joy;
		System::Windows::Forms::ComboBox^  mButtonJoystickButton;
		System::Windows::Forms::ComboBox^  mButtonJoystickJoy;
		System::Windows::Forms::ComboBox^  mButtonStartButton;
		System::Windows::Forms::ComboBox^  mButtonStartJoy;
		System::Windows::Forms::ComboBox^  mButtonBumperButton;
		System::Windows::Forms::ComboBox^  mButtonBumperJoy;


		//Analog Stick
		System::Windows::Forms::RadioButton^  mJoystickXTypeAxis;
		System::Windows::Forms::RadioButton^  mJoystickXTypeButtons;

		//Groups
		System::Windows::Forms::GroupBox^  mPositionGroup;
		System::Windows::Forms::GroupBox^  mButtonsGroup;
		System::Windows::Forms::GroupBox^  mJoystickGroup;
		System::Windows::Forms::GroupBox^  mRotationGroup;
		System::Windows::Forms::GroupBox^  mControlGroup;

		//Tests
		System::Windows::Forms::GroupBox^  mTestGroup;
		System::Windows::Forms::Label^  mPressedButtonsLabel;
		System::Windows::Forms::Label^  mLabelXAxisValue;




		/// \brief Timer for periodically polling the Hydra
		System::Windows::Forms::Timer^ mTimer;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::Label^  mLabelXAxis;
			System::Windows::Forms::Button^  mSaveButton;
			System::Windows::Forms::Button^  mLoadButton;
			System::Windows::Forms::Button^  mOriginButton;
			System::Windows::Forms::Button^  mAboutButton;
			System::Windows::Forms::Label^  mPressedButtonsDescLabel;
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
			System::Windows::Forms::PictureBox^  mButton4Image;
			this->mJoystickXTypeAxis = (gcnew System::Windows::Forms::RadioButton());
			this->mJoystickXTypeButtons = (gcnew System::Windows::Forms::RadioButton());
			this->mLabelXAxisValue = (gcnew System::Windows::Forms::Label());
			this->mLabelBase = (gcnew System::Windows::Forms::Label());
			this->mControllerChoice = (gcnew System::Windows::Forms::ComboBox());
			this->mPressedButtonsLabel = (gcnew System::Windows::Forms::Label());
			this->mButton1Joy = (gcnew System::Windows::Forms::ComboBox());
			this->mButton1Button = (gcnew System::Windows::Forms::ComboBox());
			this->mButton2Button = (gcnew System::Windows::Forms::ComboBox());
			this->mButton2Joy = (gcnew System::Windows::Forms::ComboBox());
			this->mButton3Button = (gcnew System::Windows::Forms::ComboBox());
			this->mButton3Joy = (gcnew System::Windows::Forms::ComboBox());
			this->mButton4Button = (gcnew System::Windows::Forms::ComboBox());
			this->mButton4Joy = (gcnew System::Windows::Forms::ComboBox());
			this->mButtonJoystickButton = (gcnew System::Windows::Forms::ComboBox());
			this->mButtonJoystickJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mButtonStartButton = (gcnew System::Windows::Forms::ComboBox());
			this->mButtonStartJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mButtonBumperButton = (gcnew System::Windows::Forms::ComboBox());
			this->mButtonBumperJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mPositionGroup = (gcnew System::Windows::Forms::GroupBox());
			this->mButtonsGroup = (gcnew System::Windows::Forms::GroupBox());
			this->mJoystickGroup = (gcnew System::Windows::Forms::GroupBox());
			this->mTestGroup = (gcnew System::Windows::Forms::GroupBox());
			this->mRotationGroup = (gcnew System::Windows::Forms::GroupBox());
			this->mControlGroup = (gcnew System::Windows::Forms::GroupBox());
			mLabelXAxis = (gcnew System::Windows::Forms::Label());
			mSaveButton = (gcnew System::Windows::Forms::Button());
			mLoadButton = (gcnew System::Windows::Forms::Button());
			mOriginButton = (gcnew System::Windows::Forms::Button());
			mAboutButton = (gcnew System::Windows::Forms::Button());
			mPressedButtonsDescLabel = (gcnew System::Windows::Forms::Label());
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
			mButton4Image = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButton1Image))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButton2Image))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButton3Image))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButtonBumperImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButtonJoystickImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButtonStartImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mJoystickXImage))->BeginInit();
			mJoystickXGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(mButton4Image))->BeginInit();
			this->mButtonsGroup->SuspendLayout();
			this->mJoystickGroup->SuspendLayout();
			this->mTestGroup->SuspendLayout();
			this->mControlGroup->SuspendLayout();
			this->SuspendLayout();
			// 
			// mLabelXAxis
			// 
			mLabelXAxis->AutoSize = true;
			mLabelXAxis->Location = System::Drawing::Point(6, 16);
			mLabelXAxis->Name = L"mLabelXAxis";
			mLabelXAxis->Size = System::Drawing::Size(39, 13);
			mLabelXAxis->TabIndex = 1;
			mLabelXAxis->Text = L"X Axis:";
			// 
			// mSaveButton
			// 
			mSaveButton->Location = System::Drawing::Point(139, 19);
			mSaveButton->Name = L"mSaveButton";
			mSaveButton->Size = System::Drawing::Size(50, 23);
			mSaveButton->TabIndex = 3;
			mSaveButton->Text = L"Save";
			mSaveButton->UseVisualStyleBackColor = true;
			// 
			// mLoadButton
			// 
			mLoadButton->Location = System::Drawing::Point(195, 19);
			mLoadButton->Name = L"mLoadButton";
			mLoadButton->Size = System::Drawing::Size(50, 23);
			mLoadButton->TabIndex = 4;
			mLoadButton->Text = L"Load";
			mLoadButton->UseVisualStyleBackColor = true;
			// 
			// mOriginButton
			// 
			mOriginButton->Location = System::Drawing::Point(251, 19);
			mOriginButton->Name = L"mOriginButton";
			mOriginButton->Size = System::Drawing::Size(75, 23);
			mOriginButton->TabIndex = 5;
			mOriginButton->Text = L"Set Origin";
			mOriginButton->UseVisualStyleBackColor = true;
			// 
			// mAboutButton
			// 
			mAboutButton->Location = System::Drawing::Point(332, 19);
			mAboutButton->Name = L"mAboutButton";
			mAboutButton->Size = System::Drawing::Size(75, 23);
			mAboutButton->TabIndex = 6;
			mAboutButton->Text = L"About";
			mAboutButton->UseVisualStyleBackColor = true;
			mAboutButton->Click += gcnew System::EventHandler(this, &MainForm::OnAboutClicked);
			// 
			// mPressedButtonsDescLabel
			// 
			mPressedButtonsDescLabel->AutoSize = true;
			mPressedButtonsDescLabel->Location = System::Drawing::Point(6, 29);
			mPressedButtonsDescLabel->Name = L"mPressedButtonsDescLabel";
			mPressedButtonsDescLabel->Size = System::Drawing::Size(87, 13);
			mPressedButtonsDescLabel->TabIndex = 7;
			mPressedButtonsDescLabel->Text = L"Pressed Buttons:";
			// 
			// mButton1Image
			// 
			mButton1Image->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButton1Image.Image")));
			mButton1Image->Location = System::Drawing::Point(6, 19);
			mButton1Image->Name = L"mButton1Image";
			mButton1Image->Size = System::Drawing::Size(40, 50);
			mButton1Image->TabIndex = 10;
			mButton1Image->TabStop = false;
			// 
			// mButton2Image
			// 
			mButton2Image->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButton2Image.Image")));
			mButton2Image->Location = System::Drawing::Point(6, 75);
			mButton2Image->Name = L"mButton2Image";
			mButton2Image->Size = System::Drawing::Size(40, 50);
			mButton2Image->TabIndex = 11;
			mButton2Image->TabStop = false;
			// 
			// mButton3Image
			// 
			mButton3Image->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButton3Image.Image")));
			mButton3Image->Location = System::Drawing::Point(6, 131);
			mButton3Image->Name = L"mButton3Image";
			mButton3Image->Size = System::Drawing::Size(40, 50);
			mButton3Image->TabIndex = 12;
			mButton3Image->TabStop = false;
			// 
			// mButtonBumperImage
			// 
			mButtonBumperImage->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButtonBumperImage.Image")));
			mButtonBumperImage->Location = System::Drawing::Point(6, 355);
			mButtonBumperImage->Name = L"mButtonBumperImage";
			mButtonBumperImage->Size = System::Drawing::Size(40, 50);
			mButtonBumperImage->TabIndex = 14;
			mButtonBumperImage->TabStop = false;
			// 
			// mButtonJoystickImage
			// 
			mButtonJoystickImage->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButtonJoystickImage.Image")));
			mButtonJoystickImage->Location = System::Drawing::Point(6, 243);
			mButtonJoystickImage->Name = L"mButtonJoystickImage";
			mButtonJoystickImage->Size = System::Drawing::Size(40, 50);
			mButtonJoystickImage->TabIndex = 15;
			mButtonJoystickImage->TabStop = false;
			// 
			// mButtonStartImage
			// 
			mButtonStartImage->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButtonStartImage.Image")));
			mButtonStartImage->Location = System::Drawing::Point(6, 299);
			mButtonStartImage->Name = L"mButtonStartImage";
			mButtonStartImage->Size = System::Drawing::Size(40, 50);
			mButtonStartImage->TabIndex = 16;
			mButtonStartImage->TabStop = false;
			// 
			// mButton1Label
			// 
			mButton1Label->AutoSize = true;
			mButton1Label->Location = System::Drawing::Point(52, 19);
			mButton1Label->Name = L"mButton1Label";
			mButton1Label->Size = System::Drawing::Size(47, 13);
			mButton1Label->TabIndex = 17;
			mButton1Label->Text = L"Button 1";
			// 
			// mButton2Label
			// 
			mButton2Label->AutoSize = true;
			mButton2Label->Location = System::Drawing::Point(52, 75);
			mButton2Label->Name = L"mButton2Label";
			mButton2Label->Size = System::Drawing::Size(47, 13);
			mButton2Label->TabIndex = 18;
			mButton2Label->Text = L"Button 2";
			// 
			// mButton3Label
			// 
			mButton3Label->AutoSize = true;
			mButton3Label->Location = System::Drawing::Point(52, 131);
			mButton3Label->Name = L"mButton3Label";
			mButton3Label->Size = System::Drawing::Size(47, 13);
			mButton3Label->TabIndex = 19;
			mButton3Label->Text = L"Button 3";
			// 
			// mButton4Label
			// 
			mButton4Label->AutoSize = true;
			mButton4Label->Location = System::Drawing::Point(52, 187);
			mButton4Label->Name = L"mButton4Label";
			mButton4Label->Size = System::Drawing::Size(47, 13);
			mButton4Label->TabIndex = 20;
			mButton4Label->Text = L"Button 4";
			// 
			// mButtonJoystickLabel
			// 
			mButtonJoystickLabel->AutoSize = true;
			mButtonJoystickLabel->Location = System::Drawing::Point(52, 243);
			mButtonJoystickLabel->Name = L"mButtonJoystickLabel";
			mButtonJoystickLabel->Size = System::Drawing::Size(101, 13);
			mButtonJoystickLabel->TabIndex = 21;
			mButtonJoystickLabel->Text = L"Analog Stick Button";
			// 
			// mButtonStartLabel
			// 
			mButtonStartLabel->AutoSize = true;
			mButtonStartLabel->Location = System::Drawing::Point(52, 299);
			mButtonStartLabel->Name = L"mButtonStartLabel";
			mButtonStartLabel->Size = System::Drawing::Size(63, 13);
			mButtonStartLabel->TabIndex = 22;
			mButtonStartLabel->Text = L"Start Button";
			// 
			// mButtonBumperLabel
			// 
			mButtonBumperLabel->AutoSize = true;
			mButtonBumperLabel->Location = System::Drawing::Point(52, 355);
			mButtonBumperLabel->Name = L"mButtonBumperLabel";
			mButtonBumperLabel->Size = System::Drawing::Size(70, 13);
			mButtonBumperLabel->TabIndex = 23;
			mButtonBumperLabel->Text = L"Front Bumper";
			// 
			// mJoystickXImage
			// 
			mJoystickXImage->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mJoystickXImage.Image")));
			mJoystickXImage->Location = System::Drawing::Point(6, 19);
			mJoystickXImage->Name = L"mJoystickXImage";
			mJoystickXImage->Size = System::Drawing::Size(40, 50);
			mJoystickXImage->TabIndex = 40;
			mJoystickXImage->TabStop = false;
			// 
			// mJoystickXGroup
			// 
			mJoystickXGroup->Controls->Add(this->mJoystickXTypeAxis);
			mJoystickXGroup->Controls->Add(mJoystickXImage);
			mJoystickXGroup->Controls->Add(this->mJoystickXTypeButtons);
			mJoystickXGroup->Location = System::Drawing::Point(6, 19);
			mJoystickXGroup->Name = L"mJoystickXGroup";
			mJoystickXGroup->Size = System::Drawing::Size(121, 106);
			mJoystickXGroup->TabIndex = 44;
			mJoystickXGroup->TabStop = false;
			mJoystickXGroup->Text = L"X Axis";
			// 
			// mJoystickXTypeAxis
			// 
			this->mJoystickXTypeAxis->AutoSize = true;
			this->mJoystickXTypeAxis->Checked = true;
			this->mJoystickXTypeAxis->Location = System::Drawing::Point(52, 19);
			this->mJoystickXTypeAxis->Name = L"mJoystickXTypeAxis";
			this->mJoystickXTypeAxis->Size = System::Drawing::Size(44, 17);
			this->mJoystickXTypeAxis->TabIndex = 42;
			this->mJoystickXTypeAxis->TabStop = true;
			this->mJoystickXTypeAxis->Text = L"Axis";
			this->mJoystickXTypeAxis->UseVisualStyleBackColor = true;
			// 
			// mJoystickXTypeButtons
			// 
			this->mJoystickXTypeButtons->AutoSize = true;
			this->mJoystickXTypeButtons->Location = System::Drawing::Point(52, 42);
			this->mJoystickXTypeButtons->Name = L"mJoystickXTypeButtons";
			this->mJoystickXTypeButtons->Size = System::Drawing::Size(61, 17);
			this->mJoystickXTypeButtons->TabIndex = 43;
			this->mJoystickXTypeButtons->Text = L"Buttons";
			this->mJoystickXTypeButtons->UseVisualStyleBackColor = true;
			// 
			// mButton4Image
			// 
			mButton4Image->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButton4Image.Image")));
			mButton4Image->Location = System::Drawing::Point(6, 187);
			mButton4Image->Name = L"mButton4Image";
			mButton4Image->Size = System::Drawing::Size(40, 50);
			mButton4Image->TabIndex = 13;
			mButton4Image->TabStop = false;
			// 
			// mLabelXAxisValue
			// 
			this->mLabelXAxisValue->AutoSize = true;
			this->mLabelXAxisValue->Location = System::Drawing::Point(51, 16);
			this->mLabelXAxisValue->Name = L"mLabelXAxisValue";
			this->mLabelXAxisValue->Size = System::Drawing::Size(25, 13);
			this->mLabelXAxisValue->TabIndex = 2;
			this->mLabelXAxisValue->Text = L"127";
			// 
			// mLabelBase
			// 
			this->mLabelBase->AutoSize = true;
			this->mLabelBase->Location = System::Drawing::Point(12, 9);
			this->mLabelBase->Name = L"mLabelBase";
			this->mLabelBase->Size = System::Drawing::Size(195, 13);
			this->mLabelBase->TabIndex = 0;
			this->mLabelBase->Text = L"Please place the controllers in the base.";
			this->mLabelBase->Visible = false;
			// 
			// mControllerChoice
			// 
			this->mControllerChoice->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mControllerChoice->FormattingEnabled = true;
			this->mControllerChoice->Location = System::Drawing::Point(7, 20);
			this->mControllerChoice->Name = L"mControllerChoice";
			this->mControllerChoice->Size = System::Drawing::Size(126, 21);
			this->mControllerChoice->TabIndex = 0;
			// 
			// mPressedButtonsLabel
			// 
			this->mPressedButtonsLabel->AutoSize = true;
			this->mPressedButtonsLabel->Location = System::Drawing::Point(93, 29);
			this->mPressedButtonsLabel->Name = L"mPressedButtonsLabel";
			this->mPressedButtonsLabel->Size = System::Drawing::Size(0, 13);
			this->mPressedButtonsLabel->TabIndex = 8;
			// 
			// mButton1Joy
			// 
			this->mButton1Joy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButton1Joy->FormattingEnabled = true;
			this->mButton1Joy->Location = System::Drawing::Point(52, 35);
			this->mButton1Joy->Name = L"mButton1Joy";
			this->mButton1Joy->Size = System::Drawing::Size(50, 21);
			this->mButton1Joy->TabIndex = 24;
			this->mButton1Joy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			// 
			// mButton1Button
			// 
			this->mButton1Button->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButton1Button->FormattingEnabled = true;
			this->mButton1Button->Location = System::Drawing::Point(108, 35);
			this->mButton1Button->Name = L"mButton1Button";
			this->mButton1Button->Size = System::Drawing::Size(70, 21);
			this->mButton1Button->TabIndex = 25;
			this->mButton1Button->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			// 
			// mButton2Button
			// 
			this->mButton2Button->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButton2Button->FormattingEnabled = true;
			this->mButton2Button->Location = System::Drawing::Point(108, 91);
			this->mButton2Button->Name = L"mButton2Button";
			this->mButton2Button->Size = System::Drawing::Size(70, 21);
			this->mButton2Button->TabIndex = 27;
			this->mButton2Button->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			// 
			// mButton2Joy
			// 
			this->mButton2Joy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButton2Joy->FormattingEnabled = true;
			this->mButton2Joy->Location = System::Drawing::Point(52, 91);
			this->mButton2Joy->Name = L"mButton2Joy";
			this->mButton2Joy->Size = System::Drawing::Size(50, 21);
			this->mButton2Joy->TabIndex = 26;
			this->mButton2Joy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			// 
			// mButton3Button
			// 
			this->mButton3Button->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButton3Button->FormattingEnabled = true;
			this->mButton3Button->Location = System::Drawing::Point(108, 147);
			this->mButton3Button->Name = L"mButton3Button";
			this->mButton3Button->Size = System::Drawing::Size(70, 21);
			this->mButton3Button->TabIndex = 29;
			this->mButton3Button->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			// 
			// mButton3Joy
			// 
			this->mButton3Joy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButton3Joy->FormattingEnabled = true;
			this->mButton3Joy->Location = System::Drawing::Point(52, 147);
			this->mButton3Joy->Name = L"mButton3Joy";
			this->mButton3Joy->Size = System::Drawing::Size(50, 21);
			this->mButton3Joy->TabIndex = 28;
			this->mButton3Joy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			// 
			// mButton4Button
			// 
			this->mButton4Button->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButton4Button->FormattingEnabled = true;
			this->mButton4Button->Location = System::Drawing::Point(108, 203);
			this->mButton4Button->Name = L"mButton4Button";
			this->mButton4Button->Size = System::Drawing::Size(70, 21);
			this->mButton4Button->TabIndex = 31;
			this->mButton4Button->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			// 
			// mButton4Joy
			// 
			this->mButton4Joy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButton4Joy->FormattingEnabled = true;
			this->mButton4Joy->Location = System::Drawing::Point(52, 203);
			this->mButton4Joy->Name = L"mButton4Joy";
			this->mButton4Joy->Size = System::Drawing::Size(50, 21);
			this->mButton4Joy->TabIndex = 30;
			this->mButton4Joy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			// 
			// mButtonJoystickButton
			// 
			this->mButtonJoystickButton->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButtonJoystickButton->FormattingEnabled = true;
			this->mButtonJoystickButton->Location = System::Drawing::Point(108, 259);
			this->mButtonJoystickButton->Name = L"mButtonJoystickButton";
			this->mButtonJoystickButton->Size = System::Drawing::Size(70, 21);
			this->mButtonJoystickButton->TabIndex = 33;
			this->mButtonJoystickButton->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			// 
			// mButtonJoystickJoy
			// 
			this->mButtonJoystickJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButtonJoystickJoy->FormattingEnabled = true;
			this->mButtonJoystickJoy->Location = System::Drawing::Point(52, 259);
			this->mButtonJoystickJoy->Name = L"mButtonJoystickJoy";
			this->mButtonJoystickJoy->Size = System::Drawing::Size(50, 21);
			this->mButtonJoystickJoy->TabIndex = 32;
			this->mButtonJoystickJoy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			// 
			// mButtonStartButton
			// 
			this->mButtonStartButton->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButtonStartButton->FormattingEnabled = true;
			this->mButtonStartButton->Location = System::Drawing::Point(108, 315);
			this->mButtonStartButton->Name = L"mButtonStartButton";
			this->mButtonStartButton->Size = System::Drawing::Size(70, 21);
			this->mButtonStartButton->TabIndex = 35;
			this->mButtonStartButton->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			// 
			// mButtonStartJoy
			// 
			this->mButtonStartJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButtonStartJoy->FormattingEnabled = true;
			this->mButtonStartJoy->Location = System::Drawing::Point(52, 315);
			this->mButtonStartJoy->Name = L"mButtonStartJoy";
			this->mButtonStartJoy->Size = System::Drawing::Size(50, 21);
			this->mButtonStartJoy->TabIndex = 34;
			this->mButtonStartJoy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			// 
			// mButtonBumperButton
			// 
			this->mButtonBumperButton->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButtonBumperButton->FormattingEnabled = true;
			this->mButtonBumperButton->Location = System::Drawing::Point(108, 371);
			this->mButtonBumperButton->Name = L"mButtonBumperButton";
			this->mButtonBumperButton->Size = System::Drawing::Size(70, 21);
			this->mButtonBumperButton->TabIndex = 37;
			this->mButtonBumperButton->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			// 
			// mButtonBumperJoy
			// 
			this->mButtonBumperJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mButtonBumperJoy->FormattingEnabled = true;
			this->mButtonBumperJoy->Location = System::Drawing::Point(52, 371);
			this->mButtonBumperJoy->Name = L"mButtonBumperJoy";
			this->mButtonBumperJoy->Size = System::Drawing::Size(50, 21);
			this->mButtonBumperJoy->TabIndex = 36;
			this->mButtonBumperJoy->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::UpdateBindings);
			// 
			// mPositionGroup
			// 
			this->mPositionGroup->Location = System::Drawing::Point(203, 242);
			this->mPositionGroup->Name = L"mPositionGroup";
			this->mPositionGroup->Size = System::Drawing::Size(161, 100);
			this->mPositionGroup->TabIndex = 45;
			this->mPositionGroup->TabStop = false;
			this->mPositionGroup->Text = L"Position";
			// 
			// mButtonsGroup
			// 
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
			this->mButtonsGroup->TabIndex = 46;
			this->mButtonsGroup->TabStop = false;
			this->mButtonsGroup->Text = L"Buttons";
			// 
			// mJoystickGroup
			// 
			this->mJoystickGroup->Controls->Add(mJoystickXGroup);
			this->mJoystickGroup->Location = System::Drawing::Point(203, 68);
			this->mJoystickGroup->Name = L"mJoystickGroup";
			this->mJoystickGroup->Size = System::Drawing::Size(161, 168);
			this->mJoystickGroup->TabIndex = 47;
			this->mJoystickGroup->TabStop = false;
			this->mJoystickGroup->Text = L"Analog Stick";
			// 
			// mTestGroup
			// 
			this->mTestGroup->Controls->Add(mPressedButtonsDescLabel);
			this->mTestGroup->Controls->Add(mLabelXAxis);
			this->mTestGroup->Controls->Add(this->mLabelXAxisValue);
			this->mTestGroup->Controls->Add(this->mPressedButtonsLabel);
			this->mTestGroup->Location = System::Drawing::Point(12, 486);
			this->mTestGroup->Name = L"mTestGroup";
			this->mTestGroup->Size = System::Drawing::Size(185, 59);
			this->mTestGroup->TabIndex = 48;
			this->mTestGroup->TabStop = false;
			this->mTestGroup->Text = L"Tests";
			// 
			// mRotationGroup
			// 
			this->mRotationGroup->Location = System::Drawing::Point(203, 348);
			this->mRotationGroup->Name = L"mRotationGroup";
			this->mRotationGroup->Size = System::Drawing::Size(161, 100);
			this->mRotationGroup->TabIndex = 45;
			this->mRotationGroup->TabStop = false;
			this->mRotationGroup->Text = L"Rotation";
			// 
			// mControlGroup
			// 
			this->mControlGroup->Controls->Add(this->mControllerChoice);
			this->mControlGroup->Controls->Add(mSaveButton);
			this->mControlGroup->Controls->Add(mLoadButton);
			this->mControlGroup->Controls->Add(mOriginButton);
			this->mControlGroup->Controls->Add(mAboutButton);
			this->mControlGroup->Location = System::Drawing::Point(12, 12);
			this->mControlGroup->Name = L"mControlGroup";
			this->mControlGroup->Size = System::Drawing::Size(415, 50);
			this->mControlGroup->TabIndex = 49;
			this->mControlGroup->TabStop = false;
			this->mControlGroup->Text = L"Control";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(697, 655);
			this->Controls->Add(this->mControlGroup);
			this->Controls->Add(this->mTestGroup);
			this->Controls->Add(this->mJoystickGroup);
			this->Controls->Add(this->mButtonsGroup);
			this->Controls->Add(this->mRotationGroup);
			this->Controls->Add(this->mPositionGroup);
			this->Controls->Add(this->mLabelBase);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"05 Hydra Reading";
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
			this->mButtonsGroup->ResumeLayout(false);
			this->mButtonsGroup->PerformLayout();
			this->mJoystickGroup->ResumeLayout(false);
			this->mTestGroup->ResumeLayout(false);
			this->mTestGroup->PerformLayout();
			this->mControlGroup->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		/** \brief Called when the Form is first opened. Initializes.
		**/
		System::Void OnOpen(System::Object^  sender, System::EventArgs^  e);

		/** \brief Displays an Error and exits.
		**/
		void Error(const std::string& message);

		/** \brief Changes visibility to either display "Put controllers in Base" or the actual stuff.
			\note Needs to be updated when new elements get added, obviously.
		**/
		void DisplayBaseMessage(const bool display);

		/** \brief Sets the active base to the first one connected
			\return Whether any bases are connected
			\note In debug mode, returns true and sets the active base to 0 if none are connected.
		**/
		const bool SetBase();


		int mLeftControllerIndex;
		int mRightControllerIndex;

		/**	\brief Checks if the controllers are correctly initalized (i.e. have been in the base once, but on different sides)
			and sets mLeftControllerIndex and mRightControllerIndex accordingly.
			\return Whether the controllers are correctly initialized
		**/
		const bool SetControllerIndices();

		/**	\brief This is where The Magicks happen :)
			
			Called periodically. Retrieves Data from the Hydra and uses it.
		**/
		System::Void OnTimerTick(System::Object^  sender, System::EventArgs^  e);

		AboutForm^ mAboutForm;
		System::Void OnAboutClicked(System::Object^  sender, System::EventArgs^  e);

		/** \brief Saves the current settings of a given controller to a given ini file.
		**/
		const bool SaveSettings(const std::wstring& filename, const bool left);

		/** \brief Loads settings from an ini file and applies them to the given controller.
		**/
		const bool LoadSettings(const std::wstring& filename, const bool left);
		
		bool mInitialized; ///< Set to true once OnOpen() has been called. Before that I ignore UpdateBindings() calls.

		/** \brief Called whenever a setting is changed - updates the bindings.
		**/
		System::Void UpdateBindings(System::Object^  sender, System::EventArgs^  e);

		/** \brief Called whenever the selected Controller is changed - updates the displayed bindings.
		**/
		System::Void SelectedControllerChanged(System::Object^  sender, System::EventArgs^  e);
};
}

