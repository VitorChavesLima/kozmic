//
// Created by Vitor Chaves on 12/07/2022.
//

#include "DX11ShaderController.hpp"

using namespace Kozmic::Core::Graphics;

//<editor-fold desc="Constructors and Destructors">

K_Dx11ShaderController::K_Dx11ShaderController(const std::string &t_loggerName, ID3D11Device* t_device) : K_ShaderController(t_loggerName) {
    this->m_device = t_device;
}

//</editor-fold>

std::shared_ptr<K_ShaderInputLayout>
K_Dx11ShaderController::createInputLayout(std::vector<std::shared_ptr<K_ShaderInputLayoutElement>> t_elements) {
    return nullptr;
}