#pragma once
#include "GWorld/UWorld.h"
#include "GObjects/Generator.h"
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

int Initialize(int, char**);
void DebugInfromation(UWorld&, NamesStore&, ObjectsStore&);

std::unordered_set<std::string> gMembers =
{"Owner","RootComponent"};
std::unordered_set<std::string> gClasses =
{"USceneComponent",""};


int main(int argc, char** argv)
{
	if (!Initialize(argc, argv)) return 0;

	GWorld = UWorld(GameBaseAddress + off_UWorld);
	GlobalNames = NamesStore(GameBaseAddress + off_GNames);
	GlobalObjects = ObjectsStore(GameBaseAddress + off_GObjects);


	DebugInfromation(GWorld, GlobalNames, GlobalObjects);
	Generator generator;
	fs::path outputDirectory("E:\\Desktop\\DUMP");
	generator.Dump(outputDirectory);
	//generator.ProcessPackages(outputDirectory, "ShadowTrackerExtra", "STExtraPlayerCharacter");//STExtraPlayerCharacter > STExtraPlayerCharacter > ASTExtraBaseCharacter
	//generator.ProcessPackages(outputDirectory, "ShadowTrackerExtra", "STExtraPlayerController");//STExtraPlayerCharacter > STExtraPlayerCharacter > ASTExtraBaseCharacter
	//generator.ProcessPackages(outputDirectory, "ShadowTrackerExtra", "STExtraPlayerState");//STExtraPlayerCharacter > STExtraPlayerCharacter > ASTExtraBaseCharacter
	//generator.ProcessPackages(outputDirectory, "ShadowTrackerExtra", "WeaponOwnerProxy");//STExtraPlayerCharacter > STExtraPlayerCharacter > ASTExtraBaseCharacter
	//generator.ProcessPackages(outputDirectory, "ShadowTrackerExtra", "CharacterWeaponManagerComponent");//STExtraPlayerCharacter > STExtraPlayerCharacter > ASTExtraBaseCharacter
	//generator.ProcessPackages(outputDirectory, "ShadowTrackerExtra", "UMoveAntiCheatComponent");//STExtraPlayerCharacter > STExtraPlayerCharacter > ASTExtraBaseCharacter
	//generator.ProcessPackages(outputDirectory, "ShadowTrackerExtra", "STExtraWheeledVehicle");//STExtraPlayerCharacter > STExtraPlayerCharacter > ASTExtraBaseCharacter
	//generator.ProcessPackages(outputDirectory, "ShadowTrackerExtra", "STExtraWheeledVehicle");//STExtraPlayerCharacter > STExtraPlayerCharacter > ASTExtraBaseCharacter
	//generator.ProcessPackages(outputDirectory,"ShadowTrackerExtra","SkeletalMeshComponent");//STExtraPlayerCharacter > STExtraPlayerCharacter > ASTExtraBaseCharacter
	//generator.ProcessPackages(outputDirectory, "ShadowTrackerExtra", "STExtraShootWeapon");//STExtraPlayerCharacter > STExtraPlayerCharacter > ASTExtraBaseCharacter
	//generator.ProcessPackages(outputDirectory,"ShadowTrackerExtra","ETeamNumber");//STExtraPlayerCharacter > STExtraPlayerCharacter > ASTExtraBaseCharacter
	//generator.ProcessPackages(outputDirectory, "Gameplay", "UAECharacter");// > UAECharacter
	//generator.ProcessPackages(outputDirectory, "Engine", "Character");// > ACharacter > APawn > AActor > UObject
	//"STExtraPlayerController", "STExtraPlayerState","WeaponOwnerProxy","CharacterWeaponManagerComponent","AnimStatusKeyList","UMoveAntiCheatComponent","STExtraWheeledVehicle","SkeletalMeshComponent","STExtraShootWeapon";
	//"ETeamNumber";

	//generator.ProcessPackages(outputDirectory);
	system("pause");
}

int Initialize(int argc, char** argv)
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
	std::cout << "Actor Address: ";
	std::cout << std::hex <<GWorld.GetLevel().GetActors().GetAddress() <<std::dec << std::endl;
	std::cout << "Actor Count: ";
	std::cout << GWorld.GetLevel().GetActors().Length() << std::endl;
	std::cout << "Actor Name: ";
	//std::cout << std::hex << (GWorld.GetLevel().GetActors().GetById(19).PlayerName()) <<std::dec << std::endl;
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