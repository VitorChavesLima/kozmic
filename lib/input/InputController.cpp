#include <kozmic/input/InputController.hpp>

using namespace Kozmic::Core::Input;

std::shared_ptr<K_KeyboardInput> K_InputController::getKeyboardInput() {
	return this->m_keyboardInput;
}