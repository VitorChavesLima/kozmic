#pragma once

#include <Windows.h>
#include <d3d11.h>

#include <kozmic/graphics/Graphics.hpp>

namespace Kozmic::Core::Graphics {
	struct K_BufferSize {
		unsigned int width;
		unsigned int height;
	};

	struct K_Viewport {
		unsigned int left;
		unsigned int top;
		unsigned int right;
		unsigned int bottom;
	};
	
	class K_DX11Graphics : public K_Graphics {
	private:
		ID3D11Device* m_device = nullptr;
		ID3D11DeviceContext* m_context = nullptr;
		IDXGISwapChain* m_swapChain;
		ID3D11Texture2D* m_backBuffer;
		ID3D11RenderTargetView* m_renderTargetView;

		D3D_FEATURE_LEVEL m_featureLevel = {};

		K_BufferSize m_bufferSize;
		K_Viewport m_viewportConfig;
		bool m_bFullscreen;

		HWND m_hWindow;

	private:
		void createDevice();
		void createSwapChain();
		void createRenderTargetView();
		void setViewport();

	public:
		K_DX11Graphics(HWND t_hWindow, bool t_bFullscreen);
		~K_DX11Graphics();
	};
}