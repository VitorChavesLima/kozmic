#include <kozmic/window/WindowManager.hpp>
#include <kozmic/input/KeyboardListener.hpp>
#include <kozmic/input/KeyMap.hpp>

#include <iostream>

using namespace Kozmic::Core;

class KeyboardTest : public Input::K_KeyboardListener {
private:
	void handleKeyDown(std::string t_sKeyId) {
	}

	void handleKeyUp(std::string t_sKeyId) {
	}
};

int main() {
	std::unique_ptr<KWindowManager> windowManager = std::make_unique<KWindowManager>();
	
	std::unique_ptr<Window::KWindow> window = windowManager->getWindow("EXAMPLE", {800, 600}, {0, 0}, Window::KWindowMode::WINDOWED);
	std::shared_ptr<Input::K_Keyboard> keyboardInput = window->getKeyboardInput();

	std::shared_ptr<KeyboardTest> keyboardTest = std::make_shared<KeyboardTest>();

	keyboardInput->addListener(keyboardTest);

	window->show();

	while (window->isOpen()) {
		if(window->isFocused()){
			window->update();
		}
	}
}