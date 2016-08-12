#include "Game.h"
#include "GameObjects/Player.h"
#include "GameObjects/Ball.h"
#include "GameObjects/BackGround.h"
#include "ImageManager/ImageManager.h"
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))
namespace Turki {
	Game::Game()
	{

	}

	Game::~Game()
	{
	}
	void Game::load(SDL_Renderer* render)
	{
		for (int i = 0; i < brickSize; i++)
		{
			brick[i] = new Brick;
		}

		gameRenderer = render;
		imageMan.setRenderer(gameRenderer);
		backGround.load(gameRenderer, imageMan);
		ball->load(gameRenderer, imageMan);
		player->load(gameRenderer, imageMan);
		for (int i = 0; i < brickSize; i++)
		{
			brick[i]->load(gameRenderer, imageMan);
		}


	}
	void Game::renderer()
	{

		int dX = 5;
		int dY = 5;
		for (int i = 0;; i++)
		{


			SDL_SetRenderDrawColor(gameRenderer, 183, 183, 183, 255);
			SDL_RenderClear(gameRenderer);
			backGround.draw(0, 0, 800, 600);



			if (ball->ObjectX < 0 || ball->ObjectX > 800) {
				dX = -dX;
			}
			if (ball->ObjectY < 0 || ball->ObjectY > 600) {
				dY = -dY;
			}
			for (int t = 0; t < brickSize; t++)
			{
				if (brick[t] != NULL)
				{
					if (collisionX(*ball, *brick[t], dX))
					{
						dX = -dX;
						brick[t] = NULL;
						break;
					}
					if (collisionY(*ball, *brick[t], dY))
					{
						dY = -dY;
						brick[t] = NULL;
						break;
					}
				}
			}
			int id = -1;
			for (int y = 50; y <= 200; y += 40)
			{
				for (int x = 50; x <= 700; x += 50)
				{
					id++;
					if (brick[id] != NULL)
					{
						brick[id]->draw(x, y, brick[id]->ObjectWidth, brick[id]->ObjectHeight);
					}
				}
			}
			int x, y;
			SDL_GetMouseState(&x, &y);
			player->draw(x, player->ObjectY, player->ObjectWidth, player->ObjectHeight);
			if (collisionX(*ball, *player, dX))
			{
				dX = -dX;
			}
			if (collisionY(*ball, *player, dY))
			{
				int carpmapos = ball->ObjectX - player->ObjectX;
				int yol = 0;
				if (carpmapos >= 0 && carpmapos < 10 || carpmapos < 0)
				{
					yol = -5;
				}
				if (carpmapos >= 10 && carpmapos < 20)
				{
					yol = -4;
				}
				if (carpmapos >= 20 && carpmapos < 30)
				{
					yol = -3;
				}
				if (carpmapos >= 30 && carpmapos < 40)
				{
					yol = -2;
				}
				if (carpmapos >= 40 && carpmapos < 50)
				{
					yol = -1;
				}
				if (carpmapos >= 50 && carpmapos < 60)
				{
					yol = 1;
				}
				if (carpmapos >= 60 && carpmapos < 70)
				{
					yol = 2;
				}
				if (carpmapos >= 70 && carpmapos < 80)
				{
					yol = 3;
				}
				if (carpmapos >= 80 && carpmapos < 90)
				{
					yol = 4;
				}
				if (carpmapos >= 90 && carpmapos < 100)
				{
					yol = 5;
				}
				dY = -dY;
				dX = yol;
			}

		

		ball->ObjectX += dX;
		ball->ObjectY += dY;

		ball->draw(ball->ObjectX, ball->ObjectY, 10, 10);

		EventHandle();
		SDL_RenderPresent(gameRenderer);

		SDL_Delay(7);
	}
}
//Collision Defination for From soldan saðdan
bool Game::collisionX(Ball& ballColX, GameObject& brickColX, int dx) {
	int x1 = ballColX.ObjectX;
	int y1 = ballColX.ObjectY;
	int h1 = ballColX.ObjectHeight;
	int w1 = ballColX.ObjectWidth;
	int b1 = y1 + h1;
	int r1 = x1 + w1;
	int x2 = brickColX.ObjectX;
	int y2 = brickColX.ObjectY;
	int h2 = brickColX.ObjectHeight;
	int w2 = brickColX.ObjectWidth;
	int b2 = y2 + h2;
	int r2 = x2 + w2;

	if ((b1 >= y2) && (y1 <= b2)) {
		if (dx > 0) {
			if (r1 >= x2 && r1 <= (x2 + 5)) {
				return true;
			}
		}
		if (dx < 0) {
			if (x1 <= r2 && x1 >= (r2 - 5)) {
				return true;
			}
		}
	}
	return false;
}
//Collision Defination for from yukarýdan aþaðýdan
bool Game::collisionY(Ball& ballColY, GameObject& brickColY, int dy) {
	int x1 = ballColY.ObjectX;
	int y1 = ballColY.ObjectY;
	int h1 = ballColY.ObjectHeight;
	int w1 = ballColY.ObjectWidth;
	int b1 = y1 + h1;
	int r1 = x1 + w1;
	int x2 = brickColY.ObjectX;
	int y2 = brickColY.ObjectY;
	int h2 = brickColY.ObjectHeight;
	int w2 = brickColY.ObjectWidth;
	int b2 = y2 + h2;
	int r2 = x2 + w2;

	if ((r1 >= x2) && (x1 <= r2)) {
		if (dy > 0) {
			if (b1 >= y2 && b1 <= (y2 + 5)) {
				return true;
			}
		}
		if (dy < 0) {
			if (y1 <= b2 && y1 >= (b2 - 5)) {
				return true;
			}
		}
	}
	return false;
}
void Game::update()
{
	renderer();
}
void Game::EventHandle()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:

			std::cout << SDL_GetKeyName(event.key.keysym.sym) << " Basýldý" << std::endl;
			break;
		case SDL_QUIT:

			break;
		default:
			break;
		}
	}

}
}