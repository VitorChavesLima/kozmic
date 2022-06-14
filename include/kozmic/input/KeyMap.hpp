#pragma once

#include <unordered_map>
#include <string>

namespace Kozmic::Core::Input {
	class K_KeyMap {
	protected:
		std::unordered_map<std::string, int> m_keyValues;
		std::unordered_map<int, std::string> m_keyIds;

	public:
		virtual int getKeyValue(std::string t_sKeyId) = 0;
		virtual std::string getKeyId(int t_nKeyValue) = 0;
	};
}