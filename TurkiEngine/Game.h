#pragma once
#include <SDL.h>
#include "GameObjects/Player.h"
#include "GameObjects/Ball.h"
#include "GameObjects/BackGround.h"
#include "ImageManager/ImageManager.h"
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
		BackGround backGround;
		Ball ball;

	};




}