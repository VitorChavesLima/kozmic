//
// Created by Vitor Chaves on 13/07/2022.
//

#ifndef KOZMIC_DX11SHADERINPUTLAYOUT_HPP
#define KOZMIC_DX11SHADERINPUTLAYOUT_HPP

#include <d3d11.h>

#include <kozmic/core/graphics/ShaderController.hpp>

namespace Kozmic::Core::Graphics {
    class K_Dx11ShaderInputLayout : public K_ShaderInputLayout {
        //<editor-fold desc="Properties">

        ID3D11InputLayout* m_pInputLayout;

        //</editor-fold>

        //<editor-fold desc="Constructors and Destructors">

    public:
        explicit K_Dx11ShaderInputLayout(ID3D11InputLayout* t_pInputLayout);

        //</editor-fold>
    };
}

#endif //KOZMIC_DX11SHADERINPUTLAYOUT_HPP
