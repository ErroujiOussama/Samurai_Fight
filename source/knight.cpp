#include "Knight.h"

Knight::Knight(int x, int y, const char * texture)
	: _kPosX(x), _kPosY(y), _running(false), _attack(false), _eventID(0)
{
	auto surface = IMG_Load(texture);
	_kTexture = SDL_CreateTextureFromSurface(Window::renderer, surface);
	SDL_FreeSurface(surface);
}

Knight::~Knight()
{
	SDL_DestroyTexture(_kTexture);
}

void Knight::pollEvents(SDL_Event &event)
{
	const Uint8 * keyState = SDL_GetKeyboardState(NULL);

	if (keyState[SDL_SCANCODE_D]) {
		_eventID = 1;
		_velx = 7;
		_flip = SDL_FLIP_NONE;
	}
	else if (keyState[SDL_SCANCODE_A]) {
		_eventID = 2;
		_velx = -7;
		_flip = SDL_FLIP_HORIZONTAL;
	}
	else if (keyState[SDL_SCANCODE_SPACE]) {
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


void Knight::draw(int x)
{
	_running = false;
	int y = 45; //90 - 30 - 15

	if (_velx != 0) {
		y = 145; //160 - 15
		_running = true;
	} 
	else if (_attack) {
		y = 230 + 1; //245
	}

	SDL_Rect srcrect { x, y, 70, 70 };
	SDL_Rect dstrect { _kPosX, _kPosY, 200, 200 };
	SDL_RenderCopyEx(Window::renderer, _kTexture, &srcrect, &dstrect, NULL, nullptr, _flip);
}

void Knight::move(Window &window)
{
	_kPosX += _velx;
	if (_kPosX >= window.getWidth() - _w || _kPosX <= 0)
		_kPosX -= _velx;
}