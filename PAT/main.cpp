#pragma once
#include "GWorld/UWorld.h"
#include "GObjects/Generator.h"
#include "LiteHack/HackManager.h"
#include <Psapi.h>

#define off_UWorld 0x4532298
#define off_GNames 0x46438d0
#define off_GObjects 0x4659e48

// Global Variable:
UWorld GWorld;
HackManager Hack;
Memory GameMemory;
NamesStore GlobalNames;
ObjectsStore GlobalObjects;
uint64 GameBaseAddress = 0;
HANDLE GameProcessHandle = NULL;

int Initialize(int, char**);
void DebugInfromation(UWorld&, NamesStore&, ObjectsStore&);
void GenerateSDK();

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Run from \"HLeaker.exe\"." << std::endl;
		system("pause");
		return 0;
	}
	if (!Initialize(argc, argv))
	{
		std::cout << "Initialize failed." << std::endl;
		system("pause");
		return 0;
	}

	GWorld = UWorld(GameBaseAddress + off_UWorld);
	GlobalNames = NamesStore(GameBaseAddress + off_GNames);
	GlobalObjects = ObjectsStore(GameBaseAddress + off_GObjects);

	//DebugInfromation(GWorld, GlobalNames, GlobalObjects);
	//GlobalObjects.Dump();
	GenerateSDK();
	system("pause");
	ULevel Level = GWorld.CurrentLevel();
	AActor LocalPlayer = GWorld.OwningGameInstance().LocalPlayer().PlayerController().LocalPawn();
	//Hack.Initialize();

	while (1)
	{
		break;
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
				if (info.rootScreenPos.X<0||info.rootScreenPos.X>Hack.Overlay().Width||info.rootScreenPos.Y<0||info.rootScreenPos.Y>Hack.Overlay().Height)
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
					if (NearestEnemy.GetAddress()==0)
					{
						NearestEnemy = actor;
						NearestDistance = info.Distance;
					}
					else if(info.Distance<NearestDistance)
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


int Initialize(int argc, char** argv)
{
	GameProcessHandle = reinterpret_cast<void*>(atoi(argv[1]));
	GameMemory = Memory(GameProcessHandle);
	HMODULE hMods[512];
	DWORD cb;
	LPVOID lpBase = nullptr;
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
				return 1;
			}
		}
	}
}

void GenerateSDK()
{
	Generator generator;
	fs::path outputDirectory("E:\\Desktop\\DUMP");
	generator.DumpSDK(outputDirectory);
}

void DebugInfromation(UWorld& GWorld,NamesStore& NameStore, ObjectsStore& ObjectStore)
{
	std::cout << " ===============GWorld==================="<< std::endl;
	std::cout << "ULevel Address: ";
	std::cout << std::hex << GWorld.CurrentLevel().GetAddress() << std::dec << std::endl;
	std::cout << "Actor Address: ";
	std::cout << std::hex << GWorld.CurrentLevel().Actors().GetAddress() << std::dec << std::endl;
	std::cout << "Actor Count: ";
	std::cout << GWorld.CurrentLevel().Actors().Length() << std::endl;
	std::cout << "UGameInstance Address: ";
	std::cout << std::hex << GWorld.OwningGameInstance().GetAddress() << std::dec << std::endl;
	std::cout << "LocalPlayer Address: ";
	std::cout << std::hex << GWorld.OwningGameInstance().LocalPlayer().GetAddress() << std::dec << std::endl;
	std::cout << "APlayerController Address: ";
	std::cout << std::hex << GWorld.OwningGameInstance().LocalPlayer().PlayerController().GetAddress() << std::dec << std::endl;
	std::cout << "LocalPawn Address: ";
	std::cout << std::hex << GWorld.OwningGameInstance().LocalPlayer().PlayerController().LocalPawn().GetAddress() << std::dec << std::endl;
	std::cout << "Mesh Adress: ";
	std::cout << std::hex << GWorld.OwningGameInstance().LocalPlayer().PlayerController().LocalPawn().Mesh().GetAddress() << std::dec << std::endl;
	GWorld.GameSate();
	std::cout << std::hex << GWorld.OwningGameInstance().LocalPlayer().PlayerController().LocalPawn().Mesh().GetAddress() << std::endl;
	std::cout << GWorld.OwningGameInstance().LocalPlayer().PlayerController().LocalPawn().Mesh().RecentlyRendered() << std::endl;
	std::cout << " ===============GNames==================" << std::endl;
	std::cout << "GNames Addr: ";
	std::cout << std::hex << NameStore.GetAddress() << std::dec << std::endl;
	std::cout << "Name: ";
	std::cout << NameStore.GetById(0) << std::endl;
	std::cout << " ===============GObjects=================" << std::endl;
	int i = 4;
	std::cout << "Obj Num: ";
	std::cout << std::dec << ObjectStore.GetObjectsNum() << std::endl;
	std::cout << "ID: ";
	std::cout << std::dec << ObjectStore.GetById(1).GetIndex() << std::endl;
	std::cout << "Name: ";
	std::cout << ObjectStore.GetById(1).GetName() << std::endl;
	std::cout << "Outer: ";
	std::cout << std::hex << ObjectStore.GetById(1).GetOuter().GetAddress() << std::dec<< std::endl;
	std::cout << "Class: ";
	std::cout << ObjectStore.GetById(1).GetClass().GetFullName() << std::endl;
	std::cout << "Full Name: ";
	std::cout << ObjectStore.GetById(1).GetFullName() << std::endl;
}