#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

#include <kozmic/input/KeyMapper.hpp>
#include <kozmic/input/KeyboardListener.hpp>

namespace Kozmic::Core::Input {
	class K_Keyboard
	{
	protected:
		std::unique_ptr<K_KeyMapper> m_keyMapper;
		std::unordered_map<std::string, bool> m_bKeyStates;

		std::vector<K_KeyboardListener*> m_listeners;

	public:
		K_Keyboard();

		void addListener(K_KeyboardListener* t_listener);
		void removeListener(K_KeyboardListener* t_listener);
	};
}