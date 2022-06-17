#pragma once

#include <memory>

#include <kozmic/logging/LoggingManager.hpp>
#include <kozmic/window/WindowManager.hpp>

namespace Kozmic::Core {
	class K_Application {
	private:
		std::unique_ptr<K_LoggingManager> m_loggingManager;
		std::unique_ptr<KWindowManager> m_windowManager;

	public:
		K_Application();
	};
}