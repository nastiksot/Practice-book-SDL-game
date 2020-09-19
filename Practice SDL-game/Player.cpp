#include "Player.h"

Player::Player()
{
}

void Player::load(int x, int y, int width, int height, string textureID)
{
	GameObject::load(x, y, width, height, textureID);
	cout << "load function in a player" << endl;
}

void Player::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
	cout<<"draw player"<<endl;
}

void Player::update()
{
	//GameObject::update();
	//animate opposite direction
	m_x--;
	m_currentFrame = int((SDL_GetTicks() / 100) % 6);//make obj active
	//m_y = 20;
	cout << "update player" << endl;
}

void Player::clean()
{
	GameObject::clean();
	cout << "clean player" << endl;
}

Player::~Player()
{
}
