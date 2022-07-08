#include "Win32WindowController.hpp"

#include "input/_win32/Win32Keyboard.hpp"
#include "input/_win32/Win32Mouse.hpp"

#include "graphics/_directx11/DX11Graphics.hpp"

using namespace Kozmic::Core::Window::Win32;
using namespace Kozmic::Core::Graphics;

LRESULT CALLBACK K_Win32WindowController::handleMessageSetup(HWND t_hWindow, UINT t_message, WPARAM t_wParam, LPARAM t_lParam) noexcept
{
    if (t_message == WM_NCCREATE)
    {
        const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(t_lParam);
        auto* const pWindow = static_cast<K_Win32WindowController*>(pCreate->lpCreateParams);
        
        SetWindowLongPtr(t_hWindow, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWindow));
        SetWindowLongPtr(t_hWindow, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&K_Win32WindowController::handleMessageThunk));

        return pWindow->handleMessage(t_hWindow, t_message, t_wParam, t_lParam);
    }

    return DefWindowProc(t_hWindow, t_message, t_wParam, t_lParam);
}

LRESULT K_Win32WindowController::handleMessageThunk(HWND t_hWindow, UINT t_message, WPARAM t_wParam, LPARAM t_lParam) noexcept
{
    auto* const pWnd = reinterpret_cast<K_Win32WindowController*>(GetWindowLongPtr(t_hWindow, GWLP_USERDATA));
    return pWnd->handleMessage(t_hWindow, t_message, t_wParam, t_lParam);
}

LRESULT K_Win32WindowController::handleMessage(HWND t_hWindow, UINT t_message, WPARAM t_wParam, LPARAM t_lParam) noexcept
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
        this->m_position = { LOWORD(t_lParam), HIWORD(t_lParam) };
        break;

    case WM_KEYDOWN:
        if (this->m_bFocused && this->m_keyboard)
            this->m_keyboard->notifyKeyDown(K_Win32WindowController::processKeys(t_wParam, t_lParam));
        break;

    case WM_KEYUP:
        if (this->m_bFocused && this->m_keyboard)
            this->m_keyboard->notifyKeyUp(K_Win32WindowController::processKeys(t_wParam, t_lParam));
        break;

    case WM_SYSKEYDOWN:
        if (this->m_bFocused && this->m_keyboard)
            this->m_keyboard->notifyKeyDown(K_Win32WindowController::processKeys(t_wParam, t_lParam));
        break;

    case WM_SYSKEYUP:
        if (this->m_bFocused && this->m_keyboard)
            this->m_keyboard->notifyKeyUp(K_Win32WindowController::processKeys(t_wParam, t_lParam));
        break;

    case WM_MOUSEMOVE:
        if (this->m_bFocused && this->m_mouse)
            this->m_mouse->notifyMove(t_lParam);
        break;

    case WM_MOUSEWHEEL:
        if (this->m_bFocused && this->m_mouse)
            this->m_mouse->notifyScroll(t_wParam);
        break;
    
    case WM_LBUTTONDOWN: case WM_MBUTTONDOWN: case WM_RBUTTONDOWN: case WM_XBUTTONDOWN:
        if (this->m_bFocused && this->m_mouse)
            this->m_mouse->notifyButtonDown(t_message, t_wParam);
        break;

    case WM_LBUTTONUP: case WM_MBUTTONUP: case WM_RBUTTONUP: case WM_XBUTTONUP:
        if (this->m_bFocused && this->m_mouse)
            this->m_mouse->notifyButtonUp(t_message, t_wParam);
        break;

    case WM_LBUTTONDBLCLK: case WM_MBUTTONDBLCLK: case WM_RBUTTONDBLCLK: case WM_XBUTTONDBLCLK:
        break;

    default:
        return DefWindowProc(t_hWindow, t_message, t_wParam, t_lParam);
    }

    return DefWindowProc(t_hWindow, t_message, t_wParam, t_lParam);
}

unsigned long K_Win32WindowController::getWindowStyle()
{
    return this->m_mode == K_WindowMode::WINDOWED ? WS_SYSMENU | WS_CAPTION : WS_POPUP;
}

void K_Win32WindowController::checkSize()
{
    if (this->m_mode != K_WindowMode::WINDOWED) {
        this->m_size = { GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };
    }
}

WPARAM K_Win32WindowController::processKeys(WPARAM t_wParam, LPARAM t_lParam)
{
    WPARAM checkedVk;
    UINT scanCode = (t_lParam & 0x00ff0000) >> 16;
    int extended = (t_lParam & 0x01000000) != 0;

    switch (t_wParam) {
    case VK_SHIFT:
        checkedVk = MapVirtualKey(scanCode, MAPVK_VSC_TO_VK_EX);
        break;
    case VK_CONTROL:
        checkedVk = extended ? VK_RCONTROL : VK_LCONTROL;
        break;
    case VK_MENU:
        checkedVk = extended ? VK_RMENU : VK_LMENU;
        break;
    default:
        checkedVk = t_wParam;
        break;
    }

    return checkedVk;
}

