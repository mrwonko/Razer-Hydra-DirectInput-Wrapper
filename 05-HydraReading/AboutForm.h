#pragma once

namespace My05HydraReading
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für AboutForm
	/// </summary>
	public ref class AboutForm : public System::Windows::Forms::Form
	{
	public:
		AboutForm(void);

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~AboutForm();

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::Label^  label1;
			System::Windows::Forms::LinkLabel^  linkLabel1;
			label1 = (gcnew System::Windows::Forms::Label());
			linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// label1
			// 
			label1->AutoSize = true;
			label1->Location = System::Drawing::Point(9, 9);
			label1->Name = L"label1";
			label1->Size = System::Drawing::Size(208, 78);
			label1->TabIndex = 0;
			label1->Text = L"Razer Hydra DirectInput Wrapper 0.2\r\n\r\nby Willi \"Mr. Wonko\" Schinmeyer\r\n\r\nUses PP" 
				L"Joy by Deon van der Westhuysen\r\n ";
			// 
			// linkLabel1
			// 
			linkLabel1->AutoSize = true;
			linkLabel1->Location = System::Drawing::Point(12, 87);
			linkLabel1->Name = L"linkLabel1";
			linkLabel1->Size = System::Drawing::Size(123, 13);
			linkLabel1->TabIndex = 1;
			linkLabel1->TabStop = true;
			linkLabel1->Text = L"http://www.mrwonko.de";
			linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &AboutForm::linkLabel1_LinkClicked);
			// 
			// AboutForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(229, 117);
			this->Controls->Add(linkLabel1);
			this->Controls->Add(label1);
			this->Name = L"AboutForm";
			this->Text = L"About";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e);
	};
}
