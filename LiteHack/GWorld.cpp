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
	return Dec::ObjID(ReadOffset<int>(Off::ObjID));
}

UWeaponManagerComponent^ AActor::WeaponManagerComponent()
{
	return gcnew UWeaponManagerComponent(ReadOffset<uint64_t>(Off::WeaponManager));
}
USkeletalMeshComponent^ AActor::Mesh()
{
	return gcnew USkeletalMeshComponent(Dec::pawn(ReadOffset<uint64_t>(Off::Mesh)));
}

USceneComponent^ AActor::RootComponent()
{
	return gcnew USceneComponent(Dec::pawn(ReadOffset<uint64_t>(Off::RootComponent)));
}

APlayerController^ AActor::STPlayerController()
{
	return gcnew APlayerController(ReadOffset<uint64_t>(Off::STPlayerController));
}

FString AActor::PlayerName()
{
	return ReadOffset<FString>(Off::PlayerName);
}

float AActor::Health()
{
	return ReadOffset<float>(Off::Health);
}

bool AActor::IsWeaponFiring()
{
	return ReadOffset<bool>(Off::bIsWeaponFiring);
}

bool AActor::IsAI()
{
	return ReadOffset<bool>(Off::isAI);
}

int AActor::TeamID()
{
	return ReadOffset<int>(Off::teamID);
}

uint32_t AActor::PlayerKey()
{
	return ReadOffset<uint32_t>(Off::PlayerKey);
}

int AActor::SpectatedCount()
{
	return ReadOffset<int>(Off::SpectatedCount);
}

AActor^ AActor::CurrentVehicle()
{
	return gcnew AActor(ReadOffset<uint64_t>(Off::CurrentVehicle));
}

int AActor::VehicleSeatIdx()
{
	return ReadOffset<int>(Off::VehicleSeatIdx);
}

uint8_t AActor::HealthStatus()
{
	return ReadOffset<uint8_t>(Off::HealthStatus);
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
	return ReadOffset<float>(Off::LastRenderedTime);
}

// UWeaponManagerComponent
ASTExtraWeapon^ UWeaponManagerComponent::CurrentWeapon()
{
	return gcnew ASTExtraWeapon(ReadOffset<uint64_t>(Off::CurrentWeaponReplicated));
}

UShootWeaponEntity^ ASTExtraWeapon::WeaponEntityComp()
{
	return gcnew UShootWeaponEntity(ReadOffset<uint64_t>(Off::WeaponEntity));
}

// FWeaponAttachmentData
void FWeaponAttachmentData::SetZero()
{
	Global::GMemory->Write<float>(base_address + Off::AnimationKickMultiplier, 0.f);
	Global::GMemory->Write<float>(base_address + Off::RecoilMultiplierVertical, 0.f);
	Global::GMemory->Write<float>(base_address + Off::MultipleFiringBulletsSpread, 0.f);
	Global::GMemory->Write<float>(base_address + Off::SwayMultiplier, 0.f);
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
AActor^ APlayerController::LocalPawn()
{
	return gcnew AActor(ReadOffset<uint64_t>(Off::local_pawn));
}

APlayerCameraManager^ APlayerController::CameraCache()
{
	return gcnew APlayerCameraManager(ReadOffset<uint64_t>(Off::CameraManager));
}

// APlayerCameraManager
Off::FMinimalViewInfo APlayerCameraManager::MinimalViewInfo()
{
	return ReadOffset<Off::FMinimalViewInfo>(Off::CameraCache);
}