//
// Created by Vitor Chaves on 12/07/2022.
//

#ifndef KOZMIC_SHADERCONTROLLER_HPP
#define KOZMIC_SHADERCONTROLLER_HPP

#include <kozmic/core/utils/Controller.hpp>
#include <utility>

namespace Kozmic::Core::Graphics {
    class K_ShaderInputLayout {

    };

    class K_ShaderInputLayoutElement {
        [[maybe_unused]] std::string m_sName;
        [[maybe_unused]] unsigned int m_nIndex;
        [[maybe_unused]] std::string m_sFormat;
        [[maybe_unused]] unsigned int m_nOffset;
    };

    class K_CompiledShaderData {
        //<editor-fold desc="Properties">

    protected:
        std::string m_sName;

        //</editor-fold>

        //<editor-fold desc="Constructors and Destructors">

    public:
        K_CompiledShaderData(std::string t_sName) {
            this->m_sName = std::move(t_sName);
        }

        //</editor-fold>

    public:
        std::string getShaderName() { return this->m_sName; };
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
        [[maybe_unused]] virtual std::shared_ptr<K_CompiledShaderData> compileShader(std::string t_sType, std::string t_sName, std::string t_sSourceFile, std::string t_sEntryPoint) = 0;
        [[maybe_unused]] virtual std::shared_ptr<K_Shader> addShader(std::shared_ptr<K_CompiledShaderData> t_shader) = 0;
        [[maybe_unused]] virtual void useShader(std::shared_ptr<K_CompiledShaderData> t_shader) = 0;

        [[maybe_unused]] virtual std::shared_ptr<K_ShaderInputLayout> createInputLayout(std::vector<std::shared_ptr<K_ShaderInputLayoutElement>> t_elements) = 0;
    };
}

#endif //KOZMIC_SHADERCONTROLLER_HPP
