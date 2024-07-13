#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "Window.h"

class Hero
{
public:
	Hero();
	Hero(int x, int y, int w, int h, const char * texture);
	~Hero();

	void draw() const;
	void pollEvents(SDL_Event &event);
	void move();

protected:
	int _x, _y, _w, _h;
	int _velx, _vely; //velocity x, velocity y
	SDL_Texture * _texture;
};