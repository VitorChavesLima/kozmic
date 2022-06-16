#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_sinks.h>

#include <memory>
#include <vector>
#include <string>

namespace Kozmic::Core::Logging {
	class K_Logger {
	private:
		std::unique_ptr<spdlog::logger> m_logger;

	public:
		K_Logger(std::string t_sName);

		template<typename... Args>
		void info(spdlog::format_string_t<Args...> t_sMessage, Args &&... args) {
			this->m_logger->info(t_sMessage, std::forward<Args>(args)...);
		}
	};
}