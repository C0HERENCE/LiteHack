#pragma once
#include "IDA.h"
#include "Core.h"
class Off
{
public:
	// Main
	static const uint64_t UWorld = 0x450b2b8;
	static const uint64_t GNames = 0x46daa30;
	static const uint64_t StaticGNames = 0xFFFFFFFFFFECB538;
	static const uint64_t ChunkSize = 0x40e0;
	// UWorld
	static const uint64 ulevel = 0x328;
	static const uint64 gameinstance = 0x318;
	// ULevel
	static const uint64 actor = 0xB0;
	// UGameInstance
	static const uint64 localplayer = 0xc0;
	// ULocalPlayer
	static const uint64 playerconroller = 0x38;
	static const uint64 local_pawn = 0x1180;
	// APlayerController
	static const uint64 CameraManager = 0x468;
	static const uint64 CameraCache = 0x408;
	class FMinimalViewInfo
	{
	public:
		//FRotator Rotation; //0x008C 1128
		//char pad_0x0010[0x1c]; //0x0010
		//FVector Location; //0x0004 
		//char pad_0x0012[0x550]; //0x0010
		//float FOV; //0x0070 

		float FOV; //0x0000 
		char pad_0x0004[0x88]; //0x0004
		FRotator Rotation; //0x008C 
		char pad_0x0098[0x10]; //0x0098
		FVector Location; //0x00A8 
	};
	// AActor
	static const uint64 ComparisonIndex = 0x8;
	static const uint64 RootComponent = 0x0218;
	static const uint64 Mesh = 0x0498;
	// STExtraPlayerCharacter
	static const uint64 PlayerName = 0x0808;
	static const uint64 Health = 0x08DC;
	static const uint64 bIsWeaponFiring = 0x0EEC;
	static const uint64 teamID = 0x07F4;
	static const uint64 isAI = 0x07FA;
	static const uint64 WeaponManagerComponent = 0x1CB0;
	static const uint64 PlayerKey = 0x07D0;
	static const uint64 STPlayerController = 0x1FF8;
	static const uint64 SpectatedCount = 0x1DF8;
	static const uint64 CurrentVehicle = 0x1038;
	static const uint64 VehicleSeatIdx = 0x1020;
	static const uint64 HealthStatus = 0x18DE;
	// ASTExtraWheeledVehicle
	static const uint64 VehicleShapeType = 0x0419;
	// APickUpWrapperActor
	// USceneComponent
	static const uint64 RelativeLocation = 0x0150;
	static const uint64 ComponentVelocity = 0x0230;
	// USkeletalMeshComponent
	static const uint64 CachedBoneSpaceTransforms = 0x6f8;
	static const uint64 ComponentToWorld = 0x01c0;
	static const uint64 LastRenderTime = 0x0318;
	// UWeaponManagerComponent
	static const uint64 CurrentWeaponReplicated = 0x0520;
	// ASTExtraWeapon
	static const uint64 WeaponEntity = 0x09A0;
	// UShootWeaponEntity
	static const uint64 ArrTslWeaponAttachmentData = 0x0170;
	static const uint64 BulletFireSpeed = 0x0468;
	static const uint64 bHasAutoFireMode = 0x049C;
	// FWeaponAttachmentData
	static const uint64 AnimationKickMultiplier = 0x38 + 0x0154;
	static const uint64 RecoilMultiplierVertical = 0x38 + 0x0148;
	static const uint64 MultipleFiringBulletsSpread = 0x38 + 0x0080;
	static const uint64 SwayMultiplier = 0x38 + 0x0240;

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
};;