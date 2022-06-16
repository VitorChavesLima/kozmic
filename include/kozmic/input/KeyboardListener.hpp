#pragma once

#include <kozmic/input/KeyMap.hpp>

namespace Kozmic::Core::Input {
	class K_KeyboardListener {
	public:
		virtual void handleKeyboardKeyUp(std::string t_sKeyId) {};
		virtual void handleKeyboardKeyDown(std::string t_sKeyId) {};
		virtual void handleKeyboardKey(std::string t_sKeyId) {};
	};
}