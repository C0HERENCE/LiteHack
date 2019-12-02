#include "Global.h"
#include "Updates.h"
void Names::Init(uint64_t address)
{
	base_address = Global::GMemory->Read64(address + Off::StaticGNames);
	CacheNames();
}

uint64_t Names::GetAddress()
{
	return base_address;
}

System::String^ Names::GetById(int Index)
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

void Names::CacheNames()
{
	int count = 0;
	int sum = 3;
	for (int i = 70000; i < 200000; i++)
	{
		auto name = GetById(i);
		if (name == "BP_PlayerPawnPC_C")
		{
			CharacterId = i;
			count++;
		}
		else if(name == "BP_AirDropBox_C")
		{
			AirdropId = i;
			count++;
		}
		else if (name == "PlayerDeadInventoryBox_C")
		{
			TombBox = i;
			count++;
		}
		if (count == sum)
		{
			break;
		}
	}
}