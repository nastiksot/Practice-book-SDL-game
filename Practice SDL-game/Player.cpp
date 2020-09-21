#include "Player.h"

Player::Player()
{
}

void Player::load(int x, int y, int width, int height, string textureID)
{
	GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* pRenderer)
{
	//draw player
	GameObject::draw(pRenderer);
}

void Player::update()
{
	// -- animate opposite direction
	m_x--;
	//make obj active
	m_currentFrame = int((SDL_GetTicks() / 100) % 6);
}

void Player::clean()
{
	GameObject::clean();
	cout << "clean player" << endl;
}

Player::~Player()
{
}
