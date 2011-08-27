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

		System::Windows::Forms::GroupBox^  mControlGroup;

		//Tests
		System::Windows::Forms::GroupBox^  mTestGroup;
		System::Windows::Forms::Label^  mPressedButtonsLabel;
		System::Windows::Forms::Label^  mLabelXAxisValue;
	private: System::Windows::Forms::NumericUpDown^  mAxisXRange;

	private: System::Windows::Forms::ComboBox^  mAxisXJoy;
	private: System::Windows::Forms::ComboBox^  mAxisXAxis;
	private: System::Windows::Forms::CheckBox^  mAxisXInverted;
	private: System::Windows::Forms::CheckBox^  mAxisZInvert;
	private: System::Windows::Forms::ComboBox^  mAxisZJoy;
	private: System::Windows::Forms::CheckBox^  mAxisYInvert;
	private: System::Windows::Forms::ComboBox^  mAxisYJoy;
	private: System::Windows::Forms::NumericUpDown^  mAxisZRange;
	private: System::Windows::Forms::NumericUpDown^  mAxisYRange;
	private: System::Windows::Forms::ComboBox^  mAxisZAxis;
	private: System::Windows::Forms::ComboBox^  mAxisYAxis;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  mAxisRollInvert;
	private: System::Windows::Forms::ComboBox^  mAxisRollJoy;


	private: System::Windows::Forms::CheckBox^  mAxisPitchInvert;

	private: System::Windows::Forms::ComboBox^  mAxisPitchJoy;
	private: System::Windows::Forms::NumericUpDown^  mAxisRollRange;


	private: System::Windows::Forms::CheckBox^  mAxisYawInvert;
	private: System::Windows::Forms::NumericUpDown^  mAxisPitchRange;
	private: System::Windows::Forms::ComboBox^  mAxisRollAxis;



	private: System::Windows::Forms::ComboBox^  mAxisYawJoy;
	private: System::Windows::Forms::ComboBox^  mAxisPitchAxis;


	private: System::Windows::Forms::NumericUpDown^  mAxisYawRange;

	private: System::Windows::Forms::ComboBox^  mAxisYawAxis;







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
			this->mAxisZInvert = (gcnew System::Windows::Forms::CheckBox());
			this->mAxisZJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisYInvert = (gcnew System::Windows::Forms::CheckBox());
			this->mAxisYJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisZRange = (gcnew System::Windows::Forms::NumericUpDown());
			this->mAxisXInverted = (gcnew System::Windows::Forms::CheckBox());
			this->mAxisYRange = (gcnew System::Windows::Forms::NumericUpDown());
			this->mAxisZAxis = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisXJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisYAxis = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisXRange = (gcnew System::Windows::Forms::NumericUpDown());
			this->mAxisXAxis = (gcnew System::Windows::Forms::ComboBox());
			this->mButtonsGroup = (gcnew System::Windows::Forms::GroupBox());
			this->mJoystickGroup = (gcnew System::Windows::Forms::GroupBox());
			this->mTestGroup = (gcnew System::Windows::Forms::GroupBox());
			this->mControlGroup = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->mAxisRollInvert = (gcnew System::Windows::Forms::CheckBox());
			this->mAxisRollJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisPitchInvert = (gcnew System::Windows::Forms::CheckBox());
			this->mAxisPitchJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisRollRange = (gcnew System::Windows::Forms::NumericUpDown());
			this->mAxisYawInvert = (gcnew System::Windows::Forms::CheckBox());
			this->mAxisPitchRange = (gcnew System::Windows::Forms::NumericUpDown());
			this->mAxisRollAxis = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisYawJoy = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisPitchAxis = (gcnew System::Windows::Forms::ComboBox());
			this->mAxisYawRange = (gcnew System::Windows::Forms::NumericUpDown());
			this->mAxisYawAxis = (gcnew System::Windows::Forms::ComboBox());
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
			this->mPositionGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisZRange))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisYRange))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisXRange))->BeginInit();
			this->mButtonsGroup->SuspendLayout();
			this->mJoystickGroup->SuspendLayout();
			this->mTestGroup->SuspendLayout();
			this->mControlGroup->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisRollRange))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisPitchRange))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisYawRange))->BeginInit();
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
			// pictureBox1
			// 
			pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			pictureBox1->Location = System::Drawing::Point(6, 19);
			pictureBox1->Name = L"pictureBox1";
			pictureBox1->Size = System::Drawing::Size(40, 50);
			pictureBox1->TabIndex = 38;
			pictureBox1->TabStop = false;
			// 
			// label1
			// 
			label1->AutoSize = true;
			label1->Location = System::Drawing::Point(52, 19);
			label1->Name = L"label1";
			label1->Size = System::Drawing::Size(46, 13);
			label1->TabIndex = 17;
			label1->Text = L"left/right";
			// 
			// label2
			// 
			label2->AutoSize = true;
			label2->Location = System::Drawing::Point(52, 71);
			label2->Name = L"label2";
			label2->Size = System::Drawing::Size(59, 13);
			label2->TabIndex = 17;
			label2->Text = L"range (mm)";
			// 
			// label3
			// 
			label3->AutoSize = true;
			label3->Location = System::Drawing::Point(52, 95);
			label3->Name = L"label3";
			label3->Size = System::Drawing::Size(50, 13);
			label3->TabIndex = 17;
			label3->Text = L"up/down";
			// 
			// label4
			// 
			label4->AutoSize = true;
			label4->Location = System::Drawing::Point(52, 147);
			label4->Name = L"label4";
			label4->Size = System::Drawing::Size(59, 13);
			label4->TabIndex = 17;
			label4->Text = L"range (mm)";
			// 
			// pictureBox2
			// 
			pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			pictureBox2->Location = System::Drawing::Point(6, 95);
			pictureBox2->Name = L"pictureBox2";
			pictureBox2->Size = System::Drawing::Size(40, 50);
			pictureBox2->TabIndex = 38;
			pictureBox2->TabStop = false;
			// 
			// label5
			// 
			label5->AutoSize = true;
			label5->Location = System::Drawing::Point(52, 171);
			label5->Name = L"label5";
			label5->Size = System::Drawing::Size(57, 13);
			label5->TabIndex = 17;
			label5->Text = L"front/back";
			// 
			// label6
			// 
			label6->AutoSize = true;
			label6->Location = System::Drawing::Point(52, 223);
			label6->Name = L"label6";
			label6->Size = System::Drawing::Size(59, 13);
			label6->TabIndex = 17;
			label6->Text = L"range (mm)";
			// 
			// pictureBox3
			// 
			pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox3.Image")));
			pictureBox3->Location = System::Drawing::Point(6, 171);
			pictureBox3->Name = L"pictureBox3";
			pictureBox3->Size = System::Drawing::Size(40, 50);
			pictureBox3->TabIndex = 38;
			pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox4.Image")));
			pictureBox4->Location = System::Drawing::Point(6, 171);
			pictureBox4->Name = L"pictureBox4";
			pictureBox4->Size = System::Drawing::Size(40, 50);
			pictureBox4->TabIndex = 38;
			pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox5.Image")));
			pictureBox5->Location = System::Drawing::Point(6, 95);
			pictureBox5->Name = L"pictureBox5";
			pictureBox5->Size = System::Drawing::Size(40, 50);
			pictureBox5->TabIndex = 38;
			pictureBox5->TabStop = false;
			// 
			// label7
			// 
			label7->AutoSize = true;
			label7->Location = System::Drawing::Point(52, 223);
			label7->Name = L"label7";
			label7->Size = System::Drawing::Size(81, 13);
			label7->TabIndex = 17;
			label7->Text = L"range (degrees)";
			// 
			// label8
			// 
			label8->AutoSize = true;
			label8->Location = System::Drawing::Point(52, 147);
			label8->Name = L"label8";
			label8->Size = System::Drawing::Size(81, 13);
			label8->TabIndex = 17;
			label8->Text = L"range (degrees)";
			// 
			// label9
			// 
			label9->AutoSize = true;
			label9->Location = System::Drawing::Point(52, 171);
			label9->Name = L"label9";
			label9->Size = System::Drawing::Size(20, 13);
			label9->TabIndex = 17;
			label9->Text = L"roll";
			// 
			// pictureBox6
			// 
			pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox6.Image")));
			pictureBox6->Location = System::Drawing::Point(6, 19);
			pictureBox6->Name = L"pictureBox6";
			pictureBox6->Size = System::Drawing::Size(40, 50);
			pictureBox6->TabIndex = 38;
			pictureBox6->TabStop = false;
			// 
			// label10
			// 
			label10->AutoSize = true;
			label10->Location = System::Drawing::Point(52, 95);
			label10->Name = L"label10";
			label10->Size = System::Drawing::Size(82, 13);
			label10->TabIndex = 17;
			label10->Text = L"pitch (up/down)";
			// 
			// label11
			// 
			label11->AutoSize = true;
			label11->Location = System::Drawing::Point(52, 71);
			label11->Name = L"label11";
			label11->Size = System::Drawing::Size(81, 13);
			label11->TabIndex = 17;
			label11->Text = L"range (degrees)";
			// 
			// label12
			// 
			label12->AutoSize = true;
			label12->Location = System::Drawing::Point(52, 19);
			label12->Name = L"label12";
			label12->Size = System::Drawing::Size(74, 13);
			label12->TabIndex = 17;
			label12->Text = L"yaw (left/right)";
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
			this->mPositionGroup->Controls->Add(this->mAxisZInvert);
			this->mPositionGroup->Controls->Add(this->mAxisZJoy);
			this->mPositionGroup->Controls->Add(this->mAxisYInvert);
			this->mPositionGroup->Controls->Add(this->mAxisYJoy);
			this->mPositionGroup->Controls->Add(this->mAxisZRange);
			this->mPositionGroup->Controls->Add(this->mAxisXInverted);
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
			this->mPositionGroup->TabIndex = 45;
			this->mPositionGroup->TabStop = false;
			this->mPositionGroup->Text = L"Position";
			// 
			// mAxisZInvert
			// 
			this->mAxisZInvert->AutoSize = true;
			this->mAxisZInvert->Location = System::Drawing::Point(126, 171);
			this->mAxisZInvert->Name = L"mAxisZInvert";
			this->mAxisZInvert->Size = System::Drawing::Size(52, 17);
			this->mAxisZInvert->TabIndex = 40;
			this->mAxisZInvert->Text = L"invert";
			this->mAxisZInvert->UseVisualStyleBackColor = true;
			// 
			// mAxisZJoy
			// 
			this->mAxisZJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisZJoy->FormattingEnabled = true;
			this->mAxisZJoy->Location = System::Drawing::Point(52, 194);
			this->mAxisZJoy->Name = L"mAxisZJoy";
			this->mAxisZJoy->Size = System::Drawing::Size(50, 21);
			this->mAxisZJoy->TabIndex = 38;
			// 
			// mAxisYInvert
			// 
			this->mAxisYInvert->AutoSize = true;
			this->mAxisYInvert->Location = System::Drawing::Point(126, 95);
			this->mAxisYInvert->Name = L"mAxisYInvert";
			this->mAxisYInvert->Size = System::Drawing::Size(52, 17);
			this->mAxisYInvert->TabIndex = 40;
			this->mAxisYInvert->Text = L"invert";
			this->mAxisYInvert->UseVisualStyleBackColor = true;
			// 
			// mAxisYJoy
			// 
			this->mAxisYJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisYJoy->FormattingEnabled = true;
			this->mAxisYJoy->Location = System::Drawing::Point(52, 118);
			this->mAxisYJoy->Name = L"mAxisYJoy";
			this->mAxisYJoy->Size = System::Drawing::Size(50, 21);
			this->mAxisYJoy->TabIndex = 38;
			// 
			// mAxisZRange
			// 
			this->mAxisZRange->Location = System::Drawing::Point(133, 221);
			this->mAxisZRange->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->mAxisZRange->Name = L"mAxisZRange";
			this->mAxisZRange->Size = System::Drawing::Size(45, 20);
			this->mAxisZRange->TabIndex = 39;
			this->mAxisZRange->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, 0});
			// 
			// mAxisXInverted
			// 
			this->mAxisXInverted->AutoSize = true;
			this->mAxisXInverted->Location = System::Drawing::Point(126, 19);
			this->mAxisXInverted->Name = L"mAxisXInverted";
			this->mAxisXInverted->Size = System::Drawing::Size(52, 17);
			this->mAxisXInverted->TabIndex = 40;
			this->mAxisXInverted->Text = L"invert";
			this->mAxisXInverted->UseVisualStyleBackColor = true;
			// 
			// mAxisYRange
			// 
			this->mAxisYRange->Location = System::Drawing::Point(133, 145);
			this->mAxisYRange->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->mAxisYRange->Name = L"mAxisYRange";
			this->mAxisYRange->Size = System::Drawing::Size(45, 20);
			this->mAxisYRange->TabIndex = 39;
			this->mAxisYRange->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, 0});
			// 
			// mAxisZAxis
			// 
			this->mAxisZAxis->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisZAxis->FormattingEnabled = true;
			this->mAxisZAxis->Location = System::Drawing::Point(108, 194);
			this->mAxisZAxis->Name = L"mAxisZAxis";
			this->mAxisZAxis->Size = System::Drawing::Size(70, 21);
			this->mAxisZAxis->TabIndex = 39;
			// 
			// mAxisXJoy
			// 
			this->mAxisXJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisXJoy->FormattingEnabled = true;
			this->mAxisXJoy->Location = System::Drawing::Point(52, 42);
			this->mAxisXJoy->Name = L"mAxisXJoy";
			this->mAxisXJoy->Size = System::Drawing::Size(50, 21);
			this->mAxisXJoy->TabIndex = 38;
			// 
			// mAxisYAxis
			// 
			this->mAxisYAxis->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisYAxis->FormattingEnabled = true;
			this->mAxisYAxis->Location = System::Drawing::Point(108, 118);
			this->mAxisYAxis->Name = L"mAxisYAxis";
			this->mAxisYAxis->Size = System::Drawing::Size(70, 21);
			this->mAxisYAxis->TabIndex = 39;
			// 
			// mAxisXRange
			// 
			this->mAxisXRange->Location = System::Drawing::Point(133, 69);
			this->mAxisXRange->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->mAxisXRange->Name = L"mAxisXRange";
			this->mAxisXRange->Size = System::Drawing::Size(45, 20);
			this->mAxisXRange->TabIndex = 39;
			this->mAxisXRange->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, 0});
			// 
			// mAxisXAxis
			// 
			this->mAxisXAxis->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisXAxis->FormattingEnabled = true;
			this->mAxisXAxis->Location = System::Drawing::Point(108, 42);
			this->mAxisXAxis->Name = L"mAxisXAxis";
			this->mAxisXAxis->Size = System::Drawing::Size(70, 21);
			this->mAxisXAxis->TabIndex = 39;
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
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->mAxisRollInvert);
			this->groupBox1->Controls->Add(this->mAxisRollJoy);
			this->groupBox1->Controls->Add(this->mAxisPitchInvert);
			this->groupBox1->Controls->Add(this->mAxisPitchJoy);
			this->groupBox1->Controls->Add(this->mAxisRollRange);
			this->groupBox1->Controls->Add(this->mAxisYawInvert);
			this->groupBox1->Controls->Add(this->mAxisPitchRange);
			this->groupBox1->Controls->Add(this->mAxisRollAxis);
			this->groupBox1->Controls->Add(this->mAxisYawJoy);
			this->groupBox1->Controls->Add(this->mAxisPitchAxis);
			this->groupBox1->Controls->Add(pictureBox4);
			this->groupBox1->Controls->Add(this->mAxisYawRange);
			this->groupBox1->Controls->Add(pictureBox5);
			this->groupBox1->Controls->Add(label7);
			this->groupBox1->Controls->Add(this->mAxisYawAxis);
			this->groupBox1->Controls->Add(label8);
			this->groupBox1->Controls->Add(label9);
			this->groupBox1->Controls->Add(pictureBox6);
			this->groupBox1->Controls->Add(label10);
			this->groupBox1->Controls->Add(label11);
			this->groupBox1->Controls->Add(label12);
			this->groupBox1->Location = System::Drawing::Point(395, 242);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(190, 249);
			this->groupBox1->TabIndex = 45;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Rotation";
			// 
			// mAxisRollInvert
			// 
			this->mAxisRollInvert->AutoSize = true;
			this->mAxisRollInvert->Location = System::Drawing::Point(133, 170);
			this->mAxisRollInvert->Name = L"mAxisRollInvert";
			this->mAxisRollInvert->Size = System::Drawing::Size(52, 17);
			this->mAxisRollInvert->TabIndex = 40;
			this->mAxisRollInvert->Text = L"invert";
			this->mAxisRollInvert->UseVisualStyleBackColor = true;
			// 
			// mAxisRollJoy
			// 
			this->mAxisRollJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisRollJoy->FormattingEnabled = true;
			this->mAxisRollJoy->Location = System::Drawing::Point(52, 194);
			this->mAxisRollJoy->Name = L"mAxisRollJoy";
			this->mAxisRollJoy->Size = System::Drawing::Size(50, 21);
			this->mAxisRollJoy->TabIndex = 38;
			// 
			// mAxisPitchInvert
			// 
			this->mAxisPitchInvert->AutoSize = true;
			this->mAxisPitchInvert->Location = System::Drawing::Point(133, 94);
			this->mAxisPitchInvert->Name = L"mAxisPitchInvert";
			this->mAxisPitchInvert->Size = System::Drawing::Size(52, 17);
			this->mAxisPitchInvert->TabIndex = 40;
			this->mAxisPitchInvert->Text = L"invert";
			this->mAxisPitchInvert->UseVisualStyleBackColor = true;
			// 
			// mAxisPitchJoy
			// 
			this->mAxisPitchJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisPitchJoy->FormattingEnabled = true;
			this->mAxisPitchJoy->Location = System::Drawing::Point(52, 118);
			this->mAxisPitchJoy->Name = L"mAxisPitchJoy";
			this->mAxisPitchJoy->Size = System::Drawing::Size(50, 21);
			this->mAxisPitchJoy->TabIndex = 38;
			// 
			// mAxisRollRange
			// 
			this->mAxisRollRange->Location = System::Drawing::Point(133, 221);
			this->mAxisRollRange->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {180, 0, 0, 0});
			this->mAxisRollRange->Name = L"mAxisRollRange";
			this->mAxisRollRange->Size = System::Drawing::Size(45, 20);
			this->mAxisRollRange->TabIndex = 39;
			this->mAxisRollRange->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {45, 0, 0, 0});
			// 
			// mAxisYawInvert
			// 
			this->mAxisYawInvert->AutoSize = true;
			this->mAxisYawInvert->Location = System::Drawing::Point(133, 18);
			this->mAxisYawInvert->Name = L"mAxisYawInvert";
			this->mAxisYawInvert->Size = System::Drawing::Size(52, 17);
			this->mAxisYawInvert->TabIndex = 40;
			this->mAxisYawInvert->Text = L"invert";
			this->mAxisYawInvert->UseVisualStyleBackColor = true;
			// 
			// mAxisPitchRange
			// 
			this->mAxisPitchRange->Location = System::Drawing::Point(133, 145);
			this->mAxisPitchRange->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {180, 0, 0, 0});
			this->mAxisPitchRange->Name = L"mAxisPitchRange";
			this->mAxisPitchRange->Size = System::Drawing::Size(45, 20);
			this->mAxisPitchRange->TabIndex = 39;
			this->mAxisPitchRange->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {45, 0, 0, 0});
			// 
			// mAxisRollAxis
			// 
			this->mAxisRollAxis->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisRollAxis->FormattingEnabled = true;
			this->mAxisRollAxis->Location = System::Drawing::Point(108, 194);
			this->mAxisRollAxis->Name = L"mAxisRollAxis";
			this->mAxisRollAxis->Size = System::Drawing::Size(70, 21);
			this->mAxisRollAxis->TabIndex = 39;
			// 
			// mAxisYawJoy
			// 
			this->mAxisYawJoy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisYawJoy->FormattingEnabled = true;
			this->mAxisYawJoy->Location = System::Drawing::Point(52, 42);
			this->mAxisYawJoy->Name = L"mAxisYawJoy";
			this->mAxisYawJoy->Size = System::Drawing::Size(50, 21);
			this->mAxisYawJoy->TabIndex = 38;
			// 
			// mAxisPitchAxis
			// 
			this->mAxisPitchAxis->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisPitchAxis->FormattingEnabled = true;
			this->mAxisPitchAxis->Location = System::Drawing::Point(108, 118);
			this->mAxisPitchAxis->Name = L"mAxisPitchAxis";
			this->mAxisPitchAxis->Size = System::Drawing::Size(70, 21);
			this->mAxisPitchAxis->TabIndex = 39;
			// 
			// mAxisYawRange
			// 
			this->mAxisYawRange->Location = System::Drawing::Point(133, 69);
			this->mAxisYawRange->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {180, 0, 0, 0});
			this->mAxisYawRange->Name = L"mAxisYawRange";
			this->mAxisYawRange->Size = System::Drawing::Size(45, 20);
			this->mAxisYawRange->TabIndex = 39;
			this->mAxisYawRange->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {45, 0, 0, 0});
			// 
			// mAxisYawAxis
			// 
			this->mAxisYawAxis->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mAxisYawAxis->FormattingEnabled = true;
			this->mAxisYawAxis->Location = System::Drawing::Point(108, 42);
			this->mAxisYawAxis->Name = L"mAxisYawAxis";
			this->mAxisYawAxis->Size = System::Drawing::Size(70, 21);
			this->mAxisYawAxis->TabIndex = 39;
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
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->mPositionGroup);
			this->Controls->Add(this->mLabelBase);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"Razer Hydra PPJoy DirectInput Wrapper";
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
			this->mPositionGroup->ResumeLayout(false);
			this->mPositionGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisZRange))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisYRange))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisXRange))->EndInit();
			this->mButtonsGroup->ResumeLayout(false);
			this->mButtonsGroup->PerformLayout();
			this->mJoystickGroup->ResumeLayout(false);
			this->mTestGroup->ResumeLayout(false);
			this->mTestGroup->PerformLayout();
			this->mControlGroup->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisRollRange))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisPitchRange))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mAxisYawRange))->EndInit();
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

