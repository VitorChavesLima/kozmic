#include "DX11Graphics.hpp"

#define EXCEPT(message) throw Utils::K_Exception(__FILE__, __LINE__, __FUNCTION__, message)

#include <kozmic/utils/Exception.hpp>

#include <iostream>

using namespace Kozmic::Core::Graphics;

void K_DX11Graphics::createDevice()
{
	HRESULT result;

	unsigned int createDeviceFlags = 0;

#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif // DEBUG


	result = D3D11CreateDevice(
		NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		createDeviceFlags,
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

	result = dxgiFactory->MakeWindowAssociation(this->m_hWindow, DXGI_MWA_NO_ALT_ENTER);
	if (FAILED(result)) EXCEPT("Could not make window association");

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

void K_DX11Graphics::createRenderTargetView()
{
	HRESULT result;
	result = this->m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**) &m_backBuffer);
	if (FAILED(result)) EXCEPT("Could not get the Back Buffer");

	result = this->m_device->CreateRenderTargetView(this->m_backBuffer, NULL, &this->m_renderTargetView);
	if (FAILED(result)) EXCEPT("Could not create the Render Target View");

	this->m_context->OMSetRenderTargets(1, &this->m_renderTargetView, nullptr);
}

void K_DX11Graphics::setViewport()
{
	D3D11_VIEWPORT viewport = {};

	viewport.TopLeftX = this->m_viewportConfig.left;
	viewport.TopLeftY = this->m_viewportConfig.top;
	viewport.Width = this->m_viewportConfig.right;
	viewport.Height = this->m_viewportConfig.bottom;

	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0;

	this->m_context->RSSetViewports(1, &viewport);
}

void K_DX11Graphics::setBufferSize(K_BufferSize t_bufferSize)
{
	HRESULT result;

	this->m_bufferSize = t_bufferSize;

	ID3D11RenderTargetView* nullViews[] = { nullptr };
	this->m_context->OMSetRenderTargets(ARRAYSIZE(nullViews), nullViews, nullptr);
	
	this->m_backBuffer->Release();
	this->m_renderTargetView->Release();

	this->m_context->ClearState();
	this->m_context->Flush();

	result = m_swapChain->ResizeBuffers(2, this->m_bufferSize.width, this->m_bufferSize.height, DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH);
	if (result == DXGI_ERROR_DEVICE_REMOVED || result == DXGI_ERROR_DEVICE_RESET) {
		
		this->m_swapChain->Release();
		this->m_device->Release();
		this->m_context->Release();
		
		this->createDevice();
		this->createSwapChain();
	}

	this->createRenderTargetView();
	this->setViewport();
}

void K_DX11Graphics::setFullscreen(bool t_bFullscreen)
{
}

K_DX11Graphics::K_DX11Graphics(HWND t_hWindow, bool t_bFullscreen)
{
	this->m_clearColor = { 0.0f, 0.0f, 0.3f, 1.0f };
	this->m_bVSync = true;
	this->m_hWindow = t_hWindow;

	RECT rect;
	GetClientRect(this->m_hWindow, &rect);

	this->m_bufferSize.width = rect.right;
	this->m_bufferSize.height = rect.bottom;

	this->m_bFullscreen = t_bFullscreen;

	this->m_viewportConfig = { 0.0f, 0.0f, (float) this->m_bufferSize.width, (float) this->m_bufferSize.height };

	this->createDevice();
	this->createSwapChain();
	this->createRenderTargetView();
	this->setViewport();
}

K_DX11Graphics::~K_DX11Graphics()
{
	this->m_renderTargetView->Release();
	this->m_backBuffer->Release();
	this->m_swapChain->Release();
	this->m_device->Release();
	this->m_context->Release();
}

void K_DX11Graphics::clear()
{
	const float clearColor[4] = { this->m_clearColor.red, this->m_clearColor.green, this->m_clearColor.blue, this->m_clearColor.alpha };
	this->m_context->ClearRenderTargetView(this->m_renderTargetView, clearColor);
}

void K_DX11Graphics::startDraw()
{
}

void K_DX11Graphics::finishDraw()
{
}

void K_DX11Graphics::show()
{
	this->m_swapChain->Present(this->m_bVSync, NULL);
	this->m_context->OMSetRenderTargets(1, &this->m_renderTargetView, nullptr);
}
