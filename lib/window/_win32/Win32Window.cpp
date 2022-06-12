#include "Win32Window.hpp"

Kozmic::Core::Window::Win32::KWin32Window::KWin32Window(std::string t_sTitle, KWindowSize t_size, KWindowPosition t_position, KWindowMode t_mode) : KWindow(t_sTitle, t_size, t_position, t_mode)
{
    this->m_message = { };

	HINSTANCE hInstance = GetModuleHandle(nullptr);

    WNDCLASSEX windowClass = { 0 };
    windowClass.cbSize = sizeof(windowClass);
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

void Kozmic::Core::Window::Win32::KWin32Window::show()
{
    ShowWindow(this->m_hWindow, 1);
}

void Kozmic::Core::Window::Win32::KWin32Window::hide()
{
    ShowWindow(this->m_hWindow, 0);
}

void Kozmic::Core::Window::Win32::KWin32Window::close()
{
    CloseWindow(this->m_hWindow);
}

bool Kozmic::Core::Window::Win32::KWin32Window::isOpen()
{
    return !PeekMessage(&m_message, NULL, 0, 0, PM_REMOVE);
}

void Kozmic::Core::Window::Win32::KWin32Window::update()
{
    TranslateMessage(&m_message);
    DispatchMessage(&m_message);
}

void Kozmic::Core::Window::Win32::KWin32Window::setTitle(std::string t_sTitle)
{
}

void Kozmic::Core::Window::Win32::KWin32Window::setSize(KWindowSize t_size)
{
}

void Kozmic::Core::Window::Win32::KWin32Window::setPosition(KWindowPosition t_position)
{
}

void Kozmic::Core::Window::Win32::KWin32Window::setMode(KWindowMode t_mode)
{
}
