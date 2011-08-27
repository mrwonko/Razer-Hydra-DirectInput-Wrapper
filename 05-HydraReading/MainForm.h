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
		//automatically generated form elements

		System::Windows::Forms::Label^  mLabelXAxisValue;
		System::Windows::Forms::Label^  mLabelBase;
		System::Windows::Forms::ComboBox^  mControllerChoice;

		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^  mLabelXAxis;
	private: System::Windows::Forms::Button^  mSaveButton;
	private: System::Windows::Forms::Button^  mLoadButton;
	private: System::Windows::Forms::Button^  mOriginButton;
	private: System::Windows::Forms::Button^  mAboutButton;
	private: System::Windows::Forms::Label^  mPressedButtonsDescLabel;
	private: System::Windows::Forms::Label^  mPressedButtonsLabel;

	private: System::Windows::Forms::PictureBox^  mButton1Image;
	private: System::Windows::Forms::PictureBox^  mButton2Image;
	private: System::Windows::Forms::PictureBox^  mButton3Image;
	private: System::Windows::Forms::PictureBox^  mButton4Image;
	private: System::Windows::Forms::PictureBox^  mButtonBumperImage;
	private: System::Windows::Forms::PictureBox^  mButtonJoystickImage;
	private: System::Windows::Forms::PictureBox^  mButtonStartImage;
	private: System::Windows::Forms::Label^  mButton1Label;
	private: System::Windows::Forms::Label^  mButton2Label;
	private: System::Windows::Forms::Label^  mButton3Label;
	private: System::Windows::Forms::Label^  mButton4Label;
	private: System::Windows::Forms::Label^  mButtonJoystickLabel;
	private: System::Windows::Forms::Label^  mButtonStartLabel;
	private: System::Windows::Forms::Label^  mButtonBumperLabel;
	private: System::Windows::Forms::ComboBox^  mButton1Joy;
	private: System::Windows::Forms::ComboBox^  mButton1Button;
	private: System::Windows::Forms::ComboBox^  mButton2Button;
	private: System::Windows::Forms::ComboBox^  mButton2Joy;
	private: System::Windows::Forms::ComboBox^  mButton3Button;
	private: System::Windows::Forms::ComboBox^  mButton3Joy;
	private: System::Windows::Forms::ComboBox^  mButton4Button;
	private: System::Windows::Forms::ComboBox^  mButton4Joy;
	private: System::Windows::Forms::ComboBox^  mButtonJoystickButton;
	private: System::Windows::Forms::ComboBox^  mButtonJoystickJoy;
	private: System::Windows::Forms::ComboBox^  mButtonStartButton;
	private: System::Windows::Forms::ComboBox^  mButtonStartJoy;
	private: System::Windows::Forms::ComboBox^  mButtonBumperButton;
	private: System::Windows::Forms::ComboBox^  mButtonBumperJoy;


	private: System::Windows::Forms::PictureBox^  mJoystickXImage;
	private: System::Windows::Forms::GroupBox^  mJoystickXGroup;




	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::GroupBox^  mPositionGroup;
	private: System::Windows::Forms::GroupBox^  mButtonsGroup;
	private: System::Windows::Forms::GroupBox^  mJoystickGroup;
	private: System::Windows::Forms::GroupBox^  mTestGroup;
	private: System::Windows::Forms::GroupBox^  mRotationGroup;



		/// \brief Timer for periodically polling the Hydra
		System::Windows::Forms::Timer^ mTimer;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->mLabelXAxis = (gcnew System::Windows::Forms::Label());
			this->mLabelXAxisValue = (gcnew System::Windows::Forms::Label());
			this->mLabelBase = (gcnew System::Windows::Forms::Label());
			this->mControllerChoice = (gcnew System::Windows::Forms::ComboBox());
			this->mSaveButton = (gcnew System::Windows::Forms::Button());
			this->mLoadButton = (gcnew System::Windows::Forms::Button());
			this->mOriginButton = (gcnew System::Windows::Forms::Button());
			this->mAboutButton = (gcnew System::Windows::Forms::Button());
			this->mPressedButtonsDescLabel = (gcnew System::Windows::Forms::Label());
			this->mPressedButtonsLabel = (gcnew System::Windows::Forms::Label());
			this->mButton1Image = (gcnew System::Windows::Forms::PictureBox());
			this->mButton2Image = (gcnew System::Windows::Forms::PictureBox());
			this->mButton3Image = (gcnew System::Windows::Forms::PictureBox());
			this->mButton4Image = (gcnew System::Windows::Forms::PictureBox());
			this->mButtonBumperImage = (gcnew System::Windows::Forms::PictureBox());
			this->mButtonJoystickImage = (gcnew System::Windows::Forms::PictureBox());
			this->mButtonStartImage = (gcnew System::Windows::Forms::PictureBox());
			this->mButton1Label = (gcnew System::Windows::Forms::Label());
			this->mButton2Label = (gcnew System::Windows::Forms::Label());
			this->mButton3Label = (gcnew System::Windows::Forms::Label());
			this->mButton4Label = (gcnew System::Windows::Forms::Label());
			this->mButtonJoystickLabel = (gcnew System::Windows::Forms::Label());
			this->mButtonStartLabel = (gcnew System::Windows::Forms::Label());
			this->mButtonBumperLabel = (gcnew System::Windows::Forms::Label());
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
			this->mJoystickXImage = (gcnew System::Windows::Forms::PictureBox());
			this->mJoystickXGroup = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->mPositionGroup = (gcnew System::Windows::Forms::GroupBox());
			this->mButtonsGroup = (gcnew System::Windows::Forms::GroupBox());
			this->mJoystickGroup = (gcnew System::Windows::Forms::GroupBox());
			this->mTestGroup = (gcnew System::Windows::Forms::GroupBox());
			this->mRotationGroup = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mButton1Image))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mButton2Image))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mButton3Image))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mButton4Image))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mButtonBumperImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mButtonJoystickImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mButtonStartImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mJoystickXImage))->BeginInit();
			this->mJoystickXGroup->SuspendLayout();
			this->mButtonsGroup->SuspendLayout();
			this->mJoystickGroup->SuspendLayout();
			this->mTestGroup->SuspendLayout();
			this->SuspendLayout();
			// 
			// mLabelXAxis
			// 
			this->mLabelXAxis->AutoSize = true;
			this->mLabelXAxis->Location = System::Drawing::Point(6, 16);
			this->mLabelXAxis->Name = L"mLabelXAxis";
			this->mLabelXAxis->Size = System::Drawing::Size(39, 13);
			this->mLabelXAxis->TabIndex = 1;
			this->mLabelXAxis->Text = L"X Axis:";
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
			this->mControllerChoice->Location = System::Drawing::Point(15, 14);
			this->mControllerChoice->Name = L"mControllerChoice";
			this->mControllerChoice->Size = System::Drawing::Size(126, 21);
			this->mControllerChoice->TabIndex = 0;
			// 
			// mSaveButton
			// 
			this->mSaveButton->Location = System::Drawing::Point(147, 12);
			this->mSaveButton->Name = L"mSaveButton";
			this->mSaveButton->Size = System::Drawing::Size(50, 23);
			this->mSaveButton->TabIndex = 3;
			this->mSaveButton->Text = L"Save";
			this->mSaveButton->UseVisualStyleBackColor = true;
			// 
			// mLoadButton
			// 
			this->mLoadButton->Location = System::Drawing::Point(203, 12);
			this->mLoadButton->Name = L"mLoadButton";
			this->mLoadButton->Size = System::Drawing::Size(50, 23);
			this->mLoadButton->TabIndex = 4;
			this->mLoadButton->Text = L"Load";
			this->mLoadButton->UseVisualStyleBackColor = true;
			// 
			// mOriginButton
			// 
			this->mOriginButton->Location = System::Drawing::Point(259, 12);
			this->mOriginButton->Name = L"mOriginButton";
			this->mOriginButton->Size = System::Drawing::Size(75, 23);
			this->mOriginButton->TabIndex = 5;
			this->mOriginButton->Text = L"Set Origin";
			this->mOriginButton->UseVisualStyleBackColor = true;
			// 
			// mAboutButton
			// 
			this->mAboutButton->Location = System::Drawing::Point(610, 12);
			this->mAboutButton->Name = L"mAboutButton";
			this->mAboutButton->Size = System::Drawing::Size(75, 23);
			this->mAboutButton->TabIndex = 6;
			this->mAboutButton->Text = L"About";
			this->mAboutButton->UseVisualStyleBackColor = true;
			this->mAboutButton->Click += gcnew System::EventHandler(this, &MainForm::OnAboutClicked);
			// 
			// mPressedButtonsDescLabel
			// 
			this->mPressedButtonsDescLabel->AutoSize = true;
			this->mPressedButtonsDescLabel->Location = System::Drawing::Point(6, 29);
			this->mPressedButtonsDescLabel->Name = L"mPressedButtonsDescLabel";
			this->mPressedButtonsDescLabel->Size = System::Drawing::Size(87, 13);
			this->mPressedButtonsDescLabel->TabIndex = 7;
			this->mPressedButtonsDescLabel->Text = L"Pressed Buttons:";
			// 
			// mPressedButtonsLabel
			// 
			this->mPressedButtonsLabel->AutoSize = true;
			this->mPressedButtonsLabel->Location = System::Drawing::Point(93, 29);
			this->mPressedButtonsLabel->Name = L"mPressedButtonsLabel";
			this->mPressedButtonsLabel->Size = System::Drawing::Size(0, 13);
			this->mPressedButtonsLabel->TabIndex = 8;
			// 
			// mButton1Image
			// 
			this->mButton1Image->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButton1Image.Image")));
			this->mButton1Image->Location = System::Drawing::Point(6, 19);
			this->mButton1Image->Name = L"mButton1Image";
			this->mButton1Image->Size = System::Drawing::Size(40, 50);
			this->mButton1Image->TabIndex = 10;
			this->mButton1Image->TabStop = false;
			// 
			// mButton2Image
			// 
			this->mButton2Image->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButton2Image.Image")));
			this->mButton2Image->Location = System::Drawing::Point(6, 75);
			this->mButton2Image->Name = L"mButton2Image";
			this->mButton2Image->Size = System::Drawing::Size(40, 50);
			this->mButton2Image->TabIndex = 11;
			this->mButton2Image->TabStop = false;
			// 
			// mButton3Image
			// 
			this->mButton3Image->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButton3Image.Image")));
			this->mButton3Image->Location = System::Drawing::Point(6, 131);
			this->mButton3Image->Name = L"mButton3Image";
			this->mButton3Image->Size = System::Drawing::Size(40, 50);
			this->mButton3Image->TabIndex = 12;
			this->mButton3Image->TabStop = false;
			// 
			// mButton4Image
			// 
			this->mButton4Image->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButton4Image.Image")));
			this->mButton4Image->Location = System::Drawing::Point(6, 187);
			this->mButton4Image->Name = L"mButton4Image";
			this->mButton4Image->Size = System::Drawing::Size(40, 50);
			this->mButton4Image->TabIndex = 13;
			this->mButton4Image->TabStop = false;
			// 
			// mButtonBumperImage
			// 
			this->mButtonBumperImage->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButtonBumperImage.Image")));
			this->mButtonBumperImage->Location = System::Drawing::Point(6, 355);
			this->mButtonBumperImage->Name = L"mButtonBumperImage";
			this->mButtonBumperImage->Size = System::Drawing::Size(40, 50);
			this->mButtonBumperImage->TabIndex = 14;
			this->mButtonBumperImage->TabStop = false;
			// 
			// mButtonJoystickImage
			// 
			this->mButtonJoystickImage->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButtonJoystickImage.Image")));
			this->mButtonJoystickImage->Location = System::Drawing::Point(6, 243);
			this->mButtonJoystickImage->Name = L"mButtonJoystickImage";
			this->mButtonJoystickImage->Size = System::Drawing::Size(40, 50);
			this->mButtonJoystickImage->TabIndex = 15;
			this->mButtonJoystickImage->TabStop = false;
			// 
			// mButtonStartImage
			// 
			this->mButtonStartImage->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mButtonStartImage.Image")));
			this->mButtonStartImage->Location = System::Drawing::Point(6, 299);
			this->mButtonStartImage->Name = L"mButtonStartImage";
			this->mButtonStartImage->Size = System::Drawing::Size(40, 50);
			this->mButtonStartImage->TabIndex = 16;
			this->mButtonStartImage->TabStop = false;
			// 
			// mButton1Label
			// 
			this->mButton1Label->AutoSize = true;
			this->mButton1Label->Location = System::Drawing::Point(52, 19);
			this->mButton1Label->Name = L"mButton1Label";
			this->mButton1Label->Size = System::Drawing::Size(47, 13);
			this->mButton1Label->TabIndex = 17;
			this->mButton1Label->Text = L"Button 1";
			// 
			// mButton2Label
			// 
			this->mButton2Label->AutoSize = true;
			this->mButton2Label->Location = System::Drawing::Point(52, 75);
			this->mButton2Label->Name = L"mButton2Label";
			this->mButton2Label->Size = System::Drawing::Size(47, 13);
			this->mButton2Label->TabIndex = 18;
			this->mButton2Label->Text = L"Button 2";
			// 
			// mButton3Label
			// 
			this->mButton3Label->AutoSize = true;
			this->mButton3Label->Location = System::Drawing::Point(52, 131);
			this->mButton3Label->Name = L"mButton3Label";
			this->mButton3Label->Size = System::Drawing::Size(47, 13);
			this->mButton3Label->TabIndex = 19;
			this->mButton3Label->Text = L"Button 3";
			// 
			// mButton4Label
			// 
			this->mButton4Label->AutoSize = true;
			this->mButton4Label->Location = System::Drawing::Point(52, 187);
			this->mButton4Label->Name = L"mButton4Label";
			this->mButton4Label->Size = System::Drawing::Size(47, 13);
			this->mButton4Label->TabIndex = 20;
			this->mButton4Label->Text = L"Button 4";
			// 
			// mButtonJoystickLabel
			// 
			this->mButtonJoystickLabel->AutoSize = true;
			this->mButtonJoystickLabel->Location = System::Drawing::Point(52, 243);
			this->mButtonJoystickLabel->Name = L"mButtonJoystickLabel";
			this->mButtonJoystickLabel->Size = System::Drawing::Size(101, 13);
			this->mButtonJoystickLabel->TabIndex = 21;
			this->mButtonJoystickLabel->Text = L"Analog Stick Button";
			// 
			// mButtonStartLabel
			// 
			this->mButtonStartLabel->AutoSize = true;
			this->mButtonStartLabel->Location = System::Drawing::Point(52, 299);
			this->mButtonStartLabel->Name = L"mButtonStartLabel";
			this->mButtonStartLabel->Size = System::Drawing::Size(63, 13);
			this->mButtonStartLabel->TabIndex = 22;
			this->mButtonStartLabel->Text = L"Start Button";
			// 
			// mButtonBumperLabel
			// 
			this->mButtonBumperLabel->AutoSize = true;
			this->mButtonBumperLabel->Location = System::Drawing::Point(52, 355);
			this->mButtonBumperLabel->Name = L"mButtonBumperLabel";
			this->mButtonBumperLabel->Size = System::Drawing::Size(70, 13);
			this->mButtonBumperLabel->TabIndex = 23;
			this->mButtonBumperLabel->Text = L"Front Bumper";
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
			// mJoystickXImage
			// 
			this->mJoystickXImage->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mJoystickXImage.Image")));
			this->mJoystickXImage->Location = System::Drawing::Point(6, 19);
			this->mJoystickXImage->Name = L"mJoystickXImage";
			this->mJoystickXImage->Size = System::Drawing::Size(40, 50);
			this->mJoystickXImage->TabIndex = 40;
			this->mJoystickXImage->TabStop = false;
			// 
			// mJoystickXGroup
			// 
			this->mJoystickXGroup->Controls->Add(this->radioButton1);
			this->mJoystickXGroup->Controls->Add(this->mJoystickXImage);
			this->mJoystickXGroup->Controls->Add(this->radioButton2);
			this->mJoystickXGroup->Location = System::Drawing::Point(6, 19);
			this->mJoystickXGroup->Name = L"mJoystickXGroup";
			this->mJoystickXGroup->Size = System::Drawing::Size(121, 106);
			this->mJoystickXGroup->TabIndex = 44;
			this->mJoystickXGroup->TabStop = false;
			this->mJoystickXGroup->Text = L"X Axis";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(52, 19);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(44, 17);
			this->radioButton1->TabIndex = 42;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Axis";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(52, 42);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(61, 17);
			this->radioButton2->TabIndex = 43;
			this->radioButton2->Text = L"Buttons";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// mPositionGroup
			// 
			this->mPositionGroup->Location = System::Drawing::Point(203, 215);
			this->mPositionGroup->Name = L"mPositionGroup";
			this->mPositionGroup->Size = System::Drawing::Size(161, 100);
			this->mPositionGroup->TabIndex = 45;
			this->mPositionGroup->TabStop = false;
			this->mPositionGroup->Text = L"Position";
			// 
			// mButtonsGroup
			// 
			this->mButtonsGroup->Controls->Add(this->mButton1Image);
			this->mButtonsGroup->Controls->Add(this->mButton2Image);
			this->mButtonsGroup->Controls->Add(this->mButton3Image);
			this->mButtonsGroup->Controls->Add(this->mButton4Image);
			this->mButtonsGroup->Controls->Add(this->mButtonBumperImage);
			this->mButtonsGroup->Controls->Add(this->mButtonBumperButton);
			this->mButtonsGroup->Controls->Add(this->mButtonJoystickImage);
			this->mButtonsGroup->Controls->Add(this->mButtonBumperJoy);
			this->mButtonsGroup->Controls->Add(this->mButtonStartImage);
			this->mButtonsGroup->Controls->Add(this->mButtonStartButton);
			this->mButtonsGroup->Controls->Add(this->mButton1Label);
			this->mButtonsGroup->Controls->Add(this->mButtonStartJoy);
			this->mButtonsGroup->Controls->Add(this->mButton2Label);
			this->mButtonsGroup->Controls->Add(this->mButtonJoystickButton);
			this->mButtonsGroup->Controls->Add(this->mButton3Label);
			this->mButtonsGroup->Controls->Add(this->mButtonJoystickJoy);
			this->mButtonsGroup->Controls->Add(this->mButton4Label);
			this->mButtonsGroup->Controls->Add(this->mButton4Button);
			this->mButtonsGroup->Controls->Add(this->mButtonJoystickLabel);
			this->mButtonsGroup->Controls->Add(this->mButton4Joy);
			this->mButtonsGroup->Controls->Add(this->mButtonStartLabel);
			this->mButtonsGroup->Controls->Add(this->mButton3Button);
			this->mButtonsGroup->Controls->Add(this->mButtonBumperLabel);
			this->mButtonsGroup->Controls->Add(this->mButton3Joy);
			this->mButtonsGroup->Controls->Add(this->mButton1Joy);
			this->mButtonsGroup->Controls->Add(this->mButton2Button);
			this->mButtonsGroup->Controls->Add(this->mButton1Button);
			this->mButtonsGroup->Controls->Add(this->mButton2Joy);
			this->mButtonsGroup->Location = System::Drawing::Point(12, 41);
			this->mButtonsGroup->Name = L"mButtonsGroup";
			this->mButtonsGroup->Size = System::Drawing::Size(185, 412);
			this->mButtonsGroup->TabIndex = 46;
			this->mButtonsGroup->TabStop = false;
			this->mButtonsGroup->Text = L"Buttons";
			// 
			// mJoystickGroup
			// 
			this->mJoystickGroup->Controls->Add(this->mJoystickXGroup);
			this->mJoystickGroup->Location = System::Drawing::Point(203, 41);
			this->mJoystickGroup->Name = L"mJoystickGroup";
			this->mJoystickGroup->Size = System::Drawing::Size(161, 168);
			this->mJoystickGroup->TabIndex = 47;
			this->mJoystickGroup->TabStop = false;
			this->mJoystickGroup->Text = L"Analog Stick";
			// 
			// mTestGroup
			// 
			this->mTestGroup->Controls->Add(this->mPressedButtonsDescLabel);
			this->mTestGroup->Controls->Add(this->mLabelXAxis);
			this->mTestGroup->Controls->Add(this->mLabelXAxisValue);
			this->mTestGroup->Controls->Add(this->mPressedButtonsLabel);
			this->mTestGroup->Location = System::Drawing::Point(12, 459);
			this->mTestGroup->Name = L"mTestGroup";
			this->mTestGroup->Size = System::Drawing::Size(185, 59);
			this->mTestGroup->TabIndex = 48;
			this->mTestGroup->TabStop = false;
			this->mTestGroup->Text = L"Tests";
			// 
			// mRotationGroup
			// 
			this->mRotationGroup->Location = System::Drawing::Point(203, 321);
			this->mRotationGroup->Name = L"mRotationGroup";
			this->mRotationGroup->Size = System::Drawing::Size(161, 100);
			this->mRotationGroup->TabIndex = 45;
			this->mRotationGroup->TabStop = false;
			this->mRotationGroup->Text = L"Rotation";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(697, 655);
			this->Controls->Add(this->mTestGroup);
			this->Controls->Add(this->mJoystickGroup);
			this->Controls->Add(this->mButtonsGroup);
			this->Controls->Add(this->mRotationGroup);
			this->Controls->Add(this->mPositionGroup);
			this->Controls->Add(this->mAboutButton);
			this->Controls->Add(this->mOriginButton);
			this->Controls->Add(this->mLoadButton);
			this->Controls->Add(this->mSaveButton);
			this->Controls->Add(this->mControllerChoice);
			this->Controls->Add(this->mLabelBase);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"05 Hydra Reading";
			this->Shown += gcnew System::EventHandler(this, &MainForm::OnOpen);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mButton1Image))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mButton2Image))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mButton3Image))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mButton4Image))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mButtonBumperImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mButtonJoystickImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mButtonStartImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mJoystickXImage))->EndInit();
			this->mJoystickXGroup->ResumeLayout(false);
			this->mJoystickXGroup->PerformLayout();
			this->mButtonsGroup->ResumeLayout(false);
			this->mButtonsGroup->PerformLayout();
			this->mJoystickGroup->ResumeLayout(false);
			this->mTestGroup->ResumeLayout(false);
			this->mTestGroup->PerformLayout();
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

