#include "Player.h"

Player::Player()
{
}

Player::Player(LoaderParams* pParams):SDLGameObject(pParams)
{
}

void Player::draw()
{
	//draw player
	SDLGameObject::draw();
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
	//SDLGameObject::clean();
	cout << "Clean Player" << endl;
}

Player::~Player()
{
}
