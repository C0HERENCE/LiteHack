#pragma once
#include "GWorld/UWorld.hpp"
#include "GObjects/GObjects.h"
#include <Psapi.h>

#define off_UWorld 0x43CDF38
#define off_GNames 0x46546C0
#define off_GObjects 0x43C9C20

HANDLE GameProcessHandle = NULL;
uint64 GameBaseAddress = 0;

Memory GameMemory;
UWorld GWorld;
GNames NameStore;
GObjects ObjectStore;

int CheckEnvironment(int, char**);
void DebugInfromation(UWorld&, GNames&, GObjects&);


int main(int argc, char** argv)
{
	if (CheckEnvironment(argc, argv) != 1) return -1;

	GWorld = UWorld(GameBaseAddress + off_UWorld);
	NameStore = GNames(GameBaseAddress + off_GNames);
	ObjectStore = GObjects(GameBaseAddress+off_GObjects);
	DebugInfromation(GWorld, NameStore, ObjectStore);
	system("pause");
}

int CheckEnvironment(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Please run \"HLeaker.exe\" first." << std::endl;
		system("pause");
		return 0;
	}
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

void DebugInfromation(UWorld& GWorld,GNames& NameStore, GObjects& ObjectStore)
{
	std::cout << GWorld.GetLevel().GetActors().Length() << std::endl;
	std::cout << NameStore.GetActorNameFromID(0) << std::endl;
	std::cout << ObjectStore.ObjObjects.GetObjects(0).GetUObject().GetNameID() << std::endl;
}