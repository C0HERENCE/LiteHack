#include "..//Utils/MemoryHelper.h"
#include "ADroppedItem.hpp"

Vector3 ADroppedItem::GetRelativePosition() const
{
	return this->m_vecRelativePosition;
}

UItem ADroppedItem::GetItem() const
{
	return GameMemory.Read<UItem>(this->m_pUItem);
}
