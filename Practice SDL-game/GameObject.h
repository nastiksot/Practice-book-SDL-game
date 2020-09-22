#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <SDL.h>
#include <string> 
#include <vector> 
#include "LoaderParams.h"

using namespace std;

class GameObject
{
protected:

	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject(){}

public: 
	GameObject() {}
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

};

#endif // GAMEOBJECT_H

