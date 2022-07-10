#pragma once

#include <Windows.h>
#include <d3d11.h>

#include <kozmic/core/graphics/GraphicsController.hpp>

namespace Kozmic::Core::Window::Win32 {
	class K_Win32WindowController;
}

namespace Kozmic::Core::Graphics {
	class K_Dx11GraphicsController : public K_GraphicsController {

        //<editor-fold desc="Properties">

    private:
		ID3D11Device* m_device = nullptr;
		ID3D11DeviceContext* m_context = nullptr;
		IDXGISwapChain* m_swapChain = {};
		ID3D11Texture2D* m_backBuffer = {};
		ID3D11RenderTargetView* m_renderTargetView = {};

		D3D_FEATURE_LEVEL m_featureLevel = {};

		HWND m_hWindow;

		friend class Window::Win32::K_Win32WindowController;

        //</editor-fold>

        //<editor-fold desc="Internal methods">

    private:
		void createDevice();
		void createSwapChain();
		void createRenderTargetView();
        void createViewport();

        //</editor-fold>

        //<editor-fold desc="Constructors and Destructors">

	public:
        K_Dx11GraphicsController(const std::string& t_sWindowName, HWND t_hWindow, bool t_bFullscreen);
		~K_Dx11GraphicsController() override;

        //</editor-fold>

        //<editor-fold desc="Available throughout the life cycle">

		void clear() override;
		void startDraw() override;
		void finishDraw() override;
		void show() override;

        //</editor-fold>

        //<editor-fold desc="Setters">

        void setClearColor(K_ClearColor t_clearColor) override;
        void setViewport(K_Viewport t_viewport) override;
        void setBufferSize(K_BufferSize t_bufferSize) override;

        void setFullscreen(bool t_bFullscreen) override;
        void setVSync(bool t_bVSync) override;

        //</editor-fold>
    };
}