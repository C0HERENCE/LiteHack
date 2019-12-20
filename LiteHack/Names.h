#pragma once
#include <cstdint>
#include <cliext/map>
#include <string>
#include <vector>
#include <map>
#include <d3d11.h>
#include <set>


extern std::map<uint8_t, ID3D11ShaderResourceView*> VehicleImages;
extern std::map<uint8_t, ID3D11ShaderResourceView*> ItemImages;
extern ID3D11ShaderResourceView* AirDropFlyingImages;
extern ID3D11ShaderResourceView* AirDropOpenedImages;
extern ID3D11ShaderResourceView* AirDropNormalImages;
extern ID3D11ShaderResourceView* TombboxImage;

ref class Names
{
public:
	void Init(uint64_t address);

	uint64_t GetAddress();

	System::String^ GetStringById(int Index);

	std::string GetById(int Index);

	void CacheNames();

	bool IsEnemy(int id);

	bool IsVehicle(int id);

	bool IsItem(int id);

	bool IsAirdrop(int id);

	bool IsTombbox(int id);
private:
	uint64_t base_address;
};