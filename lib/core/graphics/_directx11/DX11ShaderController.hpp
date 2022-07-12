//
// Created by Vitor Chaves on 12/07/2022.
//

#ifndef KOZMIC_DX11SHADERCONTROLLER_HPP
#define KOZMIC_DX11SHADERCONTROLLER_HPP

#include <d3d11.h>
#include <d3dcompiler.h>

#include <kozmic/core/utils/Exception.hpp>
#include <kozmic/core/graphics/ShaderController.hpp>

namespace Kozmic::Core::Graphics {
    class K_Dx11ShaderController : public K_ShaderController {
        //<editor-fold desc="Properties">

        ID3D11Device* m_device;

        //</editor-fold>

        //<editor-fold desc="Internal methods">

        const D3D11_INPUT_ELEMENT_DESC* formatInputElements(const std::vector<std::shared_ptr<K_ShaderInputLayoutElement>>& t_elements);

        //</editor-fold>

        //<editor-fold desc="Constructors and Destructors">

    public:
        explicit K_Dx11ShaderController(const std::string& t_loggerName, ID3D11Device* t_device);
        ~K_Dx11ShaderController() override;

        //</editor-fold>

    public:
        std::shared_ptr<K_Shader> compileShader(std::string t_sSourceFile, std::string t_sEntryPoint, std::string t_sVersion) override;
        std::shared_ptr<K_ShaderInputLayout> createInputLayout(std::vector<std::shared_ptr<K_ShaderInputLayoutElement>> t_elements) override;
    };
}

#endif //KOZMIC_DX11SHADERCONTROLLER_HPP
