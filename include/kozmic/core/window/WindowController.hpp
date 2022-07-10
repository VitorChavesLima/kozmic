//
// Created by Vitor Chaves on 06/07/2022.
//

#ifndef KOZMIC_WINDOWCONTROLLER_HPP
#define KOZMIC_WINDOWCONTROLLER_HPP

#include <memory>
#include <string>

#include "kozmic/core/logging/Logger.hpp"

#include "kozmic/core/utils/Exception.hpp"

#include "kozmic/core/input/Keyboard.hpp"
#include "kozmic/core/input/Mouse.hpp"
#include "kozmic/core/graphics/GraphicsController.hpp"

namespace Kozmic::Core::Window {
    struct K_WindowSize {
        int width;
        int height;
    };

    struct K_WindowPosition
    {
        int xPos;
        int yPos;
    };

    enum K_WindowMode {
        WINDOWED [[maybe_unused]],
        BORDERLESS_FULLSCREEN [[maybe_unused]],
        EXCLUSIVE_FULLSCREEN [[maybe_unused]]
    };

    class K_WindowController : public Utils::K_Controller {
        //<editor-fold desc="Properties">

    protected:
        std::string m_sTitle;
        K_WindowSize m_size = {800, 600};
        K_WindowPosition m_position = {0, 0};
        K_WindowMode m_mode;
        bool m_bFocused;
        bool m_bOpen;
        std::string m_sGraphicsControllerType;

        //</editor-fold>

        //<editor-fold desc="Constructors and Destructors">

    public:
        K_WindowController(std::string t_sTitle, const std::string& t_sLoggerName);
        virtual ~K_WindowController() = default;

        //</editor-fold>

        //<editor-fold desc="Available throughout the life cycle">

    public:
        [[maybe_unused]] virtual std::shared_ptr<Input::K_Keyboard> getKeyboardInput() = 0;
        [[maybe_unused]] virtual std::shared_ptr<Input::K_Mouse> getMouseInput() = 0;
        [[maybe_unused]] virtual std::unique_ptr<Graphics::K_GraphicsController> getGraphicsController() = 0;

        [[maybe_unused]] virtual void show() = 0;
        [[maybe_unused]] virtual void hide() = 0;
        [[maybe_unused]] virtual void close() = 0;

        [[maybe_unused]] virtual bool isOpen() = 0;
        [[maybe_unused]] virtual bool isFocused() = 0;
        [[maybe_unused]] virtual void update() = 0;

        //</editor-fold>

        //<editor-fold desc="Setters">

    public:
        [[maybe_unused]] virtual void setTitle(std::string t_sTitle) = 0;
        [[maybe_unused]] virtual void setSize(K_WindowSize t_size) = 0;
        [[maybe_unused]] virtual void setPosition(K_WindowPosition t_position) = 0;
        [[maybe_unused]] virtual void setMode(K_WindowMode t_mode) = 0;

        //</editor-fold>

        //<editor-fold desc="Getters">

    public:
        [[maybe_unused]] std::string getTitle();
        [[maybe_unused]] K_WindowSize getSize();
        [[maybe_unused]] K_WindowPosition getPosition();
        [[maybe_unused]] K_WindowMode getMode();

        //</editor-fold>
    };
}

#endif // KOZMIC_WINDOWCONTROLLER_HPP
