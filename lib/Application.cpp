#include <kozmic/Application.hpp>

using namespace Kozmic::Core;

K_Application::K_Application() {
	this->m_loggingManager = std::make_unique<K_LoggingManager>();
	this->m_windowManager = std::make_unique<KWindowManager>();
}