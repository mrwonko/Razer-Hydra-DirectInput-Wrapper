#pragma once

#include "MainForm.h"
#include <sixense.h>

namespace My05HydraReading {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für InitForm
	/// </summary>
	public ref class InitForm : public System::Windows::Forms::Form
	{
	public:
		InitForm(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~InitForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ProgressBar^  progressBar;
	private: System::Windows::Forms::Label^  baseSearchLabel;

	private: System::Windows::Forms::Button^  okButton;
	private: System::Windows::Forms::Label^  errorLabel;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;
		System::Windows::Forms::Timer^ mTimer;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->progressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->baseSearchLabel = (gcnew System::Windows::Forms::Label());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->errorLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// progressBar
			// 
			this->progressBar->Location = System::Drawing::Point(12, 25);
			this->progressBar->Maximum = 5;
			this->progressBar->Name = L"progressBar";
			this->progressBar->Size = System::Drawing::Size(170, 23);
			this->progressBar->Step = 1;
			this->progressBar->TabIndex = 0;
			// 
			// baseSearchLabel
			// 
			this->baseSearchLabel->AutoSize = true;
			this->baseSearchLabel->Location = System::Drawing::Point(54, 9);
			this->baseSearchLabel->Name = L"baseSearchLabel";
			this->baseSearchLabel->Size = System::Drawing::Size(87, 13);
			this->baseSearchLabel->TabIndex = 1;
			this->baseSearchLabel->Text = L"Looking for Base";
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(60, 71);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(75, 23);
			this->okButton->TabIndex = 2;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Visible = false;
			this->okButton->Click += gcnew System::EventHandler(this, &InitForm::Exit);
			// 
			// errorLabel
			// 
			this->errorLabel->AutoSize = true;
			this->errorLabel->ForeColor = System::Drawing::Color::Red;
			this->errorLabel->Location = System::Drawing::Point(46, 55);
			this->errorLabel->Name = L"errorLabel";
			this->errorLabel->Size = System::Drawing::Size(102, 13);
			this->errorLabel->TabIndex = 3;
			this->errorLabel->Text = L"Could not find Base!";
			this->errorLabel->Visible = false;
			// 
			// InitForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(194, 102);
			this->Controls->Add(this->errorLabel);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->baseSearchLabel);
			this->Controls->Add(this->progressBar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MinimizeBox = false;
			this->Name = L"InitForm";
			this->Text = L"Initializing";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &InitForm::OnClosed);
			this->Shown += gcnew System::EventHandler(this, &InitForm::OnOpen);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void Exit(System::Object^  sender, System::EventArgs^  e)
		{
			this->Close();
			return;
		 }

		System::Void OnOpen(System::Object^  sender, System::EventArgs^  e) 
		{
			if(sixenseInit() != SIXENSE_SUCCESS)
			{
				this->Hide();
				MessageBox::Show("Could not initalize Sixense SDK.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				this->Close();
				return;
			}
			this->mTimer = gcnew System::Windows::Forms::Timer();
			this->mTimer->Tick += gcnew System::EventHandler(this, &InitForm::OnTimerTick);
			this->mTimer->Interval = 1000;
			this->mTimer->Enabled = true;
		}

		System::Void OnTimerTick(System::Object^ sender, System::EventArgs^ e)
		{
			this->progressBar->PerformStep();
			this->Refresh(); //redraw
			bool foundBase = false;
			for(int i = 0; i < sixenseGetMaxBases(); ++i)
			{
				if(sixenseIsBaseConnected(i))
				{
					foundBase = true;
					break;
				}
			}
#ifndef _DEBUG
			if(foundBase)
#endif
			{
				this->mTimer->Enabled = false;
				this->Hide();
				MainForm^ f = gcnew MainForm();
				f->ShowDialog();
				this->Close();
				return;
			}
			//progress bar full? CJ, we're done here.
			if(this->progressBar->Value == this->progressBar->Maximum)
			{
				this->mTimer->Enabled = false;
				this->errorLabel->Visible = true;
				this->okButton->Visible = true;
			}
		}
	private:
		System::Void OnClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
		{
			sixenseExit();
		}
};
}
