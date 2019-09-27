#pragma once
#include "USceneComponent.hpp"
#include "USkeletalMeshComponent.hpp"
#include "AWeaponProcessor.hpp"
#include "UVehicleRiderComponent.hpp"
#include "UItem.hpp"

class AActor
{
public:
	int GetID() const;
	USceneComponent GetRootComponent() const;
	uint64 GetDroppedItems() const;
	int GetDroppedItemsCount() const;
	USkeletalMeshComponent GetSkeletalMeshComponent() const;
	AWeaponProcessor GetWeaponProcessor() const;
	bool InMyTeam() const;
	float GetHealth() const;
	float GetMaxHealth() const;
	float GetGroggyHealth() const;
	//UVehicleRiderComponent GetVehicleRiderComponent() const;
	TArray<UItem*> GetItems() const;
	static uint64 GetPunchDistanceOffset();

	operator bool() const
	{
		return m_nID != 0;
	}
	bool operator==(const AActor& rhs) const
	{
		return m_pRootComp == rhs.m_pRootComp;
	}
	bool operator!=(const AActor& rhs) const 
	{
		return m_pRootComp != rhs.m_pRootComp;
	}
private:
	char __pad0x18[0x1C];
	int m_nID;
	char __pad0x180[0x164];
	uint64 m_pRootComp;
	char __pad0x150[0x150];
	uint64 m_DroppedItemsArray;
	int m_nDroppedItemsCount;
	char __pad0x11C[0x11C];
	uint64 m_pMesh;
	char __pad0xC8[0xC8];
	TArray<UItem*> m_Items;
	char __pad0x508[0x508];
	uint64 m_pWeaponProcessor;
	char __pad0x78[0x78];
	float m_flPunchDistance;
	char __pad0x21C[0x21C];
	uint64 m_pTeam;
	char __pad0x3EC[0x3EC];
	float m_flHealth;
	float m_flMaxHealth;
	float m_flGroggyHealth;
	char __pad0xF8[0xF8];
	uint64 m_pVehicleRiderComponent;
};
