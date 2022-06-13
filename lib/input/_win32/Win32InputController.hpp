#pragma once

#include <Windows.h>

#include <kozmic/input/InputController.hpp>

namespace Kozmic::Core::Window::Win32 {
	class KWin32Window;
}

namespace Kozmic::Core::Input::Win32 {
	class K_Win32InputController : public K_InputController {
	private:
		HWND m_hWindow;

	private:
		void keyUpEvent(UINT t_nKey);
		void keyDownEvent(UINT t_nKey);

		friend class Core::Window::Win32::KWin32Window;

	public:
		K_Win32InputController(HWND t_hWindow);
	};
}