#pragma once
#ifndef Game_H
#define Game_H

#include <SDL.h>
#include <SDL_image.h>

class Game
{
private:
	bool m_bRunning;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	//SDL texture variable
	SDL_Texture* m_pTexture;
	//first object
	SDL_Rect m_sourceRectangle;
	//another object
	SDL_Rect m_destinationRectangle;

public:
	Game();
	bool init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);
	void render();
	//clean up SDL
	void clean();
	//return m_bRunning
	bool running();
	//allow to close aplication
	void handleEvents();
	//for changing frame img
	void update();
	~Game();
};

#endif // Game_H

