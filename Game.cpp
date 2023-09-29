#include <SDL3/SDL.h>
#include "Game.h"
Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int width, int height, bool fullscreen) {
	Uint32 flags = 0;

	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		window = SDL_CreateWindow(title, width, height, flags);

		renderer = SDL_CreateRenderer(window, NULL, 0);

		isRunning = true;
	}
	else {
		isRunning = false;
	}
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_EVENT_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::update() {}

void Game::render() {
	SDL_RenderClear(renderer);
	// Render here
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	SDL_Log("Game cleaned.");
}

bool Game::running() {
	return isRunning;
}