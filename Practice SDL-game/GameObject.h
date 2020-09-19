#pragma once
#ifndef GameObject_H
#define GameObject_H

#include <iostream>
#include <SDL.h>
#include <string> 


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
	void load(int x, int y, int width, int height, string textureID );
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();

};

#endif // GameObject_H

