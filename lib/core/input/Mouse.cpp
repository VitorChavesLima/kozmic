#include <kozmic/core/input/Mouse.hpp>

using namespace Kozmic::Core::Input;

K_Mouse::K_Mouse()
{
	this->m_nXPos = 0;
	this->m_nYPos = 0;
}

void K_Mouse::addListener(std::shared_ptr<K_MouseListener> t_listener) {
	this->m_listeners.push_back(t_listener);
}

void K_Mouse::removeListener(std::shared_ptr<K_MouseListener> t_listener) {
	// TODO
}