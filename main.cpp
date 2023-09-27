#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main(int argc, char* argv[]) {
	const int WIDTH = 640;
	const int HEIGHT = 480;

	SDL_Window* window;			// Declare a pointer

	// Initialize video and audio subsystems
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return 1;
	}

	// Create an application window
	window = SDL_CreateWindow(
		"Tetris-SDL",			// Window title
		WIDTH,					// width, in pixels
		HEIGHT,					// height, in pixels
		SDL_WINDOW_OPENGL		// flags
	);

	// Check that the window was successfully created.
	if (window == nullptr) {
		SDL_Log("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	// Window open. Enter program loop. (SDL_PollEvent())
	SDL_Delay(3000);

	// Close and destroy the window
	SDL_DestroyWindow(window);

	// Clean up
	SDL_Quit();
	return 0;
}