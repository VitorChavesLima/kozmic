//
// Created by Vitor Chaves on 12/07/2022.
//

#define EXCEPT(message) throw Utils::K_Exception(__FILE__, __LINE__, __FUNCTION__, message)

#include "DX11ShaderController.hpp"
#include "DX11Shader.hpp"

using namespace Kozmic::Core::Graphics;

//<editor-fold desc="Internal methods">

const D3D11_INPUT_ELEMENT_DESC* K_Dx11ShaderController::formatInputElements(const std::vector<std::shared_ptr<K_ShaderInputLayoutElement>>& t_elements) {
    return nullptr;
}


//</editor-fold>

//<editor-fold desc="Constructors and Destructors">

K_Dx11ShaderController::K_Dx11ShaderController(const std::string &t_loggerName, ID3D11Device* t_device) : K_ShaderController(t_loggerName + "_DX11") {
    this->m_device = t_device;
}

K_Dx11ShaderController::~K_Dx11ShaderController() = default;

//</editor-fold>

std::shared_ptr<K_Shader> K_Dx11ShaderController::compileShader(std::string t_sSourceFile, std::string t_sEntryPoint, std::string t_sVersion) {
    this->m_logger->info("Compiling shader located at: {}", t_sSourceFile.c_str());

    HRESULT result;

    DWORD shaderFlags = 0;
#if defined(DEBUG) || defined(_DEBUG)
    shaderFlags |= D3D10_SHADER_DEBUG;
    shaderFlags |= D3D10_SHADER_SKIP_OPTIMIZATION;
#endif

    ID3DBlob * pShader;
    ID3DBlob * pCompilationErrors;

    std::wstring wSourceFile(t_sSourceFile.begin(), t_sSourceFile.end());
    result = D3DCompileFromFile(wSourceFile.c_str(), nullptr, nullptr, t_sEntryPoint.c_str(), t_sVersion.c_str(), shaderFlags, 0, &pShader, &pCompilationErrors);

    if(FAILED(result) || pCompilationErrors != nullptr) EXCEPT((char*) pCompilationErrors->GetBufferPointer());

    pCompilationErrors->Release();

    return std::make_shared<K_Dx11Shader>(pShader);
}

std::shared_ptr<K_ShaderInputLayout>
K_Dx11ShaderController::createInputLayout(std::vector<std::shared_ptr<K_ShaderInputLayoutElement>> t_elements) {
    auto elements = formatInputElements(t_elements);

    /*this->m_device->CreateInputLayout(
    elements,
    sizeof(elements),

            );*/

    return nullptr;
}