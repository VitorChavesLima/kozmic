#pragma once

#include <memory>

#include <kozmic/logging/LoggerGenerator.hpp>

namespace Kozmic::Core {
	class K_LoggingManager {
	private:
		std::unique_ptr<Logging::K_LoggerGenerator> m_loggerGenerator;

	public:
		K_LoggingManager();

		std::unique_ptr<Logging::K_Logger> getLogger(std::string t_sName);
	};
}