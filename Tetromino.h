#pragma once
#include <SDL3/SDL.h>

class Tetromino {
public:
	Tetromino(int xPos, int _blockSize);
	~Tetromino();

	void init(SDL_Renderer* _renderer);
	void render();
	void update();
	void rotate();

private:
	SDL_Renderer* renderer;
	SDL_FRect rects[4];
	int y;
	int x;
	int blockSize;
	const double fallSpeed = 1;
	unsigned int lastTick;
};

