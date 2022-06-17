#pragma once

#include <string>

#include <kozmic/logging/Logger.hpp>

namespace Kozmic::Core::Logging {
	class K_LoggerGenerator {
	private:
		std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> m_consoleSink;
		std::shared_ptr<spdlog::sinks::basic_file_sink_mt> m_fileSink;

	public:
		K_LoggerGenerator(std::string t_sPath);

		std::unique_ptr<K_Logger> getLogger(std::string t_sName);
	};
}