#include <kozmic/core/utils/Controller.hpp>
#include <kozmic/core/logging/LoggingManager.hpp>

using namespace Kozmic::Core::Utils;

K_Controller::K_Controller(std::string t_loggerName) {
	this->m_logger = K_LoggingManager::getInstance()->getLogger(t_loggerName);
}