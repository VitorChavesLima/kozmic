#include <kozmic/input/KeyMap.hpp>

using namespace Kozmic::Core::Input;

const char* K_KeyMap::BACKSPACE = "S_BACKSPACE";
const char* K_KeyMap::TAB = "S_TAB";

const char* K_KeyMap::CLEAR = "S_CLEAR";
const char* K_KeyMap::ENTER = "S_ENTER";

const char* K_KeyMap::LSHIFT = "S_LSHIFT";
const char* K_KeyMap::RSHIFT = "S_RSHIFT";

const char* K_KeyMap::LCTRL = "S_LCONTROL";
const char* K_KeyMap::RCTRL = "S_RCONTROL";

const char* K_KeyMap::LALT = "S_LALT";
const char* K_KeyMap::RALT = "S_RALT";

const char* K_KeyMap::PAUSE = "S_PAUSE";
const char* K_KeyMap::CAPS_LOCK = "S_CAPSLOCK";

const char* K_KeyMap::ESC = "S_ESCAPE";
const char* K_KeyMap::SPACEBAR = "S_SPACEBAR";
const char* K_KeyMap::PAGE_UP = "S_PAGEUP";
const char* K_KeyMap::PAGE_DOWN = "S_PAGEDOWN";

const char* K_KeyMap::LEFT_ARROW = "A_LEFTARROW";
const char* K_KeyMap::UP_ARROW = "A_UPARROW";
const char* K_KeyMap::RIGHT_ARROW = "A_RIGHTARROW";
const char* K_KeyMap::DOWN_ARROW = "A_DOWNARROW";

const char* K_KeyMap::SELECT = "S_SELECT";
const char* K_KeyMap::PRINT = "S_PRINT";
const char* K_KeyMap::EXECUTE = "S_EXECUTE";
const char* K_KeyMap::SCREENSHOT = "S_SCREENSHOT";
const char* K_KeyMap::INSERT = "S_INSERT";
const char* K_KeyMap::DEL = "S_DELETE";
const char* K_KeyMap::HELP = "S_HELP";

const char* K_KeyMap::D1 = "N_1";
const char* K_KeyMap::D2 = "N_2";
const char* K_KeyMap::D3 = "N_3";
const char* K_KeyMap::D4 = "N_4";
const char* K_KeyMap::D5 = "N_5";
const char* K_KeyMap::D6 = "N_6";
const char* K_KeyMap::D7 = "N_7";
const char* K_KeyMap::D8 = "N_8";
const char* K_KeyMap::D9 = "N_9";
const char* K_KeyMap::D0 = "N_0";

const char* K_KeyMap::A = "L_A";
const char* K_KeyMap::B = "L_B";
const char* K_KeyMap::C = "L_C";
const char* K_KeyMap::D = "L_D";
const char* K_KeyMap::E = "L_E";
const char* K_KeyMap::F = "L_F";
const char* K_KeyMap::G = "L_G";
const char* K_KeyMap::H = "L_H";
const char* K_KeyMap::I = "L_I";
const char* K_KeyMap::J = "L_J";
const char* K_KeyMap::K = "L_K";
const char* K_KeyMap::L = "L_L";
const char* K_KeyMap::M = "L_M";
const char* K_KeyMap::N = "L_N";
const char* K_KeyMap::O = "L_O";
const char* K_KeyMap::P = "L_P";
const char* K_KeyMap::Q = "L_Q";
const char* K_KeyMap::R = "L_R";
const char* K_KeyMap::S = "L_S";
const char* K_KeyMap::T = "L_T";
const char* K_KeyMap::U = "L_U";
const char* K_KeyMap::V = "L_V";
const char* K_KeyMap::W = "L_W";
const char* K_KeyMap::X = "L_X";
const char* K_KeyMap::Y = "L_Y";
const char* K_KeyMap::Z = "L_Z";

const char* K_KeyMap::LSYS = "S_LSYS";
const char* K_KeyMap::RSYS = "S_RSYS";
const char* K_KeyMap::APPS = "S_APPS";

const char* K_KeyMap::NP0 = "N_NP0";
const char* K_KeyMap::NP1 = "N_NP1";
const char* K_KeyMap::NP2 = "N_NP2";
const char* K_KeyMap::NP3 = "N_NP3";
const char* K_KeyMap::NP4 = "N_NP4";
const char* K_KeyMap::NP5 = "N_NP5";
const char* K_KeyMap::NP6 = "N_NP6";
const char* K_KeyMap::NP7 = "N_NP7";
const char* K_KeyMap::NP8 = "N_NP8";
const char* K_KeyMap::NP9 = "N_NP9";

const char* K_KeyMap::MULTIPLY = "S_MULTIPLY";
const char* K_KeyMap::ADD = "S_ADD";
const char* K_KeyMap::SEPARATOR = "S_SEPARATOR";
const char* K_KeyMap::SUBTRACT = "S_SUBTRACT";
const char* K_KeyMap::DECIMAL = "S_DECIMAL";
const char* K_KeyMap::DIVIDE = "S_DIVIDE";

const char* K_KeyMap::F1 = "F_F1";
const char* K_KeyMap::F2 = "F_F2";
const char* K_KeyMap::F3 = "F_F3";
const char* K_KeyMap::F4 = "F_F4";
const char* K_KeyMap::F5 = "F_F5";
const char* K_KeyMap::F6 = "F_F6";
const char* K_KeyMap::F7 = "F_F7";
const char* K_KeyMap::F8 = "F_F8";
const char* K_KeyMap::F9 = "F_F9";
const char* K_KeyMap::F10 = "F_F10";
const char* K_KeyMap::F11 = "F_F11";
const char* K_KeyMap::F12 = "F_F12";

const char* K_KeyMap::OEM_1 = "S_OEM1";
const char* K_KeyMap::OEM_2 = "S_OEM2";
const char* K_KeyMap::OEM_3 = "S_OEM3";
const char* K_KeyMap::OEM_4 = "S_OEM4";
const char* K_KeyMap::OEM_5 = "S_OEM5";
const char* K_KeyMap::OEM_6 = "S_OEM6";
const char* K_KeyMap::OEM_7 = "S_OEM7";
const char* K_KeyMap::OEM_8 = "S_OEM8";
const char* K_KeyMap::OEM_102 = "S_OEM102";

const char* K_KeyMap::OEM_PLUS = "S_OEM_PLUS";
const char* K_KeyMap::OEM_COMMMA = "S_OEM_COMMMA";
const char* K_KeyMap::OEM_MINUS = "S_OEM_MINUS";
const char* K_KeyMap::OEM_PERIOD = "S_OEM_PERIOD";
