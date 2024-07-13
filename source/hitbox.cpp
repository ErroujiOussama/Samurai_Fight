#include "Hitbox.h"
#include "Player.h"

Hitbox::Hitbox(Character character, int playerID, int currXpos, int currYpos, SDL_RendererFlip flip)
{
	switch (character) {
	case Character::knight:
		switch (flip) {
		case SDL_FLIP_NONE:
			_xPos = currXpos + 100; break;
		case SDL_FLIP_HORIZONTAL:
			_xPos = currXpos; break;
		default: break;
		}
		_yPos = currYpos;
		_width = 100;
		_length = 200;
		break;
	case Character::samurai:
		switch (flip) {
		case SDL_FLIP_NONE:
			_xPos = currXpos + 350; break;
		case SDL_FLIP_HORIZONTAL:
			_xPos = currXpos + 50; break;
		default: break;
		}
		_yPos = currYpos + 200;
		_width = 200;
		_length = 200;
		break;
	case Character::huntress:
		switch (flip) {
		case SDL_FLIP_NONE:
			_xPos = currXpos + 305; break;
		case SDL_FLIP_HORIZONTAL:
			_xPos = currXpos + 95; break;
		default: break;
		}
		_yPos = currYpos + 200;
		_width = 200;
		_length = 200;
	default: break;
	}

	_hitbox = SDL_Rect { _xPos, _yPos, _width, _length };
}

Hitbox::~Hitbox()
{

	_hitbox.w=0;
	_hitbox.h=0;
}

void Hitbox::draw() const
{
	//SDL_RenderDrawRect(Window::renderer, &_hitbox);
	//SDL_RenderFillRect(Window::renderer, &_hitbox);
}





























