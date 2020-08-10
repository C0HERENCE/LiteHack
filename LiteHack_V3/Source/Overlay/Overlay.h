#pragma once
#include <d3d11.h>
#include <dxgi.h>
#include <Dwmapi.h>
#include "Imgui/imgui.h"
#include "Imgui/imgui_impl_dx11.h"
#include "Imgui/imgui_impl_win32.h"
#include <vector>
#include <TlHelp32.h>
#include <string>
#include <Windows.h>

class Overlay
{
public:

	LONG Width;
	LONG Height;
	HWND GameWnd;
	HWND MyWnd;
	WNDCLASSEX wClass;

	float ScreenCenterX;
	float ScreenCenterY;

	int Init();
	void NewFrame();
	void RefreshAndSleep(int);
	void Cleanup();
	void SetWindowToTarget();
	bool LoadTextureFromFile(const char* filename, ID3D11ShaderResourceView** out_srv);

	bool CreateDeviceD3D(HWND hWnd);
	void CleanupDeviceD3D();
	void CreateRenderTarget();
	void CleanupRenderTarget();

	ID3D11Device* g_pd3dDevice;
	ID3D11DeviceContext* g_pd3dDeviceContext;
	IDXGISwapChain* g_pSwapChain;
	ID3D11RenderTargetView* g_mainRenderTargetView;
};

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
