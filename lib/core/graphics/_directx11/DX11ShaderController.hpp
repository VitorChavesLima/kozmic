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
        ID3D11DeviceContext* m_context;

        //</editor-fold>

        //<editor-fold desc="Internal methods">

        ID3D11PixelShader* createPixelShader(ID3DBlob* t_shaderBlob);
        ID3D11VertexShader* createVertexShader(ID3DBlob* t_shaderBlob);

        static ID3D11PixelShader* covertToPixelShader(ID3D11DeviceChild* t_shader);
        static ID3D11VertexShader* convertToVertexShader(ID3D11DeviceChild* t_shader);

        static DXGI_FORMAT convertInputLayoutElement(const std::string& t_sFormat);
        static const D3D11_INPUT_ELEMENT_DESC* formatInputElements(const std::vector<std::shared_ptr<K_ShaderInputLayoutElement>>& t_elements);

        //</editor-fold>

        //<editor-fold desc="Constructors and Destructors">

    public:
        explicit K_Dx11ShaderController(const std::string& t_loggerName, ID3D11Device* t_device, ID3D11DeviceContext* t_context);
        ~K_Dx11ShaderController() override;

        //</editor-fold>

    public:
        std::shared_ptr<K_CompiledShaderData> compileShader(std::string t_sType, std::string t_sName, std::string t_sSourceFile, std::string t_sEntryPoint) override;
        std::shared_ptr<K_Shader> addShader(std::shared_ptr<K_CompiledShaderData> t_compiledShaderData) override;
        void useShader(std::shared_ptr<K_Shader> t_shader) override;

        std::shared_ptr<K_ShaderInputLayout> createInputLayout(std::vector<std::shared_ptr<K_ShaderInputLayoutElement>> t_elements, std::shared_ptr<K_CompiledShaderData> t_compiledShaderData ) override;
    };
}

#endif //KOZMIC_DX11SHADERCONTROLLER_HPP
