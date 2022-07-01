#pragma once

#include <Windows.h>

#include <kozmic/window/Window.hpp>

namespace Kozmic::Core::Input::Win32 {
	class K_Win32Keyboard;
	class K_Win32Mouse;
}

namespace Kozmic::Core::Window::Win32 {
	class KWin32Window : public KWindow {
	private:
		HWND m_hWindow;
		MSG m_message;

		std::unique_ptr<Logging::K_Logger> m_logger;
		std::shared_ptr<Input::Win32::K_Win32Keyboard> m_keyboard;
		std::shared_ptr<Input::Win32::K_Win32Mouse> m_mouse;
		std::shared_ptr<Graphics::K_Graphics> m_graphics;

	private:
		static LRESULT CALLBACK handleMessageSetup(HWND t_hWindow, UINT t_message, WPARAM t_wParam, LPARAM t_lParam) noexcept;
		static LRESULT CALLBACK HandleMessageThunk(HWND t_hWindow, UINT t_message, WPARAM t_wParam, LPARAM t_lParam) noexcept;
		LRESULT handleMessage(HWND t_hWindow, UINT t_message, WPARAM t_wParam, LPARAM t_lParam) noexcept;

		DWORD getWindowStyle();
		void checkSize();

		WPARAM processKeys(WPARAM t_wParam, LPARAM t_lParam);

	public:
		KWin32Window(std::unique_ptr<Logging::K_Logger> t_logger, std::string t_sTitle, KWindowSize t_size, KWindowPosition t_position, KWindowMode t_mode, std::string t_sGraphicsType);
		virtual ~KWin32Window() override;

		virtual void show() override;
		virtual void hide() override;
		virtual void close() override;

		virtual bool isOpen() override;
		virtual bool isFocused() override;
		virtual void update() override;

		virtual std::shared_ptr<Input::K_Keyboard> getKeyboardInput() override;
		virtual std::shared_ptr<Input::K_Mouse> getMouseInput() override;
		virtual std::shared_ptr<Graphics::K_Graphics> getGraphics() override;

	public:
		virtual void setTitle(std::string t_sTitle) override;
		virtual void setSize(KWindowSize t_size) override;
		virtual void setPosition(KWindowPosition t_position) override;
		virtual void setMode(KWindowMode t_mode) override;
	};
}