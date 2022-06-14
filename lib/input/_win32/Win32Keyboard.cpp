#include "Win32Keyboard.hpp"
#include "Win32KeyMapper.hpp"

using namespace Kozmic::Core::Input::Win32;

K_Win32Keyboard::K_Win32Keyboard()
{
	this->m_keyMapper = std::make_unique<K_Win32KeyMapper>();
}
