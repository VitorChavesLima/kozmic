#include <kozmic/window/WindowManager.hpp>
#include <kozmic/input/KeyboardListener.hpp>
#include <kozmic/input/MouseListener.hpp>

#include <iostream>

using namespace Kozmic::Core;

class InputTest : public Input::K_KeyboardListener, public Input::K_MouseListener {
private:
	void handleKeyboardKeyDown(std::string t_sKeyId) {
		std::cout << "KEY PRESSED: " << t_sKeyId << std::endl;
	}

	void handleKeyboardKeyUp(std::string t_sKeyId) {
		std::cout << "KEY RELEASED: " << t_sKeyId << std::endl;
	}
};

int main() {
	std::unique_ptr<KWindowManager> windowManager = std::make_unique<KWindowManager>();
	
	std::unique_ptr<Window::KWindow> window = windowManager->getWindow("EXAMPLE", {800, 600}, {0, 0}, Window::KWindowMode::WINDOWED);
	std::shared_ptr<Input::K_Keyboard> keyboardInput = window->getKeyboardInput();
	std::shared_ptr<Input::K_Mouse> mouseInput = window->getMouseInput();

	std::shared_ptr<InputTest> inputTest = std::make_shared<InputTest>();

	keyboardInput->addListener(inputTest);
	mouseInput->addListener(inputTest);

	window->show();

	while (window->isOpen()) {
		if(window->isFocused()){
			window->update();
		}
	}
}