#include "Hurtbox.h"
#include <iostream>
Hurtbox::Hurtbox(Character character, int playerID, int currXpos, int currYpos, SDL_RendererFlip flip)
{
	switch (character) {
	case Character::knight:
		switch (flip) {
		case SDL_FLIP_NONE:
			_xPos = currXpos + 55; break;
		case SDL_FLIP_HORIZONTAL:
			_xPos = currXpos + 55; break;
		default: break;
		}
		_yPos = currYpos;
		_width = 90;
		_length = 200;
		break;
	case Character::samurai:
		switch (flip) {
		case SDL_FLIP_NONE:
			_xPos = currXpos + 250; break;
		case SDL_FLIP_HORIZONTAL:
			_xPos = currXpos + 50; break;
		default: break;
		}
		_yPos = currYpos + 200;
		_width = 90;
		_length = 200;
		break;
	case Character::huntress:
		switch (flip) {
		case SDL_FLIP_NONE:
			_xPos = currXpos + 255; break;
		case SDL_FLIP_HORIZONTAL:
			_xPos = currXpos; break;
		default: break;
		}
		_yPos = currYpos + 200;
		_width = 90;
		_length = 200;
	default: break;
	}

	//_hurtbox = SDL_Rect { _xPos, _yPos, _width, _length };
}

Hurtbox::~Hurtbox()
{}

void Hurtbox::draw(Character character, int playerXpos)
{
	if (character == Character::knight)
		_xPos = playerXpos + 55;
	else if (character == Character::samurai)
		_xPos = playerXpos + 255;
	else if (character == Character::huntress)
		_xPos = playerXpos + 255;

	_hurtbox = SDL_Rect{ _xPos, _yPos, _width, _length };

	//SDL_RenderDrawRect(Window::renderer, &_hurtbox);
	//SDL_RenderFillRect(Window::renderer, &_hurtbox);
}

bool Hurtbox::collide(Hitbox hitbox)
{
	if (
		( _xPos >= hitbox.getXpos() && _xPos <= hitbox.getXpos() + hitbox.getWidth() )
		||
		( _xPos + _width >= hitbox.getXpos() && _xPos + _width <= hitbox.getXpos() + hitbox.getWidth() )
	   )
	{
		//std::cout<<"collison";
		return true;
	}
	return false;
}
