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
		InitForm(void);

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~InitForm();

	private:
		//automatically generated objects

		System::Windows::Forms::ProgressBar^  progressBar;
		System::Windows::Forms::Label^  baseSearchLabel;
		System::Windows::Forms::Button^  okButton;
		System::Windows::Forms::Label^  errorLabel;

		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

		/// \brief Timer for repeatedly trying to find the base
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
			this->MaximizeBox = false;
			this->Name = L"InitForm";
			this->Text = L"Initializing";
			this->Shown += gcnew System::EventHandler(this, &InitForm::OnOpen);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		/// \brief Closes the window, called by Error-OK button
		System::Void Exit(System::Object^  sender, System::EventArgs^  e);
		/// \brief Called once the window has been opened, initializes the Sixense SDK and the timer
		System::Void OnOpen(System::Object^  sender, System::EventArgs^  e);
		/// \brief Periodically called by the timer, looks for a Hydra base.
		System::Void OnTimerTick(System::Object^ sender, System::EventArgs^ e);
};
}
