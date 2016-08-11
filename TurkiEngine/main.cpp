#include "Window.h"
#include "ImageManager.h"
#include "Game.h"
#include <SDL.h>
#include <SDL_Image.h>
#define LOG(x) std::cout << x << std::endl

int topla(int x, int y)
{
	x++;
	return x + y;
}

int main(int argc, char* args[])
{
	int a = 5;
	int b = 4;
	int &firstP = a;
	int &secondP = b;

	LOG(topla(firstP, secondP));

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