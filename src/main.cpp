#include <kozmic/window/WindowManager.hpp>

using namespace Kozmic::Core;

int main() {
	std::unique_ptr<KWindowManager> windowManager = std::make_unique<KWindowManager>();
	
	std::unique_ptr<Window::KWindow> window = windowManager->getWindow("EXAMPLE", {800, 600}, {0, 0}, Window::KWindowMode::WINDOWED);

	window->show();

	while (window->isOpen()) {
		if(window->isFocused()){
			window->update();
		}
	}
}