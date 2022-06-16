#pragma once

namespace Kozmic::Core::Input {
	class K_MouseListener {
	public:
		virtual void handleMove(int t_nXPos, int t_nYPos) {};
		virtual void handleScroll(bool t_bUp) {};
		virtual void handleButtonDown(unsigned int t_nButtonId) {};
		virtual void handleButtonUp(unsigned int t_nButtonId) {};
		virtual void handleButton(unsigned int t_nButtonId) {}
	};
}