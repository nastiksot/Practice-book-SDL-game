#include "GameObject.h"
#include "TextureManager.h"


void GameObject::load(int x, int y, int width, int height, string textureID)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_textureID = textureID;

	m_currentFrame = 1;
	m_currentRow = 1;
	
	cout << "load function in GameObject" << endl;
}

void GameObject::draw(SDL_Renderer* pRenderer)
{
	TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, pRenderer);
	cout << "draw game object" << endl;

}

void GameObject::update()
{
	m_x++;
	m_currentFrame = int((SDL_GetTicks() / 100) % 6); //make obj active
	cout<<"update game object"<<endl;
}

void GameObject::clean()
{
	cout << "clean game object" << endl;
}
