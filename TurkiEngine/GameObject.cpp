#include "GameObject.h"
#include "ImageManager.h"
namespace Turki {

	GameObject::GameObject()
	{
		
	}


	GameObject::~GameObject()
	{
	}
	void GameObject::load(SDL_Renderer * render, ImageManager imgManager, const char* id, const char* path)
	{
		gameRenderer = render;
		ObjectID = id;
		AssetPath = path;

		Obj_imgMan = imgManager;
		Obj_imgMan.load(id, path);
	}
	void GameObject::draw(int PosX, int PosY, int img_Width, int img_Height)
	{
		ObjectX = PosX;
		ObjectY = PosY;
		ObjectWidth = img_Width;
		ObjectHeight = img_Height;
		Obj_imgMan.draw(ObjectID, ObjectX, ObjectY, ObjectWidth, ObjectHeight);
	}
}