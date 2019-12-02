#pragma once
#include "IDA.h"
#include "Core.h"
class Off
{
public:
	static const uint64_t UWorld = 0x46ECBE8;
	static const uint64_t GNames = 0x4669C10;
	static const uint64_t StaticGNames = 0x8BC30;
	static const uint64_t ChunkSize = 0x3F94;

	// UWorld
	static const uint64 ulevel = 0xB08;
	static const uint64 gameinstance = 0xB10;
	// ULevel
	static const uint64 actor = 0xF0;
	// UGameInstance
	static const uint64 localplayer = 0x228;
	// ULocalPlayer
	static const uint64 playerconroller = 0x38;
	static const uint64 local_pawn = 0xa30;
	// APlayerController
	static const uint64 CameraManager = 0x470;
	static const uint64 CameraCache = 0x910;
	class FMinimalViewInfo
	{
	public:
		char pad_0x0000[0x4]; //0x0000
		FVector Location; //0x0004 
		char pad_0x0010[0x60]; //0x0010
		float FOV; //0x0070 
		char pad_0x0074[0x18]; //0x0074
		FRotator Rotation; //0x008C 
	};
	// AActor
	static const uint64 ObjID = 0x14;
	static const uint64 RootComponent = 0x0270;
	static const uint64 PlayerName = 0x07F0;
	static const uint64 Health = 0x0A28;
	static const uint64 bIsWeaponFiring = 0x0910;
	static const uint64 teamID = 0x0814;
	static const uint64 isAI = 0x0838;
	static const uint64 Mesh = 0x04E8;
	static const uint64 WeaponManager = 0x1CC0;
	static const uint64 PlayerKey = 0x0804;
	static const uint64 STPlayerController = 0x1FB8;
	static const uint64 SpectatedCount = 0x1E28;
	static const uint64 CurrentVehicle = 0x1788;
	static const uint64 VehicleSeatIdx = 0x1BFC;
	static const uint64 HealthStatus = 0x1B68;
	// USceneComponent
	static const uint64 RelativeLocation = 0x1A0;
	static const uint64 ComponentVelocity = 0x0118;
	// USkeletalMeshComponent
	static const uint64 BoneArray = 0x06f8;
	static const uint64 ComponentToWorld = 0x01F0;
	static const uint64 LastRenderedTime = 0x0318;
	// UWeaponManagerComponent
	static const uint64 CurrentWeaponReplicated = 0x0520;
	// ASTExtraWeapon
	static const uint64 WeaponEntity = 0x0560;
	// UShootWeaponEntity
	static const uint64 ArrTslWeaponAttachmentData = 0x01B0;
	static const uint64 BulletFireSpeed = 0x0588;
	static const uint64 bHasAutoFireMode = 0x0418;
	// FWeaponAttachmentData
	static const uint64 AnimationKickMultiplier = 0x0074;
	static const uint64 RecoilMultiplierVertical = 0x0108;
	static const uint64 MultipleFiringBulletsSpread = 0x0018;
	static const uint64 SwayMultiplier = 0x0070;

};

class Dec
{
public:
	// UWorld
	static uint64 ulevel(uint64 v25);
	static uint64 gameinstance(uint64 v1);
	// ULevel
	static uint64 actor(uint64 v28);
	// AActor
	static uint64 pawn(uint64 v45);
	// UGameInstance
	static uint64 localplayer(uint64 ENC);
	// ULocalPlayer
	static uint64 playercontroller(uint64 v9);
	static uint32 ObjID(uint32 ID);
};