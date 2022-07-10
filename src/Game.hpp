#include <kozmic/Application.hpp>
#include <kozmic/utils/Exception.hpp>

namespace Game {
	class K_Game : public Kozmic::Core::K_Application {
	private:
		std::unique_ptr<Kozmic::Core::Logging::K_Logger> m_logger;
		std::unique_ptr<Kozmic::Core::Window::K_WindowController> m_window;
		std::shared_ptr<Kozmic::Core::Graphics::K_GraphicsController> m_graphics;

        std::unique_ptr<Kozmic::Core::Timing::K_ApplicationTimer> m_applicationTimer;

        int m_nFramesPerSeconds;

    private:
        void updateWindowTitle();

	public:
		K_Game();
		~K_Game();
	};
}