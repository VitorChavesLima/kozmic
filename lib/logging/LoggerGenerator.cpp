#include <kozmic/logging/LoggerGenerator.hpp>

using namespace Kozmic::Core::Logging;

K_LoggerGenerator::K_LoggerGenerator(std::string t_sPath)
{
    this->m_consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    this->m_fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(t_sPath, true);
}

std::unique_ptr<K_Logger> K_LoggerGenerator::getLogger(std::string t_sName) {
    return std::unique_ptr<K_Logger>(new K_Logger(t_sName, this->m_consoleSink, this->m_fileSink));
}

