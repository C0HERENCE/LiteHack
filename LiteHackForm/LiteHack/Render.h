#pragma once
#include "Overlay/imgui.h"
#include "Overlay/imgui_impl_win32.h"
#include "Overlay/imgui_impl_dx11.h"
#include <d3d11.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>
#include <Dwmapi.h>
#include <iostream>
#pragma comment(lib, "Dwmapi.lib")

#include "..//GWorld/FCameraCacheEntry.h"
#include "..//GWorld/Core/FColor.h"
#include "..//GWorld/AActor.h"

class Render
{
public:
	int Initialize();
	void CleanUp();
	void RefreshAndSleep(int);
	void NewFrame();
	void DrawLine(FVector from, FVector end, FColor color, float thickness);
	void DrawString(FVector pos, FColor color, std::string string);
	void DrawString(FVector pos, FColor color, char* string, int length);
	void DrawCircle(FVector center, float radius, FColor color);
	void DrawRectangle(FVector a, float, float, FColor color);
	void DrawRectangleFilled(FVector a, float, float, FColor color);
	FVector WorldToScreen(FVector WorldLocation, updates::off::FMinimalViewInfo POV);
	void DrawWorldToScreenScreenText(FVector WorldLocatoin, updates::off::FMinimalViewInfo, FColor color,std::string string);
	int Width;
	int Height;
private:
	HWND hwnd;
	bool CreateDeviceD3D(HWND hWnd);
	void CleanupDeviceD3D();
	void CreateRenderTarget();
	void CleanupRenderTarget();
	LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	bool InitializeDirect3d11App();
	
	ImVec4 clear_color = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	HRESULT hr;
	ID3D11Device* g_pd3dDevice;
	ID3D11DeviceContext* g_pd3dDeviceContext;
	IDXGISwapChain* g_pSwapChain;
	ID3D11RenderTargetView* g_mainRenderTargetView;

	IDXGISwapChain* SwapChain;
	ID3D11Device* d3d11Device;
	ID3D11DeviceContext* d3d11DevCon;
	ID3D11RenderTargetView* renderTargetView;
	ID3D11Buffer* squareIndexBuffer;
	ID3D11DepthStencilView* depthStencilView;
	ID3D11Texture2D* depthStencilBuffer;
	ID3D11Buffer* squareVertBuffer;
	ID3D11VertexShader* VS;
	ID3D11PixelShader* PS;
	ID3D10Blob* VS_Buffer;
	ID3D10Blob* PS_Buffer;
	ID3D11InputLayout* vertLayout;
	ID3D11Buffer* cbPerObjectBuffer;
	ID3D11RasterizerState* WireFrame;
};