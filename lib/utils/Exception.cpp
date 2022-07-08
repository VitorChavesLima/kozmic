#include <kozmic/utils/Exception.hpp>

#include <sstream>

using namespace Kozmic::Core::Utils;

K_Exception::K_Exception(std::string t_sFile, int t_nLine, std::string t_sFunction, std::string t_sMessage) {
	this->m_sFile = t_sFile;
	this->m_nLine = t_nLine;
	this->m_sFunction = t_sFunction;
	this->m_sMessage = t_sMessage;

	this->m_sType = "Kozmic Exception";
}

const char* K_Exception::what() const noexcept
{
	std::ostringstream stringStream;
	stringStream << this->m_sMessage << std::endl 
		<< "File: " << this->m_sFile << std::endl
		<< "Line: " << this->m_nLine << std::endl
		<< "Function: " << this->m_sFunction;
	

	this->m_sWhatBuffer = stringStream.str();
	return this->m_sWhatBuffer.c_str();
}

[[maybe_unused]] std::string K_Exception::getType()
{
	return this->m_sType;
}
