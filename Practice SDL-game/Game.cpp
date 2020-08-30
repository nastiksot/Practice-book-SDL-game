#include "Game.h"
#include <iostream>

using namespace std;

Game::Game()
{
	m_bRunning = false;
	m_pWindow = 0;
	m_pRenderer = 0;
}

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
	//everything inited successfully, start the looping

	//load the image to the surface
	SDL_Surface* pTempSurface = SDL_LoadBMP("D:\\Programming\\C++\\C++ Projects\\SDL-game\\assets\\animate.bmp");


	//create texture from surface n image
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);//texture is ready

	//get the size of image to draw n set correctly width and height
	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h); //texture stored in m_sourceRectangle

	//set start pos of animate img
	m_destinationRectangle.x = m_sourceRectangle.x = 0;
	m_destinationRectangle.y = m_sourceRectangle.y = 0;
	//set size of frame
	m_destinationRectangle.w = m_sourceRectangle.w = 128;
	m_destinationRectangle.h = m_sourceRectangle.h = 82;

	m_bRunning = true;
	return true;
}

void Game::render()
{
	//clear the renderer to draw color
	SDL_RenderClear(m_pRenderer);

	//get renderer sie of img
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
	SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, 0, SDL_FLIP_HORIZONTAL);
	//draw to the screen
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	cout << "cleaning game" << endl;
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

bool Game::running()
{
	return m_bRunning;
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
	//change img position by axis x
	m_sourceRectangle.x = 128 * int((SDL_GetTicks() / 100) % 6);
}

Game::~Game()
{
}
