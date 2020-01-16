#include "GWorld.h"
#include "Global.h"

// UWorld
void UWorld::Init(uint64_t address)
{
	base_address = Global::GMemory->Read64(base_address + address);
}

ULevel^ UWorld::CurrentLevel()
{
	return gcnew ULevel(Dec::ulevel(ReadOffset<uint64_t>(Off::ulevel)));
}

UGameInstance^ UWorld::OwningGameInstance()
{
	return gcnew UGameInstance(Dec::gameinstance(ReadOffset<uint64_t>(Off::gameinstance)));
}

// ULevel
TArray<uint64_t> ULevel::Actors()
{
	return Global::GMemory->Read<TArray<uint64_t>>(Dec::actor(ReadOffset<uint64_t>(Off::actor)));
}

// AActor
int AActor::ComparisonIndex()
{
	return Dec::ObjID(ReadOffset<int>(Off::ComparisonIndex));
}

USkeletalMeshComponent^ AActor::Mesh()
{
	return gcnew USkeletalMeshComponent(Dec::pawn(ReadOffset<uint64_t>(Off::Mesh)));
}

USceneComponent^ AActor::RootComponent()
{
	return gcnew USceneComponent(Dec::pawn(ReadOffset<uint64_t>(Off::RootComponent)));
}

// STExtraPlayer
UWeaponManagerComponent^ ASTExtraPlayerCharacter::WeaponManagerComponent()
{
	return gcnew UWeaponManagerComponent(ReadOffset<uint64_t>(Off::WeaponManagerComponent));
}

APlayerController^ ASTExtraPlayerCharacter::STPlayerController()
{
	return gcnew APlayerController(ReadOffset<uint64_t>(Off::STPlayerController));
}

FString ASTExtraPlayerCharacter::PlayerName()
{
	return ReadOffset<FString>(Off::PlayerName);
}

float ASTExtraPlayerCharacter::Health()
{
	return ReadOffset<float>(Off::Health);
}

bool ASTExtraPlayerCharacter::IsWeaponFiring()
{
	return ReadOffset<bool>(Off::bIsWeaponFiring);
}

bool ASTExtraPlayerCharacter::IsAI()
{
	return ReadOffset<bool>(Off::bIsAI);
}

int ASTExtraPlayerCharacter::TeamID()
{
	return ReadOffset<int>(Off::TeamID);
}

uint32_t ASTExtraPlayerCharacter::PlayerKey()
{
	return ReadOffset<uint32_t>(Off::PlayerKey);
}

int ASTExtraPlayerCharacter::SpectatedCount()
{
	return ReadOffset<int>(Off::SpectatedCount);
}

ASTExtraWheeledVehicle^ ASTExtraPlayerCharacter::CurrentVehicle()
{
	return gcnew ASTExtraWheeledVehicle(ReadOffset<uint64_t>(Off::CurrentVehicle));
}

int ASTExtraPlayerCharacter::VehicleSeatIdx()
{
	return ReadOffset<int>(Off::VehicleSeatIdx);
}

uint8_t ASTExtraPlayerCharacter::HealthStatus()
{
	return ReadOffset<uint8_t>(Off::HealthStatus);
}

int ASTExtraPlayerCharacter::LocalSimulateStates()
{
	return ReadOffset<int>(Off::LocalSimulateStates);
}

// ASTExtraWheeledVehicle


byte ASTExtraWheeledVehicle::VehicleShapeType()
{
	return ReadOffset<uint8_t>(Off::VehicleShapeType);
}

// USceneComponent
FVector USceneComponent::ComponentVelocity()
{
	return ReadOffset<FVector>(Off::ComponentVelocity);
}

FVector USceneComponent::Location()
{
	return ReadOffset<FVector>(Off::RelativeLocation);
}

// USkeletalMeshComponent
uint64_t USkeletalMeshComponent::BoneArray()
{
	return ReadOffset<uint64_t>(Off::BoneArray);
}

FTransform USkeletalMeshComponent::ComponentToWorld()
{
	return ReadOffset<FTransform>(Off::ComponentToWorld);
}

float USkeletalMeshComponent::LastRenderedTime()
{
	return ReadOffset<float>(Off::LastRenderTime);
}

// UWeaponManagerComponent
ASTExtraWeapon^ UWeaponManagerComponent::CurrentWeapon()
{
	return gcnew ASTExtraWeapon(ReadOffset<uint64_t>(Off::CurrentWeaponReplicated));
}

UShootWeaponEntity^ ASTExtraWeapon::WeaponEntityComp()
{
	return gcnew UShootWeaponEntity(ReadOffset<uint64_t>(Off::WeaponEntityComp));
}

// FWeaponAttachmentData
void FWeaponAttachmentData::SetZero()
{
	uint64_t add = base_address;
	uint64_t add2 = Global::GMemory->Read<uint64_t>(add);
	if (Global::Option->norecoil)
	{
		Global::GMemory->Write<float>(add2 + Off::FWeaponAttachmentData_RecoilMultiplierVertical, 0.f);
	}
	//return;
	if (Global::Option->noverticalrecoil)
	{
		Global::GMemory->Write<float>(add2 + Off::FWeaponAttachmentData_AnimationKickMultiplier, 0.f);
	}
	if (Global::Option->nospread)
	{
		Global::GMemory->Write<float>(add2 + Off::FWeaponAttachmentData_MultipleFiringBulletsSpread, 0.f);
	}
	if (Global::Option->nosway)
	{
		Global::GMemory->Write<float>(add2 + Off::FWeaponAttachmentData_SwayMultiplier, 0.f);
	}
}

float FWeaponAttachmentData::GetRecoilMultiplierVertical()
{
	uint64_t add = base_address;
	uint64_t add2 = Global::GMemory->Read<uint64_t>(add);
	return Global::GMemory->Read<float>(add2 + Off::FWeaponAttachmentData_RecoilMultiplierVertical);
}

TArray<uint64_t> UShootWeaponEntity::ArrTslWeaponAttachmentData()
{
	return ReadOffset<TArray<uint64_t>>(Off::ArrTslWeaponAttachmentData);
}

float UShootWeaponEntity::BulletFireSpeed()
{
	return ReadOffset<float>(Off::BulletFireSpeed);
}

bool UShootWeaponEntity::bHasAutoFireMode()
{
	return ReadOffset<bool>(Off::bHasAutoFireMode);
}

// UGameInstance
ULocalPlayer^ UGameInstance::LocalPlayer()
{
	return gcnew ULocalPlayer(Dec::localplayer(ReadOffset<uint64_t>(Off::localplayer)));
}

// ULocalPlayer
APlayerController^ ULocalPlayer::PlayerController()
{
	return gcnew APlayerController(Dec::playercontroller(ReadOffset<uint64_t>(Off::playerconroller)));
}

// APlayerController
ASTExtraPlayerCharacter^ APlayerController::LocalPawn()
{
	return gcnew ASTExtraPlayerCharacter(ReadOffset<uint64_t>(Off::STExtraBaseCharacter));
}

APlayerCameraManager^ APlayerController::CameraCache()
{
	return gcnew APlayerCameraManager(ReadOffset<uint64_t>(Off::PlayerCameraManager));
}

// APlayerCameraManager
FMinimalViewInfo APlayerCameraManager::MinimalViewInfo()
{
	return
	{
		ReadOffset<FVector>(Off::CameraCache_POV_Location),
		ReadOffset<FRotator>(Off::CameraCache_POV_Rotation),
		ReadOffset<float>(Off::CameraCache_POV_FOV)
	};
}