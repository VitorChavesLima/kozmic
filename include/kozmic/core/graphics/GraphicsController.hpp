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
	protected:
		K_ClearColor m_clearColor;

	public:
		K_GraphicsController(std::string t_loggerName) : K_Controller(t_loggerName + "_GRAPHICS") {
			this->m_clearColor = { 0.0f, 0.0f, 0.0f, 0.0f };
			this->m_logger->info("Constructing Graphics Controller");
		}

		virtual ~K_GraphicsController() {
			this->m_logger->info("Cleaning Graphics Controller");
		}

		virtual void setClearColor(K_ClearColor t_clearColor) = 0;

		virtual void clear() = 0;
		virtual void startDraw() = 0;
		virtual void finishDraw() = 0;
		virtual void show() = 0;

        [[maybe_unused]] virtual void setViewport() = 0;
        [[maybe_unused]] virtual void setBufferSize(K_BufferSize t_bufferSize) = 0;
        [[maybe_unused]] virtual void setFullscreen(bool t_bFullscreen) = 0;
	};
}