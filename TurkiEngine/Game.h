#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "ImageManager.h"
namespace Turki {
	class  Game
	{
	public:
		 Game();
		 ~Game();
		 void load(SDL_Renderer* render);
		 void renderer();
		 void update();
		 void EventHandle();
	private:
		SDL_Renderer* gameRenderer;
		ImageManager* imageMan;
		GameObject backGround;
		GameObject ball;

	};




}