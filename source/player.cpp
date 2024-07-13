#include "Player.h"
#include <iostream>
#include <SDL_mixer.h>
Player::Player(int xPos, int yPos, const char * texture, SDL_RendererFlip flip, Character character, int playerID)
	: _xPos(xPos), _yPos(yPos), _running(false), _attack(false), _eventID(Event::idle),
	  _flip(flip), _character(character), _playerID(playerID), _size(1), _alive(true)
{
	switch (character) {
	case Character::knight:
		_health = 100;
		_damage = 1;
		break;
	case Character::samurai:
		_health = 200;
		_damage = 1;
		break;
	case Character::huntress:
		_health = 200;
		_damage = 1;
		break;
	default: break;
	}

	auto surface = IMG_Load(texture);
	_pTexture = SDL_CreateTextureFromSurface(Window::renderer, surface);
	SDL_FreeSurface(surface);
}

Player::~Player()
{
	SDL_DestroyTexture(_pTexture);
}

void Player::draw(int &x, Event &saveEvent, int &animDelay)
{
	if (_character == Character::knight)
		drawKnight(x, saveEvent, animDelay);
	else if (_character == Character::samurai)
		drawSamurai(x, saveEvent, animDelay);
	else if (_character == Character::huntress)
		drawHuntress(x, saveEvent, animDelay);
}

void Player::drawKnight(int &x, Event &saveEvent, int &animDelay)
{
	if (saveEvent != getEventID()) {
		x = 60;
		saveEvent = getEventID();
	}
    // here we animate our knight by checking if the event is death or runing or attack 
	if (animDelay >= 5) { //animation delay for Knight
		x += 180 * ((_eventID == Event::death && x >= 1800) ? 0 : 1);

		int limit = 1800;
		if (isRunning())
			limit = 1440;
		else if (attack())
			limit = 1260;
		else if (_eventID == Event::death)
			limit = 1980;

		if (x >= limit && _eventID != Event::death) {
			x = 60; //90-21
		}
		animDelay = 0;
	}

	animDelay++;

	_running = false;
	int y = 45; //90 - 30 - 15

	if (_velx != 0) {
		y = 145; //160 - 15
		_running = true;
	}
	else if (_eventID == Event::attack && x >= 1100) {
		_attack = false; ///////////////////////////////
		_eventID = Event::idle;
	}
	else if (_attack) {
		y = 230 + 1; //245
	}
	if (_eventID == Event::death) { //////////////////////////////
		y = 230 + 180 + 180 + 180 - 5;
	}

	SDL_Rect srcrect { x, y, 70, 70 };
	SDL_Rect dstrect { _xPos, _yPos, 200 * _size, 200 * _size };
	SDL_RenderCopyEx(Window::renderer, _pTexture, &srcrect, &dstrect, NULL, nullptr, _flip);
}

void Player::drawSamurai(int &x, Event &saveEvent, int &animDelay)
{
	int initial = 0; //initial x position for the Samurai sprite

	if (saveEvent != getEventID()) {
		x = initial;
		saveEvent = getEventID();
	}

	if (animDelay >= 8) { //animation delay for Samurai
		x += 200;

		int limit = 800;
		if (isRunning())
			limit = 1600;
		else if (attack())
			limit = 800;

		if (x >= limit) {
			x = initial; //90-21
		}
		animDelay = 0;
	}

	animDelay++;

	_running = false;
	int y = 0;

	if (_velx != 0)
		y = 195 + 1; //200
	else if (_attack)
		y = 400 + 8;

	if (_eventID == Event::attack && x >= 600) {
		_attack = false; ///////////////////////////////
		_eventID = Event::idle;
	}

	SDL_Rect srcrect { x, y, 200, 200 };
	SDL_Rect dstrect { _xPos, _yPos + 13, 600 * _size, 600 * _size };
	SDL_RenderCopyEx(Window::renderer, _pTexture, &srcrect, &dstrect, NULL, nullptr, _flip);
}

