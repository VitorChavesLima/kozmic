#include "Game.hpp"

#include <kozmic/logging/LoggingManager.hpp>

#include <iostream>

using namespace Game;

K_Game::K_Game() : K_Application()
{
	this->m_logger = Kozmic::Core::K_LoggingManager::getInstance()->getLogger("GAME");

	try {
		this->m_logger->info("Starting game");

		//this->m_window = this->m_windowManager->getWindow("GAME");
		/*auto keyboardInput = this->m_window->getKeyboardInput();

		keyboardInput->addListener(this);

		this->m_graphics = this->m_window->getGraphicsController();

		this->m_window->show();

		this->m_logger->info("Running game loop");
		while (this->m_window->isOpen()) {
			this->m_window->update();
			this->m_graphics->clear();
			this->m_graphics->startDraw();
			this->m_graphics->finishDraw();
			this->m_graphics->show();
		}*/
	}
	catch (Kozmic::Core::Utils::K_Exception e) {
		this->m_logger->critical("{}\n", e.what());
	}
}

Game::K_Game::~K_Game()
{
	// this->m_window.reset();
	this->m_logger->info("Finishing game");
}

void Game::K_Game::handleKeyboardKeyDown(std::string t_sKeyId) {
	if (t_sKeyId == Kozmic::Core::Input::K_KeyMap::A) this->m_graphics->setClearColor({ 0.5f, 0.0f, 0.0f, 1.0f });
	if (t_sKeyId == Kozmic::Core::Input::K_KeyMap::S) this->m_graphics->setClearColor({ 0.0f, 0.5f, 0.0f, 1.0f });
}