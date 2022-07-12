//
// Created by vitor on 07/07/2022.
//

#ifndef KOZMIC_LOGGER_HPP
#define KOZMIC_LOGGER_HPP

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <memory>
#include <vector>
#include <string>

namespace Kozmic::Core::Logging {
    class K_LoggerGenerator;

    class K_Logger {
    private:
        friend class K_LoggerGenerator;

        std::unique_ptr<spdlog::logger> m_logger;

    private:
        K_Logger(std::string t_sName, std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> t_consoleSink, std::shared_ptr<spdlog::sinks::basic_file_sink_mt> t_fileSink);

    public:
        template<typename... Args>
        void info(spdlog::format_string_t<Args...> t_sMessage, Args &&... t_args) {
            this->m_logger->info(t_sMessage, std::forward<Args>(t_args)...);
        }

        template<typename... Args>
        void warning(spdlog::format_string_t<Args...> t_sMessage, Args &&... t_args) {
            this->m_logger->warn(t_sMessage, std::forward<Args>(t_args)...);
        }

        template<typename... Args>
        void error(spdlog::format_string_t<Args...> t_sMessage, Args &&... t_args) {
            this->m_logger->error(t_sMessage, std::forward<Args>(t_args)...);
        }

        template<typename... Args>
        void critical(spdlog::format_string_t<Args...> t_sMessage, Args &&... t_args) {
            this->m_logger->critical(t_sMessage, std::forward<Args>(t_args)...);
        }

        template<typename... Args>
        void info(spdlog::wformat_string_t<Args...> t_sMessage, Args &&... t_args) {
            this->m_logger->info(t_sMessage, std::forward<Args>(t_args)...);
        }

        template<typename... Args>
        void warning(spdlog::wformat_string_t<Args...> t_sMessage, Args &&... t_args) {
            this->m_logger->warn(t_sMessage, std::forward<Args>(t_args)...);
        }

        template<typename... Args>
        void error(spdlog::wformat_string_t<Args...> t_sMessage, Args &&... t_args) {
            this->m_logger->error(t_sMessage, std::forward<Args>(t_args)...);
        }

        template<typename... Args>
        void critical(spdlog::wformat_string_t<Args...> t_sMessage, Args &&... t_args) {
            this->m_logger->critical(t_sMessage, std::forward<Args>(t_args)...);
        }
    };
}

#endif //KOZMIC_LOGGER_HPP
