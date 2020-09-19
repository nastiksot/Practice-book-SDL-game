#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>
#include <SDL.h>
#include "GameObject.h"

class Enemy:public GameObject
{
public:
	void load(int x, int y, int width, int height, string textureID );
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();
};

#endif //ENEMY_H
