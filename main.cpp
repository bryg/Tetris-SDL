#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"
#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[]) {
	const int WIDTH = 640;
	const int HEIGHT = 480;

	game = new Game();

	game->init("Tetris-SDL", WIDTH, HEIGHT, false);

	SDL_Delay(3000);

	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();
	
	// Clean up
	SDL_Quit();
	return 0;
}