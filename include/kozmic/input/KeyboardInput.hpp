#pragma once

#include <memory>
#include <vector>

#include <kozmic/input/KeyboardInputListener.hpp>

namespace Kozmic::Core::Input {
	class K_KeyboardInput {
	protected:
		friend class K_InputController;

		std::vector<std::shared_ptr<K_KeyboardInputListener>> m_listeners;
	
	public:
		void addListener(std::shared_ptr<K_KeyboardInputListener> t_listener);
		void removeListener(std::shared_ptr<K_KeyboardInputListener> t_listener);

		virtual void notifyKeyUp(int t_nKey) = 0;
		virtual void notifyKeyDown(int t_nKey) = 0;
	};
}