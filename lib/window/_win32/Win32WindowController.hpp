//
// Created by vitor on 07/07/2022.
//

#ifndef KOZMIC_WIN32WINDOWCONTROLLER_HPP
#define KOZMIC_WIN32WINDOWCONTROLLER_HPP

#include <Windows.h>

#include <kozmic/window/WindowController.hpp>

namespace Kozmic::Core::Input::Win32 {
    class K_Win32Keyboard;
    class K_Win32Mouse;
}

namespace Kozmic::Core::Window::Win32 {
    class K_Win32WindowController : public K_WindowController {
    private:
        HWND m_hWindow;
        MSG m_message = { };

        std::shared_ptr<Input::Win32::K_Win32Keyboard> m_keyboard;
        std::shared_ptr<Input::Win32::K_Win32Mouse> m_mouse;
        std::shared_ptr<Graphics::K_GraphicsController> m_graphicsController;

    private:
        static LRESULT CALLBACK handleMessageSetup(HWND t_hWindow, UINT t_message, WPARAM t_wParam, LPARAM t_lParam) noexcept;
        static LRESULT CALLBACK handleMessageThunk(HWND t_hWindow, UINT t_message, WPARAM t_wParam, LPARAM t_lParam) noexcept;
        LRESULT handleMessage(HWND t_hWindow, UINT t_message, WPARAM t_wParam, LPARAM t_lParam) noexcept;

        unsigned long getWindowStyle();
        void checkSize();

        static WPARAM processKeys(WPARAM t_wParam, LPARAM t_lParam);

        //<editor-fold desc="Constructors and Destructors">

    public:
        explicit K_Win32WindowController(const std::string& t_sTitle);
        ~K_Win32WindowController() override;

        //</editor-fold>

        //<editor-fold desc="Controller Specific">

    public:
        void initialize() override;
        void shutdown() override;

        //</editor-fold>

        //<editor-fold desc="Available throughout the life cycle">

        std::shared_ptr<Input::K_Keyboard> getKeyboardInput() override;
        std::shared_ptr<Input::K_Mouse> getMouseInput() override;
        std::shared_ptr<Graphics::K_GraphicsController> getGraphicsController() override;

        //</editor-fold>

        //<editor-fold desc="Available after initialization and before shutdown">

        void show() override;
        void hide() override;
        void close() override;

        bool isOpen() override;
        bool isFocused() override;
        void update() override;

        //</editor-fold>

        //<editor-fold desc="Setters">

    public:
        void setTitle(std::string t_sTitle) override;
        void setSize(K_WindowSize t_size) override;
        void setPosition(K_WindowPosition t_position) override;
        void setMode(K_WindowMode t_mode) override;

        //</editor-fold>
    };
}

#endif //KOZMIC_WIN32WINDOWCONTROLLER_HPP
