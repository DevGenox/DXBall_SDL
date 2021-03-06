#pragma once
#include <iostream>
#include <SDL.h>
#define LOG(x) std::cout << x << std::endl
namespace Turki {
	class Window
	{
	private:
		int m_Height, m_Width;
		const char* m_Title;
		bool m_Running = false;
		int fullscreen;
		int m_Flags = 0;

	public:
		Window(const char* Title, int Height, int Width, bool fullscreen);
		~Window();
		bool init();
		bool running() { return m_Running; }
		
		SDL_Renderer* getRenderer() { return m_Renderer; }
	private:
		SDL_Window* m_Window;
		SDL_Renderer* m_Renderer;
	};
}