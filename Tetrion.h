#pragma once
class Tetrion {
public:
	Tetrion();
	~Tetrion();

	void init(SDL_Renderer* _renderer, int _width, int _height);
	void render();
	int getCenterX();
	int getBlockSize();

private:
	SDL_Renderer* renderer;
	int width;
	int height;
	int blockSize;
	SDL_FRect rect;
};

