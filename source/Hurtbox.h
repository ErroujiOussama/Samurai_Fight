#pragma once

#include <SDL.h>

#include "Window.h"
#include "Player.h"
#include "Collider.h"
#include "Hitbox.h"

class Hurtbox : public Collider
{
public:
	Hurtbox(Character character, int playerID, int currXpos, int currYpos, SDL_RendererFlip flip);
	~Hurtbox();

	bool collide(Hitbox hitbox);

	void draw(Character character, int playerXpos); //for debugging purposes

private:
	SDL_Rect _hurtbox;
};