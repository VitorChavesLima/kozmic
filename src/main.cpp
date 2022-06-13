#include <kozmic/window/WindowManager.hpp>

#include <iostream>

using namespace Kozmic::Core;

class Test : public Kozmic::Core::Input::K_KeyboardInputListener {
protected:
	virtual void keyUpHandler(int t_nKeyId) {
		std::cout << "Key Release: " << t_nKeyId << std::endl;
	};

	virtual void keyDownHandler(int t_nKeyId) {
		std::cout << "Key Pressed: " << t_nKeyId << std::endl;
	};
};

int main() {
	std::unique_ptr<KWindowManager> windowManager = std::make_unique<KWindowManager>();
	
	std::unique_ptr<Window::KWindow> window = windowManager->getWindow("EXAMPLE", {800, 600}, {0, 0}, Window::KWindowMode::WINDOWED);
	std::shared_ptr<Input::K_InputController> inputController = window->getInputController();

	std::shared_ptr<Test> test = std::make_shared<Test>();

	inputController->getKeyboardInput()->addListener(test);

	window->show();

	while (window->isOpen()) {
		if(window->isFocused()){
			window->update();
		}
	}
}