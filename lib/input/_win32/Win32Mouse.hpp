#pragma once 

#include <Windows.h>

#include <kozmic/input/Mouse.hpp>

namespace Kozmic::Core::Window::Win32 {
	class KWin32Window;
}

namespace Kozmic::Core::Input::Win32 {
	class K_Win32Mouse : public K_Mouse {
	private:
		friend class Window::Win32::KWin32Window;

		unsigned int getMouseXButtonId(WPARAM t_wButton);

	private:
		void notifyMove(LPARAM t_lMousePosition);
		void notifyScroll(WPARAM t_wScrollState);
		void notifyButtonUp(UINT t_message, WPARAM t_wButton);
		void notifyButtonDown(UINT t_message, WPARAM t_wButton);
	};
}