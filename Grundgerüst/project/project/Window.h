#pragma once
#include "SDL.h"
#include "glm.hpp"
#include "glew.h"


class Window
{
public:
	Window(int w, int h);
	~Window();

	void flip();
	void clear();

private:
	SDL_GLContext context;
	SDL_Window *window;

	int width, height;
};

