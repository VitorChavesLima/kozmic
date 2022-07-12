//
// Created by Vitor Chaves on 12/07/2022.
//

#include "DX11Shader.hpp"

using namespace Kozmic::Core::Graphics;

//<editor-fold desc="Constructors and Destructors">

K_Dx11Shader::K_Dx11Shader(ID3DBlob *t_pShaderBlob) {
    this->m_pShaderBlob = t_pShaderBlob;
}

K_Dx11Shader::~K_Dx11Shader() {
    this->m_pShaderBlob->Release();
}

//</editor-fold