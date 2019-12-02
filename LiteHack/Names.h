#pragma once
#include <cstdint>
#include <cliext/map>
#include <string>

ref class Names
{
public:
	void Init(uint64_t address);

	uint64_t GetAddress();

	System::String^ GetById(int Index);

	//cliext::map<int, std::string> VehichlesMap;

	//cliext::map<int, std::string> ItemsMap;

	int CharacterId;

	int AirdropId;

	int TombBox;
private:
	uint64_t base_address;
	void CacheNames();
};