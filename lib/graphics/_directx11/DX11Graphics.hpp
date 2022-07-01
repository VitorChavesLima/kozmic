#pragma once

#include <Windows.h>

#include <kozmic/graphics/Graphics.hpp>

namespace Kozmic::Core::Graphics {
	class K_DX11Graphics : public K_Graphics {
	private:
		HWND m_hWindow;

	public:
		K_DX11Graphics(HWND t_hWindow);
	};
}