#include "Global.h"
#include "Updates.h"

std::vector<int> ComparisonIndexs = {};
std::vector<std::string> NamesDump = {};



std::multimap<int, Items_Vehicles> VehiclesMap = {};
std::multimap<int, Items_Vehicles> ItemsMap = {};

std::set<int> VehiclesIndexs = {};

std::map<uint8_t, ID3D11ShaderResourceView*> VehicleImages;


void Names::Init(uint64_t address)
{
	base_address = Global::GMemory->Read64(address + Off::StaticGNames);
}

uint64_t Names::GetAddress()
{
	return base_address;
}

System::String^ Names::GetStringById(int Index)
{
	uint64_t ChunkIndex = Index / Off::ChunkSize;
	uint64_t WithinChunkIndex = Index % Off::ChunkSize;
	uint64_t Chunk = base_address + ChunkIndex * 0x8;
	uint64_t Name = Global::GMemory->Read64(Global::GMemory->Read64(Chunk) + WithinChunkIndex * 0x8);
	char* name;
	name = (char*)Global::GMemory->ReadSize(Name + 0x10, 64);
	if (name != NULL)
	{
		System::String^ s = gcnew System::String(name);
		delete name;
		return s;
	}
	else
	{
		return gcnew System::String("NULL");
	}
}

std::string Names::GetById(int Index)
{
	uint64_t ChunkIndex = Index / Off::ChunkSize;
	uint64_t WithinChunkIndex = Index % Off::ChunkSize;
	uint64_t Chunk = base_address + ChunkIndex * 0x8;
	uint64_t Name = Global::GMemory->Read64(Global::GMemory->Read64(Chunk) + WithinChunkIndex * 0x8);
	char* name;
	name = (char*)Global::GMemory->ReadSize(Name + 0x10, 64);
	if (name != NULL)
	{
		std::string s = name;
		delete name;
		return s;
	}
	else
	{
		return "NULL";
	}
}

void Names::CacheNames()
{

	ComparisonIndexs.resize(4);
	NamesDump.resize(4);

	NamesDump[AirdropID] = "BP_AirDropBox_C";
	NamesDump[TombBoxID] = "PlayerDeadInventoryBox_C";
	NamesDump[PlayerID] = "BP_PlayerPawnPC_C";


	std::map<std::string, int> VehiclesNames = {
		{"AquaRail_1_C",AquaRail},
		{"VH_PG117_C",Boat},
		{"Rony_01_C",Rony},
		{"Rony_02_C",Rony},
		{"Rony_03_C",Rony },
		{"Mirado_close_1_C",Mirado },
		{"Mirado_close_2_C",Mirado },
		{"Mirado_close_3_C",Mirado},
		{"Mirado_close_4_C",Mirado},
		{"Mirado_open_1_C",Mirado},
		{"Mirado_open_2_C",Mirado},
		{"Mirado_open_3_C",Mirado},
		{"Mirado_open_4_C",Mirado},
		{"VH_MotorcycleCart_C",MotorcycleCart},
		{"VH_MotorcycleCart_1_C",MotorcycleCart},
		{"VH_Motorcycle_C",Motorcycle},
		{"VH_Motorcycle_1_C",Motorcycle},
		{"PickUp_01_C",PickUp},
		{"PickUp_02_C",PickUp},
		{"PickUp_03_C",PickUp},
		{"PickUp_04_C",PickUp},
		{"PickUp_05_C",PickUp},
		{"PickUp_06_C",PickUp},
		{"PickUp_07_C",PickUp},
		{"PickUp_08_C",PickUp},
		{"PickUp_09_C",PickUp},
		{"PickUp_10_C",PickUp},
		{"VH_Scooter_C",Scooter},
		{"VH_Scooter2_C",Scooter},
		{"VH_Scooter3_C",Scooter},
		{"VH_Scooter4_C",Scooter},
		{"BP_VH_Tuk_1_C",TukTuk},
		{"VH_MiniBus_01_C",MiniBus},
		{"VH_MiniBus_02_C",MiniBus},
		{"VH_MiniBus_03_C",MiniBus},
		{"BP_VH_Buggy_C",Buggy},
		{"BP_VH_Buggy_2_C",Buggy},
		{"BP_VH_Buggy_3_C",Buggy},
		{"BP_VH_Buggy_4_C",Buggy},
		{"BP_VH_Buggy_5_C",Buggy},
		{"BP_VH_Buggy_6_C",Buggy},
		{"VH_Dacia_C",Dacia},
		{"VH_Dacia_2_C",Dacia},
		{"VH_Dacia_3_C",Dacia},
		{"VH_Dacia_4_C",Dacia},
		{"VH_UAZ01_C",Uaz},
		{"VH_UAZ02_C",Uaz},
		{"VH_UAZ03_C",Uaz},
		{"VH_UAZ04_C",Uaz},
		{"VH_UAZ_Armored_C",ArmoredUaz}
	};

	int count = 0;
	for (int i = 70000; i < 200000; i++)
	{
		auto name = GetById(i);
		for (int j = 0; j < 3; j++)
		{
			if (name == NamesDump[j])
			{
				ComparisonIndexs[j] = i;
				count++;
			}
		}
		if (count == 3)
		{
			break;
		}
	}
	count = 0;
	for (int i = 70000; i < 200000; i++)
	{
		auto name = GetById(i);
		if (VehiclesNames.count(name) == 1)
		{
			VehiclesIndexs.insert(i);
			count++;
		}
		if (count == VehiclesNames.size())
		{
			break;
		}
	}

	LoadVehicleImages();
}

void LoadVehicleImages()
{
	for (int i = 1; i < 19; i++)
	{
		ID3D11ShaderResourceView* texture;
		std::string path = "Images/Vehicles/" + std::to_string(i) + ".png";
		Global::Canvas->LoadTextureFromFile(path.c_str(), &texture);
		VehicleImages.insert({ i , texture });
	}
}