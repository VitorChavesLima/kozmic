#include "Win32InputController.hpp"
#include "Win32KeyboardInput.hpp"

using namespace Kozmic::Core::Input::Win32;

void Kozmic::Core::Input::Win32::K_Win32InputController::keyUpEvent(WPARAM t_key)
{
	this->m_keyboardInput->notifyKeyUp(0);
}

void Kozmic::Core::Input::Win32::K_Win32InputController::keyDownEvent(WPARAM t_key)
{
	this->m_keyboardInput->notifyKeyDown(0);
}

K_Win32InputController::K_Win32InputController(HWND t_hWindow) {
	this->m_hWindow = t_hWindow;

	this->m_keyboardInput = std::make_shared<K_Win32KeyboardInput>();
}