#pragma once

#include <Windows.h>

#include <kozmic/input/InputController.hpp>

namespace Kozmic::Core::Input::Win32 {
	class K_Win32InputController : public K_InputController {
	private:
		HWND m_hWindow;

	public:
		K_Win32InputController(HWND t_hWindow);

		virtual void update() override;
	};
}