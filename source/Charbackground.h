#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "Window.h"

class CharBG
{
public:
	CharBG(int xPos, int yPos);
	~CharBG();
	void draw() const;

private:
	int _xPos, _yPos, _width, _length;
	SDL_Texture * _texture;
};