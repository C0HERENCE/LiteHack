#pragma once
#include <cstdint>
#include <cliext/map>
#include <string>
#include <vector>
#include <map>
#include <d3d11.h>
#include <set>

#define AirdropID 0
#define TombBoxID 1
#define PlayerID 2

#define AquaRail 0
#define Boat 1
#define Mirado 2
#define Motorcycle 3
#define MotorcycleCart 4
#define PickUp 5
#define Scooter 6
#define TukTuk 7
#define MiniBus 8
#define Buggy 9
#define Dacia 10
#define Uaz 11
#define ArmoredUaz 12
#define Rony 13

extern std::vector<int> ComparisonIndexs;
extern std::vector<std::string> NamesDump;



struct Items_Vehicles
{
	int id;
	std::string showname;
	std::string path;
	ID3D11ShaderResourceView* texture;
};

extern std::multimap<int, Items_Vehicles> VehiclesMap;
extern std::multimap<int, Items_Vehicles> ItemsMap;
extern std::set<int> VehiclesIndexs;
extern std::map<uint8_t, ID3D11ShaderResourceView*> VehicleImages;
void LoadVehicleImages();


ref class Names
{
public:
	void Init(uint64_t address);

	uint64_t GetAddress();

	System::String^ GetStringById(int Index);

	std::string GetById(int Index);
private:
	uint64_t base_address;
	void CacheNames();
};