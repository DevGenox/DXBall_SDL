#include "Window/Window.h"
#include "ImageManager/ImageManager.h"
#include "Game.h"
#include <SDL.h>
#include <SDL_Image.h>
#include <SDL_mixer.h>
#define LOG(x) std::cout << x << std::endl

int main(int argc, char* args[])
{
	using namespace Turki;
	setlocale(LC_ALL, "Turkish");
	Window window("Turki ENGINE", 800, 600, false);
	SDL_Renderer* windowRenderer = window.getRenderer();
	Game game;
	game.load(windowRenderer);
	while (window.running())
	{
		game.update();
	}
	
	system("pause");
	return 0;
}