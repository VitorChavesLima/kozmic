#pragma once 

#include <kozmic/input/KeyId.hpp>

namespace Kozmic::Core::Input {
	class K_KeyboardInputListener {
	private:
		virtual void keyUpHandler(K_KeyId t_keyId) {};
		virtual void keyDownHandler(K_KeyId t_keyId) {};
		virtual void keyStateHandler(K_KeyId t_keyId, bool t_bState) {};
	};
}