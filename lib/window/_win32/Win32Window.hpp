#pragma once

#include <Windows.h>

#include <kozmic/window/Window.hpp>

#include "input/_win32/Win32InputController.hpp"

namespace Kozmic::Core::Window::Win32 {
	class KWin32Window : public KWindow {
	private:
		HWND m_hWindow;
		MSG m_message;

		std::shared_ptr<Input::Win32::K_Win32InputController> m_inputController;

	private:
		static LRESULT CALLBACK handleMessageSetup(HWND t_hWindow, UINT t_message, WPARAM t_wParam, LPARAM t_lParam) noexcept;
		static LRESULT CALLBACK HandleMessageThunk(HWND t_hWindow, UINT t_message, WPARAM t_wParam, LPARAM t_lParam) noexcept;
		LRESULT handleMessage(HWND t_hWindow, UINT t_message, WPARAM t_wParam, LPARAM t_lParam) noexcept;

		DWORD getWindowStyle();
		void checkSize();

	public:
		KWin32Window(std::string t_sTitle, KWindowSize t_size, KWindowPosition t_position, KWindowMode t_mode);

		virtual void show() override;
		virtual void hide() override;
		virtual void close() override;

		virtual bool isOpen() override;
		virtual bool isFocused() override;
		virtual void update() override;

		virtual std::shared_ptr<Input::K_InputController> getInputController() override;

	public:
		virtual void setTitle(std::string t_sTitle) override;
		virtual void setSize(KWindowSize t_size) override;
		virtual void setPosition(KWindowPosition t_position) override;
		virtual void setMode(KWindowMode t_mode) override;
	};
}