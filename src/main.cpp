#include <kozmic/window/Window.hpp>
#include <window/_win32/Win32Window.hpp>

using namespace Kozmic::Core;

int main() {
	Window::Win32::KWin32Window* window = new Window::Win32::KWin32Window("EXAMPLE", {800, 600}, {0, 0}, Window::KWindowMode::WINDOWED);

	window->show();

	while (window->isOpen()) {
		window->update();
	}
}