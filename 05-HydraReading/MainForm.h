#pragma once

#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <sixense.h>

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
		System::Windows::Forms::Label^  mLabelXAxis;
		System::Windows::Forms::Label^  mLabelXAxisValue;
		System::Windows::Forms::Label^  mLabelBase;
		System::Windows::Forms::ComboBox^  mControllerChoice;

		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

		/// \brief Timer for periodically polling the Hydra
		System::Windows::Forms::Timer^ mTimer;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->mLabelXAxis = (gcnew System::Windows::Forms::Label());
			this->mLabelXAxisValue = (gcnew System::Windows::Forms::Label());
			this->mLabelBase = (gcnew System::Windows::Forms::Label());
			this->mControllerChoice = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// mLabelXAxis
			// 
			this->mLabelXAxis->AutoSize = true;
			this->mLabelXAxis->Location = System::Drawing::Point(12, 36);
			this->mLabelXAxis->Name = L"mLabelXAxis";
			this->mLabelXAxis->Size = System::Drawing::Size(39, 13);
			this->mLabelXAxis->TabIndex = 1;
			this->mLabelXAxis->Text = L"X Axis:";
			// 
			// mLabelXAxisValue
			// 
			this->mLabelXAxisValue->AutoSize = true;
			this->mLabelXAxisValue->Location = System::Drawing::Point(57, 36);
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
			this->mControllerChoice->Location = System::Drawing::Point(12, 12);
			this->mControllerChoice->Name = L"mControllerChoice";
			this->mControllerChoice->Size = System::Drawing::Size(126, 21);
			this->mControllerChoice->TabIndex = 0;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(366, 229);
			this->Controls->Add(this->mControllerChoice);
			this->Controls->Add(this->mLabelXAxisValue);
			this->Controls->Add(this->mLabelXAxis);
			this->Controls->Add(this->mLabelBase);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"05 Hydra Reading";
			this->Shown += gcnew System::EventHandler(this, &MainForm::OnOpen);
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
	};
}

