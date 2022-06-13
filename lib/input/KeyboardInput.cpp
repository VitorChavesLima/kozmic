#include <kozmic/input/KeyboardInput.hpp>

using namespace Kozmic::Core::Input;

void K_KeyboardInput::addListener(std::shared_ptr<K_KeyboardInputListener> t_listener)
{
	this->m_listeners.push_back(t_listener);
}

void K_KeyboardInput::removeListener(std::shared_ptr<K_KeyboardInputListener> t_listener)
{
	this->m_listeners.erase(std::remove(this->m_listeners.begin(), this->m_listeners.end(), t_listener), this->m_listeners.end());
}