#include "Main.h"

using namespace System;
using namespace System::Windows::Forms; 
using namespace System::Collections::Generic;

void MainLoop();
std::string managedStrToNative(System::String^ sysstr);
void AimAtPos(float x, float y);

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

void MainLoop()
{
	AActor LocalPlayer = GWorld.OwningGameInstance().LocalPlayer().PlayerController().LocalPawn();
	int playerobjid = LocalPlayer.GetComparisonIndex();
	int myteam = LocalPlayer.TeamID();

	std::unordered_map<uint32_t, float> Players;
	while (1)
	{
		System::Diagnostics::Stopwatch^ watch = gcnew System::Diagnostics::Stopwatch();
		auto ActorArray = GWorld.CurrentLevel().Actors();
		Hack.Overlay().NewFrame();
		if (ActorArray.Length() >= 20000) continue;

		ESPInfo info;
		info.POV = GWorld.OwningGameInstance().LocalPlayer().PlayerController().CameraCache().MinimalViewInfo();
		AActor NearestEnemy=AActor(0);
		float NearestDistance = 0;
		if (Hack.options.autoFPS)	watch->Start();

		for (int i = 0; i < ActorArray.Length(); i++)
		{
			AActor actor((uint64)ActorArray[i]);
			int NameID = UObject(actor.GetAddress()).GetFName().GetComparisonIndex();
			//if (GlobalNames.GetById(NameID) != "BP_PlayerRifleBulletImpact_C")
			//{
			//	std::cout << GlobalNames.GetById(NameID) << "  "<< std::hex << actor.GetAddress() << " " << std::dec << NameID << std::endl;
			//} 
			if (Hack.Option().Enemy && actor.GetComparisonIndex() == playerobjid &&actor.TeamID()!= myteam&&actor.Health()>0)
			{
				// Get enemy's statue
				Hack.UpdateESPInfo(actor, info);
				info.visible = info.LastRenderedTime > Players[actor.PlayerKey()];
				if (info.visible) info.color = Hack.options.VisibleColor; else info.color = info.isAI ? Hack.options.BotColor : Hack.options.HumanColor;
				Players[actor.PlayerKey()] = info.LastRenderedTime;
				info.Distance = info.Location.Distance(LocalPlayer.RootComponent().Location())/100.f;
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
					std::string text;
					text += std::to_string((int)info.Distance) + " m\n";
					text += "[" + std::to_string(actor.TeamID()) + "] " + info.PlayerName + "\n";
					text += info.isFiring ? "FIRING\n" : "";
					Hack.DrawInformation(info, text);
				}
				if (Hack.options.Aimbot&& info.visible)
				{
					float radius = Hack.options.aimbotRadius;
					Hack.overlay.DrawCircle(FVector(Hack.overlay.Width/2, Hack.overlay.Height/2, 0), radius, FColor(0, 0, 0));
					if (radius>=info.aimScreenPos.Distance(FVector(Hack.overlay.Width / 2, Hack.overlay.Height / 2, 0)))
					{
						if (Hack.Option().Aimbot && (NearestEnemy.GetAddress() == 0 || info.Distance < NearestDistance))
						{
							NearestEnemy = actor;
							NearestDistance = info.Distance;
						}
					}
				}
			}
			else if (NameID == 142870)  //BP_AirDropBox_C  [142870] 
			{
				AActor actor((uint64)ActorArray[i]);
				auto loc = actor.RootComponent().Location();
				auto POV = GWorld.OwningGameInstance().LocalPlayer().PlayerController().CameraCache().MinimalViewInfo();
				info.Distance = loc.Distance(LocalPlayer.RootComponent().Location()) / 100.f;
				std::string text;
				text += std::to_string((int)info.Distance) + " m\n";
				Hack.DrawInformation(Hack.overlay.WorldToScreen(loc,POV), "Airdrop \n"+text);
			}
			else if (NameID == 143308 || NameID == 143309)
			{
				AActor actor((uint64)ActorArray[i]);
				auto loc = actor.RootComponent().Location();
				auto POV = GWorld.OwningGameInstance().LocalPlayer().PlayerController().CameraCache().MinimalViewInfo();
				info.Distance = loc.Distance(LocalPlayer.RootComponent().Location()) / 100.f;
				std::string text;
				text += std::to_string((int)info.Distance) + " m\n";
				Hack.DrawInformation(Hack.overlay.WorldToScreen(loc, POV), "Motor \n" + text);
			}
		}
		
		if (Hack.Option().Aimbot && NearestEnemy.GetAddress() != 0)
		{
			float myBulletSpeed = LocalPlayer.WeaponManagerComponent().CurrentWeapon().WeaponEntityComp().BulletFireSpeed();
			if (myBulletSpeed > 100)
			{
				FVector location = Hack.GetBoneWithRotation(NearestEnemy, Hack.options.aimpos);
				if (Hack.options.predictaimbot)
				{
					FVector enemyVelocity = NearestEnemy.RootComponent().ComponentVelocity();
					float bulletTime = info.Distance / (myBulletSpeed / 100.f);
					location = location + enemyVelocity * bulletTime;
				}
				FVector aimScreenPos = Hack.overlay.WorldToScreen(location, info.POV);
				if ((GetAsyncKeyState(VK_RBUTTON) & 0x8000 || GetAsyncKeyState(VK_LBUTTON) & 0x8000))
				{
					AimAtPos(aimScreenPos.X, aimScreenPos.Y);
					if (GetAsyncKeyState(VK_CAPITAL) & 0x0001)
					{
						mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
					}
				}
			}
		}
		if (Hack.options.autoFPS)
		{
			watch->Stop();
			TimeSpan timespan = watch->Elapsed;
			if (timespan.TotalMilliseconds <=10)Hack.Overlay().RefreshAndSleep(16- timespan.TotalMilliseconds);else	Hack.Overlay().RefreshAndSleep(6);
		}
		else	Hack.overlay.RefreshAndSleep(16);
	}
}

