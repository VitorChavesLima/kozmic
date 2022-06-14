#pragma once

#include <kozmic/input/KeyMap.hpp>

namespace Kozmic::Core::Input::Win32 {
	class K_Win32KeyMap : public K_KeyMap {
	public:
		K_Win32KeyMap();

		virtual int getKeyValue(std::string t_sKeyId) override;
		virtual std::string getKeyId(int t_nKeyValue) override;
	};
}