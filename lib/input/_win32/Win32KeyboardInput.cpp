#include "Win32KeyboardInput.hpp"

void Kozmic::Core::Input::Win32::K_Win32KeyboardInput::notifyKeyUp(int t_nKey)
{
	for (int i = 0; i < this->m_listeners.size(); i++) {
		this->m_listeners[i]->keyUpHandler(t_nKey);
	}
}

void Kozmic::Core::Input::Win32::K_Win32KeyboardInput::notifyKeyDown(int t_nKey)
{
	for (int i = 0; i < this->m_listeners.size(); i++) {
		this->m_listeners[i]->keyDownHandler(t_nKey);
	}
}
