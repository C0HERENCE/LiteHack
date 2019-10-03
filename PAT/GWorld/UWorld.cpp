#include "UWorld.h"

UWorld::UWorld()
{
	pULevel = 0;
	pGameInstance = 0;
}
UWorld::UWorld(uint64 address)
{
	pULevel = GameMemory.Read64(GameMemory.Read64(address) + off_ULevel);
	pGameInstance = GameMemory.Read64(GameMemory.Read64(address) + off_ULevel);
}