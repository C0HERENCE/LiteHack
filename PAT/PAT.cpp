#pragma once
#include <iostream>
#include <Windows.h>
#include <Psapi.h>
#include "MemoryHelper.h"
#include "Lite.h"
#include "GNames.h"
#include <string>
#include "GObjects.h"

using namespace std;

HANDLE hProcess = NULL;
LPVOID lpBase = nullptr;
uint64 Base = 0;
MemoryHelper mh;
int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Please run \"HLeaker.exe\" first." << std::endl;
		system("pause");
		return 0;
	}
	hProcess = reinterpret_cast<void*>(atoi(argv[1]));
	mh = MemoryHelper(hProcess);

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
				break;
			}
		}
	}
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
	GNames g;
	cout << hex << g.DecryptGNames(Base + 0x46546C0) << endl;
	cout << g.GetActorNameFromID(16759) << endl;
	cout << g.GetActorNameFromID(16761) << endl;
	cout << dec << "===================================" << endl;
	
	OffsetDumper od;
	od.Dump();
	
	system("pause");
	return 0;
}