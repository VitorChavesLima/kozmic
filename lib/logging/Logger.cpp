#include <kozmic/logging/Logger.hpp>

using namespace Kozmic::Core::Logging;

K_Logger::K_Logger(std::string t_sName, std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> t_consoleSink, std::shared_ptr<spdlog::sinks::basic_file_sink_mt> t_fileSink) {
	spdlog::sinks_init_list sinkList = { t_consoleSink, t_fileSink };

	this->m_logger = std::make_unique<spdlog::logger>(t_sName, sinkList.begin(), sinkList.end());
}