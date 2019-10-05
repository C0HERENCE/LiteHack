#pragma once
#include "..//GObjects/GenericTypes.h"
#include "Core/DummyTypes.h"
#include "Core/EngineTypes.h"

class ASTExtraWeapon
{
	class UWeaponEntity* WeaponEntityComp;// 0x0438 sizeof (0x0008)
};

struct FAnimStatusKeyList
{
	unsigned char UnknownData00[0x10];// 0x0000 sizeof (0x0010) MISSED OFFSET
	class ASTExtraWeapon* EquipWeapon;// 0x0010 sizeof (0x0008)
	unsigned char UnknownData01[0x8];// 0x0018 sizeof (0x0008) MISSED OFFSET
};

class AActor : public UEObject
{
	using UEObject::UEObject;
public:
	FString GetPlayerName() const
	{
		return GameMemory.Read<FString>(base + off_PlayerName);
	}
	
	float GetHealth()
	{
		return GameMemory.Read<float>(base + off_Health);
	}
	
	bool IsWeaponFiring()
	{
		return GameMemory.Read<bool>(base + off_bIsWeaponFiring);
	}
private:
	uint64 base;

	uint64 off_PlayerName = 0x818;
	uint64 off_Health = 0x1700;
	uint64 off_bIsWeaponFiring = 0x1050;
	//WeaponManagerComponent(UCharacterWeaponManagerComponent)
	//WeaponManagerComponent -> CurrentWeaponReplicated(ASTExtraWeapon)
	//WeaponManagerComponent -> CurrentWeaponReplicated -> WeaponEntityComp(UWeaponEntity)
	//1ff1 Indoor
	//1fe8 playercontroller
	//804 teamid
	//4d8 Mesh(USkeletalMeshComponent) 
	//7d8 Mesh(USkeletalMeshComponent) -> bRecentlyRendered(bool)
	//3f8 PlayerState(APlayerState)
	//7e0 ai
};


class ASTExtraBaseCharacter
{
public:
	unsigned char bDead : 1;// 0x1238 sizeof (0x0001)
	unsigned char bDying : 1;// 0x17C0 sizeof (0x0001)               ²»ÊÇ ²ÐÑª
};