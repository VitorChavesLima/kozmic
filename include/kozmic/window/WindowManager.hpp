#pragma once

#include <memory>

#include <kozmic/window/Window.hpp>

namespace Kozmic::Core {
	class KWindowManager {
	public:
		std::unique_ptr<Window::KWindow> getWindow(std::string t_sTitle, Window::KWindowSize t_size, Window::KWindowPosition t_position, Window::KWindowMode t_mode);
	};
}