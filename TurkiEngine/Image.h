#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#define LOG(x) std::cout << x << std::endl
namespace Turki {
	class Image
	{
	public:
		Image(SDL_Renderer* render, const char* path, int PosX, int PosY, int img_Width, int img_Height);
		~Image();
		void renderer(SDL_Renderer* render);
	private:
		SDL_Texture* m_Texture;
		SDL_Rect m_SourceRec;
		SDL_Rect m_destinationRec;
	};

}