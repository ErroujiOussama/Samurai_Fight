#pragma once

#include "Hero.h"

class Samurai : public Hero
{
public:
	Samurai(int x, int y, const char * texture);
	~Samurai();

	void draw(int x);
	void pollEvents(SDL_Event &event);
	void move(Window &window);

	inline int getx() { return _sPosX; }
	inline bool isRunning() { return _running; }
	inline bool attack() { return _attack; }
	inline int getEventID() { return _eventID; }

private:
	int _sPosX, _sPosY;
	bool _running;
	bool _attack;
	int _eventID;
	SDL_RendererFlip _flip = SDL_FLIP_HORIZONTAL;
	SDL_Texture * _sTexture;
};