#pragma once

#include <unordered_map>
#include <string>

#include <kozmic/core/input/KeyMapper.hpp>

namespace Kozmic::Core::Input::Win32 {
	class K_Win32KeyMapper : public K_KeyMapper {
	private:
		std::unordered_map<std::string, int> m_keyValues;

	public:
		K_Win32KeyMapper();

		virtual int getKeyValue(std::string t_sKeyId) override;
		virtual std::string getKeyId(int t_nKeyValue) override;
	};
}