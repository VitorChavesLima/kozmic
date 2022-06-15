#pragma once

namespace Kozmic::Core::Input {
	class K_MouseListener {
	public:
		virtual void handleMove(int t_nXPos, int t_nYPos) {};
		virtual void handleScroll(bool t_bUp) {};
		virtual void handleButtonDown(const char* t_sButtonId) {};
		virtual void handleButtonUp(const char* t_sButtonId) {};
	};
}