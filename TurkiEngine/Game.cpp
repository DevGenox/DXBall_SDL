#include "Game.h"
#include "GameObjects/Player.h"
#include "GameObjects/Ball.h"
#include "GameObjects/BackGround.h"
#include "ImageManager/ImageManager.h"
namespace Turki {
	Game::Game()
	{
	
	}

	Game::~Game()
	{
	}
	void Game::load(SDL_Renderer* render)
	{
		gameRenderer = render;
		ImageManager newImageMan;
		newImageMan.setRenderer(render);
		imageMan = &newImageMan;
		backGround.load(gameRenderer, *imageMan, "backGround", "Assets/backGround.png");
		ball.load(gameRenderer, *imageMan, "Ball", "Assets/Ball.png");
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

			if (ball.ObjectX < 0 || ball.ObjectX > 800) {
				dX = -dX;
			}
			if (ball.ObjectY < 0 || ball.ObjectY > 600) {
				dY = -dY;
			}





			ball.ObjectX += dX;
			ball.ObjectY += dY;

			ball.draw(ball.ObjectX, ball.ObjectY, 10, 10);
			SDL_RenderPresent(gameRenderer);

			SDL_Delay(7);
		}
	}
	void Game::update()
	{
		renderer();
	}
	void Game::EventHandle()
	{
	}
}