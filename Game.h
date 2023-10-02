#pragma once

#include "SDL3/SDL.h"
#include "Tetrion.h"

class Game {
public:
	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running();

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Tetrion* tetrion;
};

