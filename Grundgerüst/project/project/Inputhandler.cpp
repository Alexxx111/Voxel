#include "Inputhandler.h"


Inputhandler::Inputhandler(Window *window)
{
	this->window = window;
}


Inputhandler::~Inputhandler()
{
}

bool Inputhandler::get_input(){

	SDL_Event e;

	while (SDL_PollEvent(&e)){

		if (e.type == SDL_QUIT){
			return false;
		}

		if (e.key.keysym.sym == SDLK_ESCAPE){
			return false;
		}


	}

	return true;

}