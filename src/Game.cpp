#include "Game.hpp"

using namespace Game;

K_Game::K_Game() : K_Application()
{
	this->m_window = this->m_windowManager->getWindow("GAME", {800, 600}, {0, 0}, Kozmic::Core::Window::KWindowMode::WINDOWED);

	this->m_window->show();

	while (this->m_window->isOpen()) {
		this->m_window->update();
	}
}