//<editor-fold desc="Constructors and Destructors">

K_Win32WindowController::K_Win32WindowController(const std::string& t_sTitle) : K_WindowController(t_sTitle, t_sTitle + "_WIN32")
{
    this->m_keyboard = nullptr;

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
    windowClass.lpszMenuName = nullptr;
    windowClass.lpszClassName = this->m_sTitle.c_str();

    RegisterClassEx(&windowClass);

    this->m_hWindow = CreateWindowEx(
        0,
        this->m_sTitle.c_str(),
        this->m_sTitle.c_str(),
        this->getWindowStyle(),
        this->m_position.xPos, this->m_position.yPos, 
        this->m_size.width, this->m_size.height,
        nullptr,
        nullptr,
        hInstance,
        this
    );

    if (this->m_hWindow == nullptr)
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

K_Win32WindowController::~K_Win32WindowController()
{
    this->m_graphicsController.reset();
    this->m_logger->info("Cleaning window");
}

//</editor-folder>

//<editor-fold desc="Constructors and Destructors">

void K_Win32WindowController::initialize() {
}

void K_Win32WindowController::shutdown() {
}

//</editor-fold>

//<editor-fold desc="Available throughout the life cycle">

std::shared_ptr<Kozmic::Core::Input::K_Keyboard> K_Win32WindowController::getKeyboardInput()
{
    this->m_logger->info("Returning a keyboard input access");

    if (this->m_keyboard == nullptr) 
        this->m_keyboard = std::make_shared<Kozmic::Core::Input::Win32::K_Win32Keyboard>();

    return this->m_keyboard;
}

std::shared_ptr<Kozmic::Core::Input::K_Mouse> K_Win32WindowController::getMouseInput()
{
    this->m_logger->info("Returning a mouse input access");

    if (this->m_mouse == nullptr)
        this->m_mouse = std::make_shared<Kozmic::Core::Input::Win32::K_Win32Mouse>();

    return this->m_mouse;
}

std::shared_ptr<K_GraphicsController> K_Win32WindowController::getGraphicsController()
{
    if(this->m_graphicsController == nullptr) {
        if (this->m_sGraphicsControllerType == "DX11") { 
            this->m_logger->info("Generating DirectX11 Graphics Controller");
            this->m_graphicsController = std::make_shared<K_DX11Graphics>(this->m_sTitle, this->m_hWindow,
                                                                          this->m_mode ==
                                                                          K_WindowMode::EXCLUSIVE_FULLSCREEN);
        }
    }

    return this->m_graphicsController;
}

//</editor-fold>

//<editor-fold desc="Available after initialization and before shutdown">

void K_Win32WindowController::show()
{
    this->m_logger->info("Showing window");
    ShowWindow(this->m_hWindow, 1);
}

void K_Win32WindowController::hide()
{
    this->m_logger->info("Hiding window");
    ShowWindow(this->m_hWindow, 0);
}

void K_Win32WindowController::close()
{
    this->m_logger->info("Closing window");
    PostQuitMessage(0);
}

bool K_Win32WindowController::isOpen()
{
    return GetMessage(&this->m_message, nullptr, 0, 0) > 0;
}

bool K_Win32WindowController::isFocused()
{
    return this->m_bFocused;
}

void K_Win32WindowController::update()
{
    TranslateMessage(&this->m_message);
    DispatchMessage(&this->m_message);
}

//</editor-fold>

//<editor-fold desc="Setters">

void K_Win32WindowController::setTitle(std::string t_sTitle)
{
    this->m_logger->info("Changing window title");

    SetWindowText(this->m_hWindow, t_sTitle.c_str());
}

void K_Win32WindowController::setSize(K_WindowSize t_size)
{
    this->m_logger->info("Changing size");

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

    if (this->m_graphicsController) {
        if (this->m_sGraphicsControllerType == "DX11") dynamic_cast<K_DX11Graphics*>(this->m_graphicsController.get())->setBufferSize({this->m_size.width, this->m_size.height});
    }
}

void K_Win32WindowController::setPosition(K_WindowPosition t_position)
{
    this->m_logger->info("Changing position");

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

void K_Win32WindowController::setMode(K_WindowMode t_mode)
{
    this->m_logger->info("Changing window mode");

    this->m_mode = t_mode;
    this->checkSize();

    if(this->m_mode != K_WindowMode::WINDOWED) {
        this->m_position.xPos = 0;
        this->m_position.yPos = 0;
    }
    else {
        this->m_size.width = 800;
        this->m_size.height = 600;
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
    
    SetWindowLong(this->m_hWindow, GWL_STYLE, (long) this->getWindowStyle());

    bool fullscreen = true;
    if (this->m_mode == K_WindowMode::WINDOWED) fullscreen = false;

    if (this->m_graphicsController) {
        if (this->m_sGraphicsControllerType == "DX11") dynamic_cast<K_DX11Graphics*>(this->m_graphicsController.get())->setFullscreen(fullscreen);
    }

    ShowWindow(this->m_hWindow, SW_SHOW);
}

//</editor-fold>