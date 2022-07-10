#pragma once

namespace Kozmic::Core::Input {
	class K_MouseListener {
	public:
		virtual void handleMouseMove(int t_nXPos, int t_nYPos) {};
		virtual void handleMouseScroll(bool t_bUp) {};
		virtual void handleMouseButtonDown(unsigned int t_nButtonId) {};
		virtual void handleMouseButtonUp(unsigned int t_nButtonId) {};
	};
}