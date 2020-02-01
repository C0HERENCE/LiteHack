#include "Global.h"
#include "Updates.h"
//#include "VMProtectSDK.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

[STAThread]
void Main(array<String^>^ args)
{
	//VMProtectBegin("protectstart");
	if (!Global::GMemory->Init())
	{
		MessageBox::Show("Can't Read");
		Application::Exit();
		return;
	}
	Application::Run(Global::MainForm);
	//VMProtectEnd();
}
System::Void LiteHack::MainUI::MainUI_Shown(System::Object^ sender, System::EventArgs^ e)
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
	Global::Canvas->NewFrame();
	Global::Canvas->RefreshAndSleep(16);
	Global::GNames->Init(Global::GMemory->GetBase() + Off::GNames);
	Global::GNames->CacheNames(); 
	Global::GWorld = gcnew UWorld();
	Global::GWorld->Init(Global::GMemory->GetBase() + Off::UWorld);
	Global::Canvas->NewFrame();
	Global::Canvas->RefreshAndSleep(16);
	System::Console::WriteLine("Now Start Hack !");
	MainUI::BringToFront();
}
System::Void LiteHack::MainUI::btnToggleHack(System::Object^ sender, System::EventArgs^ e)
{
	if (Global::MainLoopThread->IsAlive)
	{
		Global::MainLoopThread->Abort();
		Global::Canvas->NewFrame();
		Global::Canvas->RefreshAndSleep(16);
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
	if (Global::MainLoopThread->IsAlive)
	{
		Global::MainLoopThread->Abort();
		Global::Canvas->NewFrame();
		Global::Canvas->RefreshAndSleep(16);
	}
	Global::Canvas->CleanUp();
	if (Global::MainLoopThread->IsAlive)
	{
		Global::MainLoopThread->Abort();
		Global::Canvas->CleanUp();
		MessageBox::Show("See you next time");
	}
}
