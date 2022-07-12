#include "Game.hpp"

#include <kozmic/core/logging/LoggingManager.hpp>
#include <kozmic/core/window/WindowManager.hpp>

#include <iostream>
#include <sstream>

using namespace Game;

K_Game::K_Game() : K_Application()
{
    this->m_nFramesPerSeconds = 0;
    this->m_nName = "GAME";
	this->m_logger = Kozmic::Core::K_LoggingManager::getInstance()->getLogger(this->m_nName);

    this->m_applicationTimer = std::make_unique<Kozmic::Core::Timing::K_ApplicationTimer>();
    this->m_applicationTimer->setFramesPerSecond(60);

	try {
		this->m_logger->info("Starting game");

		this->m_window = Kozmic::Core::K_WindowManager::getInstance()->getWindow(this->m_nName);
		this->m_graphics = this->m_window->getGraphicsController();
        auto shaderController = this->m_graphics->getShaderController();

		this->m_window->show();

		this->m_logger->info("Starting game loop");

        auto accumulator = 0.0;
        auto second = 0.0;

        this->m_applicationTimer->markCurrentFrameTime();
		while (this->m_window->isOpen()) {
            this->m_window->update();

            if(this->m_window->isFocused()) {
                this->m_applicationTimer->markLastFrameTime();
                auto deltaTime = this->m_applicationTimer->deltaTime();
                accumulator += deltaTime;

                if(second >= 1000000000) {
                    updateWindowTitle();
                    second = 0.0;
                    this->m_nFramesPerSeconds = 0;
                }

                while(accumulator >= this->m_applicationTimer->getIdealFrameTime()) {
                    // UPDATE STATE
                    accumulator -= deltaTime;
                    second += deltaTime;
                }

                this->m_graphics->clear();
                this->m_graphics->startDraw();
                this->m_graphics->finishDraw();
                this->m_graphics->show();

                this->m_nFramesPerSeconds++;
            }
		}
		this->m_logger->info("Exiting game loop");
	}
	catch (Kozmic::Core::Utils::K_Exception e) {
		this->m_logger->critical("{}\n", e.what());
	}
}

Game::K_Game::~K_Game()
{
	this->m_graphics.reset();
	this->m_window.reset();
	this->m_logger->info("Finishing game");
}

void K_Game::updateWindowTitle() {
    std::stringstream windowTitle;
    windowTitle << this->m_nName << " - FPS: " << this->m_nFramesPerSeconds;
    this->m_window->setTitle(windowTitle.str());
}
