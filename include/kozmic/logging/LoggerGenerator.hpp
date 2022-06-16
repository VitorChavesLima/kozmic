#pragma once

#include <kozmic/logging/Logger.hpp>

namespace Kozmic::Core::Logging {
	class K_LoggerGenerator {
	public:
		virtual void getLogger < std::string t_sName) = 0;
	};
}