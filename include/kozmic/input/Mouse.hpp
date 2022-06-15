#pragma once

namespace Kozmic::Core::Input {
	struct K_MouseScreenPosition {
		unsigned int xPos;
		unsigned int yPos;
	};

	class K_Mouse {
	private:
		K_MouseScreenPosition m_mousePosition;
	};
}