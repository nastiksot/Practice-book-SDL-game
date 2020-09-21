#pragma once
#ifndef GameObject_H
#define GameObject_H

#include <iostream>
#include <SDL.h>
#include <string> 
#include <vector> 


using namespace std;

class GameObject
{
protected:
	string m_textureID;

	int m_currentFrame;
	int m_currentRow;
	
	int m_x;
	int m_y;

	int m_width;
	int m_height;

	

public: 
	virtual void load(int x, int y, int width, int height, string textureID );
	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
	virtual void clean();

};

#endif // GameObject_H

