#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "GameObject.h"
#include "SDLGameObject.h"
#include "LoaderParams.h"
class Player:public SDLGameObject 
{

public:
	Player();
	Player(LoaderParams* pParams);
	virtual void draw()override;
	virtual void update()override;
	virtual void clean()override;
	virtual ~Player();


};

#endif // PLAYER_H

