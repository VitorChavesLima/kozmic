//
// Created by Vitor Chaves on 12/07/2022.
//

#ifndef KOZMIC_SHADERCONTROLLER_HPP
#define KOZMIC_SHADERCONTROLLER_HPP

#include <kozmic/core/utils/Controller.hpp>

namespace Kozmic::Core::Graphics {
    class K_ShaderInputLayout {

    };

    class K_ShaderInputLayoutElement {
        [[maybe_unused]] std::string m_sName;
        [[maybe_unused]] unsigned int m_nIndex;
        [[maybe_unused]] std::string m_sFormat;
        [[maybe_unused]] unsigned int m_nOffset;
    };

    class K_Shader {

    };

    class K_ShaderController : public Utils::K_Controller {

    //<editor-fold desc="Constructors and Destructors">

    public:
        explicit K_ShaderController(const std::string& t_loggerName) : Utils::K_Controller(t_loggerName + "_GRAPHICS_SHADER") {
            this->m_logger->info("Constructing Shader Controller");
        }

        virtual ~K_ShaderController() {
            this->m_logger->info("Cleaning Shader Controller");
        }

    //</editor-fold>

    public:
        [[maybe_unused]] virtual std::shared_ptr<K_Shader> compileShader(std::string t_sSourceFile, std::string t_sEntryPoint, std::string t_sVersion) = 0;

        [[maybe_unused]] virtual std::shared_ptr<K_ShaderInputLayout> createInputLayout(std::vector<std::shared_ptr<K_ShaderInputLayoutElement>> t_elements) = 0;
    };
}

#endif //KOZMIC_SHADERCONTROLLER_HPP
