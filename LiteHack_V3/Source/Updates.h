#pragma once
#include "Memory/IDA.h"
#include "SDK/Core.h"

class Off
{
public:
	// Main
	static const uint64_t UWorld = 0x44CF998;
	static const uint64_t GNames = 0x4680CB0;
	static const uint64_t StaticGNames = 0x44338;
	static const uint64_t ChunkSize = 0x408C;
	static const uint64_t ulevel = 0xB80;
	static const uint64_t gameinstance = 0x2E0;
	static const uint64_t actor = 0x260;
	static const uint64_t localplayer = 0x100;
	static const uint64_t playerconroller = 0x30;
	static const uint64_t ComparisonIndex = 0xC;
	static const uint64_t RootComponent = 0x1f0; // Actor -> RootComponent
	static const uint64_t WeaponEntityComp = 0x3c0; // STExtraWeapon -> WeaponEntityComp
	static const uint64_t ComponentVelocity = 0x160; // SceneComponent -> ComponentVelocity
	static const uint64_t RelativeLocation = 0x108; // SceneComponent -> RelativeLocation
	static const uint64_t Mesh = 0x4c8; // Character -> Mesh
	static const uint64_t TeamID = 0x818; // UAECharacter -> TeamID
	static const uint64_t PlayerName = 0x808; // UAECharacter -> PlayerName
	static const uint64_t bIsAI = 0x800; // UAECharacter -> bIsAI
	static const uint64_t PlayerKey = 0x7f0; // UAECharacter -> PlayerKey
	static const uint64_t SpectatedCount = 0x1d98; // STExtraBaseCharacter -> SpectatedCount
	static const uint64_t bIsWeaponFiring = 0x1b3c; // STExtraBaseCharacter -> bIsWeaponFiring
	static const uint64_t Health = 0x18e4; // STExtraBaseCharacter -> Health
	static const uint64_t HealthStatus = 0x1490; // STExtraBaseCharacter -> HealthStatus
	static const uint64_t VehicleSeatIdx = 0x1450; // STExtraBaseCharacter -> VehicleSeatIdx
	static const uint64_t CurrentVehicle = 0x1448; // STExtraBaseCharacter -> CurrentVehicle
	static const uint64_t STCharacterMovement = 0x1138; // STExtraBaseCharacter -> STCharacterMovement
	static const uint64_t LocalSimulateStates = 0xee8; // STExtraBaseCharacter -> LocalSimulateStates
	static const uint64_t WeaponManagerComponent = 0x888; // STExtraBaseCharacter -> WeaponManagerComponent
	static const uint64_t SkydivingComponent = 0x2078; // STExtraPlayerCharacter -> SkydivingComponent
	static const uint64_t STPlayerController = 0x1f68; // STExtraPlayerCharacter -> STPlayerController
	static const uint64_t PlayerCameraManager = 0x470; // PlayerController -> PlayerCameraManager
	static const uint64_t STExtraBaseCharacter = 0xfb0; // STExtraPlayerController -> STExtraBaseCharacter
	static const uint64_t CurrentWeaponReplicated = 0x518; // WeaponManagerComponent -> CurrentWeaponReplicated
	static const uint64_t Rotation = 0x574; // MinimalViewInfo -> Rotation
	static const uint64_t Location = 0x568; // MinimalViewInfo -> Location
	static const uint64_t FOV = 0x560; // MinimalViewInfo -> FOV
	static const uint64_t POV = 0x10; // CameraCacheEntry -> POV
	static const uint64_t RecoilMultiplierVertical = 0x2b4; // WeaponAttachmentData -> RecoilMultiplierVertical
	static const uint64_t MultipleFiringBulletsSpread = 0x70; // WeaponAttachmentData -> MultipleFiringBulletsSpread
	static const uint64_t AnimationKickMultiplier = 0x64; // WeaponAttachmentData -> AnimationKickMultiplier
	static const uint64_t SwayMultiplier = 0x60; // WeaponAttachmentData -> SwayMultiplier
	static const uint64_t LastRenderTime = 0x318; // PrimitiveComponent -> LastRenderTime
	static const uint64_t VehicleShapeType = 0x419; // STExtraVehicleBase -> VehicleShapeType
	static const uint64_t CameraCache = 0xf80; // PlayerCameraManager -> CameraCache
	static const uint64_t FreefallVelocitySettings = 0xac8; // TslSkydiveComponent -> FreefallVelocitySettings
	static const uint64_t ArrTslWeaponAttachmentData = 0x110; // WeaponEntity -> ArrTslWeaponAttachmentData
	static const uint64_t BulletFireSpeed = 0x638; // ShootWeaponEntity -> BulletFireSpeed
	static const uint64_t bHasAutoFireMode = 0x414; // ShootWeaponEntity -> bHasAutoFireMode
	static const uint64_t JumpZVelocity = 0x1b4; // CharacterMovementComponent -> JumpZVelocity
	static const uint64_t MinWalkSpeedModifier = 0x83c; // STCharacterMovementComponent -> MinWalkSpeedModifier
	static const uint64_t WalkSpeedCurveScale = 0x82c; // STCharacterMovementComponent -> WalkSpeedCurveScale

	static const uint64_t FWeaponAttachmentData_SwayMultiplier = 0x38 + SwayMultiplier;
	static const uint64_t FWeaponAttachmentData_RecoilMultiplierVertical = 0x38 + RecoilMultiplierVertical;
	static const uint64_t FWeaponAttachmentData_AnimationKickMultiplier = 0x38 + AnimationKickMultiplier;
	static const uint64_t FWeaponAttachmentData_MultipleFiringBulletsSpread = 0x38 + MultipleFiringBulletsSpread;
	static const uint64_t CameraCache_POV_Location = CameraCache + POV + Location;
	static const uint64_t CameraCache_POV_Rotation = CameraCache + POV + Rotation;
	static const uint64_t CameraCache_POV_FOV = CameraCache + POV + FOV;
	static const uint64_t FreefallVelocitySettings_SpeedMax = FreefallVelocitySettings + 0x0004;

	static const uint64_t BoneArray = 0x06F8;
	static const uint64_t ComponentToWorld = 0x1B0;
};

class Dec
{
public:
	// UWorld
	static uint64_t ulevel(uint64 v25);
	static uint64_t gameinstance(uint64 v1);
	// ULevel
	static uint64_t actor(uint64 v28);
	// AActor
	static uint64_t pawn(uint64 v45);
	// UGameInstance
	static uint64_t localplayer(uint64 ENC);
	// ULocalPlayer
	static uint64_t playercontroller(uint64 v9);
	static int ObjID(uint32 ID);
};;