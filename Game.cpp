#include "Game.h"

Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int width, int height, bool fullscreen) {
	Uint32 flags = 0;

	if (fullscreen)
		flags = SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN;
	else
		flags = SDL_WINDOW_OPENGL;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		window = SDL_CreateWindow(title, width, height, flags);

		// Create OpenGL context
		glcontext = SDL_GL_CreateContext(window);

		// OpenGL functions
		// glClearColor(0, 0, 0, 1);
		// glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(window);

		renderer = SDL_CreateRenderer(window, NULL, 0);

		//SDL_GL_DeleteContext(glcontext);

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