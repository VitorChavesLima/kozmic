#pragma once

#include <memory>
#include <vector>

#include <kozmic/input/MouseListener.hpp>

namespace Kozmic::Core::Input {
	class K_Mouse {
	private:
		K_MouseScreenPosition m_mousePosition;

		std::vector<std::shared_ptr<K_MouseListener>> m_listeners;

	public:
		K_Mouse();

		void addListener(std::shared_ptr<K_MouseListener> t_listener);
		void removeListener(std::shared_ptr<K_MouseListener> t_listener);
	};
}