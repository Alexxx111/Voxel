#include "Inputhandler.h"


Inputhandler::Inputhandler(Window *window)
{
	this->window = window;
	w = false;
	a = false;
	d = false;
	s = false;

	keys[0] = false;
	keys[1] = false;
	keys[2] = false;
	keys[3] = false;
	keys[4] = false;
	keys[5] = false;
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

		if (e.type == SDL_KEYDOWN){
			if (e.key.keysym.sym == SDLK_ESCAPE){
				return false;
			}
			if (e.key.keysym.sym == SDLK_w){
				keys[0] = true;
			}
			if (e.key.keysym.sym == SDLK_a){
				keys[1] = true;
			}
			if (e.key.keysym.sym == SDLK_s){
				keys[2] = true;

			}
			if (e.key.keysym.sym == SDLK_d){
				keys[3] = true;
			}

			if (e.key.keysym.sym == SDLK_SPACE){
				keys[4] = true;
			}
			if (e.key.keysym.sym == SDLK_LSHIFT){
				keys[5] = true;
			}
		}

		if (e.type == SDL_KEYUP){
			if (e.key.keysym.sym == SDLK_w){
				keys[0] = false;
			}
			if (e.key.keysym.sym == SDLK_a){
				keys[1] = false;
			}
			if (e.key.keysym.sym == SDLK_s){
				keys[2] = false;

			}
			if (e.key.keysym.sym == SDLK_d){
				keys[3] = false;
			}
			if (e.key.keysym.sym == SDLK_SPACE){
				keys[4] = false;
			}
			if (e.key.keysym.sym == SDLK_LSHIFT){
				keys[5] = false;
			}
		}

		if (e.type == SDL_MOUSEMOTION){

			
				distX = e.motion.xrel;
			
				distY = e.motion.yrel;


		}
		else{
			distX = 0;
			distY = 0;
		}

			

			SDL_WarpMouseInWindow(window->get_window(), 200, 200);

	}
	notify();
	distX = 0;
	distY = 0;
	return true;

}

void Inputhandler::register_observer(GameObject &o){
	this->observers.push_back(&o);
}

void Inputhandler::notify(){
	for (int i = 0; i < observers.size(); i++){
		observers.at(i)->update(keys, distX, distY);
	}
}