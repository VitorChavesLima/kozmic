#include <kozmic/window/WindowManager.hpp>
#include <kozmic/logging/LoggingManager.hpp>

#ifdef WIN32
#include "_win32/Win32WindowController.hpp"
#endif // WIN32

using namespace Kozmic::Core;

//<editor-fold desc="Constructors and Destructors">

K_WindowManager::K_WindowManager() {
	this->m_logger = K_LoggingManager::getInstance()->getLogger("WINDOW_MANAGER");
}

//</editor-fold>

//<editor-fold desc="Manager related">

K_WindowManager* K_WindowManager::m_instance = nullptr;

K_WindowManager* K_WindowManager::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new K_WindowManager();
	}

	return m_instance;
}

//</editor-fold>

//<editor-fold desc="Generators">

std::unique_ptr<Window::K_WindowController> K_WindowManager::getWindow(const std::string& t_sTitle) {
#ifdef WIN32
	this->m_logger->info("Generating WIN32 Window");
	return std::make_unique<Window::Win32::K_Win32WindowController>(t_sTitle);
#endif
}

//</editor-fold>