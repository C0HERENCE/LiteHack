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
	Image^ img = Image::FromFile("Images/Ammunition/Item_Ammo_9mm_C.png");
	pictureBox1->Image = img;
}
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
		Global::Option->UseHijackOverlay = radioButton1->Checked;
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

System::Void LiteHack::MainUI::btnUpdateOptions_Click(System::Object^ sender, System::EventArgs^ e)
{
	Global::Option->aimbot = switchAimbot->Checked;
	Global::Option->aimbot_part = (int)aimPart->Value;
	Global::Option->aimbot_radius = (float)aimRadius->Value;
	Global::Option->aimbot_speed = (int)aimSpeed->Value;
	Global::Option->aimbot_second_part = (int)secondAimPart->Value;

	Global::Option->enemyESP = switchEnemyESP->Checked;
	Global::Option->bone = switchBone->Checked;
	Global::Option->maxBoneDis = maxBoneDis->Value;

	Global::Option->norecoil = switchNoRecoil->Checked;
	Global::Option->noanimkick = noanimkick->Checked;
	Global::Option->noverticalrecoil = norecoil->Checked;
	Global::Option->nospread = nospread->Checked;
	Global::Option->nosway = nosway->Checked;
}

System::Void LiteHack::MainUI::switchEnemyESP_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	groupBox1->Enabled = switchEnemyESP->Checked;
}

System::Void LiteHack::MainUI::switchAimbot_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	groupBox2->Enabled = switchAimbot->Checked;
}

System::Void LiteHack::MainUI::switchNoRecoil_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	groupBox3->Enabled = switchNoRecoil->Checked;
}

System::Void LiteHack::MainUI::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	auto rootcomp = Global::GWorld->OwningGameInstance()->LocalPlayer()->PlayerController()->LocalPawn()->RootComponent();
	Global::GMemory->Write<float>(rootcomp->GetAddress() + Off::RelativeLocation + 0x8, rootcomp->Location().Z + 200.f);
}
