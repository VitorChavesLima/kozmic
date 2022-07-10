#include <kozmic/core/window/WindowController.hpp>

using namespace Kozmic::Core::Window;

//<editor-fold desc="Constructors and Destructors">

K_WindowController::K_WindowController(std::string t_sTitle, const std::string& t_sLoggerName) : Utils::K_Controller(t_sLoggerName + "_WINDOW") {
	this->m_logger->info("Constructing Window");

	this->m_sTitle = std::move(t_sTitle);
	this->m_mode = K_WindowMode::WINDOWED;
    this->m_bFocused = false;
	this->m_sGraphicsControllerType = "DX11";
}

//</editor-fold>

//<editor-fold desc="Getters">

[[maybe_unused]] std::string K_WindowController::getTitle()
{
	return this->m_sTitle;
}

[[maybe_unused]] K_WindowSize K_WindowController::getSize()
{
	return this->m_size;
}

[[maybe_unused]] K_WindowPosition K_WindowController::getPosition()
{
	return this->m_position;
}

[[maybe_unused]] K_WindowMode K_WindowController::getMode() {
	return this->m_mode;
}

//</editor-fold>