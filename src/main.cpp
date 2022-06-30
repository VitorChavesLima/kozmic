#include "Game.hpp"

using namespace Game;

int main() {
	std::unique_ptr<K_Game> game = std::make_unique<K_Game>();
	game.reset();
}