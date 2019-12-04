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
	bool LoadTextureFromFile(const char* filename, ID3D11ShaderResourceView** out_srv, int* out_width, int* out_height);
	int Width;
	int Height;
//private:
	HWND hwnd;
	bool CreateDeviceD3D(HWND hWnd);
	void CleanupDeviceD3D();
	void CreateRenderTarget();
	void CleanupRenderTarget();

	ID3D11Device* g_pd3dDevice;
	ID3D11DeviceContext* g_pd3dDeviceContext;
	IDXGISwapChain* g_pSwapChain;
	ID3D11RenderTargetView* g_mainRenderTargetView;
	ID3D11BlendState* g_pBlendState;
private:

};

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
