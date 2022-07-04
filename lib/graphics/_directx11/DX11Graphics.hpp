#pragma once

#include <Windows.h>
#include <d3d11.h>

#include <kozmic/graphics/GraphicsController.hpp>

namespace Kozmic::Core::Window::Win32 {
	class K_Win32WindowController;
}

namespace Kozmic::Core::Graphics {
	struct K_BufferSize {
		unsigned int width;
		unsigned int height;
	};

	struct K_Viewport {
		float left;
		float top;
		float right;
		float bottom;
	};
	
	class K_DX11Graphics : public K_GraphicsController {
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
		bool m_bVSync;

		HWND m_hWindow;

		friend class Window::Win32::K_Win32WindowController;

	private:
		void createDevice();
		void createSwapChain();
		void createRenderTargetView();
		void setViewport();

		void setBufferSize(K_BufferSize t_bufferSize);
		void setFullscreen(bool t_bFullscreen);

	public:
		K_DX11Graphics(HWND t_hWindow, bool t_bFullscreen);
		~K_DX11Graphics();

		virtual void initialize() override {}
		virtual void shutdown() override {}

		virtual void setClearColor(K_ClearColor t_clearColor) override;

		virtual void clear() override;
		virtual void startDraw() override;
		virtual void finishDraw() override;
		virtual void show() override;
	};
}