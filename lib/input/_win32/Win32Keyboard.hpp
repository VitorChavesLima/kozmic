#pragma once

#include <Windows.h>

#include <kozmic/input/Keyboard.hpp>

namespace Kozmic::Core::Window::Win32 {
	class K_Win32WindowController;
}

namespace Kozmic::Core::Input::Win32 {
	class K_Win32Keyboard : public K_Keyboard {
	private:
		friend class Window::Win32::K_Win32WindowController;

	private:
		void notifyKeyUp(WPARAM t_wKey);
		void notifyKeyDown(WPARAM t_wKey);

	public:
		K_Win32Keyboard();
	};
}