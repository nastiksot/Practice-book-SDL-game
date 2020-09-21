#pragma once
#ifndef Game_H
#define Game_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"


class Game
{
private:
	bool m_bRunning;
	int m_currentFrame;

	//varible to allow animate sprite
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	//SDL texture variable
	SDL_Texture* m_pTexture;

	
	vector<GameObject*> m_gameObjects;
	GameObject* m_go;
	Player* m_player;
	Enemy* m_enemy;
	

public:
	Game() {};
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

#endif // Game_H