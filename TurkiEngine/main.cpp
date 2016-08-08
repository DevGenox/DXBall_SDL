#include "Window.h"
#include "Image.h"
#include <SDL.h>
#include <SDL_image.h>
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
	Image newImage(window.getRenderer(), "Assets/backGround.png", 0, 0, 800, 600);
	
	
	while (window.running())
	{
		newImage.renderer(window.getRenderer());
	}

	system("pause");
	return 0;
}