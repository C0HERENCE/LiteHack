#include "Commons.h"
void NoRecoil(UShootWeaponEntity^ weaponcomp)
{
	auto attachment_array = weaponcomp->ArrTslWeaponAttachmentData();
	auto attachment_count = attachment_array.Length();
	if (attachment_count > 0 && attachment_count < 10)
	{
		auto attachment_data = gcnew FWeaponAttachmentData(attachment_array.GetAddress());
		if (attachment_data->GetRecoilMultiplierVertical() != 0.f)
		{
			attachment_data->SetZero();
		}
	}
}
