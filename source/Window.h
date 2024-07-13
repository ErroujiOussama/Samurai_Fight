#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

class Window
{
public:
	Window(const char * title, int width, int height);
	~Window();

	enum class CurrWindow {
		mainMenu, game, help
	};

	void clear() const;
	void pollEvents(SDL_Event &event);
	void draw() const;

	inline bool isRunning() { return _running; }
	inline int getWidth() { return _width; }
	inline int getHeight() { return _height; }

	inline CurrWindow getCurWindow() { return _currWindow; }

	void setCurWindow(CurrWindow currWindow) {
		_currWindow = currWindow;
	}

	void setWindowTexture(const char * texture) {
		auto surface = IMG_Load(texture);
		_wTexture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
	}

	void terminate() {
		_running = false;
	}

	static SDL_Renderer * renderer;

private:
	bool init();

	const char * _title;
	int _width = 640;
	int _height = 640;

	bool _running;

	CurrWindow _currWindow = CurrWindow::mainMenu;
	SDL_Window * _window = nullptr;
	SDL_Texture * _wTexture = nullptr;
};
