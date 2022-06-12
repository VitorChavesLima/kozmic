#pragma once

#include <kozmic/window/Window.hpp>

namespace Kozmic::Core::Window::Win32 {
	class KWin32Window : public KWindow {
	public:
		KWin32Window(std::string t_sTitle, KWindowSize t_size, KWindowPosition t_position, KWindowMode t_mode);

		virtual void show() override;
		virtual void hide() override;
		virtual void close() override;

		virtual void isOpen() override;

	public:
		virtual void setTitle(std::string t_sTitle) override;
		virtual void setSize(KWindowSize t_size) override;
		virtual void setPosition(KWindowPosition t_position) override;
		virtual void setMode(KWindowMode t_mode) override;
	};
}