#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"
#include "Game.h"
#include "Tetrion.h"
Game* game = nullptr;

int main(int argc, char* argv[]) {
	const int WIDTH = 640;
	const int HEIGHT = 480;

	unsigned int currentTick = SDL_GetTicks();
	unsigned int lastTick = SDL_GetTicks();
	
	game = new Game();

	game->init("Tetris-SDL", WIDTH, HEIGHT, false);

	while (game->running()) {
		game->handleEvents();

		currentTick = SDL_GetTicks();
		if (currentTick - lastTick > 1000 / 60.0) {
			lastTick = currentTick;
			game->update();
			game->render();
		}

	}

	game->clean();
	
	// Clean up
	SDL_Quit();
	return 0;
}