#include "Tetromino.h"
#include <SDL3/SDL.h>

Tetromino::Tetromino(int xPos, int _blockSize) {
	x = xPos;
	y = 0;
	blockSize = _blockSize;

}

Tetromino::~Tetromino() {}

void Tetromino::setVelocity(int amount) {
	xVelocity += amount;
}
void Tetromino::init(SDL_Renderer* _renderer) {
	renderer = _renderer;
	for (int i = 0; i < 4; i++) {
		rects[i].w = blockSize;
		rects[i].h = blockSize;
	}


	rects[0].x = x;
	rects[0].y = y;
	
	rects[1].x = x - blockSize;
	rects[1].y = y;
	
	rects[2].x = x + blockSize;
	rects[2].y = y;
	
	rects[3].x = x + blockSize * 2;
	rects[3].y = y;

	xVelocity = 0;
	
	lastTick = SDL_GetTicks();
}

void Tetromino::update() {
	if (SDL_GetTicks() - lastTick > 1000 * fallSpeed) {
		lastTick = SDL_GetTicks();
		for (int i = 0; i < 4; i++) {
			rects[i].y += blockSize;
			rects[i].x += xVelocity * blockSize;
		}

	}

}

void Tetromino::render() {
	SDL_SetRenderDrawColor(renderer, 49, 199, 239, 255);
	SDL_RenderFillRects(renderer, rects, 4);
}