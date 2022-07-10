//
// Created by Vitor Chaves on 07/07/2022.
//

#ifndef KOZMIC_CONTROLLER_HPP
#define KOZMIC_CONTROLLER_HPP

#include <memory>
#include <string>

#include "kozmic/core/logging/Logger.hpp"

namespace Kozmic::Core::Utils {
    class K_Controller {
    protected:
        std::unique_ptr<Logging::K_Logger> m_logger;

    protected:
        explicit K_Controller(std::string t_loggerName);
    };
}

#endif //KOZMIC_CONTROLLER_HPP
