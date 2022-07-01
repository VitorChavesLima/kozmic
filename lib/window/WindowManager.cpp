#include <kozmic/window/WindowManager.hpp>

#ifdef WIN32
#include "_win32/Win32Window.hpp"
#endif // WIN32

using namespace Kozmic::Core;

std::unique_ptr<Window::KWindow> KWindowManager::getWindow(std::unique_ptr<Logging::K_Logger> t_logger, std::string t_sTitle, Window::KWindowSize t_size, Window::KWindowPosition t_position, Window::KWindowMode t_mode, std::string t_sGraphicsType) {
#ifdef WIN32
	return std::make_unique<Window::Win32::KWin32Window>(std::move(t_logger), t_sTitle, t_size, t_position, t_mode, t_sGraphicsType);
#endif
}