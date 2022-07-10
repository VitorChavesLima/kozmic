//
// Created by vitor on 07/07/2022.
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
        bool m_bInitialized = false;

    protected:
        explicit K_Controller(std::string t_loggerName);

    public:
        [[maybe_unused]] virtual void initialize() = 0;
        [[maybe_unused]] virtual void shutdown() = 0;
    };
}

#endif //KOZMIC_CONTROLLER_HPP
