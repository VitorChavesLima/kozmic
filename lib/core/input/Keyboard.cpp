#include <kozmic/core/input/Keyboard.hpp>

using namespace Kozmic::Core::Input;

K_Keyboard::K_Keyboard() {
	this->m_bKeyStates.insert({ "S_BACKSPACE",  false });
	this->m_bKeyStates.insert({ "S_TAB",  false });
	this->m_bKeyStates.insert({ "S_CLEAR",  false });
	this->m_bKeyStates.insert({ "S_ENTER",  false });
	this->m_bKeyStates.insert({ "S_LSHIFT",  false });
	this->m_bKeyStates.insert({ "S_RSHIFT",  false });
	this->m_bKeyStates.insert({ "S_LCONTROL",  false });
	this->m_bKeyStates.insert({ "S_RCONTROL",  false });
	this->m_bKeyStates.insert({ "S_LALT",  false });
	this->m_bKeyStates.insert({ "S_RALT",  false });
	this->m_bKeyStates.insert({ "S_PAUSE",  false });
	this->m_bKeyStates.insert({ "S_CAPSLOCK",  false });
	this->m_bKeyStates.insert({ "S_ESCAPE",  false });
	this->m_bKeyStates.insert({ "S_SPACEBAR",  false });
	this->m_bKeyStates.insert({ "S_PAGEUP",  false });
	this->m_bKeyStates.insert({ "S_PAGEDOWN",  false });
	this->m_bKeyStates.insert({ "A_LEFTARROW",  false });
	this->m_bKeyStates.insert({ "A_UPARROW",  false });
	this->m_bKeyStates.insert({ "A_RIGHTARROW",  false });
	this->m_bKeyStates.insert({ "A_DOWNARROW",  false });
	this->m_bKeyStates.insert({ "S_SELECT",  false });
	this->m_bKeyStates.insert({ "S_PRINT",  false });
	this->m_bKeyStates.insert({ "S_EXECUTE",  false });
	this->m_bKeyStates.insert({ "S_SCREENSHOT",  false });
	this->m_bKeyStates.insert({ "S_INSERT",  false });
	this->m_bKeyStates.insert({ "S_DELETE",  false });
	this->m_bKeyStates.insert({ "S_HELP",  false });
	this->m_bKeyStates.insert({ "N_1",  false });
	this->m_bKeyStates.insert({ "N_2",  false });
	this->m_bKeyStates.insert({ "N_3",  false });
	this->m_bKeyStates.insert({ "N_4",  false });
	this->m_bKeyStates.insert({ "N_5",  false });
	this->m_bKeyStates.insert({ "N_6",  false });
	this->m_bKeyStates.insert({ "N_7",  false });
	this->m_bKeyStates.insert({ "N_8",  false });
	this->m_bKeyStates.insert({ "N_9",  false });
	this->m_bKeyStates.insert({ "N_0",  false });
	this->m_bKeyStates.insert({ "L_A",  false });
	this->m_bKeyStates.insert({ "L_B",  false });
	this->m_bKeyStates.insert({ "L_C",  false });
	this->m_bKeyStates.insert({ "L_D",  false });
	this->m_bKeyStates.insert({ "L_E",  false });
	this->m_bKeyStates.insert({ "L_F",  false });
	this->m_bKeyStates.insert({ "L_G",  false });
	this->m_bKeyStates.insert({ "L_H",  false });
	this->m_bKeyStates.insert({ "L_I",  false });
	this->m_bKeyStates.insert({ "L_J",  false });
	this->m_bKeyStates.insert({ "L_K",  false });
	this->m_bKeyStates.insert({ "L_L",  false });
	this->m_bKeyStates.insert({ "L_M",  false });
	this->m_bKeyStates.insert({ "L_N",  false });
	this->m_bKeyStates.insert({ "L_O",  false });
	this->m_bKeyStates.insert({ "L_P",  false });
	this->m_bKeyStates.insert({ "L_Q",  false });
	this->m_bKeyStates.insert({ "L_R",  false });
	this->m_bKeyStates.insert({ "L_S",  false });
	this->m_bKeyStates.insert({ "L_T",  false });
	this->m_bKeyStates.insert({ "L_U",  false });
	this->m_bKeyStates.insert({ "L_V",  false });
	this->m_bKeyStates.insert({ "L_W",  false });
	this->m_bKeyStates.insert({ "L_X",  false });
	this->m_bKeyStates.insert({ "L_Y",  false });
	this->m_bKeyStates.insert({ "L_Z",  false });
	this->m_bKeyStates.insert({ "S_LSYS",  false });
	this->m_bKeyStates.insert({ "S_RSYS",  false });
	this->m_bKeyStates.insert({ "S_APPS",  false });
	this->m_bKeyStates.insert({ "N_NP0",  false });
	this->m_bKeyStates.insert({ "N_NP1",  false });
	this->m_bKeyStates.insert({ "N_NP2",  false });
	this->m_bKeyStates.insert({ "N_NP3",  false });
	this->m_bKeyStates.insert({ "N_NP4",  false });
	this->m_bKeyStates.insert({ "N_NP5",  false });
	this->m_bKeyStates.insert({ "N_NP6",  false });
	this->m_bKeyStates.insert({ "N_NP7",  false });
	this->m_bKeyStates.insert({ "N_NP8",  false });
	this->m_bKeyStates.insert({ "N_NP9",  false });
	this->m_bKeyStates.insert({ "S_MULTIPLY",  false });
	this->m_bKeyStates.insert({ "S_ADD",  false });
	this->m_bKeyStates.insert({ "S_SEPARATOR",  false });
	this->m_bKeyStates.insert({ "S_SUBTRACT",  false });
	this->m_bKeyStates.insert({ "S_DECIMAL",  false });
	this->m_bKeyStates.insert({ "S_DIVIDE",  false });
	this->m_bKeyStates.insert({ "F_F1",  false });
	this->m_bKeyStates.insert({ "F_F2",  false });
	this->m_bKeyStates.insert({ "F_F3",  false });
	this->m_bKeyStates.insert({ "F_F4",  false });
	this->m_bKeyStates.insert({ "F_F5",  false });
	this->m_bKeyStates.insert({ "F_F6",  false });
	this->m_bKeyStates.insert({ "F_F7",  false });
	this->m_bKeyStates.insert({ "F_F8",  false });
	this->m_bKeyStates.insert({ "F_F9",  false });
	this->m_bKeyStates.insert({ "F_F10",  false });
	this->m_bKeyStates.insert({ "F_F11",  false });
	this->m_bKeyStates.insert({ "F_F12",  false });
	this->m_bKeyStates.insert({ "S_OEM1",  false });
	this->m_bKeyStates.insert({ "S_OEM2",  false });
	this->m_bKeyStates.insert({ "S_OEM3",  false });
	this->m_bKeyStates.insert({ "S_OEM4",  false });
	this->m_bKeyStates.insert({ "S_OEM5",  false });
	this->m_bKeyStates.insert({ "S_OEM6",  false });
	this->m_bKeyStates.insert({ "S_OEM7",  false });
	this->m_bKeyStates.insert({ "S_OEM8",  false });
	this->m_bKeyStates.insert({ "S_OEM102",  false });
	this->m_bKeyStates.insert({ "S_OEM_PLUS",  false });
	this->m_bKeyStates.insert({ "S_OEM_COMMMA",  false });
	this->m_bKeyStates.insert({ "S_OEM_MINUS",  false });
	this->m_bKeyStates.insert({ "S_OEM_PERIOD",  false });
}

void K_Keyboard::addListener(K_KeyboardListener* t_listener) {
	this->m_listeners.push_back(t_listener);
}

void K_Keyboard::removeListener(K_KeyboardListener* t_listener) {
	// TODO
}