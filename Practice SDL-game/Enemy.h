#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>
#include <SDL.h>
#include "GameObject.h"
#include "LoaderParams.h"
#include "SDLGameObject.h"

class Enemy:public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual ~Enemy() {}
};

#endif //ENEMY_H
