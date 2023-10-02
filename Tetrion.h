#pragma once
class Tetrion {
public:
	Tetrion();
	~Tetrion();

	void init(SDL_Renderer* _renderer, int _width, int _height);
	void render();

private:
	SDL_Renderer* renderer;
	int width;
	int height;
	int blockSize;
	SDL_FRect rect;
};

