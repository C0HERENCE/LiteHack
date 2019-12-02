#pragma once
#include <d3d11.h>
#include <dxgi.h>
#include <Dwmapi.h>


ref class Overlay
{
public:
	int Init();
	void NewFrame();
	void RefreshAndSleep(int);
	void CleanUp();
	int Width;
	int Height;
private:
	HWND hwnd;
	bool CreateDeviceD3D(HWND hWnd);
	void CleanupDeviceD3D();
	void CreateRenderTarget();
	void CleanupRenderTarget();

	ID3D11Device* g_pd3dDevice;
	ID3D11DeviceContext* g_pd3dDeviceContext;
	IDXGISwapChain* g_pSwapChain;
	ID3D11RenderTargetView* g_mainRenderTargetView;

private:

};