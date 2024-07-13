#include "Samurai.h"

Samurai::Samurai(int x, int y, const char * texture)
	: _sPosX(x), _sPosY(y), _running(false), _attack(false), _eventID(0)
{
	auto surface = IMG_Load(texture);
	_sTexture = SDL_CreateTextureFromSurface(Window::renderer, surface);
	SDL_FreeSurface(surface);
}

Samurai::~Samurai()
{
	SDL_DestroyTexture(_sTexture);
}

void Samurai::pollEvents(SDL_Event &event)
{
	const Uint8 * keyState = SDL_GetKeyboardState(NULL);

	if (keyState[SDL_SCANCODE_RIGHT]) {
		_eventID = 1;
		_velx = 7;
		_flip = SDL_FLIP_NONE;
	}
	else if (keyState[SDL_SCANCODE_LEFT]) {
		_eventID = 2;
		_velx = -7;
		_flip = SDL_FLIP_HORIZONTAL;
	}
	else if (keyState[SDL_SCANCODE_R]) {
		_eventID = 3;
		_velx = 0;
		_attack = true;
	}
	else {
		_eventID = 0;
		_velx = 0;
		_attack = false;
	}

	SDL_PumpEvents();
}

void Samurai::draw(int x)
{
	_running = false;
	int y = 0;

	if (_velx != 0)
		y = 195 + 1; //200
	else if (_attack)
		y = 400 + 8;

	SDL_Rect srcrect { x, y, 200, 200 };
	SDL_Rect dstrect { _sPosX, _sPosY + 13, 600, 600 };
	SDL_RenderCopyEx(Window::renderer, _sTexture, &srcrect, &dstrect, NULL, nullptr, _flip);
}

void Samurai::move(Window &window)
{
	_sPosX += _velx;
	if (_sPosX >= window.getWidth() - 400 || _sPosX <= 0 - 200)
		_sPosX -= _velx;
}