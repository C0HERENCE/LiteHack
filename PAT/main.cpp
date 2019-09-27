#pragma once
#include <iostream>
#include <Windows.h>
#include <Psapi.h>
#include <string>
#include "Utils/MemoryHelper.h"
#include "GWorld/GWorld.h"
#include "GNames/GNames.h"
#include "GObjects/GObjects.h"

using namespace std;

HANDLE hProcess = NULL;
LPVOID lpBase = nullptr;
uint64 Base = 0;
MemoryHelper mem;

#define off_UWorld 0x43CDF38
#define off_GNames 0x46546C0
#define off_GObjects 0x43C9C20

UWorld GWorld;
GNames NameStore;
GObjects ObjectStore;

int CheckEnvironment(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Please run \"HLeaker.exe\" first." << std::endl;
		system("pause");
		return 0;
	}
	hProcess = reinterpret_cast<void*>(atoi(argv[1]));
	mem = MemoryHelper(hProcess);

	//
	HMODULE hMods[512];
	DWORD cb;
	if (EnumProcessModulesEx(hProcess, hMods, sizeof(hMods), &cb, LIST_MODULES_ALL))
	{
		char szModName[MAX_PATH] = { NULL };
		for (int i = 0; i < cb / sizeof(HMODULE); i++)
		{
			GetModuleBaseNameA(hProcess, hMods[i], szModName, MAX_PATH);
			if (!strcmp(szModName, "PUBGLite-Win64-Shipping.exe"))
			{
				std::cout << "MoudleBase: 0x" << hMods[i] << " Process: " << szModName << std::endl;
				lpBase = hMods[i];
				Base = (uint64)lpBase;
				return 1;
			}
		}
	}
}

void DebugInfromation(UWorld& GWorld,GNames& NameStore, GObjects& ObjectStore)
{
	/*
	cout << dec << "===================================" << endl;
	std::string sb;
	uint64 GWorld = mh.Read64(Base + 0x44DAAA8);
	UWorld pUWorld = mh.Read<UWorld>(GWorld);
	cout << dec << pUWorld.GetLevel().GetActors().Length() << endl;
	cout << dec << pUWorld.GetLevel().GetActors().IsValidIndex(20) << endl;
	cout << dec << pUWorld.GetLevel().GetActors().IsValid() << endl;
	cout << dec << pUWorld.GetLevel().GetActors().GetValue(20).GetID() << endl;
	cout << dec << "==================================="<< endl;
	*/
	cout << NameStore.GetActorNameFromID(16759) << endl;
	cout << NameStore.GetActorNameFromID(16761) << endl;
	cout << ObjectStore.ObjObjects.GetObjects(0).GetUObject().GetNameID() << endl;
}

int main(int argc, char** argv)
{
	if (CheckEnvironment(argc, argv) != 1) return -1;

	GWorld= mem.Read<UWorld>(mem.Read64(Base + off_UWorld));
	NameStore = GNames(Base + off_GNames);
	ObjectStore = GObjects(Base+off_GObjects);

	DebugInfromation(GWorld, NameStore, ObjectStore);
	
	//ObjectStore.Dump();
	system("pause");
	return 0;
}