#pragma once
#include <string>

class Names
{
private:
	uint64_t base_address;
public:
	bool Init(uint64_t address);
	uint64_t GetAddress();
	std::string GetById(int Index);
	void CacheNames();

	bool IsEnemy(int id);
	bool IsVehicle(int id);
	bool IsItem(int id);
	bool IsAirdrop(int id);
	bool IsTombbox(int id);
};