void AimAtPos(float x, float y)
{
	float ScreenCenterX = ((Hack.overlay.Width-1) / 2);
	float ScreenCenterY = ((Hack.overlay.Height-1) / 2);
	Hack.overlay.DrawLine(FVector(x,y,0) - FVector(10, 0, 0), FVector(x, y, 0) + FVector(10, 0, 0), FColor(255, 0, 0), 1.2f);
	Hack.overlay.DrawLine(FVector(x, y, 0) - FVector(0, 10, 0), FVector(x, y, 0) + FVector(0, 10, 0), FColor(255, 0, 0), 1.2f);
	Hack.overlay.DrawLine(FVector(ScreenCenterX, ScreenCenterY, 0) + FVector(10, -10, 0), FVector(ScreenCenterX, ScreenCenterY, 0) + FVector(-10, 10, 0), FColor(255, 0, 0), 1.2f);
	Hack.overlay.DrawLine(FVector(ScreenCenterX, ScreenCenterY, 0) + FVector(10, 10, 0), FVector(ScreenCenterX, ScreenCenterY, 0) + FVector(-10, -10, 0), FColor(255, 0, 0), 1.2f);
	float TargetX = 0;
	float TargetY = 0;
	if (x != 0)
	{
		if (x > ScreenCenterX)
		{
			TargetX = -(ScreenCenterX - x);
			TargetX /= Hack.options.aimbotSpeed;
			if (TargetX + ScreenCenterX > ScreenCenterX * 2) TargetX = 0;
		}

		if (x < ScreenCenterX)
		{
			TargetX = x - ScreenCenterX;
			TargetX /= Hack.options.aimbotSpeed;
			if (TargetX + ScreenCenterX < 0) TargetX = 0;
		}
	}
	if (y != 0)
	{
		if (y > ScreenCenterY)
		{
			TargetY = -(ScreenCenterY - y);
			TargetY /= Hack.options.aimbotSpeed;
			if (TargetY + ScreenCenterY > ScreenCenterY * 2) TargetY = 0;
		}

		if (y < ScreenCenterY)
		{
			TargetY = y - ScreenCenterY;
			TargetY /= Hack.options.aimbotSpeed;
			if (TargetY + ScreenCenterY < 0) TargetY = 0;
		}
	}
	mouse_event(0x0001, (uint)(TargetX), (uint)(TargetY), NULL, NULL);
}

std::string managedStrToNative(System::String^ sysstr)
{
	using System::IntPtr;
	using System::Runtime::InteropServices::Marshal;

	IntPtr ip = Marshal::StringToHGlobalAnsi(sysstr);
	std::string outString = static_cast<const char*>(ip.ToPointer());
	Marshal::FreeHGlobal(ip);
	return outString;
}

void LiteHackForm::MainForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	GWorld = UWorld(GameBaseAddress + updates::off::uworld);
	GlobalNames = NamesStore(GameBaseAddress + updates::off::gnames);
	GlobalObjects = ObjectsStore(GameBaseAddress + updates::off::gobjects);
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
		DebugUObjectByID(1);
	else
		DebugUObjectByID(int::Parse(numericUpDown1->Text));
	DebugGNamesByID(1);
	DebugGWorld();
	DebugPlayer();
}

void LiteHackForm::MainForm::Button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox1->Text == "")
		DebugUObjectByID(1);
	else
		DebugUObjectByAddress(UINT64::Parse(textBox1->Text));
	DebugGWorld();
	DebugPlayer();
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
		panel1->Enabled = false; 
		button3->Text = "Start Hack";
	}
	else
	{
		GWorld = UWorld(GameBaseAddress + updates::off::uworld);
		panel1->Enabled = true;
		Hack.options.Enemy = checkBox1->Checked;
		Hack.options.Box = checkBox2->Checked;
		Hack.options.Line = checkBox3->Checked;
		Hack.options.Health  = checkBox4->Checked;
		Hack.options.Skeleton = checkBox5->Checked;
		Hack.options.maxSkeletonDistance = trackBar1->Value;
		Hack.options.HumanColor = FColor(linkLabel1->VisitedLinkColor.R, linkLabel1->VisitedLinkColor.G, linkLabel1->VisitedLinkColor.B);
		Hack.options.BotColor = FColor(linkLabel2->VisitedLinkColor.R, linkLabel2->VisitedLinkColor.G, linkLabel2->VisitedLinkColor.B);
		Hack.options.VisibleColor = FColor(linkLabel3->VisitedLinkColor.R, linkLabel3->VisitedLinkColor.G, linkLabel3->VisitedLinkColor.B);

		Hack.options.Aimbot = checkBox6->Checked;
		Hack.options.predictaimbot = checkBox8->Checked;
		Hack.options.aimpos = 
			radioButton1->Checked? 
			AimbotPos::Head 
			:(
				radioButton2->Checked ?
				AimbotPos::Pelvis
				:(
					radioButton3->Checked ?
					AimbotPos::Neck 
					:
					AimbotPos::Body
					)
				);
		Hack.options.aimbotSpeed = trackBar2->Value;
		Hack.options.aimbotRadius = trackBar3->Value;;
		Hack.options.autoFPS = checkBox7->Checked;
		Hack.Initialize();
		MainLoopThread->Start();
		button3->Text = "Stop Hack";
	}
}