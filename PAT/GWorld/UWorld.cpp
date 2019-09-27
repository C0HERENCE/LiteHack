#include "UWorld.hpp"
UWorld::UWorld()
{

}
UWorld::UWorld(uint64 a)
{

}
ULevel UWorld::GetLevel() const
{
	return GameMemory.Read<ULevel>(this->m_pULevel);
}

UGameInstance UWorld::GetGameInstance() const
{
	return GameMemory.Read<UGameInstance>(this->m_pGameInstance);
}
