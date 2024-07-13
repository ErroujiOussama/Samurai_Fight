#pragma once

#include <SDL.h>

#include "Window.h"
#include "Player.h"
#include "Collider.h"

class Hitbox : public Collider
{
public:
	Hitbox(Character character, int playerID, int currXpos, int currYpos, SDL_RendererFlip flip);
	~Hitbox();

	void draw() const; //for debugging purposes

private:
	SDL_Rect _hitbox;
};