#pragma once

#include <Windows.h>
#include <d3d11.h>

#include <kozmic/graphics/Graphics.hpp>

namespace Kozmic::Core::Graphics {
	struct K_BufferSize {
		unsigned int width;
		unsigned int height;
	};
	
	class K_DX11Graphics : public K_Graphics {
	private:
		ID3D11Device* m_device = nullptr;
		ID3D11DeviceContext* m_context = nullptr;
		IDXGISwapChain* m_swapChain;

		D3D_FEATURE_LEVEL m_featureLevel = {};

		K_BufferSize m_bufferSize;
		bool m_bFullscreen;

		HWND m_hWindow;

	private:
		void createDevice();
		void createSwapChain();

	public:
		K_DX11Graphics(HWND t_hWindow, bool t_bFullscreen);
		~K_DX11Graphics();
	};
}