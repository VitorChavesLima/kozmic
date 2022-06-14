#include <kozmic/input/Keyboard.hpp>

using namespace Kozmic::Core::Input;

void K_Keyboard::addListener(std::shared_ptr<K_KeyboardListener> t_listener) {
	this->m_listeners.push_back(t_listener);
}

void K_Keyboard::removeListener(std::shared_ptr<K_KeyboardListener> t_listener) {
	// TODO
}