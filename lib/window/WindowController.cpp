#include <kozmic/window/WindowController.hpp>

using namespace Kozmic::Core::Window;

K_WindowController::K_WindowController(std::string t_sTitle, K_WindowSize t_size, K_WindowPosition t_position, K_WindowMode t_mode, std::string t_sGraphicsControllerType) {
	this->m_sTitle = t_sTitle;
	this->m_size = t_size;
	this->m_position = t_position;
	this->m_mode = t_mode;
	this->m_sGraphicsControllerType = t_sGraphicsControllerType;
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