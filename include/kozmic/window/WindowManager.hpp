#pragma once

#include <memory>

#include <kozmic/logging/Logger.hpp>
#include <kozmic/window/WindowController.hpp>

namespace Kozmic::Core {
	class KWindowManager {
	private:
		static KWindowManager* m_instance;

	private:
		KWindowManager();

	public:
		static KWindowManager* getInstance();
		
		std::unique_ptr<Window::K_WindowController> getWindow(std::string t_sTitle);
	};
}