#include "Global.h"
#include "Updates.h"

void LoadVehicleImages();

int AirdropID = 0;
int TombBoxID = 1;
int PlayerID = 2;
int LobbyID = 3;
std::set<int> VehiclesIndexs = {};
std::set<int> ItemsIndexs = {};

std::map<uint8_t, ID3D11ShaderResourceView*> VehicleImages;
std::map<uint8_t, ID3D11ShaderResourceView*> ItemImages;
ID3D11ShaderResourceView* AirDropFlyingImages;
ID3D11ShaderResourceView* AirDropOpenedImages;
ID3D11ShaderResourceView* AirDropNormalImages;
ID3D11ShaderResourceView* TombboxImage;

void Names::CacheNames()
{
	std::set<std::string> VehiclesNames = { "AquaRail_1_C","VH_PG117_C","Rony_01_C","Rony_02_C","Rony_03_C","Mirado_close_1_C","Mirado_close_2_C","Mirado_close_3_C","Mirado_close_4_C","Mirado_open_1_C","Mirado_open_2_C","Mirado_open_3_C","Mirado_open_4_C","BP_Motorbike_SideCart_1_C","BP_Motorbike_SideCart_C","BP_Motorbike_C","BP_Motorbike_1_C","PickUp_01_C","PickUp_02_C","PickUp_03_C","PickUp_04_C","PickUp_05_C","PickUp_06_C","PickUp_07_C","PickUp_08_C","PickUp_09_C","PickUp_10_C","VH_Scooter_C","VH_Scooter2_C","VH_Scooter3_C","VH_Scooter4_C","BP_VH_Tuk_1_C","VH_MiniBus_01_C","VH_MiniBus_02_C","VH_MiniBus_03_C","BP_VH_Buggy_C","BP_VH_Buggy_2_C","BP_VH_Buggy_3_C","BP_VH_Buggy_4_C","BP_VH_Buggy_5_C","BP_VH_Buggy_6_C","VH_Dacia_C","VH_Dacia_2_C","VH_Dacia_3_C","VH_Dacia_4_C","VH_UAZ01_C","VH_UAZ02_C","VH_UAZ03_C","VH_UAZ04_C","VH_UAZ_Armored_C","BP_Niva_C","BP_Niva_1_C","BP_Niva_2_C","BP_Niva_3_C","BP_Niva_4_C","BP_Niva_5_C","BP_Niva_6_C" };
	std::set<std::string> ItemsNames = {};
	for (int Index = 70000; Index < 200000; Index++)
	{
		auto name = GetById(Index);
		if (VehiclesNames.count(name) == 1)
		{
			VehiclesIndexs.insert(Index);
		}
		else if (ItemsNames.count(name) == 1)
		{
			ItemsIndexs.insert(Index);
		}
		else if (name == "PlayerDeadInventoryBox_C")
		{
			TombBoxID = Index;
		}
		else if (name == "BP_AirDropBox_C")
		{
			AirdropID = Index;
		}
		else if (name == "BP_PlayerPawnPC_C")
		{
			PlayerID = Index;
		}
		else if (name == "BP_LitePCLobbyPC_C")
		{
			LobbyID = Index;
		}
	}
	LoadVehicleImages();
	Global::Canvas->LoadTextureFromFile("Images/CarePackage/Flying.png", &AirDropFlyingImages);
	Global::Canvas->LoadTextureFromFile("Images/CarePackage/Open.png", &AirDropOpenedImages);
	Global::Canvas->LoadTextureFromFile("Images/CarePackage/Normal.png", &AirDropNormalImages);
	Global::Canvas->LoadTextureFromFile("Images/Tombbox/Death.png", &TombboxImage);
}

bool Names::IsEnemy(int id)
{
	return PlayerID == id;
}

bool Names::IsVehicle(int id)
{
	return VehiclesIndexs.count(id) == 1;
}

bool Names::IsInLobby(int id)
{
	return LobbyID == id;
}

bool Names::IsItem(int id)
{
	return ItemsIndexs.count(id) == 1;
}

bool Names::IsAirdrop(int id)
{
	return AirdropID == id;
}

bool Names::IsTombbox(int id)
{
	return TombBoxID == id;
}

void LoadVehicleImages()
{
	for (int i = 1; i < 29; i++)
	{
		ID3D11ShaderResourceView* texture;
		std::string path = "Images/Vehicles/" + std::to_string(i) + ".png";
		Global::Canvas->LoadTextureFromFile(path.c_str(), &texture);
		VehicleImages.insert({ i , texture });
	}
}

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
