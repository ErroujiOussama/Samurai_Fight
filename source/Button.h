#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "Window.h"

class Button
{
public:
	Button();
	Button(int xPos, int yPos, const char * textrue);
	~Button();

	bool pollEvents(SDL_Event &event);
	void draw() const;

protected:
	int _xPos;
	int _yPos;

	bool _overButton;

	SDL_Texture * _bTexture;
};