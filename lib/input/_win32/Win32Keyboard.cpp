#include "Win32Keyboard.hpp"
#include "Win32KeyMapper.hpp"

#include <iostream>

using namespace Kozmic::Core::Input::Win32;

void K_Win32Keyboard::notifyKeyUp(WPARAM t_wKey)
{
	std::cout << this->m_keyMapper->getKeyId(t_wKey) << " RELEASED" << std::endl;
}

void K_Win32Keyboard::notifyKeyDown(WPARAM t_wKey)
{
	std::cout << this->m_keyMapper->getKeyId(t_wKey) << " PRESSED" << std::endl;
}

K_Win32Keyboard::K_Win32Keyboard()
{
	this->m_keyMapper = std::make_unique<K_Win32KeyMapper>();
}
