#pragma once

#include <Windows.h>

#include <kozmic/input/KeyboardInput.hpp>

namespace Kozmic::Core::Input::Win32 {
	class K_Win32KeyboardInput : public K_KeyboardInput {
	private:
		virtual void notifyKeyUp(int t_nKey) override;
		virtual void notifyKeyDown(int t_nKey) override;
	};
}