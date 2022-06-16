#pragma once

#include <string>

namespace Kozmic::Core::Logging {
	class K_Logger {
	public:
		template <typename... T>
		virtual void info(std::string t_sMessage, T &&...args) = 0;

		template <typename... T>
		virtual void warn(std::string t_sMessage, T &&...args) = 0;

		template <typename... T>
		virtual void error(std::string t_sMessage, T &&...args) = 0;

		template <typename... T>
		virtual void critical(std::string t_sMessage, T &&...args) = 0;
	};
}