#pragma once

#include <kozmic/logging/Logger.hpp>

namespace Kozmic::Core::Graphics {
	class K_Graphics {
	private:
		std::unique_ptr<Logging::K_Logger> m_logger;
	};
}