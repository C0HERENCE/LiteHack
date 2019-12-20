#pragma once
#include "IDA.h"
#include "Core.h"
class Off
{
public:
	// Main
	static const uint64_t UWorld = 0x477BB38;
	static const uint64_t GNames = 0x470c7d0;
	static const uint64_t StaticGNames = 0xFFFFFFFFFFEFE4B8;
	static const uint64_t ChunkSize = 0x4100;
	// UWorld
	static const uint64 ulevel = 0x110;
	static const uint64 gameinstance = 0xAD8;
	// ULevel
	static const uint64 actor = 0x100;
	// UGameInstance
	static const uint64 localplayer = 0x100;
	// ULocalPlayer
	static const uint64 playerconroller = 0x38;
	// APlayerController
	static const uint64 CameraManager = 0x460; // APlayerController -> PlayerCameraManager
	static const uint64 CameraCache_POV_Location = 0x1610 + 0x10 + 0x0;
	static const uint64 CameraCache_POV_Rotation = 0x1610 + 0x10 + 0x28;
	static const uint64 CameraCache_POV_FOV = 0x1610 + 0x10 + 0x38;
	// ULocalPlayer
	static const uint64 STExtraBaseCharacter = 0x15F8; // ASTExtraPlayerController -> STExtraBaseCharacter
	// AActor
	static const uint64 ComparisonIndex = 0xc;
	static const uint64 RootComponent = 0x02D8; // AActor -> RootComponent
	static const uint64 Mesh = 0x0418; // ACharacter -> Mesh
	// STExtraPlayerCharacter
	static const uint64 PlayerName = 0x0810; // AUAECharacter -> PlayerName
	static const uint64 PlayerKey = 0x07EC; // AUAECharacter -> PlayerKey
	static const uint64 teamID = 0x07F4; // AUAECharacter -> TeamID
	static const uint64 isAI = 0x082C; // AUAECharacter -> bIsAI
	
	static const uint64 Health = 0x0C4C; // STExtraPlayerCharacter -> Health
	static const uint64 bIsWeaponFiring = 0x1818; // STExtraPlayerCharacter -> bIsWeaponFiring
	static const uint64 WeaponManagerComponent = 0x0D20; // STExtraPlayerCharacter -> WeaponManagerComponent
	static const uint64 STPlayerController = 0x2068; // STExtraPlayerCharacter -> STPlayerController
	static const uint64 SpectatedCount = 0x1E18; // STExtraPlayerCharacter -> SpectatedCount
	static const uint64 CurrentVehicle = 0x0C78; // STExtraPlayerCharacter -> CurrentVehicle
	static const uint64 VehicleSeatIdx = 0x0B14; // STExtraPlayerCharacter -> VehicleSeatIdx
	static const uint64 HealthStatus = 0x193C; // STExtraPlayerCharacter -> HealthStatus
	static const uint64 SkydivingComponent = 0x20F0; // STExtraPlayerCharacter -> SkydivingComponent
	static const uint64 STCharacterMovement = 0x0D70; // STExtraPlayerCharacter -> STCharacterMovement
	static const uint64 LocalSimulateStates = 0x13B0; // STExtraPlayerCharacter -> LocalSimulateStates
	// USTCharacterMovementComponent
	static const uint64 JumpZVelocity = 0x01BC; // UCharacterMovementComponent -> JumpZVelocity
	static const uint64 WalkSpeedCurveScale = 0x082C; // USTCharacterMovementComponent -> WalkSpeedCurveScale
	static const uint64 MinWalkSpeedModifier = 0x083C; // USTCharacterMovementComponent -> MinWalkSpeedModifier
	// UTslSkydiveComponent
	static const uint64 FreefallVelocitySettings_SpeedMax = 0x0AC8 + 0x0004; // UTslSkydiveComponent -> FreefallVelocitySettings -> SpeedMax
	// ASTExtraWheeledVehicle
	static const uint64 VehicleShapeType = 0x0419; // ASTExtraVehicleBase -> VehicleShapeType
	// APickUpWrapperActor
	// USceneComponent
	static const uint64 RelativeLocation = 0x01B8; // USceneComponent -> RelativeLocation
	static const uint64 ComponentVelocity = 0x0138; // USceneComponent -> RelativeLocation
	// USkeletalMeshComponent
	static const uint64 BoneArray = 0x708;
	static const uint64 ComponentToWorld = 0x220;
	static const uint64 LastRenderTime = 0x0328; // UPrimitiveComponent -> LastRenderTime
	// UWeaponManagerComponent
	static const uint64 CurrentWeaponReplicated = 0x0520; // UWeaponManagerComponent -> CurrentWeaponReplicated
	// ASTExtraWeapon
	static const uint64 WeaponEntityComp = 0x04A0; // ASTExtraWeapon -> WeaponEntity
	// UShootWeaponEntity
	static const uint64 ArrTslWeaponAttachmentData = 0x0138; // UWeaponEntity -> ArrTslWeaponAttachmentData
	static const uint64 BulletFireSpeed = 0x054C; // UShootWeaponEntity -> BulletFireSpeed
	static const uint64 bHasAutoFireMode = 0x050C; // UShootWeaponEntity -> bHasAutoFireMode
	// FWeaponAttachmentData
	static const uint64 AnimationKickMultiplier = 0x38 + 0x00E4; // FWeaponAttachmentData -> AnimationKickMultiplier
	static const uint64 RecoilMultiplierVertical = 0x38 + 0x0114; // FWeaponAttachmentData -> RecoilMultiplierVertical
	static const uint64 MultipleFiringBulletsSpread = 0x38 + 0x00E0; // FWeaponAttachmentData -> MultipleFiringBulletsSpread
	static const uint64 SwayMultiplier = 0x38 + 0x01D8; // FWeaponAttachmentData -> SwayMultiplier
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