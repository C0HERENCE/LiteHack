#pragma once
#include "Vector.hpp"
#include "UItem.hpp"

extern Memory GameMemory;

class ADroppedItem
{
public:
	Vector3 GetRelativePosition() const;
	UItem GetItem() const;
private:
	char __pad0x1E0[0x1E0];
	Vector3 m_vecRelativePosition;
	char __pad0x25C[0x25C];
	uint64 m_pUItem;
};
