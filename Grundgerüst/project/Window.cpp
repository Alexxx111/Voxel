#include "Window.h"



Window::Window(int w, int h)
{
	this->width = w;
	this->height = h;

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow(".. ", 600, 100, width, height, SDL_WINDOW_OPENGL);

	context = SDL_GL_CreateContext(window);

	glClearColor(0.f, 0.1f, 0.3f, 1.0f);
}


Window::~Window()
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
}

void Window::clear(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

void Window::flip(){
	SDL_GL_SwapWindow(window);
}
SDL_Window *Window::get_window(){
	return this->window;
}