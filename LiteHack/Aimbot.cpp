#include "Aimbot.h"

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

void Aimbot(ASTExtraPlayerCharacter^ local_pawn)
{
	if (Global::Option->aimbot)
	{
		if (distances.size() > 0)
		{
			Global::Draw->Circle(FVector(Global::Canvas->Width / 2.f, Global::Canvas->Height / 2.f, 0), Global::Option->aimbot_radius, FGRAY_BLACK);
			auto weaponcomp = local_pawn->WeaponManagerComponent()->CurrentWeapon()->WeaponEntityComp();
			float myBulletSpeed = weaponcomp->BulletFireSpeed();
			if (myBulletSpeed > 100)
			{
				ASTExtraPlayerCharacter^ nearest_enemy = gcnew ASTExtraPlayerCharacter(distances.begin().operator*().second);

				if (Global::Option->norecoil)
				{
					NoRecoil(weaponcomp);
				}

				if ((GetAsyncKeyState(VK_RBUTTON) & 0x8000 || GetAsyncKeyState(VK_LBUTTON) & 0x8000))
				{
					FVector aimpos;
					if (weaponcomp->bHasAutoFireMode())
					{
						if ((GetAsyncKeyState(VK_LCONTROL) & 0x8000))
						{
							aimpos = GetBoneWithRotation(nearest_enemy, Global::Option->aimbot_second_part);
						}
						else
						{
							aimpos = GetBoneWithRotation(nearest_enemy, Global::Option->aimbot_part);
						}
					}
					else
					{
						aimpos = GetBoneWithRotation(nearest_enemy, 7);
					}
					FVector velocity = nearest_enemy->RootComponent()->ComponentVelocity();
					float FlyTime = distances.begin().operator*().first / (myBulletSpeed / 100.f);
					float Fall = 0.98 * FlyTime * FlyTime * distances.begin().operator*().first;
					aimpos = aimpos + velocity * FlyTime;
					auto aimScreenPos = Global::Draw->WorldToScreen(aimpos, local_pawn->STPlayerController()->CameraCache()->MinimalViewInfo());
					AimAtPos(aimScreenPos.X, aimScreenPos.Y);
					if (GetAsyncKeyState(VK_CAPITAL) & 0x0001)
					{
						mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
					}
				}
			}
		}
	}
}

void AimAtPos(float x, float y)
{
	float ScreenCenterX = ((Global::Canvas->Width - 1) / 2.f);
	float ScreenCenterY = ((Global::Canvas->Height - 1) / 2.f);
	Global::Draw->Line(FVector(x, y, 0) - FVector(10, 0, 0), FVector(x, y, 0) + FVector(10, 0, 0), FColor(255, 0, 0), 1.2f);
	Global::Draw->Line(FVector(x, y, 0) - FVector(0, 10, 0), FVector(x, y, 0) + FVector(0, 10, 0), FColor(255, 0, 0), 1.2f);
	Global::Draw->Line(FVector(ScreenCenterX, ScreenCenterY, 0) + FVector(10, -10, 0), FVector(ScreenCenterX, ScreenCenterY, 0) + FVector(-10, 10, 0), FColor(255, 0, 0), 1.2f);
	Global::Draw->Line(FVector(ScreenCenterX, ScreenCenterY, 0) + FVector(10, 10, 0), FVector(ScreenCenterX, ScreenCenterY, 0) + FVector(-10, -10, 0), FColor(255, 0, 0), 1.2f);
	float TargetX = 0;
	float TargetY = 0;
	int aimbot_speed = Global::Option->aimbot_speed;
	if (x != 0)
	{
		if (x > ScreenCenterX)
		{
			TargetX = -(ScreenCenterX - x);
			TargetX /= aimbot_speed;
			if (TargetX + ScreenCenterX > ScreenCenterX * 2) TargetX = 0;
		}

		if (x < ScreenCenterX)
		{
			TargetX = x - ScreenCenterX;
			TargetX /= aimbot_speed;
			if (TargetX + ScreenCenterX < 0) TargetX = 0;
		}
	}
	if (y != 0)
	{
		if (y > ScreenCenterY)
		{
			TargetY = -(ScreenCenterY - y);
			TargetY /= aimbot_speed;
			if (TargetY + ScreenCenterY > ScreenCenterY * 2) TargetY = 0;
		}

		if (y < ScreenCenterY)
		{
			TargetY = y - ScreenCenterY;
			TargetY /= aimbot_speed;
			if (TargetY + ScreenCenterY < 0) TargetY = 0;
		}
	}
	mouse_event(0x0001, (uint32_t)(TargetX), (uint32_t)(TargetY), NULL, NULL);
}