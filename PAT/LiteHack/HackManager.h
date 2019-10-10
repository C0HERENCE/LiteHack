#pragma once
#include "Render.h"
std::list<int> rightarm = { 5,15,16,17,18 };
std::list<int> leftarm = { 5,35,36,37,38 };
std::list<int> upper = { 5,4,3,2,1 };
std::list<int> rightleg = { 1,56,57,58 };
std::list<int> leftleg = { 1,60,61,62 };
std::list<std::list<int>> part = { rightarm,leftarm,upper,rightleg,leftleg };

struct ESPOption
{
	bool Enemy;
	bool Box;
	bool Health;
	bool Skeleton;
	bool Line;

	bool Aimbot;
	float maxSkeletonDistance;

	FColor HumanColor;
	FColor BotColor;
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

	FVector Location;
	float Distance;

	bool isAI;
	float health;
	FMinimalViewInfo POV;
};

class HackManager
{
public:
	int Initialize()
	{
		options.Enemy = true;
		options.Box = true;
		options.Line = true;
		options.Health = true;
		options.Skeleton = true;
		options.Aimbot = true;
		options.HumanColor = FColor(255, 0, 0);
		options.BotColor = FColor(0, 0, 255);
		options.maxSkeletonDistance = 100;
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

	void UpdateESPInfo(AActor actor,ESPInfo& info)
	{
		info.actor = actor;
		info.headpos = GetBoneWithRotation(info.actor, 11);
		info.rootpos = GetBoneWithRotation(info.actor, 0);
		info.neckpos = GetBoneWithRotation(info.actor, 5);
		info.pelvispos = GetBoneWithRotation(info.actor, 1);
		info.headScreenPos = overlay.WorldToScreen(info.headpos, info.POV);
		info.rootScreenPos = overlay.WorldToScreen(info.rootpos, info.POV);
		info.isAI = actor.IsAI();
		info.health = actor.Health();
		info.color = info.isAI ? options.BotColor : options.HumanColor;
		info.Location = actor.RootComponent().Location();
	}

	FVector GetBoneWithRotation(AActor actor, int id)
	{
		auto mesh = actor.Mesh();
		auto arrybone = mesh.BoneArray();
		FTransform bone = GameMemory.Read<FTransform>(arrybone + (id * 0x30));
		FTransform ComponentToWorld = mesh.ComponentToWorld();
		D3DMATRIX Matrix;
		Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());
		return FVector(Matrix._41, Matrix._42, Matrix._43);
	}

	void DrawSkeleton(ESPInfo info)
	{
		if (info.Distance > options.maxSkeletonDistance) return;
		FVector previous(0, 0, 0);
		FVector current, p1, c1;
		float headradius = info.headScreenPos.Y - overlay.WorldToScreen(info.neckpos, info.POV).Y;
		overlay.DrawCircle(info.headScreenPos, headradius, info.color);

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


	void DrawBox(ESPInfo info)
	{
		float boxheight = info.headScreenPos.Y - info.rootScreenPos.Y;
		if (boxheight > -50.f)return;
		float boxwidth = boxheight / 1.7f;
		overlay.DrawRectangle(info.rootScreenPos - FVector(0.5 * boxwidth, 0, 0), boxheight, boxwidth, info.color);
	}

	void DrawHealthBar(ESPInfo info)
	{
		FColor color = info.isAI ? options.BotColor : options.HumanColor;
		FMinimalViewInfo cameracache = info.POV;
		float barwidth = (info.rootScreenPos.Y - info.headScreenPos.Y) / 1.7f;
		float boxheight = (info.rootScreenPos.Y - info.headScreenPos.Y);
		float barheight = 10;
		if (barwidth < 30.f)return;
		float healthwidth = info.health / 100.f * barwidth;
		overlay.DrawRectangleFilled(info.rootScreenPos - FVector(0.5 * barwidth, boxheight, 0), barheight, barwidth, FColor(0, 255, 0, 255));
		overlay.DrawRectangleFilled(info.rootScreenPos - FVector(0.5 * barwidth, boxheight, 0), barheight, healthwidth, color);
	}

	void DrawGuideLine(ESPInfo info)
	{
		FColor color = info.isAI ? options.BotColor : options.HumanColor;
		overlay.DrawLine(info.rootScreenPos, FVector(0.5 * overlay.Width, 0, 0), color, 1.0f);
	}

	void DrawInformation(ESPInfo info,std::string text)
	{
		float barwidth = (info.rootScreenPos.Y - info.headScreenPos.Y) / 1.7f;
		overlay.DrawString(info.rootScreenPos - FVector(0.5 * barwidth, 0, 0), info.color, text);
	}

private:
	Render overlay;
	ESPOption options;
};