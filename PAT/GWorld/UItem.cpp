#include "../Utils/MemoryHelper.h"
#include "UItem.hpp"


extern Memory GameMemory;
std::string UItem::GetItemName() const
{
	return GameMemory.Read<FTextData>(this->m_ItemNameData).GetName();
}
