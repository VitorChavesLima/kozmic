#include <kozmic/core/logging/LoggingManager.hpp>

#include <chrono>
#include <filesystem>
#include <iostream>

using namespace Kozmic::Core;

K_LoggingManager* K_LoggingManager::m_instance = 0;

K_LoggingManager::K_LoggingManager()
{
	std::filesystem::path directory = std::filesystem::current_path();
	if (!std::filesystem::exists("logs")) std::filesystem::create_directory("logs");

	std::time_t currentTimestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	char filename[100];
	std::strftime(filename, sizeof(filename), "%Y-%M-%dT%H-%M-%S", std::localtime(&currentTimestamp));

	std::filesystem::path completePath = directory;
	completePath.append("logs");
	completePath.append(filename);
	completePath.replace_extension(".txt");

	this->m_loggerGenerator = std::make_unique<Logging::K_LoggerGenerator>(completePath.string());
}

K_LoggingManager* K_LoggingManager::getInstance()
{
	if (m_instance == 0)
	{
		m_instance = new K_LoggingManager();
	}

	return m_instance;
}

std::unique_ptr<Logging::K_Logger> K_LoggingManager::getLogger(std::string t_sName) {
	return this->m_loggerGenerator->getLogger(t_sName);
}