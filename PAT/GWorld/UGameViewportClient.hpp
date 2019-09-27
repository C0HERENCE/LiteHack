#pragma once

class UGameViewportClient
{
public:
	class UWorld GetWorld() const;
private:
	char __pad0x80[0x80];
	uint64 m_pUWorld;
};