void Player::drawHuntress(int &x, Event &saveEvent, int &animDelay)
{
	int initial = 0; //initial x position for the Samurai sprite

	if (saveEvent != getEventID()) {
		x = initial;
		saveEvent = getEventID();
	}

	if (animDelay >= 6) { //animation delay for Samurai
		x += 150;

		int limit = 1200;
		if (isRunning())
			limit = 1200;
		else if (attack())
			limit = 750;

		if (x >= limit) {
			x = initial; //90-21
		}
		animDelay = 0;
	}

	animDelay++;

	_running = false;
	int y = 0;

	if (_velx != 0)
		y = 150 - 4; //200
	else if (_attack)
		y = 300;

	if (_eventID == Event::attack && x >= 600) {
		_attack = false; ///////////////////////////////
		_eventID = Event::idle;
	}

	SDL_Rect srcrect{ x, y, 150, 150 };
	SDL_Rect dstrect{ _xPos, _yPos + 9, 600 * _size, 600 * _size };
	SDL_RenderCopyEx(Window::renderer, _pTexture, &srcrect, &dstrect, NULL, nullptr, _flip);
}

void Player::pollEventsP1(SDL_Event &event)
{
	//switch (event.type) {
	//case SDL_KEYDOWN:
	//	switch (event.key.keysym.sym) {
	//	case SDLK_SPACE:
	//		_eventID = 3;
	//		_velx = 0;
	//		_attack = true;
	//		break;
	//	default: break;
	//	}
	//default: break;
	//}

	const Uint8 * keyState = SDL_GetKeyboardState(NULL);

	if (keyState[SDL_SCANCODE_D]) {
		_eventID = Event::idle;
		_velx = 7;
		_flip = SDL_FLIP_NONE;
	}
	else if (keyState[SDL_SCANCODE_A]) {
		_eventID = Event::run;
		_velx = -7;
		_flip = SDL_FLIP_HORIZONTAL;
	}
//	else if (keyState[SDL_SCANCODE_SPACE]) {
//		_eventID = Event::attack;
//		_velx = 0;
//		_attack = true;
//	}
	else {
		_eventID = Event::idle;
		_velx = 0;
		_attack = false;
	}
	
	
	 if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_SPACE:    
					    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
                        _eventID = Event::attack;
		                _velx = 0;
						_attack = true;
						  Mix_Chunk* sound = Mix_LoadWAV("Assets/knife1.wav");
                          Mix_PlayChannel(-1, sound, 0);
//          				 while (Mix_Playing(-1)) {
//        					SDL_Delay(0.01);
//    						}
                        break;

                }
            }
	
	
	SDL_PumpEvents();
}

void Player::pollEventsP2(SDL_Event &event)
{
	const Uint8 * keyState = SDL_GetKeyboardState(NULL);

	if (keyState[SDL_SCANCODE_RIGHT]) {
		_eventID = Event::idle;
		_velx = 7;
		_flip = SDL_FLIP_NONE;
	}
	else if (keyState[SDL_SCANCODE_LEFT]) {
		_eventID = Event::run;
		_velx = -7;
		_flip = SDL_FLIP_HORIZONTAL;
	}
//	else if (keyState[SDL_SCANCODE_K]) {
//		_eventID = Event::attack;
//		_velx = 0;
//		_attack = true;
//	}
	else {
		_eventID = Event::idle;
		_velx = 0;
		_attack = false;
	}
	 if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_k:    
					    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 5, 2048);
                        _eventID = Event::attack;
		                _velx = 0;
						_attack = true;
						  Mix_Chunk* sound = Mix_LoadWAV("Assets/knife2.wav");
                          Mix_PlayChannel(5, sound, 0);
//          				 while (Mix_Playing(-1)) {
//        					SDL_Delay(0.01);
//    						}
                        break;

                }
            }
}

void Player::takeHit(Character character, float damage, Player &player)
{

	_health -= damage;
	std::cout<<"damage is  "<<_health<<std::endl;
	
	if (_health <= 0) {
		if(_health == 0){
					Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 5, 2048);
		Mix_Chunk* sound = Mix_LoadWAV("Assets/death.wav");
        Mix_PlayChannel(5, sound, 0);
		}
		_eventID = Event::death;
		
	}
}

void Player::move(Window &window)
{
	int rightWall = 0;
	int leftWall = 0;

	if (_character == Character::knight) {
		rightWall = window.getWidth() - _w;
		leftWall = 0;
	}
	else if (_character == Character::samurai) {
		rightWall = window.getWidth() - 400;
		leftWall = -200;
	}
	else if (_character == Character::huntress) {
		rightWall = window.getWidth() - 170 - 300;
		leftWall = -170;
	}

	_xPos += _velx;
	if (_xPos >= rightWall || _xPos <= leftWall)
		_xPos -= _velx;
}
