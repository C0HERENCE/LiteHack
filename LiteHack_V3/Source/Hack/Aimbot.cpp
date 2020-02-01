#include "Common.h"
#include "../Global.h"

void Aimbot(ESPInfo& info, ASTExtraPlayerCharacter local_pawn)
{
	if (LiteHack.Option->aimbot)
	{
		if (distances.size() > 0)
		{
			LiteHack.Draw->Circle(FVector(LiteHack.Canvas->Width / 2.f, LiteHack.Canvas->Height / 2.f, 0), LiteHack.Option->aimbot_radius, FGRAY_BLACK);
			auto weaponcomp = local_pawn.WeaponManagerComponent().CurrentWeapon().WeaponEntityComp();
			if (info.Local.isGunFire || info.Local.isShoulderFiring || (info.Local.isGunADS && GetAsyncKeyState(VK_LSHIFT)))
			{
				if (distances.size() <= 0) return;
				ASTExtraPlayerCharacter nearest_enemy = ASTExtraPlayerCharacter(distances.begin().operator*().second);
				FVector aimpos;
				if (weaponcomp.bHasAutoFireMode())
					if ((GetAsyncKeyState(VK_LCONTROL) & 0x8000))
						aimpos = GetBoneWithRotation(nearest_enemy, LiteHack.Option->aimbot_second_part);
					else
						aimpos = GetBoneWithRotation(nearest_enemy, LiteHack.Option->aimbot_part);
				else
					aimpos = GetBoneWithRotation(nearest_enemy, 6);
				FVector velocity = nearest_enemy.RootComponent().ComponentVelocity();
				float FlyTime = distances.begin().operator*().first / (weaponcomp.BulletFireSpeed() / 100.f);
				float Fall = 0.98f * FlyTime * FlyTime * distances.begin().operator*().first;
				aimpos = aimpos + velocity * FlyTime + FVector(0, 0, Fall);
				auto aimScreenPos = LiteHack.Draw->WorldToScreen(aimpos, local_pawn.STPlayerController().CameraCache().MinimalViewInfo());
				AimAtPos(aimScreenPos.X, aimScreenPos.Y);
			}
		}
	}
}

void AimAtPos(float x, float y)
{
	float ScreenCenterX = ((LiteHack.Canvas->Width - 1) / 2.f);
	float ScreenCenterY = ((LiteHack.Canvas->Height - 1) / 2.f);
	LiteHack.Draw->Line(FVector(x, y, 0) - FVector(10, 0, 0), FVector(x, y, 0) + FVector(10, 0, 0), FColor(255, 0, 0));
	LiteHack.Draw->Line(FVector(x, y, 0) - FVector(0, 10, 0), FVector(x, y, 0) + FVector(0, 10, 0), FColor(255, 0, 0));
	LiteHack.Draw->Line(FVector(ScreenCenterX, ScreenCenterY, 0) + FVector(10, -10, 0), FVector(ScreenCenterX, ScreenCenterY, 0) + FVector(-10, 10, 0), FColor(255, 0, 0));
	LiteHack.Draw->Line(FVector(ScreenCenterX, ScreenCenterY, 0) + FVector(10, 10, 0), FVector(ScreenCenterX, ScreenCenterY, 0) + FVector(-10, -10, 0), FColor(255, 0, 0));
	float TargetX = 0;
	float TargetY = 0;
	int aimbot_speed = LiteHack.Option->aimbot_speed;
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