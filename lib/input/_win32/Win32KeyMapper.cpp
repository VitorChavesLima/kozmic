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
	this->m_keyValues.insert({ "S_LALT",  VK_LMENU });
	this->m_keyValues.insert({ "S_RALT",  VK_RMENU });
	this->m_keyValues.insert({ "S_PAUSE",  VK_PAUSE });
	this->m_keyValues.insert({ "S_CAPSLOCK",  VK_CAPITAL });
	this->m_keyValues.insert({ "S_ESCAPE",  VK_ESCAPE });
	this->m_keyValues.insert({ "S_SPACEBAR",  VK_SPACE });
	this->m_keyValues.insert({ "S_PAGEUP",  VK_PRIOR });
	this->m_keyValues.insert({ "S_PAGEDOWN",  VK_NEXT });
	this->m_keyValues.insert({ "A_LEFTARROW",  VK_LEFT});
	this->m_keyValues.insert({ "A_UPARROW",  VK_UP });
	this->m_keyValues.insert({ "A_RIGHTARROW",  VK_RIGHT });
	this->m_keyValues.insert({ "A_DOWNARROW",  VK_DOWN });
	this->m_keyValues.insert({ "S_SELECT",  VK_SELECT});
	this->m_keyValues.insert({ "S_PRINT",  VK_PRINT });
	this->m_keyValues.insert({ "S_EXECUTE",  VK_EXECUTE });
	this->m_keyValues.insert({ "S_SCREENSHOT",  VK_SNAPSHOT });
	this->m_keyValues.insert({ "S_INSERT",  VK_INSERT });
	this->m_keyValues.insert({ "S_DELETE",  VK_DELETE });
	this->m_keyValues.insert({ "S_HELP",  VK_HELP });
	this->m_keyValues.insert({ "N_1",  49 });
	this->m_keyValues.insert({ "N_2",  50 });
	this->m_keyValues.insert({ "N_3",  51 });
	this->m_keyValues.insert({ "N_4",  52 });
	this->m_keyValues.insert({ "N_5",  53 });
	this->m_keyValues.insert({ "N_6",  54 });
	this->m_keyValues.insert({ "N_7",  55 });
	this->m_keyValues.insert({ "N_8",  56 });
	this->m_keyValues.insert({ "N_9",  57 });
	this->m_keyValues.insert({ "N_0",  48 });
	this->m_keyValues.insert({ "L_A",  65 });
	this->m_keyValues.insert({ "L_B",  66 });
	this->m_keyValues.insert({ "L_C",  67 });
	this->m_keyValues.insert({ "L_D",  68 });
	this->m_keyValues.insert({ "L_E",  69 });
	this->m_keyValues.insert({ "L_F",  70 });
	this->m_keyValues.insert({ "L_G",  71 });
	this->m_keyValues.insert({ "L_H",  72 });
	this->m_keyValues.insert({ "L_I",  73 });
	this->m_keyValues.insert({ "L_J",  74 });
	this->m_keyValues.insert({ "L_K",  75 });
	this->m_keyValues.insert({ "L_L",  76 });
	this->m_keyValues.insert({ "L_M",  77 });
	this->m_keyValues.insert({ "L_N",  78 });
	this->m_keyValues.insert({ "L_O",  79 });
	this->m_keyValues.insert({ "L_P",  80 });
	this->m_keyValues.insert({ "L_Q",  81 });
	this->m_keyValues.insert({ "L_R",  82 });
	this->m_keyValues.insert({ "L_S",  83 });
	this->m_keyValues.insert({ "L_T",  84 });
	this->m_keyValues.insert({ "L_U",  85 });
	this->m_keyValues.insert({ "L_V",  86 });
	this->m_keyValues.insert({ "L_W",  87 });
	this->m_keyValues.insert({ "L_X",  88 });
	this->m_keyValues.insert({ "L_Y",  89 });
	this->m_keyValues.insert({ "L_Z",  90 });
	this->m_keyValues.insert({ "S_LSYS",  VK_LWIN });
	this->m_keyValues.insert({ "S_RSYS",  VK_RWIN });
	this->m_keyValues.insert({ "S_APPS",  VK_APPS });
	this->m_keyValues.insert({ "N_NP0",  VK_NUMPAD0 });
	this->m_keyValues.insert({ "N_NP1",  VK_NUMPAD1 });
	this->m_keyValues.insert({ "N_NP2",  VK_NUMPAD2 });
	this->m_keyValues.insert({ "N_NP3",  VK_NUMPAD3 });
	this->m_keyValues.insert({ "N_NP4",  VK_NUMPAD4 });
	this->m_keyValues.insert({ "N_NP5",  VK_NUMPAD5 });
	this->m_keyValues.insert({ "N_NP6",  VK_NUMPAD6 });
	this->m_keyValues.insert({ "N_NP7",  VK_NUMPAD7 });
	this->m_keyValues.insert({ "N_NP8",  VK_NUMPAD8 });
	this->m_keyValues.insert({ "N_NP9",  VK_NUMPAD9 });
	this->m_keyValues.insert({ "S_MULTIPLY",  VK_MULTIPLY });
	this->m_keyValues.insert({ "S_ADD",  VK_ADD });
	this->m_keyValues.insert({ "S_SEPARATOR",  VK_SEPARATOR });
	this->m_keyValues.insert({ "S_SUBTRACT",  VK_SUBTRACT });
	this->m_keyValues.insert({ "S_DECIMAL",  VK_DECIMAL });
	this->m_keyValues.insert({ "S_DIVIDE",  VK_DIVIDE });
	this->m_keyValues.insert({ "F_F1",  VK_F1 });
	this->m_keyValues.insert({ "F_F2",  VK_F2 });
	this->m_keyValues.insert({ "F_F3",  VK_F3 });
	this->m_keyValues.insert({ "F_F4",  VK_F4 });
	this->m_keyValues.insert({ "F_F5",  VK_F5 });
	this->m_keyValues.insert({ "F_F6",  VK_F6 });
	this->m_keyValues.insert({ "F_F7",  VK_F7 });
	this->m_keyValues.insert({ "F_F8",  VK_F8 });
	this->m_keyValues.insert({ "F_F9",  VK_F9 });
	this->m_keyValues.insert({ "F_F10",  VK_F10 });
	this->m_keyValues.insert({ "F_F11",  VK_F11 });
	this->m_keyValues.insert({ "F_F12",  VK_F12 });
	this->m_keyValues.insert({ "S_OEM1",  VK_OEM_1 });
	this->m_keyValues.insert({ "S_OEM2",  VK_OEM_2 });
	this->m_keyValues.insert({ "S_OEM3",  VK_OEM_3 });
	this->m_keyValues.insert({ "S_OEM4",  VK_OEM_4 });
	this->m_keyValues.insert({ "S_OEM5",  VK_OEM_5 });
	this->m_keyValues.insert({ "S_OEM6",  VK_OEM_6 });
	this->m_keyValues.insert({ "S_OEM7",  VK_OEM_7 });
	this->m_keyValues.insert({ "S_OEM8",  VK_OEM_8 });
	this->m_keyValues.insert({ "S_OEM102",  VK_OEM_102 });
	this->m_keyValues.insert({ "S_OEM_PLUS",  VK_OEM_PLUS});
	this->m_keyValues.insert({ "S_OEM_COMMMA",  VK_OEM_COMMA });
	this->m_keyValues.insert({ "S_OEM_MINUS",  VK_OEM_MINUS });
	this->m_keyValues.insert({ "S_OEM_PERIOD",  VK_OEM_PERIOD });
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
