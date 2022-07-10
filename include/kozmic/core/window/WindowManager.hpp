//
// Created by Vitor Chaves on 06/07/2022.
//

#ifndef KOZMIC_WINDOWMANAGER_HPP
#define KOZMIC_WINDOWMANAGER_HPP

#include <memory>

#include "kozmic/core/logging/Logger.hpp"
#include "WindowController.hpp"

namespace Kozmic::Core {
    class K_WindowManager {
        //<editor-fold desc="Properties">

    private:
        static K_WindowManager* m_instance;
        std::unique_ptr<Logging::K_Logger> m_logger;

        //</editor-fold>

        //<editor-fold desc="Constructors and Destructors">

    private:
        K_WindowManager();

        //</editor-fold>

        //<editor-fold desc="Manager related">

    public:
        static K_WindowManager* getInstance();

        //</editor-fold>

        //<editor-fold desc="Generators">

    public:
        std::unique_ptr<Window::K_WindowController> getWindow(const std::string& t_sTitle);

        //</editor-fold>
    };
}

#endif //KOZMIC_WINDOWMANAGER_HPP
