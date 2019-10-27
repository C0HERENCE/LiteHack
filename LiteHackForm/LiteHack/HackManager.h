#pragma once
#include "Render.h"
std::list<int> rightarm = { 5,15,16,17,18 };
std::list<int> leftarm = { 5,35,36,37,38 };
std::list<int> upper = { 5,4,3,2,1 };
std::list<int> rightleg = { 1,56,57,58 };
std::list<int> leftleg = { 1,60,61,62 };
std::list<std::list<int>> part = { rightarm,leftarm,upper,rightleg,leftleg };

enum AimbotPos
{
	Head = 11,
	Neck = 5,
	Body = 3,
	Pelvis = 1,
};

struct ESPOption
{
	bool Enemy;
	bool Box;
	bool Health;
	bool Skeleton;
	bool Line;

	bool Aimbot;
	AimbotPos aimpos;
	float maxSkeletonDistance;
	int aimbotSpeed;
	float aimbotRadius;
	bool predictaimbot;

	FColor HumanColor;
	FColor BotColor;
	FColor VisibleColor;

	bool autoFPS;
};

struct ESPInfo
{
	AActor actor;
	FVector headpos;
	FVector rootpos;
	FVector neckpos;
	FVector pelvispos;

	FColor color;

	FVector headScreenPos;
	FVector rootScreenPos;
	FVector aimScreenPos;
	std::string PlayerName;

	FVector Location;
	float Distance;

	bool visible;
	float LastRenderedTime;
	bool isAI;
	bool isFiring;
	float health;
	updates::off::FMinimalViewInfo POV;
};

class HackManager
{
public:
	int Initialize()
	{
		return overlay.Initialize();
	}

	Render Overlay()
	{
		return overlay;
	}
	ESPOption Option()
	{
		return options;
	}

	void UpdateESPInfo(AActor& actor,ESPInfo& info)
	{
		info.actor = actor;
		info.Location = actor.RootComponent().Location();
		info.isAI = actor.IsAI();
		info.headpos = GetBoneWithRotation(actor, 11);
		info.rootpos = GetBoneWithRotation(actor, 0);
		info.headScreenPos = overlay.WorldToScreen(info.headpos, info.POV);
		info.rootScreenPos = overlay.WorldToScreen(info.rootpos, info.POV);
		info.neckpos = GetBoneWithRotation(actor, 5);
		info.pelvispos = GetBoneWithRotation(actor, 1);
		info.health = actor.Health();
		info.aimScreenPos = overlay.WorldToScreen(GetBoneWithRotation(actor, options.aimpos),info.POV);
		info.LastRenderedTime = actor.Mesh().LastRenderedTime();
		info.PlayerName = actor.PlayerName().ToString();
		info.isFiring = actor.IsWeaponFiring();
	}

	FVector GetBoneWithRotation(AActor& actor, int id)
	{
		auto mesh = actor.Mesh();
		auto arrybone = mesh.BoneArray();
		FTransform bone = GameMemory.Read<FTransform>(arrybone + (id * 0x30));
		FTransform ComponentToWorld = mesh.ComponentToWorld();
		D3DMATRIX Matrix;
		Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());
		return FVector(Matrix._41, Matrix._42, Matrix._43);
	}

	void DrawSkeleton(ESPInfo& info)
	{
		if (info.Distance > options.maxSkeletonDistance) return;
		FVector previous(0, 0, 0);
		FVector current, p1, c1;
		//float headradius = info.headScreenPos.Y - overlay.WorldToScreen(info.neckpos, info.POV).Y;
		//overlay.DrawCircle(info.headScreenPos, headradius, info.color);

		for (auto a : part)
		{
			previous = FVector(0, 0, 0);
			for (int bone : a)
			{
				current = bone == 5 ? info.neckpos : (bone == 1 ? info.pelvispos : GetBoneWithRotation(info.actor, bone));
				if (previous.X == 0.f)
				{
					previous = current;
					continue;
				}
				p1 = overlay.WorldToScreen(previous, info.POV);
				c1 = overlay.WorldToScreen(current, info.POV);
				overlay.DrawLine(p1, c1, info.color , 2.0f);
				previous = current;
			}
		}
	}


	void DrawBox(ESPInfo& info)
	{
		float boxheight = info.headScreenPos.Y - info.rootScreenPos.Y;
		if (boxheight > -50.f)return;
		float boxwidth = boxheight / 1.7f;
		overlay.DrawRectangle(info.rootScreenPos - FVector(0.5 * boxwidth, 0, 0), boxheight, boxwidth, info.color);
	}

	void DrawHealthBar(ESPInfo& info)
	{
		FColor color = info.color;
		updates::off:: FMinimalViewInfo cameracache = info.POV;
		float barwidth = (info.rootScreenPos.Y - info.headScreenPos.Y) / 1.7f;
		float boxheight = (info.rootScreenPos.Y - info.headScreenPos.Y);
		float barheight = 10;
		if (barwidth < 30.f)return;
		float healthwidth = info.health / 100.f * barwidth;
		overlay.DrawRectangleFilled(info.rootScreenPos - FVector(0.5 * barwidth, boxheight, 0), barheight, barwidth, color);
		overlay.DrawRectangleFilled(info.rootScreenPos - FVector(0.5 * barwidth, boxheight, 0), barheight, healthwidth, FColor(0, 255, 0, 255));
	}

	void DrawGuideLine(ESPInfo& info)
	{
		FColor color = info.color;
		overlay.DrawLine(info.rootScreenPos, FVector(0.5 * overlay.Width, 0, 0), color, 1.0f);
	}

	void DrawInformation(ESPInfo& info,std::string text)
	{
		float barwidth = (info.rootScreenPos.Y - info.headScreenPos.Y) / 1.7f;
		overlay.DrawString(info.rootScreenPos - FVector(0.5 * barwidth, 0, 0), info.color, text);
	}

	void DrawInformation(FVector loc,std::string text)
	{
		overlay.DrawString(loc, FColor(255, 255, 0), text);
	}

	Render overlay;
	ESPOption options;
};