#include <SDL3/SDL.h>
#include "Tetrion.h"
#include <iostream>

Tetrion::Tetrion() {}
Tetrion::~Tetrion() {}

void Tetrion::init(SDL_Renderer* _renderer, int _width, int _height) {
	renderer = _renderer;
	width = _width;
	height = _height;
	blockSize = height / 21;

	rect.x = 0;
	rect.w = blockSize;
	rect.h = blockSize;
}
	

void Tetrion::render() {
	SDL_SetRenderDrawColor(renderer, 169, 169, 169, 255);

	// Render tetrion's side walls
	for (int i = 0; i <= 20; i++) {
		rect.x = 0;
		rect.y = i * blockSize;
		SDL_RenderFillRect(renderer, &rect);

		rect.x = 11 * blockSize;
		SDL_RenderFillRect(renderer, &rect);
	}

	// Render tetrion's bottom wall
	for (int i = 1; i <= 10; i++) {
		rect.x = i * blockSize;
		SDL_RenderFillRect(renderer, &rect);
	}

	SDL_SetRenderDrawColor(renderer, 105, 105, 105, 255);
	// Render tetrion's (well) vertical lines
	int ySize = 21 * blockSize;
	for (int i = 0; i <= 12; i++) {
		int xPos = i * blockSize;
		SDL_RenderLine(renderer, xPos, 0, xPos, ySize);
	}

	// Render tetrion's horizontal lines
	int xSize = 12 * blockSize;
	for (int i = 0; i <= 21; i++) {
		int yPos = i * blockSize;
		SDL_RenderLine(renderer, 0, yPos, xSize, yPos);
	}
	
}

int Tetrion::getCenterX() {
	return blockSize * 5;
}

int Tetrion::getBlockSize() {
	return blockSize;
}