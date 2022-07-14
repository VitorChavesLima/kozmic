//
// Created by Vitor Chaves on 12/07/2022.
//

#include "DX11Shader.hpp"

using namespace Kozmic::Core::Graphics;

//<editor-fold desc="Constructors and Destructors">

K_Dx11Shader::K_Dx11Shader(K_ShaderType t_shaderType, ID3D11DeviceChild *t_shader) {
    this->m_shaderType = t_shaderType;
    this->m_shader = t_shader;
}

//</editor-fold>