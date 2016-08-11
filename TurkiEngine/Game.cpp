#include "Game.h"
#include "GameObject.h"
#include "ImageManager.h"
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
		SDL_SetRenderDrawColor(gameRenderer, 183, 183, 183, 255);
		SDL_RenderClear(gameRenderer);
		backGround.draw(0, 0, 800, 600);
		ball.draw(400, 300, 10, 10);
		SDL_RenderPresent(gameRenderer);

	}
	void Game::update()
	{
		renderer();
	}
	void Game::EventHandle()
	{
	}
}