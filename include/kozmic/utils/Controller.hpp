#pragma once

#include <memory>
#include <string>

#include <kozmic/logging/Logger.hpp>

namespace Kozmic::Core::Utils {
	class K_Controller {
	protected:
		std::unique_ptr<Logging::K_Logger> m_logger;

	protected:
		K_Controller(std::string t_loggerName);

	public:
		virtual void initialize() = 0;
		virtual void shutdown() = 0;
	};
}