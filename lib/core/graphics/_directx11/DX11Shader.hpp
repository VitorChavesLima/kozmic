//
// Created by Vitor Chaves on 12/07/2022.
//

#ifndef KOZMIC_DX11SHADER_HPP
#define KOZMIC_DX11SHADER_HPP

#include <d3d11.h>

#include <kozmic/core/graphics/ShaderController.hpp>

namespace Kozmic::Core::Graphics {
    class K_Dx11Shader: public K_Shader {
        //<editor-fold desc="Properties">

        ID3DBlob* m_pShaderBlob;

        //</editor-fold>

        //<editor-fold desc="Constructors and Destructors">

    public:
        explicit K_Dx11Shader(ID3DBlob* t_pShaderBlob);
        ~K_Dx11Shader();

        //</editor-fold>
    };
}

#endif //KOZMIC_DX11SHADER_HPP
