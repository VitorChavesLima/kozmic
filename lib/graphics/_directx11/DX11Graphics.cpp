#include "DX11Graphics.hpp"

#define EXCEPT(message) throw Utils::K_Exception(__FILE__, __LINE__, __FUNCTION__, message)

#include <kozmic/utils/Exception.hpp>

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

K_DX11Graphics::K_DX11Graphics(HWND t_hWindow)
{
	this->m_hWindow = t_hWindow;

	this->createDevice();
}

K_DX11Graphics::~K_DX11Graphics()
{
	this->m_device->Release();
	this->m_context->Release();
}
