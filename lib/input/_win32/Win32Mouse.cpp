#include "Win32Mouse.hpp"

#include <windowsx.h>

#include <iostream>

using namespace Kozmic::Core::Input::Win32;

unsigned int K_Win32Mouse::getMouseXButtonId(WPARAM t_wButton)
{
	UINT button = GET_XBUTTON_WPARAM(t_wButton);
	if (button == XBUTTON1) return 3;
	return 4;
}

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

void K_Win32Mouse::notifyScroll(WPARAM t_wScrollState)
{
	int zDelta = GET_WHEEL_DELTA_WPARAM(t_wScrollState);
	bool up = zDelta > 0 ? true : false;

	for (int i = 0; i < this->m_listeners.size(); i++) {
		this->m_listeners[i]->handleScroll(up);
	}
}

void K_Win32Mouse::notifyButtonUp(UINT t_message, WPARAM t_wButton)
{
	unsigned int buttonId;

	switch (t_message) {
	case WM_LBUTTONUP:
		buttonId = 0;
		break;

	case WM_MBUTTONUP:
		buttonId = 2;
		break;

	case WM_RBUTTONUP:
		buttonId = 1;
		break;

	case WM_XBUTTONUP:
		buttonId = this->getMouseXButtonId(t_wButton);
		break;
	}

	for (int i = 0; i < this->m_listeners.size(); i++) {
		this->m_listeners[i]->handleButtonUp(buttonId);
	}
}

void K_Win32Mouse::notifyButtonDown(UINT t_message, WPARAM t_wButton)
{
	unsigned int buttonId;

	switch (t_message) {
	case WM_LBUTTONDOWN:
		buttonId = 0;
		break;

	case WM_MBUTTONDOWN:
		buttonId = 2;
		break;

	case WM_RBUTTONDOWN:
		buttonId = 1;
		break;

	case WM_XBUTTONDOWN:
		buttonId = this->getMouseXButtonId(t_wButton);
		break;
	}

	for (int i = 0; i < this->m_listeners.size(); i++) {
		this->m_listeners[i]->handleButtonDown(buttonId);
	}
}
