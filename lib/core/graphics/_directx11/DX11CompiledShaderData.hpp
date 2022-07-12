//
// Created by Vitor Chaves on 12/07/2022.
//

#ifndef KOZMIC_DX11COMPILEDSHADERDATA_HPP
#define KOZMIC_DX11COMPILEDSHADERDATA_HPP

#include <d3d11.h>

#include <kozmic/core/graphics/ShaderController.hpp>
#include "DX11ShaderType.hpp"

namespace Kozmic::Core::Graphics {
    class K_Dx11CompiledShaderData: public K_CompiledShaderData {
        //<editor-fold desc="Properties">

    private:
        K_ShaderType m_shaderType;
        ID3DBlob* m_pShaderBlob;

        friend class K_Dx11ShaderController;

        //</editor-fold>

        //<editor-fold desc="Constructors and Destructors">

    public:
        explicit K_Dx11CompiledShaderData(K_ShaderType t_shaderType, ID3DBlob* t_pShaderBlob);
        ~K_Dx11CompiledShaderData();

        //</editor-fold>

        //<editor-fold desc="Getters">

    private:
        ID3DBlob* getShaderBlob() { return this->m_pShaderBlob; };
        K_ShaderType getShaderType() { return this->m_shaderType; };

        //</editor-fold>
    };
}

#endif //KOZMIC_DX11COMPILEDSHADERDATA_HPP
