#include "Win32Window.hpp"
#include "input/_win32/Win32Keyboard.hpp"
#include "input/_win32/Win32Mouse.hpp"

#include <iostream>

using namespace Kozmic::Core::Window::Win32;

LRESULT CALLBACK KWin32Window::handleMessageSetup(HWND t_hWindow, UINT t_message, WPARAM t_wParam, LPARAM t_lParam) noexcept
{
    if (t_message == WM_NCCREATE)
    {
        const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(t_lParam);
        KWin32Window* const pWindow = static_cast<KWin32Window*>(pCreate->lpCreateParams);
        
        SetWindowLongPtr(t_hWindow, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWindow));
        SetWindowLongPtr(t_hWindow, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&KWin32Window::HandleMessageThunk));

        return pWindow->handleMessage(t_hWindow, t_message, t_wParam, t_lParam);
    }

    return DefWindowProc(t_hWindow, t_message, t_wParam, t_lParam);
}

LRESULT KWin32Window::HandleMessageThunk(HWND t_hWindow, UINT t_message, WPARAM t_wParam, LPARAM t_lParam) noexcept
{
    KWin32Window* const pWnd = reinterpret_cast<KWin32Window*>(GetWindowLongPtr(t_hWindow, GWLP_USERDATA));
    return pWnd->handleMessage(t_hWindow, t_message, t_wParam, t_lParam);
}

LRESULT KWin32Window::handleMessage(HWND t_hWindow, UINT t_message, WPARAM t_wParam, LPARAM t_lParam) noexcept
{
    switch (t_message)
    {
    case WM_CLOSE:
        PostQuitMessage(0);
        return 0;

    case WM_KILLFOCUS:
        this->m_bFocused = false;
        break;

    case WM_SETFOCUS:
        this->m_bFocused = true;
        break;

    case WM_MOVE:
        this->m_position = { (unsigned int)(short)LOWORD(t_lParam), (unsigned int)(short)HIWORD(t_lParam) };
        break;

    case WM_KEYDOWN:
        if (this->m_bFocused && this->m_keyboard)
            this->m_keyboard->notifyKeyDown(this->processKeys(t_wParam, t_lParam));
        break;

    case WM_KEYUP:
        if (this->m_bFocused && this->m_keyboard)
            this->m_keyboard->notifyKeyUp(this->processKeys(t_wParam, t_lParam));
        break;

    case WM_SYSKEYDOWN:
        if (this->m_bFocused && this->m_keyboard)
            this->m_keyboard->notifyKeyUp(this->processKeys(t_wParam, t_lParam));
        break;

    case WM_SYSKEYUP:
        if (this->m_bFocused && this->m_keyboard)
            this->m_keyboard->notifyKeyUp(this->processKeys(t_wParam, t_lParam));
        break;

    case WM_MOUSEMOVE:
        if (this->m_bFocused && this->m_mouse)
            this->m_mouse->notifyMove(t_lParam);
        break;
    }

    return DefWindowProc(t_hWindow, t_message, t_wParam, t_lParam);
}

DWORD Kozmic::Core::Window::Win32::KWin32Window::getWindowStyle()
{
    return this->m_mode == KWindowMode::WINDOWED ? WS_SYSMENU : WS_POPUP;
}

void Kozmic::Core::Window::Win32::KWin32Window::checkSize()
{
    if (this->m_mode != KWindowMode::WINDOWED) {
        this->m_size = { (unsigned int) GetSystemMetrics(SM_CXSCREEN), (unsigned int) GetSystemMetrics(SM_CYSCREEN) };
    }
}

WPARAM Kozmic::Core::Window::Win32::KWin32Window::processKeys(WPARAM t_wParam, LPARAM t_lParam)
{
    WPARAM checked_vk = t_wParam;
    UINT scancode = (t_lParam & 0x00ff0000) >> 16;
    int extended = (t_lParam & 0x01000000) != 0;

    switch (t_wParam) {
    case VK_SHIFT:
        checked_vk = MapVirtualKey(scancode, MAPVK_VSC_TO_VK_EX);
        break;
    case VK_CONTROL:
        checked_vk = extended ? VK_RCONTROL : VK_LCONTROL;
        break;
    case VK_MENU:
        checked_vk = extended ? VK_RMENU : VK_LMENU;
        break;
    default:
        checked_vk = t_wParam;
        break;
    }

    return checked_vk;
}

