#include "Win32Mouse.hpp"

#include <windowsx.h>

#include <iostream>

using namespace Kozmic::Core::Input::Win32;

void K_Win32Mouse::notifyMove(LPARAM t_lMousePosition)
{
	int xPos = GET_X_LPARAM(t_lMousePosition);
	int yPos = GET_Y_LPARAM(t_lMousePosition);

	this->m_nXPos = xPos;
	this->m_nYPos = yPos;

	for (int i = 0; i < this->m_listeners.size(); i++) {
		this->m_listeners[i]->handleMove(this->m_nXPos, this->m_nYPos);
	}
}

void K_Win32Mouse::notifyButtonUp(WPARAM t_wButton)
{
}

void K_Win32Mouse::notifyButtonDown(WPARAM t_wButton)
{
}
