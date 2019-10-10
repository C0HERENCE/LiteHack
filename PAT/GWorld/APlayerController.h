#pragma once
#include "../Utils/MemoryHelper.h"
#include "FCameraCacheEntry.h"

class APlayerController : public Base
{
public:
	using Base::Base;
	
	AActor LocalPawn()
	{
		return AActor(GameMemory.Read64(base + off_LocalPawn));
	}
	TArray<ASTExtraWeapon*> NowShotWeaponList()
	{
		return GameMemory.Read<TArray<ASTExtraWeapon*>>(base + off_NowShotWeaponList);
	}

	APlayerCameraManager CameraCache()
	{
		return APlayerCameraManager(GameMemory.Read64(base + off_CameraManager));
	}
private:
	uint64 off_LocalPawn = 0x1050;
	uint64 off_NowShotWeaponList = 0xe98;
	uint64 off_CameraManager = 0x478;
};