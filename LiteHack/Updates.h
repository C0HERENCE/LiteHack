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
	static const uint64_t ulevel = 0x110;
	static const uint64_t gameinstance = 0xAD8;
	static const uint64_t actor = 0x100;
	static const uint64_t localplayer = 0x100;
	static const uint64_t playerconroller = 0x38;
	static const uint64_t ComparisonIndex = 0xc;

	static const uint64_t RootComponent = 0x2d8; // Actor -> RootComponent
	static const uint64_t WeaponEntityComp = 0x4a0; // STExtraWeapon -> WeaponEntityComp
	static const uint64_t RelativeLocation = 0x1b8; // SceneComponent -> RelativeLocation
	static const uint64_t ComponentVelocity = 0x138; // SceneComponent -> ComponentVelocity
	static const uint64_t Mesh = 0x418; // Character -> Mesh
	static const uint64_t bIsAI = 0x82c; // UAECharacter -> bIsAI
	static const uint64_t PlayerName = 0x810; // UAECharacter -> PlayerName
	static const uint64_t TeamID = 0x7f4; // UAECharacter -> TeamID
	static const uint64_t PlayerKey = 0x7ec; // UAECharacter -> PlayerKey
	static const uint64_t SpectatedCount = 0x1e18; // STExtraBaseCharacter -> SpectatedCount
	static const uint64_t HealthStatus = 0x193c; // STExtraBaseCharacter -> HealthStatus
	static const uint64_t bIsWeaponFiring = 0x1818; // STExtraBaseCharacter -> bIsWeaponFiring
	static const uint64_t LocalSimulateStates = 0x13b0; // STExtraBaseCharacter -> LocalSimulateStates
	static const uint64_t STCharacterMovement = 0xd70; // STExtraBaseCharacter -> STCharacterMovement
	static const uint64_t WeaponManagerComponent = 0xd20; // STExtraBaseCharacter -> WeaponManagerComponent
	static const uint64_t CurrentVehicle = 0xc78; // STExtraBaseCharacter -> CurrentVehicle
	static const uint64_t Health = 0xc4c; // STExtraBaseCharacter -> Health
	static const uint64_t VehicleSeatIdx = 0xb14; // STExtraBaseCharacter -> VehicleSeatIdx
	static const uint64_t SkydivingComponent = 0x20f0; // STExtraPlayerCharacter -> SkydivingComponent
	static const uint64_t STPlayerController = 0x2068; // STExtraPlayerCharacter -> STPlayerController
	static const uint64_t PlayerCameraManager = 0x460; // PlayerController -> PlayerCameraManager
	static const uint64_t STExtraBaseCharacter = 0x15f8; // STExtraPlayerController -> STExtraBaseCharacter
	static const uint64_t CurrentWeaponReplicated = 0x520; // WeaponManagerComponent -> CurrentWeaponReplicated
	static const uint64_t LastRenderTime = 0x328; // PrimitiveComponent -> LastRenderTime
	static const uint64_t FOV = 0x38; // MinimalViewInfo -> FOV
	static const uint64_t Rotation = 0x28; // MinimalViewInfo -> Rotation
	static const uint64_t Location = 0x0; // MinimalViewInfo -> Location
	static const uint64_t POV = 0x10; // CameraCacheEntry -> POV
	static const uint64_t SwayMultiplier = 0x1d8; // WeaponAttachmentData -> SwayMultiplier
	static const uint64_t RecoilMultiplierVertical = 0x114; // WeaponAttachmentData -> RecoilMultiplierVertical
	static const uint64_t AnimationKickMultiplier = 0xe4; // WeaponAttachmentData -> AnimationKickMultiplier
	static const uint64_t MultipleFiringBulletsSpread = 0xe0; // WeaponAttachmentData -> MultipleFiringBulletsSpread
	static const uint64_t ArrTslWeaponAttachmentData = 0x138; // WeaponEntity -> ArrTslWeaponAttachmentData
	static const uint64_t CameraCache = 0x1610; // PlayerCameraManager -> CameraCache
	static const uint64_t VehicleShapeType = 0x419; // STExtraVehicleBase -> VehicleType
	static const uint64_t JumpZVelocity = 0x1bc; // CharacterMovementComponent -> JumpZVelocity
	static const uint64_t MinWalkSpeedModifier = 0x83c; // STCharacterMovementComponent -> MinWalkSpeedModifier
	static const uint64_t WalkSpeedCurveScale = 0x82c; // STCharacterMovementComponent -> WalkSpeedCurveScale
	static const uint64_t BulletFireSpeed = 0x54c; // ShootWeaponEntity -> BulletFireSpeed
	static const uint64_t bHasAutoFireMode = 0x50c; // ShootWeaponEntity -> bHasAutoFireMode
	static const uint64_t FreefallVelocitySettings = 0xac8; // TslSkydiveComponent -> FreefallVelocitySettings

	static const uint64_t FWeaponAttachmentData_SwayMultiplier = 0x38 + 0x1d8;
	static const uint64_t FWeaponAttachmentData_RecoilMultiplierVertical = 0x38 + 0x114;
	static const uint64_t FWeaponAttachmentData_AnimationKickMultiplier = 0x38 + 0xe4;
	static const uint64_t FWeaponAttachmentData_MultipleFiringBulletsSpread = 0x38 + 0xe0;
	static const uint64_t CameraCache_POV_Location = CameraCache + POV + Location;
	static const uint64_t CameraCache_POV_Rotation = CameraCache + POV + Rotation;
	static const uint64_t CameraCache_POV_FOV = CameraCache + POV + FOV;
	static const uint64_t FreefallVelocitySettings_SpeedMax = FreefallVelocitySettings + 0x0004;

	static const uint64_t BoneArray = 0x708;
	static const uint64_t ComponentToWorld = 0x220;
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