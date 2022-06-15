#pragma once

namespace Kozmic::Core::Input {
	struct K_MouseScreenPosition {
		unsigned int xPos;
		unsigned int yPos;
	};

	class K_MouseListener {
	public:
		virtual void handleMove(K_MouseScreenPosition t_mousePosition) {};
		virtual void handleButtonDown(const char* t_sButtonId) {};
		virtual void handleButtonUp(const char* t_sButtonId) {};
	};
}