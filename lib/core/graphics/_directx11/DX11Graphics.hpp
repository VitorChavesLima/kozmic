#pragma once

#include <Windows.h>
#include <d3d11.h>

#include <kozmic/core/graphics/GraphicsController.hpp>

namespace Kozmic::Core::Window::Win32 {
	class K_Win32WindowController;
}

namespace Kozmic::Core::Graphics {
	class K_Dx11GraphicsController : public K_GraphicsController {
	private:
		ID3D11Device* m_device = nullptr;
		ID3D11DeviceContext* m_context = nullptr;
		IDXGISwapChain* m_swapChain{};
		ID3D11Texture2D* m_backBuffer{};
		ID3D11RenderTargetView* m_renderTargetView{};

		D3D_FEATURE_LEVEL m_featureLevel = {};

		K_BufferSize m_bufferSize{};
		K_Viewport m_viewportConfig{};

		bool m_bFullscreen;
		bool m_bVSync;

		HWND m_hWindow;

		friend class Window::Win32::K_Win32WindowController;

	private:
		void createDevice();
		void createSwapChain();
		void createRenderTargetView();

	public:
        K_Dx11GraphicsController(const std::string& t_sWindowName, HWND t_hWindow, bool t_bFullscreen);
		~K_Dx11GraphicsController();

		void initialize();
		void shutdown();

		void setClearColor(K_ClearColor t_clearColor) override;

		void clear() override;
		void startDraw() override;
		void finishDraw() override;
		void show() override;

        void setViewport() override;
        void setBufferSize(K_BufferSize t_bufferSize) override;
        void setFullscreen(bool t_bFullscreen) override;
    };
}