#include "Player.h"
#include "GameObject.h"

namespace Turki {
	Player::Player()
	{
		ObjectID = "Player";
		AssetPath = "Assets/Images/Player.png";
		ObjectWidth = 100;
		ObjectHeight = 20;
		ObjectX = 400 - (ObjectWidth/2);
		ObjectY = 580;

	}


	Player::~Player()
	{
	}
}