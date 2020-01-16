#pragma once
#include "IDA.h"
#include "Core.h"
class Off
{
public:
	// Main
	static const uint64_t UWorld = 0x44D1F78;
	static const uint64_t GNames = 0x45e7420;
	static const uint64_t StaticGNames = 0x86AF8;
	static const uint64_t ChunkSize = 0x40f0;
	static const uint64_t ulevel = 232;
	static const uint64_t gameinstance = 2936;
	static const uint64_t actor = 280;
	static const uint64_t localplayer = 560;
	static const uint64_t playerconroller = 56;
	static const uint64_t ComparisonIndex = 0x18;

	static const uint64_t RootComponent = 0x268; // Actor -> RootComponent
	static const uint64_t WeaponEntityComp = 0x418; // STExtraWeapon -> WeaponEntityComp
	static const uint64_t ComponentVelocity = 0x220; // SceneComponent -> ComponentVelocity
	static const uint64_t RelativeLocation = 0x110; // SceneComponent -> RelativeLocation
	static const uint64_t Mesh = 0x430; // Character -> Mesh
	static const uint64_t bIsAI = 0x820; // UAECharacter -> bIsAI
	static const uint64_t TeamID = 0x814; // UAECharacter -> TeamID
	static const uint64_t PlayerKey = 0x80c; // UAECharacter -> PlayerKey
	static const uint64_t PlayerName = 0x7f8; // UAECharacter -> PlayerName
	static const uint64_t SpectatedCount = 0x1dc8; // STExtraBaseCharacter -> SpectatedCount
	static const uint64_t STCharacterMovement = 0x1a90; // STExtraBaseCharacter -> STCharacterMovement
	static const uint64_t WeaponManagerComponent = 0x1710; // STExtraBaseCharacter -> WeaponManagerComponent
	static const uint64_t VehicleSeatIdx = 0x16d4; // STExtraBaseCharacter -> VehicleSeatIdx
	static const uint64_t HealthStatus = 0x1621; // STExtraBaseCharacter -> HealthStatus
	static const uint64_t Health = 0x119c; // STExtraBaseCharacter -> Health
	static const uint64_t bIsWeaponFiring = 0x10b0; // STExtraBaseCharacter -> bIsWeaponFiring
	static const uint64_t CurrentVehicle = 0xd20; // STExtraBaseCharacter -> CurrentVehicle
	static const uint64_t LocalSimulateStates = 0xc30; // STExtraBaseCharacter -> LocalSimulateStates
	static const uint64_t SkydivingComponent = 0x20a8; // STExtraPlayerCharacter -> SkydivingComponent
	static const uint64_t STPlayerController = 0x2020; // STExtraPlayerCharacter -> STPlayerController
	static const uint64_t PlayerCameraManager = 0x478; // PlayerController -> PlayerCameraManager
	static const uint64_t STExtraBaseCharacter = 0x1d18; // STExtraPlayerController -> STExtraBaseCharacter
	static const uint64_t CurrentWeaponReplicated = 0x520; // WeaponManagerComponent -> CurrentWeaponReplicated
	static const uint64_t Rotation = 0x20; // MinimalViewInfo -> Rotation
	static const uint64_t FOV = 0x10; // MinimalViewInfo -> FOV
	static const uint64_t Location = 0x4; // MinimalViewInfo -> Location
	static const uint64_t POV = 0x10; // CameraCacheEntry -> POV
	static const uint64_t SwayMultiplier = 0x248; // WeaponAttachmentData -> SwayMultiplier
	static const uint64_t RecoilMultiplierVertical = 0x8c; // WeaponAttachmentData -> RecoilMultiplierVertical
	static const uint64_t MultipleFiringBulletsSpread = 0x6c; // WeaponAttachmentData -> MultipleFiringBulletsSpread
	static const uint64_t AnimationKickMultiplier = 0x68; // WeaponAttachmentData -> AnimationKickMultiplier
	static const uint64_t LastRenderTime = 0x328; // PrimitiveComponent -> LastRenderTime
	static const uint64_t ArrTslWeaponAttachmentData = 0x2f0; // WeaponEntity -> ArrTslWeaponAttachmentData
	static const uint64_t CameraCache = 0xfb0; // PlayerCameraManager -> CameraCache
	static const uint64_t JumpZVelocity = 0x1bc; // CharacterMovementComponent -> JumpZVelocity
	static const uint64_t VehicleShapeType = 0x429; // STExtraVehicleBase -> VehicleShapeType
	static const uint64_t MinWalkSpeedModifier = 0x83c; // STCharacterMovementComponent -> MinWalkSpeedModifier
	static const uint64_t WalkSpeedCurveScale = 0x82c; // STCharacterMovementComponent -> WalkSpeedCurveScale
	static const uint64_t FreefallVelocitySettings = 0xac8; // TslSkydiveComponent -> FreefallVelocitySettings
	static const uint64_t BulletFireSpeed = 0x628; // ShootWeaponEntity -> BulletFireSpeed
	static const uint64_t bHasAutoFireMode = 0x5a8; // ShootWeaponEntity -> bHasAutoFireMode

	static const uint64_t FWeaponAttachmentData_SwayMultiplier = 0x38 + SwayMultiplier;
	static const uint64_t FWeaponAttachmentData_RecoilMultiplierVertical = 0x38 + RecoilMultiplierVertical;
	static const uint64_t FWeaponAttachmentData_AnimationKickMultiplier = 0x38 + AnimationKickMultiplier;
	static const uint64_t FWeaponAttachmentData_MultipleFiringBulletsSpread = 0x38 + MultipleFiringBulletsSpread;
	static const uint64_t CameraCache_POV_Location = CameraCache + POV + Location;
	static const uint64_t CameraCache_POV_Rotation = CameraCache + POV + Rotation;
	static const uint64_t CameraCache_POV_FOV = CameraCache + POV + FOV;
	static const uint64_t FreefallVelocitySettings_SpeedMax = FreefallVelocitySettings + 0x0004;

	static const uint64_t BoneArray = 0x708;
	static const uint64_t ComponentToWorld = 416;
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