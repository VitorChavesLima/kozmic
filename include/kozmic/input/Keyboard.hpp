#pragma once

#include <memory>

#include <kozmic/input/KeyMapper.hpp>

namespace Kozmic::Core::Input {
	class K_Keyboard
	{
	protected:
		std::unique_ptr<K_KeyMapper> m_keyMapper;
	};
}