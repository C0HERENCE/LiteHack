#pragma once
#include "MainForm.h"
#include "Memory.h"
#include "GWorld.h"
#include "Names.h"
#include "Overlay.h"
#include "Renderer.h"
#include <string>

void MainLoop();
ref class Options
{
public:
	// color 
	static FColor* BotColor = new FBLUE_BLUE;
	static FColor* HumColor = new FPURPLE_BLUEVIOLET;
	static FColor* VisColor = new FRED_RED;

	// esp
	static bool esp = false;
	static bool bone = false;
	static int maxBoneDis = 100;
	
	// aimbot 
	static bool aimbot = true;
	static int aimbot_speed = 5;
	static int aimbot_part = 1;
	static int aimbot_radius = 500;

	//
	static bool item = false;
	static bool vehicle = false;
};;

ref class Global
{
public:
	static Memory^ GMemory = gcnew Memory;
	static UWorld^ GWorld = gcnew UWorld;
	static Names^ GNames = gcnew Names;
	static Overlay^ Canvas = gcnew Overlay;
	static Renderer^ Draw = gcnew Renderer;
	static LiteHack::MainUI^ MainForm = gcnew LiteHack::MainUI;
	static System::Threading::Thread^ MainLoopThread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(MainLoop));
	static Options^ Option = gcnew Options;
};



namespace Settings
{
	static std::string ProcessName = "PUBGLite-Win64-Shipping";
	static std::string MoudleName = "PUBGLite-Win64-Shipping.exe";
	static std::string WindowsClass = "UnrealWindow";
	static std::string WindowsCaption = "PUBG LITE ";
}