#pragma once
#include"FRotator.h"
struct FQuat
{
	float X;
	float Y;
	float Z;
	float W;
};

struct FTransform
{
	FQuat rot;
	FVector translation;
	char pad[4];
	FVector scale;
	char pad1[4];

	D3DMATRIX ToMatrixWithScale()
	{
		D3DMATRIX m;
		m._41 = translation.X;
		m._42 = translation.Y;
		m._43 = translation.Z;

		float x2 = rot.X + rot.X;
		float y2 = rot.Y + rot.Y;
		float z2 = rot.Z + rot.Z;

		float xx2 = rot.X * x2;
		float yy2 = rot.Y * y2;
		float zz2 = rot.Z * z2;
		m._11 = (1.0f - (yy2 + zz2)) * scale.X;
		m._22 = (1.0f - (xx2 + zz2)) * scale.Y;
		m._33 = (1.0f - (xx2 + yy2)) * scale.Z;

		float yz2 = rot.Y * z2;
		float wx2 = rot.W * x2;
		m._32 = (yz2 - wx2) * scale.Z;
		m._23 = (yz2 + wx2) * scale.Y;

		float xy2 = rot.X * y2;
		float wz2 = rot.W * z2;
		m._21 = (xy2 - wz2) * scale.Y;
		m._12 = (xy2 + wz2) * scale.X;

		float xz2 = rot.X * z2;
		float wy2 = rot.W * y2;
		m._31 = (xz2 + wy2) * scale.Z;
		m._13 = (xz2 - wy2) * scale.X;

		m._14 = 0.0f;
		m._24 = 0.0f;
		m._34 = 0.0f;
		m._44 = 1.0f;

		return m;
	}
};


D3DMATRIX MatrixMultiplication(D3DMATRIX pM1, D3DMATRIX pM2);