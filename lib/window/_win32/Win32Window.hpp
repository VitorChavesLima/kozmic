#pragma once

#include <Windows.h>

#include <kozmic/window/Window.hpp>

namespace Kozmic::Core::Window::Win32 {
	class KWin32Window : public KWindow {
	private:
		HWND m_hWindow;
		MSG m_message;

	public:
		KWin32Window(std::string t_sTitle, KWindowSize t_size, KWindowPosition t_position, KWindowMode t_mode);

		virtual void show() override;
		virtual void hide() override;
		virtual void close() override;

		virtual bool isOpen() override;
		virtual void update() override;

	public:
		virtual void setTitle(std::string t_sTitle) override;
		virtual void setSize(KWindowSize t_size) override;
		virtual void setPosition(KWindowPosition t_position) override;
		virtual void setMode(KWindowMode t_mode) override;
	};
}