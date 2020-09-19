#pragma once
#ifndef Player_H
#define Player_H
#include <iostream>
#include <string>
#include "GameObject.h"
class Player:public GameObject 
{

public:
	Player();
	void load(int x, int y, int width, int height, string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();
	~Player();


};

#endif // Player_H

