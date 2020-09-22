#pragma once
#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H
#include <iostream>
#include <string>
#include "LoaderParams.h"
#include "GameObject.h"

class SDLGameObject : public GameObject
{
protected:
	int m_x;
	int m_y;
	
	int m_width;
	int m_height;

	int m_currentRow;
	int m_currentFrame;
	
	string m_textureID;
public:
	SDLGameObject(const LoaderParams* pParams);
	SDLGameObject() {}

	virtual void draw();
	virtual void update();
	virtual void clean();
};
#endif // SDLGAMEOBJECT_H

