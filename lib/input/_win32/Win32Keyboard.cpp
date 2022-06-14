#include "Win32Keyboard.hpp"
#include "Win32KeyMapper.hpp"

using namespace Kozmic::Core::Input::Win32;

void K_Win32Keyboard::notifyKeyUp(WPARAM t_wKey)
{
	for (int i = 0; i < this->m_listeners.size(); i++) {
		std::string keyId = this->m_keyMapper->getKeyId(t_wKey);
		if(keyId != "NOT_MAPPED") this->m_listeners[i]->handleKeyUp(keyId);
	}
}

void K_Win32Keyboard::notifyKeyDown(WPARAM t_wKey)
{
	for (int i = 0; i < this->m_listeners.size(); i++) {
		std::string keyId = this->m_keyMapper->getKeyId(t_wKey);
		if (keyId != "NOT_MAPPED") this->m_listeners[i]->handleKeyDown(keyId);
	}
}

K_Win32Keyboard::K_Win32Keyboard()
{
	this->m_keyMapper = std::make_unique<K_Win32KeyMapper>();
}
