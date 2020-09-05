#pragma once
#ifndef TextureManager_H
#define TextureManager_H

#include <iostream>
#include <string>
#include <map>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class TextureManager {
public:
	//renderer surface n image
	bool load(string fileName, string id, SDL_Renderer* pRenderer);

	//draw function
	void draw(string id, int x, int y, int width, int height, SDL_Renderer* pRenderer,
			  SDL_RendererFlip = SDL_FLIP_NONE);
	
	//drawFrame function
	void drawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame, 
				   SDL_Renderer* pRenderer, SDL_RendererFlip = SDL_FLIP_NONE);

	//create map which contain 2 definition Texture onjects and string keys
	map<string, SDL_Texture*> m_textureMap;
};
#endif //TextureManager_H
