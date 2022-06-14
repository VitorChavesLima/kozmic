#pragma once

#include <memory>
#include <vector>

#include <kozmic/input/KeyMapper.hpp>
#include <kozmic/input/KeyboardListener.hpp>

namespace Kozmic::Core::Input {
	class K_Keyboard
	{
	protected:
		std::unique_ptr<K_KeyMapper> m_keyMapper;
		std::vector<std::shared_ptr<K_KeyboardListener>> m_listeners;
	
	public:
		void addListener(std::shared_ptr<K_KeyboardListener> t_listener);
		void removeListener(std::shared_ptr<K_KeyboardListener> t_listener);
	};
}