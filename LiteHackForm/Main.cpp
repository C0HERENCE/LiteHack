#include "Main.h"

using namespace System;
using namespace System::Windows::Forms; 
using namespace System::Collections::Generic;

#define off_UWorld 0x4532298
#define off_GNames 0x46438d0
#define off_GObjects 0x4659e48

std::string managedStrToNative(System::String^ sysstr)
{
	using System::IntPtr;
	using System::Runtime::InteropServices::Marshal;

	IntPtr ip = Marshal::StringToHGlobalAnsi(sysstr);
	std::string outString = static_cast<const char*>(ip.ToPointer());
	Marshal::FreeHGlobal(ip);
	return outString;
}
void MainLoop();

void MainLoop()
{
	while (1)
	{
		ULevel Level = GWorld.CurrentLevel();
		AActor LocalPlayer = GWorld.OwningGameInstance().LocalPlayer().PlayerController().LocalPawn();
		Hack.Overlay().NewFrame();
		if (Level.Actors().Length() >= 10000) continue;

		ESPInfo info;
		info.POV = GWorld.OwningGameInstance().LocalPlayer().PlayerController().CameraCache().MinimalViewInfo();
		AActor NearestEnemy;
		float NearestDistance = 0;

		for (int i = 0; i < Level.Actors().Length(); i++)
		{
			AActor actor((uint64)Level.Actors()[i]);

			if (Hack.Option().Enemy && actor.GetComparisonIndex() == LocalPlayer.GetComparisonIndex())
			{
				// Get enemy's statue
				Hack.UpdateESPInfo(actor, info);
				info.Distance = info.Location.Distance(LocalPlayer.RootComponent().Location());
				if (info.rootScreenPos.X<0 || info.rootScreenPos.X>Hack.Overlay().Width || info.rootScreenPos.Y<0 || info.rootScreenPos.Y>Hack.Overlay().Height)
				{
					// if current not on the screen
					if (Hack.Option().Line)	Hack.DrawGuideLine(info);
				}
				else
				{
					// if on the screen
					if (Hack.Option().Skeleton)	Hack.DrawSkeleton(info);
					if (Hack.Option().Health)	Hack.DrawHealthBar(info);
					if (Hack.Option().Box)	Hack.DrawBox(info);
				}
				if (Hack.Option().Aimbot)
				{
					// Find the nearest enemy
					if (NearestEnemy.GetAddress() == 0)
					{
						NearestEnemy = actor;
						NearestDistance = info.Distance;
					}
					else if (info.Distance < NearestDistance)
					{
						NearestDistance = info.Location.Distance(LocalPlayer.RootComponent().Location()) < NearestDistance;
						NearestEnemy = actor;
					}
				}
			}
		}

		if (Hack.Option().Aimbot && NearestEnemy.GetAddress() != 0)
		{

		}

		Hack.Overlay().Refresh();
	}
}

[STAThread]
void Main(array<String^>^ args)
{
	if (args->Length == 0)
	{
		MessageBox::Show("Run from \"HLeaker.exe\"!");
		return;
	}
	GameProcessHandle = reinterpret_cast<void*>(int::Parse(args[0]));
	GameMemory = Memory(GameProcessHandle);
	HMODULE hMods[512];
	DWORD cb;
	LPVOID lpBase = nullptr;
	bool success = false;
	if (EnumProcessModulesEx(GameProcessHandle, hMods, sizeof(hMods), &cb, LIST_MODULES_ALL))
	{
		char szModName[MAX_PATH] = { NULL };
		for (int i = 0; i < cb / sizeof(HMODULE); i++)
		{
			GetModuleBaseNameA(GameProcessHandle, hMods[i], szModName, MAX_PATH);
			if (!strcmp(szModName, "PUBGLite-Win64-Shipping.exe"))
			{
				std::cout << "MoudleBase: 0x" << hMods[i] << " Process: " << szModName << std::endl;
				lpBase = hMods[i];
				GameBaseAddress = (uint64)lpBase;
				success = true;
				break;
			}
		}
	}
	if (!success)
	{
		MessageBox::Show("Initialize failed!");
		return;
	}
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	LiteHackForm::MainForm form;
	Application::Run(% form);
}

void LiteHackForm::MainForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	GWorld = UWorld(GameBaseAddress + off_UWorld);
	GlobalNames = NamesStore(GameBaseAddress + off_GNames);
	GlobalObjects = ObjectsStore(GameBaseAddress + off_GObjects);
	MainLoopThread = gcnew Thread(gcnew ThreadStart(MainLoop));
}

void LiteHackForm::MainForm::MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	if (MainLoopThread->IsAlive)
	{
		MainLoopThread->Abort();
		Hack.Overlay().CleanUp();
		MessageBox::Show("See you next time");
	}
}

void LiteHackForm::MainForm::btnDebug_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (int::Parse(numericUpDown1->Text) == 0)
		DebugUObjectByID(159715);
	else
		DebugUObjectByID(int::Parse(numericUpDown1->Text));
	DebugGNamesByID(159714);
	DebugGWorld();
}

void LiteHackForm::MainForm::btnDump_Click(System::Object^ sender, System::EventArgs^ e)
{
	FolderBrowserDialog^ fd = gcnew FolderBrowserDialog;
	fd->ShowNewFolderButton = true;
	if (fd->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		std::cout << "ObjObjects: 0x" << std::hex << GlobalObjects.GetById(0).GetAddress() << std::endl;
		std::cout << "NumElements: " << std::dec << GlobalObjects.GetObjectsNum() << std::endl;
		fs::path outputDirectory(managedStrToNative(fd->SelectedPath));
		GlobalObjects.Dump(outputDirectory.string());
		Generator generator;
		generator.Dump(outputDirectory);
		generator.DumpSDK(outputDirectory);
		MessageBox::Show("Dump Finished.");
	}
}

void LiteHackForm::MainForm::BtnToggleHack_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MainLoopThread->IsAlive)
	{
		MainLoopThread->Abort();
		Hack.Overlay().CleanUp();
		MainLoopThread = gcnew Thread(gcnew ThreadStart(MainLoop));
		button3->Text = "Start Hack";
	}
	else
	{
		Hack.Initialize();
		MainLoopThread->Start();
		button3->Text = "Stop Hack";
	}
}