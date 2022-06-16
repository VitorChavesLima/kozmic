#include <kozmic/logging/Logger.hpp>
#include "spdlog/sinks/stdout_color_sinks.h"

using namespace Kozmic::Core::Logging;

K_Logger::K_Logger(std::string t_sName) {
	auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	spdlog::sinks_init_list sink_list = { console_sink };

	this->m_logger = std::make_unique<spdlog::logger>(t_sName , sink_list.begin(), sink_list.end());
}