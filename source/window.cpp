#include <iostream>

#include "Window.h"

SDL_Renderer * Window::renderer = nullptr;

Window::Window(const char * title, int width, int height)
	: _title(title), _width(width), _height(height), _running(init()) {}

Window::~Window()
{
	SDL_DestroyTexture(_wTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit;
}

bool Window::init()
{   

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialised" << std::endl;
	}
	else {
		std::cout << "Subsystems Failure: " << SDL_GetError() << std::endl;
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG) == IMG_INIT_PNG) {
		std::cout << "SDL Image Initialised" << std::endl;
	}
	else {
		std::cout << "SDL Image Failure: " << SDL_GetError() << std::endl;
		return false;
	}

	_window = SDL_CreateWindow(
		_title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_width,
		_height,
		SDL_WINDOW_FULLSCREEN
	);

	if (_window == nullptr) {
		std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
		return false;
	}
	else {
		std::cout << "Window created" << std::endl;
	}
	
	renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr) {
		std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
		return false;
	}
	else {
		std::cout << "Renderer created" << std::endl;
	}

	return true;
}

void Window::clear() const
{
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 200, 255, 255);
	SDL_RenderClear(renderer);
}

void Window::pollEvents(SDL_Event &event)
{
	switch (event.type) {
	case SDL_QUIT:
		_running = false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE: _running = false; break;
		case SDLK_p: _currWindow = CurrWindow::mainMenu; break;
		default:
			break;
		}
	default:
		break;
	}
}

void Window::draw() const
{
	SDL_Rect srcrect { 0, 0, 1900, 1200 };
	SDL_Rect dstrect { 0, 0, _width, _height };
	SDL_RenderCopy(renderer, _wTexture, &srcrect, &dstrect);
}
