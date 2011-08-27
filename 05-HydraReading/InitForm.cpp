#include "StdAfx.h"
#include "InitForm.h"


namespace My05HydraReading
{
	InitForm::InitForm()
	{
		InitializeComponent();
	}

	InitForm::~InitForm()
	{
		if (components)
		{
			delete components;
		}
		assert(sixenseExit() == SIXENSE_SUCCESS);
	}

	System::Void InitForm::Exit(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
		return;
	}

	System::Void InitForm::OnOpen(System::Object^  sender, System::EventArgs^  e) 
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

	System::Void InitForm::OnTimerTick(System::Object^ sender, System::EventArgs^ e)
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
}