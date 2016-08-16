#include "Ball.h"


#include "GameObject.h"
namespace Turki {
	Ball::Ball()
	{
		ObjectX = 400;
		ObjectY = 500;
		ObjectWidth = 12;
		ObjectHeight = 12;
		ObjectID = "Ball";
		AssetPath = "Assets/Images/Ball.png";
	}


	Ball::~Ball()
	{
	}
}