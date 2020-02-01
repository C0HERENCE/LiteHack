#pragma once
#include "Memory/VMProtectSDK.h"
#include "Memory/Memory.h"
#include "Overlay/Overlay.h"
#include "Overlay/Renderer.h"
#include "SDK/Names.h"
#include "SDK/GWorld.h"

#include <iostream>
#define VmpStr(str) (VMProtectDecryptStringA(str))

class Options
{
public:
	bool StartHack = false;
	bool aimbot = true;
	FColor* BotColor = new FBLUE_BLUE;
	FColor* HumColor = new FPURPLE_BLUEVIOLET;
	FColor* VisColor = new FRED_RED;
	int aimbot_part = 4;
	int aimbot_second_part = 6;
	float aimbot_radius = 500.f;
	float maxBoneDis = 75.f;
	bool bone = true;
	int aimbot_speed = 4;
};

class Global
{
public:
	Memory* GMemory = new Memory();
	Overlay* Canvas = new Overlay();
	Renderer* Draw = new Renderer();
	Names* GNames = new Names();
	UWorld* GWorld = new UWorld();
	Options* Option = new Options();

	LPCSTR WindowsClass = VmpStr("UnrealWindow");
	LPCSTR WindowsCaption = VmpStr("PUBG LITE ");
	LPCSTR M_Name = VmpStr("zb");
};

extern Global LiteHack;

template<class T>
T TArray<T>::GetById(int i)
{
	return LiteHack.GMemory->Read<T>(m_Data + i * 8);
}

void MainLoop();