#pragma once

struct FVector
{
public:
	FVector()
	{
		X = 0;
		Y = 0;
		Z = 0;
	}
	FVector(float x, float y, float z)
	{
		X = x;
		Y = y;
		Z = z;
	}
	float Dot(const FVector& v) const
	{
		return X * v.X + Y * v.Y + Z * v.Z;
	}

	float Distance(const FVector& v) const
	{
		return float(sqrtf(powf(v.X - X, 2.0) + powf(v.Y - Y, 2.0) + powf(v.Z - Z, 2.0)));
	}

	FVector operator+(const FVector& v) const
	{
		return FVector(X + v.X, Y + v.Y, Z + v.Z);
	}

	FVector operator-(const FVector& v) const
	{
		return FVector(X - v.X, Y - v.Y, Z - v.Z);
	}

	FVector operator*(float v) const
	{
		return FVector(X * v, Y * v, Z * v);
	}

	bool operator==(const FVector& v) const
	{
		return X == v.X && Y == v.Y && Z == v.Z;
	}

	bool operator!=(const FVector& v) const
	{
		return !(*this == v);
	}

	float X;
	float Y;
	float Z;
};