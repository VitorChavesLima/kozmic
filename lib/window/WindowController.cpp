#include <kozmic/window/WindowController.hpp>

using namespace Kozmic::Core::Window;

K_WindowController::K_WindowController(std::string t_sTitle, std::string t_sLoggerName) : Utils::K_Controller(t_sLoggerName + "_WINDOW") {
	this->m_logger->info("Constructing Window");

	this->m_sTitle = t_sTitle;
	this->m_size = { 800, 600 };
	this->m_position = { 0, 0 };
	this->m_mode = K_WindowMode::WINDOWED;
	this->m_sGraphicsControllerType = "DX11";
}

std::string K_WindowController::getTitle()
{
	return this->m_sTitle;
}

K_WindowSize K_WindowController::getSize()
{
	return this->m_size;
}

K_WindowPosition K_WindowController::getPosition()
{
	return this->m_position;
}

K_WindowMode K_WindowController::getMode() {
	return this->m_mode;
}