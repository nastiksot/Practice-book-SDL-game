#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include <SDL_image.h>
#include <iostream>

using namespace std;

bool Game::init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen)
{
	//attempt to initializate SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "SDL initializate success" << endl;
		int flags = 0;
		if (fullscreen)
		{
			flags = SDL_WINDOW_OPENGL;
		}

		//init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
		if (m_pWindow != 0)
		{

			//windows init success
			cout << "windows creation success" << endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			//render unit success
			if (m_pRenderer != 0)
			{
				//set background color
				SDL_SetRenderDrawColor(m_pRenderer, 112, 140, 194, 255);
			}
			else
			{
				cout << "render init failed" << endl;
				return false;
			}
		}
		else
		{
			cout << "windows init failed" << endl;
			return false;
		}
	}
	else
	{
		cout << "SDL init failed" << endl;
		return false;
	}
	cout << "Init success" << endl;
	m_bRunning = true;
	//to load texture
	if (!TheTextureManager::Instance()->load("../assets/animate-alpha.png", "animate", m_pRenderer))//given the texture ID "animate"
	{
		return false;
	}
	m_go.load(100,100,128,82,"animate");
	m_player.load(300,300,128,82,"animate");
	return true;
}

void Game::render()
{
	//clear the renderer to draw color
	SDL_RenderClear(m_pRenderer);
	m_go.draw(m_pRenderer);
	m_player.draw(m_pRenderer);
	//to draw texture
	//TheTextureManager::Instance()->draw("animate",0,0,128,82,m_pRenderer);
	//TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	cout << "cleaning game" << endl;
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}


void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

//for changing frame
void Game::update()
{
	m_go.update();
	m_player.update();
	//change img position by axis x
	//m_currentFrame = int((SDL_GetTicks() / 100) % 6);
}