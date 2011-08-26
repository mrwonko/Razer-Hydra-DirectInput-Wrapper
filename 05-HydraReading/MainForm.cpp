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
	}

	MainForm::MainForm(void) :
		mLeftControllerIndex(-1),
		mRightControllerIndex(-1)
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

		//let's prevent myself from screwing this up with the visual editor.
		this->mControllerChoice->Items->Clear();
		this->mControllerChoice->Items->Add("left controller");
		this->mControllerChoice->Items->Add("right controller");
		//for some reason I can't set this in the Visual Editor thingy.
		this->mControllerChoice->SelectedIndex = 0; //0: left, 1: right

		if(!LoadSettings(GetDefaultIniFilename(true), true) || !LoadSettings(GetDefaultIniFilename(false), false) )
		{
			Error("Could not load settings!");
			return;
		}
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
		this->mLabelXAxis->Visible = !display;
		this->mLabelXAxisValue->Visible = !display;
		this->mControllerChoice->Visible = !display;
		this->mSaveButton->Visible = !display;
		this->mLoadButton->Visible = !display;
		this->mOriginButton->Visible = !display;
		this->mAboutButton->Visible = !display;

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

		static int i = 0;
		std::stringstream ss;
		//ss<<++i;
		//ss<<mControllerChoice->SelectedIndex;
		ss << data.pos[0];
		this->mLabelXAxisValue->Text = gcnew String(ss.str().c_str());
	}


	const bool MainForm::SaveSettings(const std::wstring& filename, const bool left)
	{
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
		/*
		std::wstringstream wss;
		wss << buffer;
		int somenumber;
		wss >> somenumber;
		*/
		return true;
	}
}