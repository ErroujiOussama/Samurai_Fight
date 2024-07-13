#include <iostream>

#include "Button.h"

Button::Button()
	: _xPos(0), _yPos(0), _overButton(false)
{
	auto surface = IMG_Load("Assets/ButtonStart.png");
	_bTexture = SDL_CreateTextureFromSurface(Window::renderer, surface);
	SDL_FreeSurface(surface);
}

Button::Button(int xPos, int yPos, const char * texture)
	: _xPos(xPos), _yPos(yPos), _overButton(false)
{
	auto surface = IMG_Load(texture);
	_bTexture = SDL_CreateTextureFromSurface(Window::renderer, surface);
	SDL_FreeSurface(surface);
}

Button::~Button()
{
	SDL_DestroyTexture(_bTexture);
}

bool Button::pollEvents(SDL_Event &event)
{
	switch (event.type) {
	case SDL_MOUSEMOTION:
		if (event.motion.x >= _xPos && event.motion.x <= _xPos + 256
			&& event.motion.y >= _yPos + 46 && event.motion.y <= _yPos + 226)
			_overButton = true;
		else
			_overButton = false;
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (_overButton)
			return true;

	default:
		break;
	}

	return false;
}

void Button::draw() const
{
	int y = 0;
	if (_overButton)
		y = 256 - 26;
		
	SDL_Rect srcrect { 0, y, 256, 256 };
	SDL_Rect dstrect { _xPos, _yPos, 256, 256 };
	SDL_RenderCopy(Window::renderer, _bTexture, &srcrect, &dstrect);
}