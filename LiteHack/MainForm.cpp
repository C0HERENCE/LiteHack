#include "Global.h"
#include "Updates.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

//#define DEBUG

[STAThread]
void Main(array<String^>^ args)
{
	#ifndef DEBUG
	//if (args->Length == 0)
	//{
	//	MessageBox::Show("Run from HLeaker!");
	//	Application::Exit();
	//	return;
	//}
	//
	//if (!Global::GMemory->Init(reinterpret_cast<void*>(int::Parse(args[0]))))
	//{
	//	MessageBox::Show("Can't Read GameMemory");
	//	Application::Exit();
	//	return;
	//}
	if (!Global::GMemory->Init())
	{
		MessageBox::Show("Can't Read GameMemory");
		Application::Exit();
		return;
	}
	#endif

	Application::Run(Global::MainForm);
}
System::Void LiteHack::MainUI::MainUI_Load(System::Object^ sender, System::EventArgs^ e)
{
}
#include <iostream>
System::Void LiteHack::MainUI::btnToggleHack(System::Object^ sender, System::EventArgs^ e)
{
	if (Global::MainLoopThread->IsAlive)
	{
		Global::MainLoopThread->Abort();
		Global::Canvas->CleanUp();
		Global::MainLoopThread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(MainLoop));
		button1->Text = "Start Hack";
	}
	else
	{
		Global::Canvas->Init();
		Global::MainLoopThread->Start();
		button1->Text = "Stop Hack";
		return;
	}
}

System::Void LiteHack::MainUI::MainUI_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	if (Global::MainLoopThread->IsAlive)
	{
		Global::MainLoopThread->Abort();
		Global::Canvas->CleanUp();
		MessageBox::Show("See you next time");
	}
}

