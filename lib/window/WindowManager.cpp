#include <kozmic/window/WindowManager.hpp>

#ifdef WIN32
#include "_win32/Win32WindowController.hpp"
#endif // WIN32

using namespace Kozmic::Core;

KWindowManager* KWindowManager::m_instance = 0;

KWindowManager::KWindowManager() {

}

KWindowManager* KWindowManager::getInstance()
{
	if (m_instance == 0)
	{
		m_instance = new KWindowManager();
	}

	return m_instance;
}

std::unique_ptr<Window::K_WindowController> KWindowManager::getWindow(std::string t_sTitle) {
#ifdef WIN32
	return std::make_unique<Window::Win32::K_Win32WindowController>(t_sTitle);
#endif
}