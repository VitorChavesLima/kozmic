#include "Win32KeyMapper.hpp"

#include <Windows.h>

using namespace Kozmic::Core::Input::Win32;

K_Win32KeyMapper::K_Win32KeyMapper()
{
	this->m_keyValues.insert({ "S_BACKSPACE",  VK_BACK});
	this->m_keyValues.insert({ "S_TAB",  VK_TAB});
	this->m_keyValues.insert({ "S_CLEAR",  VK_CLEAR });
	this->m_keyValues.insert({ "S_ENTER",  VK_RETURN });
	this->m_keyValues.insert({ "S_LSHIFT",  VK_LSHIFT });
	this->m_keyValues.insert({ "S_RSHIFT",  VK_RSHIFT });
	this->m_keyValues.insert({ "S_LCONTROL",  VK_LCONTROL });
	this->m_keyValues.insert({ "S_RCONTROL",  VK_RCONTROL });
	this->m_keyValues.insert({ "S_PAUSE",  VK_PAUSE });
	this->m_keyValues.insert({ "S_CAPSLOCK",  VK_CAPITAL });
}

int K_Win32KeyMapper::getKeyValue(std::string t_sKeyId)
{
	auto search = this->m_keyValues.find(t_sKeyId);

	if (search != this->m_keyValues.end()) {
		return search->second;
	}

	return -1;
}

std::string K_Win32KeyMapper::getKeyId(int t_nKeyValue)
{
	for (auto it = this->m_keyValues.begin(); it != this->m_keyValues.end(); ++it) {
		if (it->second == t_nKeyValue) return it->first;
	}

	return "NOT_MAPPED";
}
