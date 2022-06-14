#pragma once

#include <Windows.h>

#include <kozmic/input/Keyboard.hpp>

namespace Kozmic::Core::Window::Win32 {
	class KWin32Window;
}

namespace Kozmic::Core::Input::Win32 {
	class K_Win32Keyboard : public K_Keyboard {
	private:
		friend class Window::Win32::KWin32Window;

	private:
		void notifyKeyUp(WPARAM t_wKey);
		void notifyKeyDown(WPARAM t_wKey);

	public:
		K_Win32Keyboard();
	};
}