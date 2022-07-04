#pragma once

#include <memory>
#include <string>

#include <kozmic/logging/Logger.hpp>

namespace Kozmic::Core::Utils {
	class K_Controller {
	protected:
		const std::string m_loggerName;
		std::unique_ptr<Logging::K_Logger> m_logger;

	protected:
		K_Controller(std::string t_loggerName) : m_loggerName(t_loggerName) { }

	// PRE INITIALIZATION ALLOWED METHODS
	// POST INITIALIZATION ALLOWED METHODS
	// GETTERS
	// SETTERS
	};
}