#pragma once
#include <stdint.h>
#include <d3d9.h>
#include <cmath>
#include <string>

template<class T>
class TArray
{
	friend struct FString;
public:
	int Length() const
	{
		return m_nCount;
	}

	bool IsValid() const
	{
		if (m_nCount > m_nMax)
			return false;
		if (!m_Data)
			return false;
		return true;
	}

	uint64_t GetAddress() const
	{
		return m_Data;
	}

	T GetById(int i);

protected:
	uint64_t m_Data;
	uint32_t m_nCount;
	uint32_t m_nMax;
};

struct FString : public TArray<wchar_t>
{
	std::string ToString() const;
};
class FColor
{
public:
	FColor() 
	{
		R = 0;
		G = 0;
		B = 0;
		A = 0;
	}

	FColor(uint8_t InR, uint8_t InG, uint8_t InB, uint8_t InA = 255)
	{
		R = InR;
		G = InG;
		B = InB;
		A = InA;
	}

public:
	float R, G, B, A;
};

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

class FRotator
{
public:
	float pitch, yaw, roll;

	FRotator() : pitch(0.0f), yaw(0.0f), roll(0.0f) {}
	FRotator(float _pitch, float _yaw, float _roll)
	{
		pitch = _pitch;
		yaw = _yaw;
		roll = _roll;
	}

	FRotator(const FVector& vec)
	{
		static constexpr auto RADPI = static_cast<float>(180 / 3.14159265358979323846);
		yaw = static_cast<float>(atan2(vec.Y, vec.X))* RADPI;
		pitch = static_cast<float>(atan2(vec.Z, sqrt((vec.X * vec.X) + (vec.Y * vec.Y))))* RADPI;
		roll = 0;
	}

	FLOAT length() const
	{
		return abs(sqrt(pitch * pitch + yaw * yaw + roll * roll));
	}

	FRotator clamp() const
	{
		auto result = *this;

		while (result.pitch > 180.0f)
			result.pitch -= 360.0f;

		while (result.pitch < -180.0f)
			result.pitch += 360.0f;

		while (result.yaw < -180.0f)
			result.yaw += 360.0f;

		while (result.yaw > 180.0f)
			result.yaw -= 360.0f;

		if (result.pitch < -89.f)
			result.pitch = -89.f;

		if (result.pitch > 89.f)
			result.pitch = 89.f;

		result.roll = 0;

		return result;
	}

	void get_axes(FVector& x, FVector& y, FVector& z) const
	{
		auto m = to_matrix();

		x = FVector(m.m[0][0], m.m[0][1], m.m[0][2]);
		y = FVector(m.m[1][0], m.m[1][1], m.m[1][2]);
		z = FVector(m.m[2][0], m.m[2][1], m.m[2][2]);
	}

	D3DMATRIX to_matrix(const FVector& origin = { 0.0f, 0.0f, 0.0f }) const
	{
		auto radPitch = static_cast<float>(pitch * 3.14159265358979323846 / 180.f);
		auto radYaw = static_cast<float>(yaw * 3.14159265358979323846 / 180.f);
		auto radRoll = static_cast<float>(roll * 3.14159265358979323846 / 180.f);

		auto SP = static_cast<float>(sin(radPitch));
		auto CP = static_cast<float>(cos(radPitch));
		auto SY = static_cast<float>(sin(radYaw));
		auto CY = static_cast<float>(cos(radYaw));
		auto SR = static_cast<float>(sin(radRoll));
		auto CR = static_cast<float>(cos(radRoll));

		D3DMATRIX m;

		m.m[0][0] = CP * CY;
		m.m[0][1] = CP * SY;
		m.m[0][2] = SP;
		m.m[0][3] = 0.f;

		m.m[1][0] = SR * SP * CY - CR * SY;
		m.m[1][1] = SR * SP * SY + CR * CY;
		m.m[1][2] = -SR * CP;
		m.m[1][3] = 0.f;

		m.m[2][0] = -(CR * SP * CY + SR * SY);
		m.m[2][1] = CY * SR - CR * SP * SY;
		m.m[2][2] = CR * CP;
		m.m[2][3] = 0.f;

		m.m[3][0] = origin.X;
		m.m[3][1] = origin.Y;
		m.m[3][2] = origin.Z;
		m.m[3][3] = 1.f;
		return m;
	}

	bool operator ==(const FRotator& o) const
	{
		return pitch == o.pitch && yaw == o.yaw && roll == o.roll;
	}

	bool operator !=(const FRotator& o) const
	{
		return !(*this == o);
	}

	FRotator& operator+(const FRotator& o)
	{
		pitch += o.pitch;
		yaw += o.yaw;
		roll += o.roll;
		return *this;
	}
	FRotator& operator-(const FRotator& o)
	{
		pitch -= o.pitch;
		yaw -= o.yaw;
		roll -= o.roll;
		return *this;
	}
	FRotator& operator*(const FRotator& o)
	{
		pitch *= o.pitch;
		yaw *= o.yaw;
		roll *= o.roll;
		return *this;
	}
	FRotator& operator/(const FRotator& o)
	{
		pitch /= o.pitch;
		yaw /= o.yaw;
		roll /= o.roll;
		return *this;
	}

	FRotator& operator+(float o)
	{
		pitch += o;
		yaw += o;
		roll += o;
		return *this;
	}
	FRotator& operator-(float o)
	{
		pitch -= o;
		yaw -= o;
		roll -= o;
		return *this;
	}
	FRotator& operator*(float o)
	{
		pitch *= o;
		yaw *= o;
		roll *= o;
		return *this;
	}
	FRotator& operator/(float o)
	{
		pitch /= o;
		yaw /= o;
		roll /= o;
		return *this;
	}

	operator FVector() const
	{
		auto radPitch = static_cast<float>(pitch * 3.14159265358979323846 / 180.f);
		auto radYaw = static_cast<float>(yaw * 3.14159265358979323846 / 180.f);

		auto SP = static_cast<float>(sin(radPitch));
		auto CP = static_cast<float>(cos(radPitch));
		auto SY = static_cast<float>(sin(radYaw));
		auto CY = static_cast<float>(cos(radYaw));

		return FVector(CP * CY, CP * SY, SP);
	}
};

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

struct FMinimalViewInfo
{
	FVector Location;
	FRotator Rotation;
	float FOV;
};


D3DMATRIX MatrixMultiplication(D3DMATRIX pM1, D3DMATRIX pM2);

