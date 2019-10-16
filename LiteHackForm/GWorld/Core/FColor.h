#pragma once
#include "..//..//Utils/ida_defs.h"
 class FColor
{
public:
	FColor() {}

	FColor(uint8 InR, uint8 InG, uint8 InB, uint8 InA = 255)
	{
		R = InR;
		G = InG;
		B = InB;
		A = InA;
	}

public:
	float R,G,B,A;
};