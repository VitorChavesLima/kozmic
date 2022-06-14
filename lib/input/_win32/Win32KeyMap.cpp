#include "Win32KeyMap.hpp"

#include <Windows.h>

using namespace Kozmic::Core::Input::Win32;

K_Win32KeyMap::K_Win32KeyMap()
{
	this->m_keyValues.insert({ "BACKSPACE",  VK_BACK});
	this->m_keyValues.insert({ "TAB",  VK_TAB});
}

int Kozmic::Core::Input::Win32::K_Win32KeyMap::getKeyValue(std::string t_sKeyId)
{
	return this->m_keyValues.find(t_sKeyId)->second;
}

std::string Kozmic::Core::Input::Win32::K_Win32KeyMap::getKeyId(int t_nKeyValue)
{
	return this->m_keyIds.find(t_nKeyValue)->second;
}
