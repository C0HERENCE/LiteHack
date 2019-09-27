#pragma once
#include <string>

class FTextData
{
public:
	std::string GetName() const;
private:
	char __pad0x028[0x28];
	uint64 m_pName;
	int m_nLength;
};