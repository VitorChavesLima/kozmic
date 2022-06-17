#include <kozmic/Application.hpp>

namespace Game {
	class K_Game : public Kozmic::Core::K_Application {
	private:
		std::unique_ptr<Kozmic::Core::Logging::K_Logger> m_logger;
		std::unique_ptr<Kozmic::Core::Window::KWindow> m_window;

	public:
		K_Game();
	};
}