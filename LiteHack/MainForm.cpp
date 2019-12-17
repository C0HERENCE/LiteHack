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
	Application::Run(Global::MainForm);
	#endif

}
System::Void LiteHack::MainUI::MainUI_Load(System::Object^ sender, System::EventArgs^ e)
{
	Global::Option->UseHijackOverlay = false;
	Global::Canvas->twnd = FindWindow("UnrealWindow", "PUBG LITE ");
	if (Global::Canvas->twnd == NULL)
	{
		System::Console::WriteLine("Game window not found !");
		Application::Exit();
	}
	System::Console::WriteLine("Now creating overlay and cache names...");
	Global::Canvas->Init();
	Global::GNames->Init(Global::GMemory->GetBase() + Off::GNames);
	Global::GNames->CacheNames();
	System::Console::WriteLine("Now Start Hack !");
}
System::Void LiteHack::MainUI::btnToggleHack(System::Object^ sender, System::EventArgs^ e)
{
	if (Global::MainLoopThread->IsAlive)
	{
		Global::MainLoopThread->Abort();
		Global::MainLoopThread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(MainLoop));
		button1->Text = "Start Hack";
	}
	else
	{
		Global::MainLoopThread->Start();
		button1->Text = "Stop Hack";
		return;
	}
}

System::Void LiteHack::MainUI::MainUI_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	Global::Canvas->CleanUp();
	if (Global::MainLoopThread->IsAlive)
	{
		Global::MainLoopThread->Abort();
		Global::Canvas->CleanUp();
		MessageBox::Show("See you next time");
	}
}
