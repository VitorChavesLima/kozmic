#include "Game.hpp"

#include <iostream>

using namespace Game;

K_Game::K_Game() : K_Application()
{
	try {
		this->m_logger = this->m_loggingManager->getLogger("Game");
		auto windowLogger = this->m_loggingManager->getLogger("Window");

		this->m_logger->info("Starting game");

		this->m_window = this->m_windowManager->getWindow(std::move(windowLogger), "GAME", { 800, 600 }, { 0, 0 }, Kozmic::Core::Window::KWindowMode::WINDOWED);

		this->m_window->show();

		this->m_logger->info("Running game loop");
		while (this->m_window->isOpen()) {
			this->m_window->update();
		}
	}
	catch (Kozmic::Utils::K_Exception e) {
		this->m_logger->critical("{}\n", e.what());
	}
}

Game::K_Game::~K_Game()
{
	this->m_window.reset();
	this->m_logger->info("Finishing game");
}
