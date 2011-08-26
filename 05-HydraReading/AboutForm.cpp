#include "StdAfx.h"
#include "AboutForm.h"
#include <Windows.h>

namespace My05HydraReading
{
	AboutForm::AboutForm(void)
	{
		InitializeComponent();
		//
		//TODO: Konstruktorcode hier hinzufügen.
		//
	}

	AboutForm::~AboutForm()
	{
		if (components)
		{
			delete components;
		}
	}

	System::Void AboutForm::linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e)
	{
		ShellExecute(NULL, L"open", L"http://www.mrwonko.de", NULL, NULL, SW_SHOWNORMAL);
	}
}