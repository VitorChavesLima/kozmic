#pragma once

#include <memory>

#include <kozmic/logging/LoggerGenerator.hpp>

namespace Kozmic::Core {
	class K_LoggingManager {
	private:
		static K_LoggingManager* m_instance;

		std::unique_ptr<Logging::K_LoggerGenerator> m_loggerGenerator;

	private:
		K_LoggingManager();

	public:
		static K_LoggingManager* getInstance();

		std::unique_ptr<Logging::K_Logger> getLogger(std::string t_sName);
	};
}