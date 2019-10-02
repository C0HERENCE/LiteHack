#pragma once
#include "GWorld/UWorld.hpp"
#include "GObjects/ObjectsStore.h"
#include "GObjects/Package.h"
#include <Psapi.h>

#define off_UWorld 0x4401688
#define off_GNames 0x461C070
#define off_GObjects 0x4505298

HANDLE GameProcessHandle = NULL;
uint64 GameBaseAddress = 0;

Memory GameMemory;
UWorld GWorld;
NamesStore GlobalNames;
ObjectsStore GlobalObjects;

int CheckEnvironment(int, char**);
void DebugInfromation(UWorld&, NamesStore&, ObjectsStore&);
void ProcessPackages();


int main(int argc, char** argv)
{
	if (CheckEnvironment(argc, argv) != 1) return -1;

	GWorld = UWorld(GameBaseAddress + off_UWorld);
	GlobalNames = NamesStore(GameBaseAddress + off_GNames);
	GlobalObjects = ObjectsStore(GameBaseAddress+off_GObjects);

	ProcessPackages();
	//DebugInfromation(GWorld, GlobalNames, GlobalObjects);
	//GlobalObjects.Dump();
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

void DebugInfromation(UWorld& GWorld,NamesStore& NameStore, ObjectsStore& ObjectStore)
{
	std::cout << " ===============GWorld==================="<< std::endl;
	std::cout << "Actor Count: ";
	std::cout << GWorld.GetLevel().GetActors().Length() << std::endl;
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
	for (int i = 0; i < 100; i++)
	{
		//std::cout << ObjectStore.GetById(i).GetFullName() << std::endl;
	}
}

void ProcessPackages()
{
	std::unordered_map<uint64, bool> processedObjects;
	std::unordered_set<uint64> packageObjects;
	for (int i = 0; i < GlobalObjects.GetObjectsNum(); i++)
	{
		if(!GlobalObjects.GetById(i).IsValid()) continue;
		processedObjects.insert({GlobalObjects.GetById(i).GetAddress(),false });
		auto package = GlobalObjects.GetById(i).GetPackageObject();
		if (!package.IsValid()) continue;
		packageObjects.insert(package.GetAddress());
	}
	std::cout << "Package Count: " << packageObjects.size() << std::endl;
	std::cout << "Objects Count: " << processedObjects.size() << std::endl;
	for (auto i : packageObjects)
	{
		auto package = Package(UEObject(i));
		package.Process(processedObjects);
		package.Save();
	}
}