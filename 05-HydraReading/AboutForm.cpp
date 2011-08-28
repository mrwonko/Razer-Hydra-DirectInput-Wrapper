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