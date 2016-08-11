#pragma once
#include <SDL.h>
#include "../ImageManager/ImageManager.h"
namespace Turki {
	class GameObject
	{
	public:
		GameObject();
		~GameObject();
		int ObjectX;
		int ObjectY;
		int ObjectWidth;
		int ObjectHeight;
		void load(SDL_Renderer * render, ImageManager imgManager, const char* id, const char* path);
		void draw(int PosX, int PosY, int img_Width, int img_Height);
	private:
		const char* ObjectID;
		const char* AssetPath;
		ImageManager Obj_imgMan;
		SDL_Renderer* gameRenderer;
	};

}