#pragma once

#include <kozmic/input/KeyMap.hpp>

namespace Kozmic::Core::Input {
	class K_KeyboardListener {
	public:
		virtual void handleKeyUp(std::string t_sKeyId) {};
		virtual void handleKeyDown(std::string t_sKeyId) {};
	};
}