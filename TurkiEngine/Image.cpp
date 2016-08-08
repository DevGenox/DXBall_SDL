#include "Image.h"


namespace Turki {
	Image::Image(SDL_Renderer* render, const char* path, int PosX, int PosY, int img_Width, int img_Height)
	{
		SDL_Surface* surface = IMG_Load(path);
		//IMG_Load
		m_Texture = SDL_CreateTextureFromSurface(render, surface);
		SDL_FreeSurface(surface);
		SDL_QueryTexture(m_Texture, NULL, NULL, &m_SourceRec.w, &m_SourceRec.h);
		m_destinationRec.x = PosX;
		m_destinationRec.y = PosY;
		m_destinationRec.w = img_Width;
		m_destinationRec.h = img_Height;
		renderer(render);

	}


	Image::~Image()
	{
		SDL_DestroyTexture(m_Texture);
	}
	void Image::renderer(SDL_Renderer* render)
	{
		SDL_SetRenderDrawColor(render, 183, 183, 183, 255);
		SDL_RenderClear(render);
		SDL_RenderCopy(render, m_Texture, &m_SourceRec, &m_destinationRec);
		SDL_RenderPresent(render);

	}
}