#pragma once

#include "Button.h"

class ArrowButton : public Button
{
public:
	ArrowButton(int xPos, int yPos, const char * texture, bool flip);
	~ArrowButton();

	bool pollEvents(SDL_Event &event);
	void draw() const;

private:
	SDL_RendererFlip _flip;
};