#include "ArrowButton.h"

ArrowButton::ArrowButton(int xPos, int yPos, const char * texture, bool flip)
{
	if (!flip)
		_flip = SDL_FLIP_NONE;
	else
		_flip = SDL_FLIP_HORIZONTAL;
	_xPos = xPos;
	_yPos = yPos;
	_overButton = false;
	auto surface = IMG_Load(texture);
	_bTexture = SDL_CreateTextureFromSurface(Window::renderer, surface);
	SDL_FreeSurface(surface);
}

ArrowButton::~ArrowButton()
{
	SDL_DestroyTexture(_bTexture);
}

bool ArrowButton::pollEvents(SDL_Event &event)
{
	switch (event.type) {
	case SDL_MOUSEMOTION:
		if (event.motion.x >= _xPos && event.motion.x <= _xPos + 59 * 6
			&& event.motion.y >= _yPos && event.motion.y <= _yPos + 18 * 6)
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

void ArrowButton::draw() const
{
	int y = 0;
	if (_overButton)
		y = 18;

	SDL_Rect srcrect{ 0, y, 59, 18 };
	SDL_Rect dstrect{ _xPos, _yPos, 59 * 6, 18 * 6 };
	SDL_RenderCopyEx(Window::renderer, _bTexture, &srcrect, &dstrect, NULL, nullptr, _flip);

}