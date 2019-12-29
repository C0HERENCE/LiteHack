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
	// overlay
	static bool UseHijackOverlay = true;

	// color 
	FColor* BotColor = new FBLUE_BLUE;
	FColor* HumColor = new FPURPLE_BLUEVIOLET;
	FColor* VisColor = new FRED_RED;

	// esp
	bool enemyESP = true;
	bool bone = true;
	int maxBoneDis = 100;
	
	// aimbot 
	bool aimbot = true;
	int aimbot_speed = 3;
	int aimbot_part = 4;
	float aimbot_radius = 500;
	int aimbot_second_part = 6;

	// no recoil
	bool norecoil = true;
	bool noanimkick = true;
	bool noverticalrecoil = true;
	bool nospread = true;
	bool nosway = true;

	//
	bool itemESP = true;
	bool vehicleESP = true;
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