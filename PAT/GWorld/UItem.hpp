#pragma once
#include "FText.hpp"
class UItem
{
public:
	std::string GetItemName() const;
private:
	char __pad0x40[0x40];
	uint64 m_ItemNameData;
};
