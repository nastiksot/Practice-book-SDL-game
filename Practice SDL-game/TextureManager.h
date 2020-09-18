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

	//do private constructor for singletone
	TextureManager() {}
	static TextureManager* s_pInstance;
public:
	//function keep or create objects
	static TextureManager* Instance();
	//renderer surface n image
	bool load(string fileName, string id, SDL_Renderer* pRenderer);

	//draw static image
	void draw(string id, int x, int y, int width, int height, SDL_Renderer* pRenderer,
			  SDL_RendererFlip = SDL_FLIP_NONE);
	
	//draw dynamic image
	void drawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame, 
				   SDL_Renderer* pRenderer, SDL_RendererFlip = SDL_FLIP_NONE);

	//create map which contain 2 definition Texture onjects and string keys
	map<string, SDL_Texture*> m_textureMap;
};
typedef TextureManager TheTextureManager;
#endif //TextureManager_H
