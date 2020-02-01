#include "Common.h"
#include "../Global.h"

std::map<float, uint64_t> distances;
std::map<uint32_t, float> player_keys;
int warning_count;

void UpdateEnemyInfo(ESPInfo& info, ASTExtraPlayerCharacter enemy)
{
	// enemy
	info.Enemy.Health = enemy.Health();
	info.Enemy.Address = enemy.GetAddress();
	if (enemy.VehicleSeatIdx() == -1)
		info.Enemy.Pos = enemy.RootComponent().Location();
	else
		info.Enemy.Pos = enemy.CurrentVehicle().RootComponent().Location();
	info.Enemy.IsAI = enemy.IsAI();
	info.Enemy.PlayerName = enemy.PlayerName().ToString();
	info.Enemy.Distance = info.Enemy.Pos.Distance(info.Local.Pos) / 100.f;

	// visible & color
	info.Enemy.HeadScreenPos = LiteHack.Draw->WorldToScreen(GetBoneWithRotation(enemy, 6), info.Local.POV);
	info.Enemy.RootScreenPos = LiteHack.Draw->WorldToScreen(GetBoneWithRotation(enemy, 0), info.Local.POV);
	info.Enemy.InScreen = !(info.Enemy.HeadScreenPos.X<0 || info.Enemy.HeadScreenPos.X>LiteHack.Canvas->Width || info.Enemy.HeadScreenPos.Y<0 || info.Enemy.HeadScreenPos.Y>LiteHack.Canvas->Height);
	float lastRenderedTime = enemy.Mesh().LastRenderedTime();
	info.Enemy.IsVisible = lastRenderedTime > player_keys[enemy.PlayerKey()];
	player_keys[enemy.PlayerKey()] = lastRenderedTime;
	if (info.Enemy.IsVisible)
	{
		info.Enemy.ESPColor = *(LiteHack.Option->VisColor);
		if (LiteHack.Option->aimbot)
		{
			auto aimpos = GetBoneWithRotation(enemy, LiteHack.Option->aimbot_part);
			auto aimScreenPos = LiteHack.Draw->WorldToScreen(aimpos, info.Local.POV);
			if (aimScreenPos.Distance(FVector(LiteHack.Canvas->Width / 2.f, LiteHack.Canvas->Height / 2.f, 0)) <= LiteHack.Option->aimbot_radius)
			{
				distances[info.Enemy.Distance] = info.Enemy.Address;
			}
		}
	}
	else
		info.Enemy.ESPColor = info.Enemy.IsAI ? *(LiteHack.Option->BotColor) : *(LiteHack.Option->HumColor);
	if (info.Enemy.Distance < 50)
	{
		warning_count++;
	}
}

void UpdateLocalInfo(ESPInfo& info, ASTExtraPlayerCharacter local_pawn)
{
	info.Local.POV = local_pawn.STPlayerController().CameraCache().MinimalViewInfo();
	info.Local.TeamID = local_pawn.TeamID();
	uint64_t state = local_pawn.LocalSimulateStates();
	info.Local.isGunADS = (state >> 9) & 1;
	info.Local.isGunFire = (state >> 7) & 1;
	info.Local.isInParachute = (state >> 23) & 1;
	info.Local.isInVehicle = ((state >> 19) & 1) || ((state >> 20) & 1);
	info.Local.isSprint = (state >> 1) & 1;
	info.Local.isShoulderFiring = (state >> 29) & 1;
	info.Local.isMove = (state >> 0) & 1;
	if (info.Local.isInVehicle)
		info.Local.Pos = local_pawn.CurrentVehicle().RootComponent().Location();
	else
		info.Local.Pos = local_pawn.RootComponent().Location();
	LiteHack.Draw->Alpha = info.Local.isGunADS || info.Local.isShoulderFiring;
}

FVector GetBoneWithRotation(ASTExtraPlayerCharacter actor, int id)
{
	auto mesh = actor.Mesh();
	auto arrybone = mesh.BoneArray();
	FTransform bone = LiteHack.GMemory->Read<FTransform>(arrybone + ((uint64_t)id * 0x30));
	FTransform ComponentToWorld = mesh.ComponentToWorld();
	D3DMATRIX Matrix;
	Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());
	return FVector(Matrix._41, Matrix._42, Matrix._43);
}

std::string FString::ToString() const
{
	wchar_t* Name;
	if (m_nCount >= 60)
	{
		return "Error";
	}
	Name = (wchar_t*)LiteHack.GMemory->ReadSize(m_Data, m_nCount * sizeof(wchar_t));
	if (Name != NULL)
	{
		char text[60];
		sprintf_s(text, "%ls", Name);
		delete Name;
		return text;
	}
	else
	{
		delete Name;
		return "NULL";
	}
}

D3DMATRIX MatrixMultiplication(D3DMATRIX pM1, D3DMATRIX pM2)
{
	D3DMATRIX pOut;
	pOut._11 = pM1._11 * pM2._11 + pM1._12 * pM2._21 + pM1._13 * pM2._31 + pM1._14 * pM2._41;
	pOut._12 = pM1._11 * pM2._12 + pM1._12 * pM2._22 + pM1._13 * pM2._32 + pM1._14 * pM2._42;
	pOut._13 = pM1._11 * pM2._13 + pM1._12 * pM2._23 + pM1._13 * pM2._33 + pM1._14 * pM2._43;
	pOut._14 = pM1._11 * pM2._14 + pM1._12 * pM2._24 + pM1._13 * pM2._34 + pM1._14 * pM2._44;
	pOut._21 = pM1._21 * pM2._11 + pM1._22 * pM2._21 + pM1._23 * pM2._31 + pM1._24 * pM2._41;
	pOut._22 = pM1._21 * pM2._12 + pM1._22 * pM2._22 + pM1._23 * pM2._32 + pM1._24 * pM2._42;
	pOut._23 = pM1._21 * pM2._13 + pM1._22 * pM2._23 + pM1._23 * pM2._33 + pM1._24 * pM2._43;
	pOut._24 = pM1._21 * pM2._14 + pM1._22 * pM2._24 + pM1._23 * pM2._34 + pM1._24 * pM2._44;
	pOut._31 = pM1._31 * pM2._11 + pM1._32 * pM2._21 + pM1._33 * pM2._31 + pM1._34 * pM2._41;
	pOut._32 = pM1._31 * pM2._12 + pM1._32 * pM2._22 + pM1._33 * pM2._32 + pM1._34 * pM2._42;
	pOut._33 = pM1._31 * pM2._13 + pM1._32 * pM2._23 + pM1._33 * pM2._33 + pM1._34 * pM2._43;
	pOut._34 = pM1._31 * pM2._14 + pM1._32 * pM2._24 + pM1._33 * pM2._34 + pM1._34 * pM2._44;
	pOut._41 = pM1._41 * pM2._11 + pM1._42 * pM2._21 + pM1._43 * pM2._31 + pM1._44 * pM2._41;
	pOut._42 = pM1._41 * pM2._12 + pM1._42 * pM2._22 + pM1._43 * pM2._32 + pM1._44 * pM2._42;
	pOut._43 = pM1._41 * pM2._13 + pM1._42 * pM2._23 + pM1._43 * pM2._33 + pM1._44 * pM2._43;
	pOut._44 = pM1._41 * pM2._14 + pM1._42 * pM2._24 + pM1._43 * pM2._34 + pM1._44 * pM2._44;

	return pOut;
}