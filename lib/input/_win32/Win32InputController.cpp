#include "Win32InputController.hpp"

#include <iostream>

using namespace Kozmic::Core::Input::Win32;

void Kozmic::Core::Input::Win32::K_Win32InputController::keyUpEvent(UINT t_nKey)
{
	std::cout << "Key up: " << t_nKey << std::endl;
}

void Kozmic::Core::Input::Win32::K_Win32InputController::keyDownEvent(UINT t_nKey)
{
	std::cout << "Key down: " << t_nKey << std::endl;
}

K_Win32InputController::K_Win32InputController(HWND t_hWindow) {
	this->m_hWindow = t_hWindow;
}