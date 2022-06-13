#pragma once

#include <memory>

#include <kozmic/input/KeyboardInput.hpp>

namespace Kozmic::Core::Input {
	class K_InputController {
	protected:
		std::shared_ptr<K_KeyboardInput> m_keyboardInput;

	public:
		std::shared_ptr<K_KeyboardInput> getKeyboardInput();
	};
}