#pragma once

#include <kozmic/logging/Logger.hpp>

namespace Kozmic::Core::Graphics {
	struct K_ClearColor {
		float red;
		float green;
		float blue;
		float alpha;
	};
	
	class K_Graphics {
	protected:
		std::unique_ptr<Logging::K_Logger> m_logger;
	
		K_ClearColor m_clearColor;

	public:
		virtual void setClearColor(K_ClearColor t_clearColor) = 0;

		virtual void clear() = 0;
		virtual void startDraw() = 0;
		virtual void finishDraw() = 0;
		virtual void show() = 0;
	};
}