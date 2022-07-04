#pragma once

#include <exception>
#include <string>

namespace Kozmic::Core::Utils {
	class K_Exception : public std::exception {
	private:
		std::string m_sFile;
		int m_nLine;
		std::string m_sFunction;
		
		std::string m_sType;
		std::string m_sMessage;
		
		mutable std::string m_sWhatBuffer;

	public:
		K_Exception(std::string t_sFile, int t_nLine, std::string t_sFunction, std::string t_sMessage);

		const char* what() const noexcept override;

		std::string getType();
	};
}