// 05-HydraReading.cpp: Hauptprojektdatei.

#include "stdafx.h"
#include "InitForm.h"

using namespace My05HydraReading;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Aktivieren visueller Effekte von Windows XP, bevor Steuerelemente erstellt werden
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Hauptfenster erstellen und ausführen
	//Application::Run(gcnew Form1());
	Application::Run(gcnew InitForm());
	return 0;
}
