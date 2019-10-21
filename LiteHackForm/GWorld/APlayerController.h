#pragma once
#include "FCameraCacheEntry.h"

class APlayerController : public Base
{
public:
	using Base::Base;
	
	AActor LocalPawn()
	{
		return AActor(GameMemory.Read64(base + updates::off::local_pawn));
	}
	TArray<ASTExtraWeapon*> NowShotWeaponList()
	{
		return GameMemory.Read<TArray<ASTExtraWeapon*>>(base + updates::off::NowShotWeaponList);
	}

	APlayerCameraManager CameraCache()
	{
		return APlayerCameraManager(GameMemory.Read64(base + updates::off::CameraManager));
	}
};