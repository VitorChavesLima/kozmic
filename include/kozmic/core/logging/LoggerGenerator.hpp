//
// Created by vitor on 07/07/2022.
//

#ifndef KOZMIC_LOGGERGENERATOR_HPP
#define KOZMIC_LOGGERGENERATOR_HPP

#include <string>

#include "Logger.hpp"

namespace Kozmic::Core::Logging {
    class K_LoggerGenerator {
    private:
        std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> m_consoleSink;
        std::shared_ptr<spdlog::sinks::basic_file_sink_mt> m_fileSink;

    public:
        explicit K_LoggerGenerator(std::string t_sPath);

        std::unique_ptr<K_Logger> getLogger(std::string t_sName);
    };
}

#endif //KOZMIC_LOGGERGENERATOR_HPP
