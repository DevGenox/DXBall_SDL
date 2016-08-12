#include "Ball.h"


#include "GameObject.h"
namespace Turki {
	Ball::Ball()
	{
		ObjectX = 400;
		ObjectY = 500;
		ObjectWidth = 10;
		ObjectHeight = 10;
		ObjectID = "Ball";
		AssetPath = "Assets/Ball.png";
	}


	Ball::~Ball()
	{
	}
}