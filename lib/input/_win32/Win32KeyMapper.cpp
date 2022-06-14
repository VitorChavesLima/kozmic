#include "Win32KeyMapper.hpp"

#include <Windows.h>

using namespace Kozmic::Core::Input::Win32;

K_Win32KeyMapper::K_Win32KeyMapper()
{
	this->m_keyValues.insert({ "BACKSPACE",  VK_BACK});
	this->m_keyValues.insert({ "TAB",  VK_TAB});

	this->m_keyIds.insert({ VK_BACK, "BACKSPACE" });
	this->m_keyIds.insert({ VK_TAB, "TAB" });
}

int K_Win32KeyMapper::getKeyValue(std::string t_sKeyId)
{
	return this->m_keyValues.find(t_sKeyId)->second;
}

std::string K_Win32KeyMapper::getKeyId(int t_nKeyValue)
{
	return this->m_keyIds.find(t_nKeyValue)->second;
}
