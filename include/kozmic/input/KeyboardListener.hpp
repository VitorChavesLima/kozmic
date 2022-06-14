#pragma once

namespace Kozmic::Core::Input {
	class K_KeyboardListener {
	private:
		virtual void handleKeyUp(int key) {};
		virtual void handleKeyDown(int key) {};
	};
}