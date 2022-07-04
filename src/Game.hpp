#include <kozmic/Application.hpp>
#include <kozmic/utils/Exception.hpp>

namespace Game {
	class K_Game : public Kozmic::Core::K_Application, public Kozmic::Core::Input::K_KeyboardListener {
	private:
		std::unique_ptr<Kozmic::Core::Logging::K_Logger> m_logger;
		std::unique_ptr<Kozmic::Core::Window::KWindow> m_window;
		std::shared_ptr<Kozmic::Core::Graphics::K_GraphicsController> m_graphics;

	public:
		K_Game();
		~K_Game();

		void handleKeyboardKeyDown(std::string t_sKeyId);
	};
}