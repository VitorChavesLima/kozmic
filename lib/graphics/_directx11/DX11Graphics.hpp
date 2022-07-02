#pragma once

#include <Windows.h>
#include <d3d11.h>

#include <kozmic/graphics/Graphics.hpp>

namespace Kozmic::Core::Graphics {
	class K_DX11Graphics : public K_Graphics {
	private:
		ID3D11Device* m_device = nullptr;
		ID3D11DeviceContext* m_context = nullptr;
		D3D_FEATURE_LEVEL m_featureLevel = {};

		HWND m_hWindow;

	private:
		void createDevice();

	public:
		K_DX11Graphics(HWND t_hWindow);
		~K_DX11Graphics();
	};
}