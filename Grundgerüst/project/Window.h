#pragma once
#include "SDL.h"
#include "glm\glm.hpp"
#include "glew.h"


class Window
{
public:
	Window(int w, int h);
	~Window();

	void flip();
	void clear();

	SDL_Window * get_window();

private:
	SDL_GLContext context;
	SDL_Window *window;

	int width, height;
};

