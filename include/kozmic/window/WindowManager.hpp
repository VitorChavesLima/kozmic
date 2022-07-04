#pragma once

#include <memory>

#include <kozmic/logging/Logger.hpp>
#include <kozmic/window/WindowController.hpp>

namespace Kozmic::Core {
	class KWindowManager {
	public:
		std::unique_ptr<Window::K_WindowController> getWindow(std::unique_ptr<Logging::K_Logger> t_logger, std::string t_sTitle, Window::K_WindowSize t_size, Window::K_WindowPosition t_position, Window::K_WindowMode t_mode, std::string t_sGraphicsType);
	};
}