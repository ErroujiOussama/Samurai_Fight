#include <iostream>

#include "Hero.h"

Hero::Hero()
	: _x(0), _y(0), _w(200), _h(200), _velx(0), _vely(0)
{
	auto surface = IMG_Load("Assets/samurai_idle_1.png");
	_texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
	SDL_FreeSurface(surface);
}

Hero::Hero(int x, int y, int w, int h, const char * texture)
	: _x(x), _y(y), _w(w), _h(h), _velx(0), _vely(0)
{
	auto surface = IMG_Load(texture);

	if (!surface)
		std::cout << "Hero: Failed to create surface" << std::endl;
	else
		std::cout << "Hero: Surface created" << std::endl;
	
	_texture = SDL_CreateTextureFromSurface(Window::renderer, surface);

	if (!_texture)
		std::cout << "Hero: Failed to create texture" << std::endl;
	else
		std::cout << "Hero: Texture created" << std::endl;

	SDL_FreeSurface(surface);
}

Hero::~Hero()
{
	SDL_DestroyTexture(_texture);
}

void Hero::draw() const
{
	SDL_Rect hero = { _x, _y, _w, _h };
	SDL_RenderCopy(Window::renderer, _texture, nullptr, &hero);
}

void Hero::pollEvents(SDL_Event &event)
{
	const Uint8 * keyState = SDL_GetKeyboardState(NULL);

	if (keyState[SDL_SCANCODE_D])
		_velx = 7;
	else if (keyState[SDL_SCANCODE_A])
		_velx = -7;
	else
		_velx = 0;

	SDL_PumpEvents();
}

void Hero::move()
{
	_x += _velx;
	if (_x >= 800 - _w || _x <= 0)
		_x -= _velx;
}