//
// Created by Vitor Chaves on 12/07/2022.
//

#ifndef KOZMIC_SHADERCONTROLLER_H
#define KOZMIC_SHADERCONTROLLER_H

#include <kozmic/core/utils/Controller.hpp>

namespace Kozmic::Core::Graphics {
    class K_ShaderInputLayout {

    };

    class K_ShaderInputLayoutElement {
        std::string t_sName;
        unsigned int t_nIndex;
        std::string t_sFormat;
        unsigned int t_nOffset;
    };

    class K_ShaderController : public Utils::K_Controller {
    public:
        virtual std::shared_ptr<K_ShaderInputLayout> createShaderInputLayout(std::vector<std::shared_ptr<K_ShaderInputLayoutElement>> t_elements) = 0;
    };
}

#endif //KOZMIC_SHADERCONTROLLER_H
