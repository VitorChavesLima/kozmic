#include "Game.hpp"

#include <iostream>

using namespace Game;

K_Game::K_Game() : K_Application()
{
	try {
		this->m_logger = this->m_loggingManager->getLogger("Game");
		auto windowLogger = this->m_loggingManager->getLogger("Window");

		this->m_logger->info("Starting game");

		this->m_window = this->m_windowManager->getWindow(std::move(windowLogger), "GAME", { 800, 600 }, { 0, 0 }, Kozmic::Core::Window::KWindowMode::WINDOWED, "DX11");
		auto keyboardInput = this->m_window->getKeyboardInput();

		keyboardInput->addListener(this);

		this->m_graphics = this->m_window->getGraphics();

		this->m_window->show();

		this->m_logger->info("Running game loop");
		while (this->m_window->isOpen()) {
			this->m_window->update();
			this->m_graphics->clear();
			this->m_graphics->startDraw();
			this->m_graphics->finishDraw();
			this->m_graphics->show();
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

void Game::K_Game::handleKeyboardKeyDown(std::string t_sKeyId) {
	if (t_sKeyId == Kozmic::Core::Input::K_KeyMap::T) {
		this->m_window->setSize({ 1280, 720 });
	}

	if (t_sKeyId == Kozmic::Core::Input::K_KeyMap::F) {
		if (this->m_window->getMode() == Kozmic::Core::Window::WINDOWED) { 
			this->m_window->setMode(Kozmic::Core::Window::EXCLUSIVE_FULLSCREEN); 
		}
		else if (this->m_window->getMode() == Kozmic::Core::Window::EXCLUSIVE_FULLSCREEN) { 
			this->m_window->setMode(Kozmic::Core::Window::WINDOWED); 
		}
	}
}