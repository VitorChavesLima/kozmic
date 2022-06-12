#pragma once

#include <string>

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
		FULLSCREEN,
		EXCLUSIVE_FULLSCREEN
	};

	class KWindow {
	protected:
		std::string m_sTitle;
		KWindowSize m_size;
		KWindowPosition m_position;
		KWindowMode m_mode;

	public:
		KWindow(std::string t_sTitle, KWindowSize t_size, KWindowPosition t_position, KWindowMode t_mode);

		virtual void show() = 0;
		virtual void hide() = 0;
		virtual void close() = 0;

		virtual void isOpen() = 0;

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