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

        //<editor-fold desc="Properties">

    private:
        std::string m_sName;
        unsigned int m_nIndex;
        std::string m_sFormat;
        unsigned int m_nOffset;

        //</editor-fold>

        //<editor-fold desc="Constructors and Destructors">

    public:
        K_ShaderInputLayoutElement(std::string t_sName, unsigned int t_nIndex, std::string t_sFormat, unsigned int t_nOffset) {
            this->m_sName = std::move(t_sName);
            this->m_nIndex = t_nIndex;
            this->m_sFormat = std::move(t_sFormat);
            this->m_nOffset = t_nOffset;
        }

        //</editor-fold>

        //<editor-fold desc="Getters">

    public:
        const char* getName() { return this->m_sName.c_str(); }
        [[nodiscard]] unsigned int getIndex() const { return this->m_nIndex; }
        std::string getFormat() { return this->m_sFormat; }
        [[nodiscard]] unsigned int getOffset() const { return this->m_nOffset; }

        //</editor-fold>

    };

    class K_CompiledShaderData {
        //<editor-fold desc="Properties">

    protected:
        std::string m_sName;

        //</editor-fold>

        //<editor-fold desc="Constructors and Destructors">

    public:
        explicit K_CompiledShaderData(std::string t_sName) {
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
        [[maybe_unused]] virtual std::shared_ptr<K_Shader> addShader(std::shared_ptr<K_CompiledShaderData> t_compiledShaderData) = 0;
        [[maybe_unused]] virtual void useShader(std::shared_ptr<K_Shader> t_shader) = 0;

        [[maybe_unused]] virtual std::shared_ptr<K_ShaderInputLayout> createInputLayout(std::vector<std::shared_ptr<K_ShaderInputLayoutElement>> t_elements, std::shared_ptr<K_CompiledShaderData> t_compiledShaderData) = 0;
    };
}

#endif //KOZMIC_SHADERCONTROLLER_HPP
