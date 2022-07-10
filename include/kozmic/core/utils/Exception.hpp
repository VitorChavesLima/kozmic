//
// Created by vitor on 07/07/2022.
//

#ifndef KOZMIC_EXCEPTION_HPP
#define KOZMIC_EXCEPTION_HPP

#include <exception>
#include <string>

namespace Kozmic::Core::Utils {
    class K_Exception : public std::exception {
    private:
        std::string m_sFile;
        int m_nLine;
        std::string m_sFunction;

        std::string m_sType;
        std::string m_sMessage;

        mutable std::string m_sWhatBuffer;

    public:
        K_Exception(std::string t_sFile, int t_nLine, std::string t_sFunction, std::string t_sMessage);

        [[maybe_unused]] const char* what() const noexcept override;
        [[maybe_unused]] std::string getType();
    };
}

#endif //KOZMIC_EXCEPTION_HPP
