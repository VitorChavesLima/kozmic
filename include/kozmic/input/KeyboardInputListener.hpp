#pragma once 

namespace Kozmic::Core::Input {
	class K_KeyboardInputListener {
	private:
		virtual void keyUpHandler() {};
		virtual void keyDownHandler() {};
		virtual void keyStateHandler() {};
	};
}