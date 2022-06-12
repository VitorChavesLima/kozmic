#include "Win32Window.hpp"

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
    }

    return DefWindowProc(t_hWindow, t_message, t_wParam, t_lParam);
}

KWin32Window::KWin32Window(std::string t_sTitle, KWindowSize t_size, KWindowPosition t_position, KWindowMode t_mode) : KWindow(t_sTitle, t_size, t_position, t_mode)
{
    this->m_message = { };

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
        WS_OVERLAPPEDWINDOW,
        this->m_position.xPos, this->m_position.yPos, 
        this->m_size.width, this->m_size.height,
        NULL,  
        NULL,
        hInstance,
        NULL
    );

    if (this->m_hWindow == NULL)
    {
        return;
    }
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
    CloseWindow(this->m_hWindow);
}

bool KWin32Window::isOpen()
{
    return GetMessage(&this->m_message, NULL, 0, 0) > 0;
}

void KWin32Window::update()
{
    TranslateMessage(&this->m_message);
    DispatchMessage(&this->m_message);
}

void KWin32Window::setTitle(std::string t_sTitle)
{
}

void KWin32Window::setSize(KWindowSize t_size)
{
}

void KWin32Window::setPosition(KWindowPosition t_position)
{
}

void KWin32Window::setMode(KWindowMode t_mode)
{
}
