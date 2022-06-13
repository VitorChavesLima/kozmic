#include "Win32InputController.hpp"

#include <kozmic/input/KeyMap.hpp>

#include <iostream>

using namespace Kozmic::Core::Input::Win32;

void Kozmic::Core::Input::Win32::K_Win32InputController::keyUpEvent(WPARAM t_key)
{
}

void Kozmic::Core::Input::Win32::K_Win32InputController::keyDownEvent(WPARAM t_key)
{
}

K_Win32InputController::K_Win32InputController(HWND t_hWindow) {
	this->m_hWindow = t_hWindow;
}