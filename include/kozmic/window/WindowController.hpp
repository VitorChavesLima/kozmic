#pragma once

#include <memory>
#include <string>

#include <kozmic/logging/Logger.hpp>

#include <kozmic/input/Keyboard.hpp>
#include <kozmic/input/Mouse.hpp>
#include <kozmic/graphics/GraphicsController.hpp>

namespace Kozmic { namespace Core { namespace Window {
	struct K_WindowSize {
		unsigned int width;
		unsigned int height;
	};

	struct K_WindowPosition
	{
		unsigned int xPos;
		unsigned int yPos;
	};

	enum K_WindowMode {
		WINDOWED [[maybe_unused]],
		BORDERLESS_FULLSCREEN [[maybe_unused]],
		EXCLUSIVE_FULLSCREEN [[maybe_unused]]
	};

	class K_WindowController : public Utils::K_Controller {
	protected:
		std::string m_sTitle;
		K_WindowSize m_size;
		K_WindowPosition m_position;
		K_WindowMode m_mode;
		bool m_bFocused;
		std::string m_sGraphicsControllerType;

        //<editor-fold desc="Constructors and Destructors">

    public:
		K_WindowController(std::string t_sTitle, std::string t_sLoggerName);
		virtual ~K_WindowController() = default;

        //</editor-fold>

        //<editor-fold desc="Controller Specific">

    public:
		void initialize() override = 0;
		void shutdown() override = 0;

        //</editor-fold>

        //<editor-fold desc="Available throughout the life cycle">

    public:
        [[maybe_unused]] virtual std::shared_ptr<Input::K_Keyboard> getKeyboardInput() = 0;
        [[maybe_unused]] virtual std::shared_ptr<Input::K_Mouse> getMouseInput() = 0;
        [[maybe_unused]] virtual std::shared_ptr<Graphics::K_GraphicsController> getGraphicsController() = 0;

        //</editor-fold>

        //<editor-fold desc="Available after initialization and before shutdown">

    public:
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

} } }