KWin32Window::KWin32Window(std::string t_sTitle, KWindowSize t_size, KWindowPosition t_position, KWindowMode t_mode) : KWindow(t_sTitle, t_size, t_position, t_mode)
{
    this->m_keyboard = nullptr;

    this->m_message = { };
    this->checkSize();

	HINSTANCE hInstance = GetModuleHandle(nullptr);

    WNDCLASSEX windowClass = { 0 };
    windowClass.cbSize = sizeof(windowClass);
    windowClass.lpfnWndProc = this->handleMessageSetup;
    windowClass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
    windowClass.hInstance = hInstance;
    windowClass.hbrBackground = (HBRUSH) CreateSolidBrush(RGB(0,0,0));
    windowClass.lpszMenuName = NULL;
    windowClass.lpszClassName = this->m_sTitle.c_str();

    RegisterClassEx(&windowClass);

    this->m_hWindow = CreateWindowEx(
        0,
        this->m_sTitle.c_str(),
        this->m_sTitle.c_str(),
        this->getWindowStyle(),
        this->m_position.xPos, this->m_position.yPos, 
        this->m_size.width, this->m_size.height,
        NULL,
        NULL,
        hInstance,
        this
    );

    if (this->m_hWindow == NULL)
    {
        return;
    }

    SetWindowPos(
        this->m_hWindow,
        nullptr,
        this->m_position.xPos,
        this->m_position.yPos,
        this->m_size.width,
        this->m_size.height,
        0
    );
}

void KWin32Window::show()
{
    ShowWindow(this->m_hWindow, 1);
}

void KWin32Window::hide()
{
    ShowWindow(this->m_hWindow, 0);
}

void KWin32Window::close()
{
    PostQuitMessage(0);
}

bool KWin32Window::isOpen()
{
    return GetMessage(&this->m_message, NULL, 0, 0) > 0;
}

bool KWin32Window::isFocused()
{
    return this->m_bFocused;
}

void KWin32Window::update()
{
    TranslateMessage(&this->m_message);
    DispatchMessage(&this->m_message);
}

std::shared_ptr<Kozmic::Core::Input::K_Keyboard> KWin32Window::getKeyboardInput()
{
    if (this->m_keyboard == nullptr) 
        this->m_keyboard = std::make_shared<Kozmic::Core::Input::Win32::K_Win32Keyboard>();

    return this->m_keyboard;
}

std::shared_ptr<Kozmic::Core::Input::K_Mouse> KWin32Window::getMouseInput()
{
    if (this->m_mouse == nullptr)
        this->m_mouse = std::make_shared<Kozmic::Core::Input::Win32::K_Win32Mouse>();

    return this->m_mouse;
}

void KWin32Window::setTitle(std::string t_sTitle)
{
    SetWindowText(this->m_hWindow, t_sTitle.c_str());
}

void KWin32Window::setSize(KWindowSize t_size)
{
    this->m_size = t_size;

    SetWindowPos(
        this->m_hWindow,
        nullptr,
        this->m_position.xPos,
        this->m_position.yPos,
        this->m_size.width,
        this->m_size.height,
        SWP_NOREPOSITION
    );
}

void KWin32Window::setPosition(KWindowPosition t_position)
{
    this->m_position = t_position;

    SetWindowPos(
        this->m_hWindow,
        nullptr,
        this->m_position.xPos,
        this->m_position.yPos,
        this->m_size.width,
        this->m_size.height,
        SWP_NOSIZE
    );
}

void KWin32Window::setMode(KWindowMode t_mode)
{
    this->m_mode = t_mode;
    this->checkSize();

    SetWindowPos(
        this->m_hWindow,
        nullptr,
        this->m_position.xPos,
        this->m_position.yPos,
        this->m_size.width,
        this->m_size.height,
        0
    );
    
    SetWindowLong(this->m_hWindow, GWL_STYLE, this->getWindowStyle());
    ShowWindow(this->m_hWindow, SW_SHOW);
}
