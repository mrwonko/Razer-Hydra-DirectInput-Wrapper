#pragma once

#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <sixense.h>

namespace My05HydraReading {

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
		MainForm(void) :
		  mLeftControllerIndex(-1),
		  mRightControllerIndex(-1)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  mLabelXAxis;
	protected: 

	private: System::Windows::Forms::Label^  mLabelXAxisValue;
	protected: 

	protected: 



	protected: 

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^  mLabelBase;
	private: System::Windows::Forms::ComboBox^  mControllerChoice;

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
		System::Void OnOpen(System::Object^  sender, System::EventArgs^  e)
		{
			this->mTimer = gcnew System::Windows::Forms::Timer();
			this->mTimer->Tick += gcnew System::EventHandler(this, &MainForm::OnTimerTick);
			this->mTimer->Interval = 16;
			this->mTimer->Enabled = true;

			//let's prevent myself from screwing this up with the visual editor.
			this->mControllerChoice->Items->Clear();
			this->mControllerChoice->Items->Add("left controller");
			this->mControllerChoice->Items->Add("right controller");
			//for some reason I can't set this in the Visual Editor thingy.
			this->mControllerChoice->SelectedIndex = 0; //0: left, 1: right
		}

		/** \brief Displays an Error and exits.
		**/
		void Error(const std::string& message)
		{
			this->mTimer->Enabled = false; //IMPORTANT!
			this->Hide();
			MessageBox::Show(gcnew System::String(message.c_str()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->Close();
		}

		/** \brief Changes visibility to either display "Put controllers in Base" or the actual stuff.
			\note Needs to be updated when new elements get added, obviously.
		**/
		void DisplayBaseMessage(const bool display)
		{
			//ordinary stuff: hidden when base message displayed.
			this->mLabelXAxis->Visible = !display;
			this->mLabelXAxisValue->Visible = !display;
			this->mControllerChoice->Visible = !display;

			//base message
			this->mLabelBase->Visible = display;
		}

		/** \brief Sets the active base to the first one connected
			\return Whether any bases are connected
			\note In debug mode, returns true and sets the active base to 0 if none are connected.
		**/
		const bool SetBase()
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


		int mLeftControllerIndex;
		int mRightControllerIndex;

		const bool SetControllerIndices()
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

			// not initialized?
			if(data[0].which_hand == 0 || data[1].which_hand == 0)
			{
				this->mLabelBase->Text = "Please place the controllers in the base.";
				DisplayBaseMessage(true);
				return false;
			}
			//same hand?
			if(data[0].which_hand == data[1].which_hand)
			{
				this->mLabelBase->Text = "Please place the controllers in different base docks.";
				DisplayBaseMessage(true);
				return false;
			}
			//yay, both are initialized and they correspond to different hands!
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

		/**	This is where The Magicks happen :)
		**/
		System::Void OnTimerTick(System::Object^  sender, System::EventArgs^  e)
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

			static int i = 0;
			std::stringstream ss;
			//ss<<++i;
			//ss<<mControllerChoice->SelectedIndex;
			ss << data.pos[0];
			this->mLabelXAxisValue->Text = gcnew String(ss.str().c_str());
		}
	};
}

