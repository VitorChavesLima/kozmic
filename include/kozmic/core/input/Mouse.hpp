#pragma once

#include <memory>
#include <vector>

#include "MouseListener.hpp"

namespace Kozmic::Core::Input {
	class K_Mouse {
	protected:
		int m_nXPos;
		int m_nYPos;

		std::vector<std::shared_ptr<K_MouseListener>> m_listeners;

	public:
		K_Mouse();

		void addListener(std::shared_ptr<K_MouseListener> t_listener);
		void removeListener(std::shared_ptr<K_MouseListener> t_listener);
	};
}