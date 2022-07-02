#include "DX11Graphics.hpp"

#define EXCEPT(message) throw Utils::K_Exception(__FILE__, __LINE__, __FUNCTION__, message)

#include <kozmic/utils/Exception.hpp>

#include <iostream>

using namespace Kozmic::Core::Graphics;

void K_DX11Graphics::createDevice()
{
	HRESULT result;

	result = D3D11CreateDevice(
		NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		D3D11_CREATE_DEVICE_DEBUG,
		NULL,
		0,
		D3D11_SDK_VERSION,
		&this->m_device,
		&this->m_featureLevel,
		&this->m_context
	);

	if (FAILED(result)) EXCEPT("Could not create D3D11Device");
}

void K_DX11Graphics::createSwapChain()
{
	HRESULT result;
	DXGI_SWAP_CHAIN_DESC swapChainDesc = { 0 };
	
	swapChainDesc.BufferDesc.Width = this->m_bufferSize.width;
	swapChainDesc.BufferDesc.Height = this->m_bufferSize.height;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 1;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount = 2;
	swapChainDesc.OutputWindow = this->m_hWindow;
	swapChainDesc.Windowed = !this->m_bFullscreen;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	IDXGIDevice* dxgiDevice = nullptr;
	result = this->m_device->QueryInterface(__uuidof(IDXGIDevice), (void**) &dxgiDevice);
	if (FAILED(result)) EXCEPT("Could not get DxgiDevice");

	IDXGIAdapter* dxgiAdapter = nullptr;
	result = dxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**) &dxgiAdapter);
	if (FAILED(result)) EXCEPT("Could not get DxgiAdapter");

	IDXGIFactory* dxgiFactory = nullptr;
	result = dxgiAdapter->GetParent(__uuidof(IDXGIFactory), (void**) &dxgiFactory);
	if (FAILED(result)) EXCEPT("Could not get DxgiFactory");

	result = dxgiFactory->CreateSwapChain(
		this->m_device,
		&swapChainDesc,
		&this->m_swapChain
	);
	if (FAILED(result)) EXCEPT("Could not create a Swap Chain");

	dxgiDevice->Release();
	dxgiAdapter->Release();
	dxgiFactory->Release();
}

K_DX11Graphics::K_DX11Graphics(HWND t_hWindow, bool t_bFullscreen)
{
	this->m_hWindow = t_hWindow;

	RECT rect;
	GetClientRect(this->m_hWindow, &rect);

	this->m_bufferSize.width = rect.right;
	this->m_bufferSize.height = rect.bottom;

	this->m_bFullscreen = t_bFullscreen;

	this->createDevice();
	this->createSwapChain();
}

K_DX11Graphics::~K_DX11Graphics()
{
	this->m_swapChain->Release();
	this->m_device->Release();
	this->m_context->Release();
}
