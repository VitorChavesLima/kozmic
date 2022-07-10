#pragma once

#include "kozmic/core/utils/Controller.hpp"

namespace Kozmic::Core::Graphics {
	struct K_ClearColor {
		float red;
		float green;
		float blue;
		float alpha;
	};

    struct K_BufferSize {
        int width;
        int height;
    };

    struct K_Viewport {
        float left;
        float top;
        float right;
        float bottom;
    };

    class K_GraphicsController : public Utils::K_Controller {
        //<editor-fold desc="Properties">

	protected:
		K_ClearColor m_clearColor = { 0.0f, 0.0f, 0.0f, 0.0f };
        K_Viewport m_viewport = { 0, 0, 0, 0 };
        K_BufferSize m_bufferSize = { 0, 0 };

        bool m_bFullscreen;
        bool m_bVSync;

        //</editor-fold>

        //<editor-fold desc="Constructors and Destructors">

	public:
		explicit K_GraphicsController(const std::string& t_loggerName) : K_Controller(t_loggerName + "_GRAPHICS") {
            this->m_bVSync = false;
            this->m_bFullscreen = false;
			this->m_logger->info("Constructing Graphics Controller");
		}

		virtual ~K_GraphicsController() {
			this->m_logger->info("Cleaning Graphics Controller");
		}

        //</editor-fold>

        //<editor-fold desc="Available throughout the life cycle"

    public:
        [[maybe_unused]] virtual void clear() = 0;
        [[maybe_unused]] virtual void startDraw() = 0;
        [[maybe_unused]] virtual void finishDraw() = 0;
        [[maybe_unused]] virtual void show() = 0;

        //</editor-fold>

        //<editor-fold desc="Setters">

        [[maybe_unused]] virtual void setClearColor(K_ClearColor t_clearColor) = 0;
        [[maybe_unused]] virtual void setViewport(K_Viewport t_viewport) = 0;
        [[maybe_unused]] virtual void setBufferSize(K_BufferSize t_bufferSize) = 0;

        [[maybe_unused]] virtual void setFullscreen(bool t_bFullscreen) = 0;
        [[maybe_unused]] virtual void setVSync(bool t_bVSync) = 0;

        //</editor-fold>

        //<editor-fold desc="Getters">

        [[maybe_unused]] K_ClearColor getClearColor() { return this->m_clearColor; }
        [[maybe_unused]] K_Viewport getViewport() { return this->m_viewport; }
        [[maybe_unused]] K_BufferSize getBufferSize() { return this->m_bufferSize; }

        [[maybe_unused]] [[nodiscard]] bool getFullscreenState() const { return this->m_bFullscreen; }
        [[maybe_unused]] [[nodiscard]] bool getVSyncState() const { return this->m_bVSync; }

        //</editor-fold>
    };
}