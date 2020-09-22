#pragma once
#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "SDLGameObject.h"
#include "LoaderParams.h"


class Game
{
private:
	Game() {};

	bool m_bRunning;
	int m_currentFrame;

	//varible to allow animate sprite
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	//SDL texture variable
	SDL_Texture* m_pTexture;

	vector<GameObject*> m_gameObjects;

	
	static Game* s_pInstance;

public:
	static Game* Instance();
	SDL_Renderer* getRenderer()const { return m_pRenderer; }
	bool init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);
	void render();
	//return m_bRunning
	bool running() { return m_bRunning; }
	//for changing frame img
	void update();
	//allow to close aplication
	void handleEvents();
	//clean up SDL
	void clean();

	~Game(){};
};

typedef Game TheGame;
#endif // GAME_H
