#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"
#include "TextureManager.h"
#include "Player.h"



int main(int argc, char* args[])
{
	if (TheGame::Instance()->init("WOW WINDOW!!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false))
	{
		cout << "Game init succsess" << endl;
		while (TheGame::Instance()->running())
		{
			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();
			SDL_Delay(10);
		}
	}
	else 
	{
		cout << "Game init failure" << SDL_GetError() << endl;
		return -1;
	}
	cout << "Game closing..." << endl;
	TheGame::Instance()->clean();
	return 0;
}
