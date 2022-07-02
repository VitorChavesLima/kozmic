#pragma once

#include <kozmic/logging/Logger.hpp>

namespace Kozmic::Core::Graphics {
	class K_Graphics {
	protected:
		std::unique_ptr<Logging::K_Logger> m_logger;
	
	private:
		virtual void clear() = 0;
		virtual void startDraw() = 0;
		virtual void finishDraw() = 0;
		virtual void show() = 0;
	};
}