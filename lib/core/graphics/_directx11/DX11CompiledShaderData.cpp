//
// Created by Vitor Chaves on 12/07/2022.
//

#include "DX11CompiledShaderData.hpp"

using namespace Kozmic::Core::Graphics;

//<editor-fold desc="Constructors and Destructors">

K_Dx11CompiledShaderData::K_Dx11CompiledShaderData(K_ShaderType t_shaderType, ID3DBlob *t_pShaderBlob) {
    this->m_shaderType = t_shaderType;
    this->m_pShaderBlob = t_pShaderBlob;
}

K_Dx11CompiledShaderData::~K_Dx11CompiledShaderData() {
    this->m_pShaderBlob->Release();
}

//</editor-fold