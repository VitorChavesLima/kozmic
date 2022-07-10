#pragma once

#include <string>

namespace Kozmic::Core::Input {
	class K_KeyMapper {
    public:
        virtual ~K_KeyMapper() = default;

	public:
		virtual int getKeyValue(std::string t_sKeyId) = 0;
		virtual std::string getKeyId(int t_nKeyValue) = 0;
	};
}