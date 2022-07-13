//
// Created by Vitor Chaves on 12/07/2022.
//

#define EXCEPT(message) throw Utils::K_Exception(__FILE__, __LINE__, __FUNCTION__, message)

#include "DX11ShaderController.hpp"
#include "DX11CompiledShaderData.hpp"
#include "DX11Shader.hpp"

using namespace Kozmic::Core::Graphics;

//<editor-fold desc="Internal methods">

ID3D11PixelShader* K_Dx11ShaderController::createPixelShader(ID3DBlob *t_shaderBlob) {
    HRESULT result;
    ID3D11PixelShader* pixelShader;

    result = this->m_device->CreatePixelShader(t_shaderBlob->GetBufferPointer(), t_shaderBlob->GetBufferSize(), nullptr, &pixelShader);
    if(FAILED(result)) this->m_logger->error("Could not create pixel shader");

    return pixelShader;
}

ID3D11VertexShader* K_Dx11ShaderController::createVertexShader(ID3DBlob *t_shaderBlob) {
    HRESULT result;
    ID3D11VertexShader* vertexShader;

    result = this->m_device->CreateVertexShader(t_shaderBlob->GetBufferPointer(), t_shaderBlob->GetBufferSize(), nullptr, &vertexShader);
    if(FAILED(result)) this->m_logger->error("Could not create vertex shader");

    return vertexShader;
}

ID3D11PixelShader *K_Dx11ShaderController::covertToPixelShader(ID3D11DeviceChild *t_shader) {
    ID3D11PixelShader* pixelShader;
    HRESULT result = t_shader->QueryInterface(&pixelShader);
    if (FAILED(result)) EXCEPT("Could not convert to pixel shader");
    return pixelShader;
}

ID3D11VertexShader *K_Dx11ShaderController::convertToVertexShader(ID3D11DeviceChild *t_shader) {
    ID3D11VertexShader* vertexShader;
    HRESULT result = t_shader->QueryInterface(&vertexShader);
    if (FAILED(result)) EXCEPT("Could not convert to vertex shader");
    return vertexShader;
}

DXGI_FORMAT K_Dx11ShaderController::convertInputLayoutElement(const std::string& t_sFormat) {
    DXGI_FORMAT convertedFormat;

    if(t_sFormat == "R32G32B32_FLOAT") convertedFormat = DXGI_FORMAT_R32G32B32_FLOAT;
    else if (t_sFormat == "R32G32B32A32_FLOAT") convertedFormat = DXGI_FORMAT_R32G32B32A32_FLOAT;
    else EXCEPT("Invalid input layout element format");

    return convertedFormat;
}


const D3D11_INPUT_ELEMENT_DESC* K_Dx11ShaderController::formatInputElements(const std::vector<std::shared_ptr<K_ShaderInputLayoutElement>>& t_elements) {

    std::vector<D3D11_INPUT_ELEMENT_DESC> inputLayoutElementDescriptionVector;

    for(const auto & element : t_elements) {
        D3D11_INPUT_ELEMENT_DESC inputLayoutElementDescription;
        inputLayoutElementDescription.SemanticName = element->getName().c_str();
        inputLayoutElementDescription.SemanticIndex = element->getIndex();
        inputLayoutElementDescription.Format = convertInputLayoutElement(element->getFormat());
        inputLayoutElementDescription.InputSlot = 0;
        inputLayoutElementDescription.AlignedByteOffset = element->getOffset();
        inputLayoutElementDescription.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
        inputLayoutElementDescription.InstanceDataStepRate = 0;

        inputLayoutElementDescriptionVector.push_back(inputLayoutElementDescription);
    }

    D3D11_INPUT_ELEMENT_DESC* inputLayoutElementDescriptionArray = &inputLayoutElementDescriptionVector[0];
    return inputLayoutElementDescriptionArray;
}

//</editor-fold>

//<editor-fold desc="Constructors and Destructors">

K_Dx11ShaderController::K_Dx11ShaderController(const std::string &t_loggerName, ID3D11Device* t_device, ID3D11DeviceContext* t_context) : K_ShaderController(t_loggerName + "_DX11") {
    this->m_device = t_device;
    this->m_context = t_context;
}

K_Dx11ShaderController::~K_Dx11ShaderController() = default;

//</editor-fold>

std::shared_ptr<K_CompiledShaderData> K_Dx11ShaderController::compileShader(std::string t_sType, std::string t_sName, std::string t_sSourceFile, std::string t_sEntryPoint) {
    this->m_logger->info("Compiling shader located at: {}", t_sSourceFile.c_str());

    HRESULT result;

    DWORD shaderFlags = 0;
#if defined(DEBUG) || defined(_DEBUG)
    shaderFlags |= D3D10_SHADER_DEBUG;
    shaderFlags |= D3D10_SHADER_SKIP_OPTIMIZATION;
#endif

    ID3DBlob * pShader;
    ID3DBlob * pCompilationErrors;

    std::string sProfile;
    K_ShaderType shaderType;

    if(t_sType == "VERTEX_SHADER") { sProfile = "vs_4_0"; shaderType = K_ShaderType::VERTEX_SHADER; }
    else if(t_sType == "PIXEL_SHADER") { sProfile = "ps_4_0"; shaderType = K_ShaderType::PIXEL_SHADER; }
    else EXCEPT("Invalid shader type");

    std::wstring wSourceFile(t_sSourceFile.begin(), t_sSourceFile.end());
    result = D3DCompileFromFile(wSourceFile.c_str(), nullptr, nullptr, t_sEntryPoint.c_str(), sProfile.c_str(), shaderFlags, 0, &pShader, &pCompilationErrors);

    if(FAILED(result) || pCompilationErrors != nullptr) EXCEPT((char*) pCompilationErrors->GetBufferPointer());
    if(pCompilationErrors != nullptr) pCompilationErrors->Release();

    return std::make_shared<K_Dx11CompiledShaderData>(shaderType, t_sName, pShader);
}

std::shared_ptr<K_Shader> K_Dx11ShaderController::addShader(std::shared_ptr<K_CompiledShaderData> t_compiledShaderData) {
    this->m_logger->info("Adding shader: {}", t_compiledShaderData->getShaderName());

    auto compiledShaderData = std::reinterpret_pointer_cast<K_Dx11CompiledShaderData>(t_compiledShaderData);
    auto shaderType = compiledShaderData->getShaderType();

    ID3D11DeviceChild* shader = nullptr;
    if(shaderType == K_ShaderType::PIXEL_SHADER) shader = createPixelShader(compiledShaderData->getShaderBlob());
    else if(shaderType == K_ShaderType::VERTEX_SHADER) shader = createVertexShader(compiledShaderData->getShaderBlob());

    return std::make_shared<K_Dx11Shader>(shaderType, shader);
}

void K_Dx11ShaderController::useShader(std::shared_ptr<K_Shader> t_shader) {
    auto shader = std::reinterpret_pointer_cast<K_Dx11Shader>(t_shader);
    auto shaderType = shader->getShaderType();

    if(shaderType == K_ShaderType::PIXEL_SHADER) this->m_context->PSSetShader(this->covertToPixelShader(shader->getShader()), nullptr, 0);
    else if(shaderType == K_ShaderType::VERTEX_SHADER) this->m_context->VSSetShader(this->convertToVertexShader(shader->getShader()), nullptr, 0);
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