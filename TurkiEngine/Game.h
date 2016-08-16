#pragma once
#include <SDL.h>
#include "GameObjects/Player.h"
#include "GameObjects/Ball.h"
#include "GameObjects/BackGround.h"
#include "GameObjects/Brick.h"
#include "ImageManager/ImageManager.h"
#include "Sound/SoundManager.h"
#include "GameObjects/Player.h"
#include "GameObjects/Ball.h"
#include "GameObjects/BackGround.h"
#include "GameObjects/Heart.h"
namespace Turki {
	class  Game
	{
	public:
		 Game();
		 ~Game();
		 void load(SDL_Renderer* render);
		 void playBackground();
		 void renderer();
		 void update();
		 void EventHandle();
		 bool collisionX(Ball& ballColX, GameObject& brickColX, int dx);
		 bool collisionY(Ball& ballColY, GameObject& brickColY, int dy);
	private:
		int dX;
		int dY;
		int max = 5;
		int min = -5;
		int ilkyol;
		bool gameStart;
		bool ballDestroyed;
		bool gameOver;
		int life;


	private:
		SDL_Renderer* gameRenderer;
		ImageManager imageMan;
		SoundManager soundMan;

	private:
		int brickSize = 56;
		BackGround backGround;
		Ball* ball = new Ball;
		Player* player = new Player;
		Brick* brick[56];
		Heart* firstHeart = new Heart;
		Heart* secondHeart = new Heart;
		Heart* thirdHeart = new Heart;
	};




}