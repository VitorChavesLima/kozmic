#pragma once

#include <memory>
#include <string>

#include <kozmic/logging/Logger.hpp>
#include <kozmic/input/Keyboard.hpp>
#include <kozmic/input/Mouse.hpp>

namespace Kozmic::Core::Window {
	struct KWindowSize {
		unsigned int width;
		unsigned int height;
	};

	struct KWindowPosition
	{
		unsigned int xPos;
		unsigned int yPos;
	};

	enum KWindowMode {
		WINDOWED,
		BORDERLESS_FULLSCREEN,
		EXCLUSIVE_FULLSCREEN
	};

	class KWindow {
	protected:
		std::string m_sTitle;
		KWindowSize m_size;
		KWindowPosition m_position;
		KWindowMode m_mode;
		bool m_bFocused;

	public:
		KWindow(std::string t_sTitle, KWindowSize t_size, KWindowPosition t_position, KWindowMode t_mode);

		virtual void show() = 0;
		virtual void hide() = 0;
		virtual void close() = 0;

		virtual bool isOpen() = 0;
		virtual bool isFocused() = 0;
		virtual void update() = 0;

		virtual std::shared_ptr<Input::K_Keyboard> getKeyboardInput() = 0;
		virtual std::shared_ptr<Input::K_Mouse> getMouseInput() = 0;

	public:
		virtual void setTitle(std::string t_sTitle) = 0;
		virtual void setSize(KWindowSize t_size) = 0;
		virtual void setPosition(KWindowPosition t_position) = 0;
		virtual void setMode(KWindowMode t_mode) = 0;

	public:
		std::string getTitle();
		KWindowSize getSize();
		KWindowPosition getPosition();
		KWindowMode getMode();
	};
}