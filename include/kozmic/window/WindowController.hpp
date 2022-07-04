#pragma once

#include <memory>
#include <string>

#include <kozmic/logging/Logger.hpp>
#include <kozmic/input/Keyboard.hpp>
#include <kozmic/input/Mouse.hpp>
#include <kozmic/graphics/GraphicsController.hpp>

namespace Kozmic::Core::Window {
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
		WINDOWED,
		BORDERLESS_FULLSCREEN,
		EXCLUSIVE_FULLSCREEN
	};

	class K_WindowController {
	protected:
		std::string m_sTitle;
		K_WindowSize m_size;
		K_WindowPosition m_position;
		K_WindowMode m_mode;
		bool m_bFocused;
		std::string m_sGraphicsControllerType;

	public:
		K_WindowController(std::string t_sTitle, K_WindowSize t_size, K_WindowPosition t_position, K_WindowMode t_mode, std::string t_sGraphicsControllerType);
		virtual ~K_WindowController() = default;

		virtual void show() = 0;
		virtual void hide() = 0;
		virtual void close() = 0;

		virtual bool isOpen() = 0;
		virtual bool isFocused() = 0;
		virtual void update() = 0;

		virtual std::shared_ptr<Input::K_Keyboard> getKeyboardInput() = 0;
		virtual std::shared_ptr<Input::K_Mouse> getMouseInput() = 0;
		virtual std::shared_ptr<Graphics::K_GraphicsController> getGraphicsController() = 0;

	public:
		virtual void setTitle(std::string t_sTitle) = 0;
		virtual void setSize(K_WindowSize t_size) = 0;
		virtual void setPosition(K_WindowPosition t_position) = 0;
		virtual void setMode(K_WindowMode t_mode) = 0;

	public:
		std::string getTitle();
		K_WindowSize getSize();
		K_WindowPosition getPosition();
		K_WindowMode getMode();
	};
}