#pragma once
#include "..//GObjects/GenericTypes.h"
#include "USkeletalMeshComponent.h"
#include "UWeaponManagerComponent.h"
#include "USceneComponent.h"

class AActor : public Base
{
public:
	using Base::Base;
	UEObject GetUObject()
	{
		return UEObject(base);
	}
	int GetComparisonIndex()
	{
		return GameMemory.Read32(base + off_ObjID);
	}
	UWeaponManagerComponent WeaponManagerComponent()
	{
		return UWeaponManagerComponent(GameMemory.Read64(base + off_WeaponManager));
	}

	USkeletalMeshComponent Mesh()
	{
		__int64 v52;
		_int64 v43 = GameMemory.Read64(base + off_Mesh);
		LODWORD(v52) = (315787853 - (v43 ^ 0x800FC42)) ^ 0x802D89F3;
		HIDWORD(v52) = (294457613 - (HIDWORD(v43) ^ 0xA3D13917)) ^ 0x195C281A;
		return USkeletalMeshComponent(v52);
	}

	USceneComponent RootComponent()
	{
		__int64 v43 = GameMemory.Read64(base + off_RootComp);
		__int64 v52;
		LODWORD(v52) = (315787853 - (v43 ^ 0x800FC42)) ^ 0x802D89F3;
		HIDWORD(v52) = (294457613 - (HIDWORD(v43) ^ 0xA3D13917)) ^ 0x195C281A;
		return USceneComponent(v52);
	}

	FString PlayerName()
	{
		return GameMemory.Read<FString>(base + off_PlayerName);
	}
	
	float Health()
	{
		return GameMemory.Read<float>(base + off_Health);
	}
	
	bool IsWeaponFiring()
	{
		return GameMemory.Read<bool>(base + off_bIsWeaponFiring);
	}

	bool IsAI()
	{
		return GameMemory.Read<bool>(base + off_isAI);
	}

	int TeamID()
	{
		return GameMemory.Read<bool>(base + off_teamID);
	}
	
	bool InDoor()
	{
		return GameMemory.Read<bool>(base + off_Indoor);
	}
private:
	uint64 off_ObjID = 0xc;
	uint64 off_RootComp = 0x118;
	uint64 off_PlayerName = 0x818;
	uint64 off_Health = 0x1700;
	uint64 off_bIsWeaponFiring = 0x1050;
	uint64 off_Indoor = 0x1ff1; 
	uint64 off_teamID = 0x804;
	uint64 off_isAI = 0x7e0;
	uint64 off_Mesh = 0x4d8;
	uint64 off_WeaponManager = 0x1C98;
	//3f8 PlayerState(APlayerState)
};


class ASTExtraBaseCharacter
{
public:
	unsigned char bDead : 1;// 0x1238 sizeof (0x0001)
	unsigned char bDying : 1;// 0x17C0 sizeof (0x0001)               ²»ÊÇ ²ÐÑª
};