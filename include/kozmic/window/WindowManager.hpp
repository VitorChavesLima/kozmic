#pragma once

#include <memory>

#include <kozmic/logging/Logger.hpp>
#include <kozmic/window/Window.hpp>

namespace Kozmic::Core {
	class KWindowManager {
	public:
		std::unique_ptr<Window::KWindow> getWindow(std::unique_ptr<Logging::K_Logger> t_logger, std::string t_sTitle, Window::KWindowSize t_size, Window::KWindowPosition t_position, Window::KWindowMode t_mode, std::string t_sGraphicsType);
	};
}