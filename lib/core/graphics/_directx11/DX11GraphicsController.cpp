#include "DX11GraphicsController.hpp"

#define EXCEPT(message) throw Utils::K_Exception(__FILE__, __LINE__, __FUNCTION__, message)

#include <kozmic/core/utils/Exception.hpp>
#include "DX11ShaderController.hpp"
#include "DX11MeshController.hpp"

#include <cstdio>
#include <string>

using namespace Kozmic::Core::Graphics;

//<editor-fold desc="Internal methods">

void K_Dx11GraphicsController::createDevice()
{
    this->m_logger->info("Creating device");

	HRESULT result;

	unsigned int createDeviceFlags = 0;

#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif // _DEBUG

	result = D3D11CreateDevice(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		createDeviceFlags,
		nullptr,
		0,
		D3D11_SDK_VERSION,
		&this->m_device,
		&this->m_featureLevel,
		&this->m_context
	);

	if (FAILED(result)) EXCEPT("Could not create D3D11Device");
}

void K_Dx11GraphicsController::createSwapChain()
{
    this->m_logger->info("Creating swap chain");

    HRESULT result;
	DXGI_SWAP_CHAIN_DESC swapChainDesc = { 0 };
	
	swapChainDesc.BufferDesc.Width = this->m_bufferSize.width;
	swapChainDesc.BufferDesc.Height = this->m_bufferSize.height;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount = 2;
	swapChainDesc.OutputWindow = this->m_hWindow;
	swapChainDesc.Windowed = !this->m_bFullscreen;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	result = this->m_dxgiFactory->MakeWindowAssociation(this->m_hWindow, DXGI_MWA_NO_ALT_ENTER);
	if (FAILED(result)) EXCEPT("Could not make window association");

	result = this->m_dxgiFactory->CreateSwapChain(
		this->m_device,
		&swapChainDesc,
		&this->m_swapChain
	);
	if (FAILED(result)) EXCEPT("Could not create a Swap Chain");
}

void K_Dx11GraphicsController::createRenderTargetView()
{
    this->m_logger->info("Creating render target view");

    HRESULT result;
	result = this->m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**) &m_backBuffer);
	if (FAILED(result)) EXCEPT("Could not get the Back Buffer");

	result = this->m_device->CreateRenderTargetView(this->m_backBuffer, nullptr, &this->m_renderTargetView);
	if (FAILED(result)) EXCEPT("Could not create the Render Target View");

	this->m_context->OMSetRenderTargets(1, &this->m_renderTargetView, nullptr);
}

void K_Dx11GraphicsController::fetchDisplayModes(unsigned int t_nAdapterIndex, unsigned int t_nOutputIndex, IDXGIOutput* t_pOutput) {
    UINT nDisplayModeCount = 0;
    DXGI_FORMAT format = DXGI_FORMAT_R8G8B8A8_UNORM;
    UINT flags         = DXGI_ENUM_MODES_INTERLACED;

    t_pOutput->GetDisplayModeList( format, flags, &nDisplayModeCount, nullptr);

    auto * pModeDescriptions = new DXGI_MODE_DESC[nDisplayModeCount];
    t_pOutput->GetDisplayModeList( format, flags, &nDisplayModeCount, pModeDescriptions);

    for(unsigned int i = 0; i < nDisplayModeCount; i++) {
        K_Resolution resolution = { };
        resolution.id = i;
        resolution.width = pModeDescriptions[i].Width;
        resolution.height = pModeDescriptions[i].Height;
        resolution.refreshRate = pModeDescriptions[i].RefreshRate.Numerator / pModeDescriptions[i].RefreshRate.Denominator;

        this->m_videoAdapterData[t_nAdapterIndex].videoOutputList[t_nOutputIndex].resolutionList.push_back(resolution);
    }
}

void K_Dx11GraphicsController::fetchOutputs(unsigned int t_nAdapterIndex, IDXGIAdapter* t_pAdapter) {
    UINT nOutputIndex = 0;
    IDXGIOutput* pOutput;

    while (t_pAdapter->EnumOutputs(nOutputIndex, &pOutput) != DXGI_ERROR_NOT_FOUND) {
        DXGI_OUTPUT_DESC outputDescription;
        pOutput->GetDesc(&outputDescription);

        K_VideoOutput output;
        output.id = nOutputIndex;
        output.name = outputDescription.DeviceName;

        this->m_videoAdapterData[t_nAdapterIndex].videoOutputList.push_back(output);
        this->fetchDisplayModes(t_nAdapterIndex, nOutputIndex, pOutput);

        ++nOutputIndex;
    }
}

