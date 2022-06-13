#pragma once

#include <kozmic/input/KeyboardInput.hpp>

namespace Kozmic::Core::Input {
	class K_InputController {
	protected:
		K_KeyboardInput m_keyboardInput;

	public:
		virtual void update() = 0;
	};
}