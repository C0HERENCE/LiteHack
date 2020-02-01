#include "../Global.h"

ASTExtraPlayerCharacter APlayerController::LocalPawn()
{
	return ASTExtraPlayerCharacter(ReadOffset<uint64_t>(Off::STExtraBaseCharacter));
}

APlayerCameraManager APlayerController::CameraCache()
{
	return APlayerCameraManager(ReadOffset<uint64_t>(Off::PlayerCameraManager));
}

void UWorld::Init(uint64_t address)
{
	base_address = LiteHack.GMemory->Read64(address);
}

ULevel UWorld::CurrentLevel()
{
	return ULevel(Dec::ulevel(ReadOffset<uint64_t>(Off::ulevel)));
}

UGameInstance UWorld::OwningGameInstance()
{
	return UGameInstance(Dec::gameinstance(ReadOffset<uint64_t>(Off::gameinstance)));
}

TArray<uint64_t> ULevel::Actors()
{
	return LiteHack.GMemory->Read<TArray<uint64_t>>(Dec::actor(ReadOffset<uint64_t>(Off::actor)));
}

ULocalPlayer UGameInstance::LocalPlayer()
{
	return ULocalPlayer(Dec::localplayer(ReadOffset<uint64_t>(Off::localplayer)));
}

APlayerController ULocalPlayer::PlayerController()
{
	return APlayerController(Dec::playercontroller(ReadOffset<uint64_t>(Off::playerconroller)));
}
