#pragma once 

namespace Kozmic::Core::Input {
	class K_KeyboardInputListener {
	public:
		virtual void keyUpHandler(int t_nKeyId) {};
		virtual void keyDownHandler(int t_nKeyId) {};
		virtual void keyStateHandler(int t_nKeyId, bool t_bState) {};
	};
}