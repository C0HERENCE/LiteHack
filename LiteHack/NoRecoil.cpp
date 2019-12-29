#include "Commons.h"
void NoRecoil(UShootWeaponEntity^ weaponcomp)
{
	auto attachment_array = weaponcomp->ArrTslWeaponAttachmentData();
	auto attachment_count = attachment_array.Length();
	if (attachment_count > 0 && attachment_count < 8)
	{
		auto attachment_data = gcnew FWeaponAttachmentData(attachment_array.GetAddress());
		//auto data = Global::GMemory->Read64(attachment_data->GetAddress());
		//auto data1 = Global::GMemory->Read<float>(data + Off::FWeaponAttachmentData_AnimationKickMultiplier);
		//auto data2 = Global::GMemory->Read<float>(data + Off::FWeaponAttachmentData_MultipleFiringBulletsSpread);
		//auto data3 = Global::GMemory->Read<float>(data + Off::FWeaponAttachmentData_RecoilMultiplierVertical);
		//auto data4 = Global::GMemory->Read<float>(data + Off::FWeaponAttachmentData_SwayMultiplier);
		//System::Console::WriteLine(data1);
		//System::Console::WriteLine(data2);
		//System::Console::WriteLine(data3);
		//System::Console::WriteLine(data4);
		//System::Console::WriteLine("xxxxxxxxxxxxxxx");
		if (attachment_data->GetRecoilMultiplierVertical() != 0.f)
		{
			attachment_data->SetZero();
		}
	}

	return;
	uint64_t recoilcurve = weaponcomp->ReadOffset<uint64_t>(0x5E8);
	uint64_t tarray1 = Global::GMemory->Read<uint64_t>(recoilcurve + 0x108);
	uint64_t tarray2 = Global::GMemory->Read<uint64_t>(recoilcurve + 0x98);
	float sway = Global::GMemory->Read<float>(tarray2 + 0x24);
	float recoil1 = Global::GMemory->Read<float>(tarray1 + 0x8);
	float recoil2 = Global::GMemory->Read<float>(tarray1 + 0x8 + 28);
	float recoil3 = Global::GMemory->Read<float>(tarray1 + 0x8 + 28 + 28);
	float recoil4 = Global::GMemory->Read<float>(tarray1 + 0x8 + 28 + 28 + 28);

	if (false)
	{
		Global::GMemory->Write<float>(tarray2 + 0x24, 0.f);
		Global::GMemory->Write<float>(tarray1 + 0x8, 0.f);
		Global::GMemory->Write<float>(tarray1 + 0x8 + 28, 0.f);
		Global::GMemory->Write<float>(tarray1 + 0x8 + 28 + 28, 0.f);
		Global::GMemory->Write<float>(tarray1 + 0x8 + 28 + 28 + 28, 0.f);
	}
	System::Console::WriteLine("Sway: " + sway);
	System::Console::WriteLine("Recoil 1: " + recoil1);
	System::Console::WriteLine("Recoil 2: " + recoil2);
	System::Console::WriteLine("Recoil 3: " + recoil3);
	System::Console::WriteLine("Recoil 4: " + recoil4);
	return;

}
