#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"
#include "TextureManager.h"
#include "Player.h"


Game* g_game = 0;




int main(int argc, char* args[])
{
	g_game = new Game();
	g_game->init("WOW WINDOW!!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false);
	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
		SDL_Delay(10);
	}
	g_game->clean();

	return 0;

}
