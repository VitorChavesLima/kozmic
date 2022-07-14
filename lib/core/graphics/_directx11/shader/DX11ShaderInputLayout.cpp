//
// Created by Vitor Chaves on 13/07/2022.
//

#include "DX11ShaderInputLayout.hpp"

using namespace Kozmic::Core::Graphics;

//<editor-fold desc="Constructors and Destructors">

K_Dx11ShaderInputLayout::K_Dx11ShaderInputLayout(ID3D11InputLayout *t_pInputLayout) {
    this->m_pInputLayout = t_pInputLayout;
}

//</editor-fold>
