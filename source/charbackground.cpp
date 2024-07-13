#include "Charbackground.h"

CharBG::CharBG(int xPos, int yPos)
	: _xPos(xPos), _yPos(yPos), _width(200), _length(200)
{
	auto surface = IMG_Load("Assets/charBackground1.png");
	_texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
	SDL_FreeSurface(surface);
}

CharBG::~CharBG()
{
	SDL_DestroyTexture(_texture);
}

void CharBG::draw() const
{
	SDL_Rect srcCharBG { 0, 0, 32, 44 };
	SDL_Rect dstCharBG { _xPos, _yPos, 32 * 12, 44 * 12 };
	SDL_RenderCopy(Window::renderer, _texture, &srcCharBG, &dstCharBG);
}