void K_Dx11GraphicsController::fetchAvailableVideoAdapterData() {

    this->m_logger->info("Fetching available video adapter data");

    UINT nAdapterIndex = 0;
    IDXGIAdapter* pAdapter;

    while(this->m_dxgiFactory->EnumAdapters(nAdapterIndex, &pAdapter) != DXGI_ERROR_NOT_FOUND)
    {
        DXGI_ADAPTER_DESC adapterDescription;
        pAdapter->GetDesc(&adapterDescription);

        K_VideoAdapter adapter;
        adapter.id = nAdapterIndex;
        adapter.name = std::wstring(adapterDescription.Description);

        this->m_videoAdapterData.push_back(adapter);

        fetchOutputs(nAdapterIndex, pAdapter);
        ++nAdapterIndex;
    }
}

//</editor-fold>

//<editor-fold desc="Constructors and Destructors">

K_Dx11GraphicsController::K_Dx11GraphicsController(const std::string& t_sWindowName, HWND t_hWindow, bool t_bFullscreen) : K_GraphicsController(t_sWindowName + "_DX11")
{
    this->m_clearColor = { 0.0f, 0.0f, 0.3f, 1.0f };
    this->m_bVSync = false;
    this->m_hWindow = t_hWindow;

    RECT rect;
    GetClientRect(this->m_hWindow, &rect);

    this->m_bufferSize.width = rect.right;
    this->m_bufferSize.height = rect.bottom;

    this->m_bFullscreen = t_bFullscreen;

    this->m_viewport = { 0.0f, 0.0f, (float) this->m_bufferSize.width, (float) this->m_bufferSize.height };

    this->createDevice();

    HRESULT result;
    result = this->m_device->QueryInterface(__uuidof(IDXGIDevice), (void**) &this->m_dxgiDevice);
    if (FAILED(result)) EXCEPT("Could not get DxgiDevice");

    result = this->m_dxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**) &this->m_dxgiAdapter);
    if (FAILED(result)) EXCEPT("Could not get DxgiAdapter");

    result = this->m_dxgiAdapter->GetParent(__uuidof(IDXGIFactory), (void**) &this->m_dxgiFactory);
    if (FAILED(result)) EXCEPT("Could not get DxgiFactory");

    this->fetchAvailableVideoAdapterData();

    this->createSwapChain();
    this->createRenderTargetView();

    this->m_shaderController = std::make_shared<K_Dx11ShaderController>(t_sWindowName, this->m_device, this->m_context);
    this->m_meshController = std::make_shared<K_Dx11MeshController>(t_sWindowName, this->m_device, this->m_context);

    this->m_dxgiFactory->Release();
    this->m_dxgiAdapter->Release();
    this->m_dxgiDevice->Release();
}

K_Dx11GraphicsController::~K_Dx11GraphicsController()
{
    this->m_shaderController.reset();

    this->m_renderTargetView->Release();
    this->m_backBuffer->Release();
    this->m_swapChain->Release();
    this->m_device->Release();
    this->m_context->Release();
}

//</editor-fold>

//<editor-fold desc="Available throughout the life cycle">

void K_Dx11GraphicsController::clear()
{
    const float clearColor[4] = { this->m_clearColor.red, this->m_clearColor.green, this->m_clearColor.blue, this->m_clearColor.alpha };
    this->m_context->ClearRenderTargetView(this->m_renderTargetView, clearColor);
}

void K_Dx11GraphicsController::startDraw()
{
}

void K_Dx11GraphicsController::finishDraw()
{
}

void K_Dx11GraphicsController::show()
{
    this->m_swapChain->Present(this->m_bVSync, NULL);
    this->m_context->OMSetRenderTargets(1, &this->m_renderTargetView, nullptr);
}

void K_Dx11GraphicsController::createViewport() {
    D3D11_VIEWPORT viewport = {};

    viewport.TopLeftX = this->m_viewport.left;
    viewport.TopLeftY = this->m_viewport.top;
    viewport.Width = this->m_viewport.right;
    viewport.Height = this->m_viewport.bottom;

    viewport.MinDepth = 0.0f;
    viewport.MaxDepth = 1.0;

    this->m_context->RSSetViewports(1, &viewport);
}

//</editor-fold>

//<editor-fold desc="Setters">

void K_Dx11GraphicsController::setClearColor(K_ClearColor t_clearColor)
{
    this->m_clearColor = t_clearColor;
}

void K_Dx11GraphicsController::setViewport(K_Viewport t_viewport)
{
    this->m_viewport = t_viewport;

    this->createViewport();
}

void K_Dx11GraphicsController::setBufferSize(K_BufferSize t_bufferSize)
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
    this->createViewport();
}

void K_Dx11GraphicsController::setFullscreen(bool t_bFullscreen)
{
    HRESULT result;
    this->m_bFullscreen = t_bFullscreen;

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
    this->createViewport();
}

void K_Dx11GraphicsController::setVSync(bool t_bVSync) {
    this->m_bVSync = t_bVSync;
}

//</editor-fold