#include "../Global.h"

FMinimalViewInfo APlayerCameraManager::MinimalViewInfo()
{
	return
	{
		ReadOffset<FVector>(Off::CameraCache_POV_Location),
		ReadOffset<FRotator>(Off::CameraCache_POV_Rotation),
		ReadOffset<float>(Off::CameraCache_POV_FOV)
	};
}

template<typename T>
inline T Base::ReadOffset(uint64_t offset)
{
	return LiteHack.GMemory->Read<T>(base_address + offset);
}

template<typename T>
inline bool Base::WriteOffset(uint64_t offset, T value)
{
	return LiteHack.GMemory->Write<T>(base_address + offset, value);
}

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

int AActor::ComparisonIndex()
{
	return Dec::ObjID(ReadOffset<int>(Off::ComparisonIndex));
}

USkeletalMeshComponent AActor::Mesh()
{
	return USkeletalMeshComponent(Dec::pawn(ReadOffset<uint64_t>(Off::Mesh)));
}

USceneComponent AActor::RootComponent()
{
	return USceneComponent(Dec::pawn(ReadOffset<uint64_t>(Off::RootComponent)));
}

uint8_t ASTExtraWheeledVehicle::VehicleShapeType()
{
	return ReadOffset<uint8_t>(Off::VehicleShapeType);
}

bool ASTExtraPlayerCharacter::IsAI()
{
	return ReadOffset<bool>(Off::bIsAI);
}

int ASTExtraPlayerCharacter::TeamID()
{
	return ReadOffset<int>(Off::TeamID);
}

float ASTExtraPlayerCharacter::Health()
{
	return ReadOffset<float>(Off::Health);
}

FString ASTExtraPlayerCharacter::PlayerName()
{
	return ReadOffset<FString>(Off::PlayerName);
}

uint32_t ASTExtraPlayerCharacter::PlayerKey()
{
	return ReadOffset<uint32_t>(Off::PlayerKey);
}

int ASTExtraPlayerCharacter::SpectatedCount()
{
	return ReadOffset<int>(Off::SpectatedCount);
}

int ASTExtraPlayerCharacter::VehicleSeatIdx()
{
	return ReadOffset<int>(Off::VehicleSeatIdx);
}

bool ASTExtraPlayerCharacter::IsWeaponFiring()
{
	return ReadOffset<bool>(Off::bIsWeaponFiring);
}

uint8_t ASTExtraPlayerCharacter::HealthStatus()
{
	return ReadOffset<uint8_t>(Off::HealthStatus);
}

int ASTExtraPlayerCharacter::LocalSimulateStates()
{
	return ReadOffset<int>(Off::LocalSimulateStates);
}

APlayerController ASTExtraPlayerCharacter::STPlayerController()
{
	return APlayerController(ReadOffset<uint64_t>(Off::STPlayerController));
}

ASTExtraWheeledVehicle ASTExtraPlayerCharacter::CurrentVehicle()
{
	return ASTExtraWheeledVehicle(ReadOffset<uint64_t>(Off::CurrentVehicle));
}

UWeaponManagerComponent ASTExtraPlayerCharacter::WeaponManagerComponent()
{
	return UWeaponManagerComponent(ReadOffset<uint64_t>(Off::WeaponManagerComponent));
}

ASTExtraWeapon UWeaponManagerComponent::CurrentWeapon()
{
	return ASTExtraWeapon(ReadOffset<uint64_t>(Off::CurrentWeaponReplicated));
}

UShootWeaponEntity ASTExtraWeapon::WeaponEntityComp()
{
	return UShootWeaponEntity(ReadOffset<uint64_t>(Off::WeaponEntityComp));
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

FVector USceneComponent::ComponentVelocity()
{
	return ReadOffset<FVector>(Off::ComponentVelocity);
}

FVector USceneComponent::Location()
{
	return ReadOffset<FVector>(Off::RelativeLocation);
}