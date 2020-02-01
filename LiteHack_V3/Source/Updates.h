#pragma once
#include "Memory/IDA.h"
#include "SDK/Core.h"

class Off
{
public:
	// Main
	static const uint64_t UWorld = 0x45C80F8;
	static const uint64_t GNames = 0x453B6F0;
	static const uint64_t StaticGNames = 0x11EA78;
	static const uint64_t ChunkSize = 0x4030;
	static const uint64_t ulevel = 0x908;
	static const uint64_t gameinstance = 0x230;
	static const uint64_t actor = 0x228;
	static const uint64_t localplayer = 0x98;
	static const uint64_t playerconroller = 0x30;
	static const uint64_t ComparisonIndex = 0x14;
	static const uint64_t RootComponent = 0x148; // Actor -> RootComponent
	static const uint64_t WeaponEntityComp = 0x3f0; // STExtraWeapon -> WeaponEntityComp
	static const uint64_t ComponentVelocity = 0x1e0; // SceneComponent -> ComponentVelocity
	static const uint64_t RelativeLocation = 0x10c; // SceneComponent -> RelativeLocation
	static const uint64_t Mesh = 0x4c0; // Character -> Mesh
	static const uint64_t PlayerName = 0x838; // UAECharacter -> PlayerName
	static const uint64_t PlayerKey = 0x82c; // UAECharacter -> PlayerKey
	static const uint64_t bIsAI = 0x824; // UAECharacter -> bIsAI
	static const uint64_t TeamID = 0x820; // UAECharacter -> TeamID
	static const uint64_t SpectatedCount = 0x1dc8; // STExtraBaseCharacter -> SpectatedCount
	static const uint64_t CurrentVehicle = 0x1af0; // STExtraBaseCharacter -> CurrentVehicle
	static const uint64_t HealthStatus = 0x1add; // STExtraBaseCharacter -> HealthStatus
	static const uint64_t VehicleSeatIdx = 0x15d0; // STExtraBaseCharacter -> VehicleSeatIdx
	static const uint64_t STCharacterMovement = 0x15b0; // STExtraBaseCharacter -> STCharacterMovement
	static const uint64_t WeaponManagerComponent = 0xdd8; // STExtraBaseCharacter -> WeaponManagerComponent
	static const uint64_t bIsWeaponFiring = 0xc00; // STExtraBaseCharacter -> bIsWeaponFiring
	static const uint64_t LocalSimulateStates = 0xaac; // STExtraBaseCharacter -> LocalSimulateStates
	static const uint64_t Health = 0xa90; // STExtraBaseCharacter -> Health
	static const uint64_t SkydivingComponent = 0x20b0; // STExtraPlayerCharacter -> SkydivingComponent
	static const uint64_t STPlayerController = 0x2020; // STExtraPlayerCharacter -> STPlayerController
	static const uint64_t PlayerCameraManager = 0x478; // PlayerController -> PlayerCameraManager
	static const uint64_t STExtraBaseCharacter = 0x1bb8; // STExtraPlayerController -> STExtraBaseCharacter
	static const uint64_t CurrentWeaponReplicated = 0x518; // WeaponManagerComponent -> CurrentWeaponReplicated
	static const uint64_t FOV = 0x56c; // MinimalViewInfo -> FOV
	static const uint64_t Rotation = 0x560; // MinimalViewInfo -> Rotation
	static const uint64_t Location = 0x548; // MinimalViewInfo -> Location
	static const uint64_t POV = 0x10; // CameraCacheEntry -> POV
	static const uint64_t RecoilMultiplierVertical = 0x258; // WeaponAttachmentData -> RecoilMultiplierVertical
	static const uint64_t AnimationKickMultiplier = 0x250; // WeaponAttachmentData -> AnimationKickMultiplier
	static const uint64_t MultipleFiringBulletsSpread = 0x23c; // WeaponAttachmentData -> MultipleFiringBulletsSpread
	static const uint64_t SwayMultiplier = 0x1b0; // WeaponAttachmentData -> SwayMultiplier
	static const uint64_t LastRenderTime = 0x318; // PrimitiveComponent -> LastRenderTime
	static const uint64_t CameraCache = 0xa10; // PlayerCameraManager -> CameraCache
	static const uint64_t JumpZVelocity = 0x1b4; // CharacterMovementComponent -> JumpZVelocity
	static const uint64_t VehicleShapeType = 0x429; // STExtraVehicleBase -> VehicleShapeType
	static const uint64_t FreefallVelocitySettings = 0xac8; // TslSkydiveComponent -> FreefallVelocitySettings
	static const uint64_t ArrTslWeaponAttachmentData = 0x110; // WeaponEntity -> ArrTslWeaponAttachmentData
	static const uint64_t BulletFireSpeed = 0x6ac; // ShootWeaponEntity -> BulletFireSpeed
	static const uint64_t bHasAutoFireMode = 0x68c; // ShootWeaponEntity -> bHasAutoFireMode
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

	static const uint64_t BoneArray = 0x6F8;
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
	static uint32 ObjID(uint32 ID);
};;