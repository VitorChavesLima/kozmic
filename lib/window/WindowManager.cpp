#include <kozmic/window/WindowManager.hpp>

#ifdef WIN32
#include "_win32/Win32WindowController.hpp"
#endif // WIN32

using namespace Kozmic::Core;

std::unique_ptr<Window::K_WindowController > KWindowManager::getWindow(std::unique_ptr<Logging::K_Logger> t_logger, std::string t_sTitle, Window::K_WindowSize t_size, Window::K_WindowPosition t_position, Window::K_WindowMode t_mode, std::string t_sGraphicsType) {
#ifdef WIN32
	return std::make_unique<Window::Win32::K_Win32WindowController>(std::move(t_logger), t_sTitle, t_size, t_position, t_mode, t_sGraphicsType);
#endif
}