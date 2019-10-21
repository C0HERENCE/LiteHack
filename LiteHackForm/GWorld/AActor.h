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
		return updates::dec::comparison_id(GameMemory.Read32(base +updates::off::name +updates::off::comparison_id));
	}
	UWeaponManagerComponent WeaponManagerComponent()
	{
		return UWeaponManagerComponent(GameMemory.Read64(base + updates::off::WeaponManager));
	}

	USkeletalMeshComponent Mesh()
	{
		return USkeletalMeshComponent(updates::dec::pawn(GameMemory.Read64(base + updates::off::Mesh)));
	}

	USceneComponent RootComponent()
	{
		return USceneComponent(updates::dec::pawn(GameMemory.Read64(base + updates::off::RootComponent)));
	}

	FString PlayerName()
	{
		return GameMemory.Read<FString>(base + updates::off::PlayerName);
	}
	
	float Health()
	{
		return GameMemory.Read<float>(base + updates::off::Health);
	}
	
	bool IsWeaponFiring()
	{
		return GameMemory.Read<bool>(base + updates::off::bIsWeaponFiring);
	}

	bool IsAI()
	{
		return GameMemory.Read<bool>(base + updates::off::isAI);
	}

	int TeamID()
	{
		return GameMemory.Read<bool>(base + updates::off::teamID);
	}
	
	bool InDoor()
	{
		return GameMemory.Read<bool>(base + updates::off::Indoor);
	}
};