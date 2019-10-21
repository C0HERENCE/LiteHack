#pragma once
#include <string>

class NamesStore
{
public:
	NamesStore();

	NamesStore(uint64);

	uint64 GetAddress();

	uint64 Initialize(uint64 a);

	std::string GetById(int id) const;
private:
	uint64 Address;
};