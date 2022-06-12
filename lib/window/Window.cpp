#include <kozmic/window/Window.hpp>

using namespace Kozmic::Core::Window;

KWindow::KWindow(std::string t_sTitle, KWindowSize t_size, KWindowPosition t_position, KWindowMode t_mode) {
	this->m_sTitle = t_sTitle;
	this->m_size = t_size;
	this->m_position = t_position;
	this->m_mode = t_mode;
}

std::string KWindow::getTitle()
{
	return this->m_sTitle;
}

KWindowSize KWindow::getSize()
{
	return this->m_size;
}

KWindowPosition KWindow::getPosition()
{
	return this->m_position;
}

KWindowMode KWindow::getMode() {
	return this->m_mode;
}