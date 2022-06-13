#include "Win32InputController.hpp"

using namespace Kozmic::Core::Input::Win32;

K_Win32InputController::K_Win32InputController(HWND t_hWindow) {
	this->m_hWindow = t_hWindow;
}

void Kozmic::Core::Input::Win32::K_Win32InputController::update()
{
}
