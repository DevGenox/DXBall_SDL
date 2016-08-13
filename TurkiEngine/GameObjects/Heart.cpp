#include "Heart.h"
#include "GameObject.h"

namespace Turki {
	Heart::Heart()
	{
		ObjectID = "Heart";
		AssetPath = "Assets/Heart.png";
		ObjectWidth = 25;
		ObjectHeight = 22;
	}


	Heart::~Heart()
	{
	}
}