//
// Created by Vitor Chaves on 12/07/2022.
//

#ifndef KOZMIC_DX11SHADER_HPP
#define KOZMIC_DX11SHADER_HPP

#include <d3d11.h>

#include "kozmic/core/graphics/ShaderController.hpp"
#include "DX11ShaderType.hpp"

namespace Kozmic::Core::Graphics {
    class K_Dx11Shader : public K_Shader{

        //<editor-fold desc="Properties">

    private:
        K_ShaderType m_shaderType;
        ID3D11DeviceChild* m_shader;

        friend class K_Dx11ShaderController;

        //</editor-fold>

        //<editor-fold desc="Constructors and Destructors">

    public:
        K_Dx11Shader(K_ShaderType t_shaderType, ID3D11DeviceChild* t_shader);

        //</editor-fold>

        //<editor-fold desc="Getters">
    private:
        K_ShaderType getShaderType() { return this->m_shaderType; }
        ID3D11DeviceChild* getShader() { return this->m_shader; }

        //</editor-fold>
    };
}

#endif //KOZMIC_DX11SHADER_HPP
