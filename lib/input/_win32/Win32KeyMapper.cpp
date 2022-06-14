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
	auto search = this->m_keyValues.find(t_sKeyId);

	if (search != this->m_keyValues.end()) {
		return search->second;
	}

	return -1;
}

std::string K_Win32KeyMapper::getKeyId(int t_nKeyValue)
{
	auto search = this->m_keyIds.find(t_nKeyValue);

	if (search != this->m_keyIds.end()) {
		return search->second;
	}

	return "NOT_FOUND";
}
