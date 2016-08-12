#pragma once
#include <SDL.h>
#include "GameObjects/Player.h"
#include "GameObjects/Ball.h"
#include "GameObjects/BackGround.h"
#include "GameObjects/Brick.h"
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
		 bool collisionX(Ball& ballColX, GameObject& brickColX, int dx);
		 bool collisionY(Ball& ballColY, GameObject& brickColY, int dy);
	private:
		SDL_Renderer* gameRenderer;
		ImageManager imageMan;
		int brickSize = 56;
		BackGround backGround;
		Ball* ball = new Ball;
		Player* player = new Player;
		Brick* brick[56];
		

	};




}