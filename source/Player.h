#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "Window.h"
#include "Hero.h"

enum class Character
{
	knight, samurai, huntress
};

enum class Event
{
	idle, run, attack, attackTwo, takeHit, death
};

class Player : public Hero
{
public:
	Player(int xPos, int yPos, const char * texture, SDL_RendererFlip flip, Character character, int playerID);
	~Player();
	
	void draw(int &x, Event &saveEvent, int &animDelay);

	void drawKnight(int &x, Event &saveEvent, int &animDelay);
	void drawSamurai(int &x, Event &saveEvent, int &animDelay);
	void drawHuntress(int &x, Event &saveEvent, int &animDelay);

	void pollEventsP1(SDL_Event &event);
	void pollEventsP2(SDL_Event &event);
	void move(Window &window);
	void takeHit(Character character, float damage, Player& player);

	void setSize(int sizeMultiplier) {
		_size = sizeMultiplier;
	}

	inline int getXpos() const { return _xPos; }
	inline int getYpos() const { return _yPos; }
	inline bool isRunning() const { return _running; }
	inline bool attack() const { return _attack; }
	inline Event getEventID() const { return _eventID; }
	inline int getHealth() const { return _health; }
	inline int getDamage() const { return _damage; }
	inline SDL_RendererFlip getFlip() const { return _flip; }
	inline bool isAlive() const { return _alive; }

private:
	int _xPos, _yPos;
	bool _running;
	bool _attack;
	Event _eventID;
	int _playerID;

	bool _alive;

	int _size;

	int _health = 0;
	float _damage = 0;

	Character _character;

	SDL_RendererFlip _flip;
	SDL_Texture * _pTexture;
};
