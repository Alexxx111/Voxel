#include "Engine.h"

#ifdef _WIN32
#undef main
#endif

Engine::Engine()
{
	this->running = true;

	window = new Window(400, 400);

	GLint er = glewInit();
	if (er != GLEW_OK) {
		std::cout << "Glew not okay! " ;
		exit(EXIT_FAILURE);
	}



	manager = new Scenemanager(window);

	glEnable(GL_DEPTH_TEST);

	now = SDL_GetTicks();
	time = SDL_GetTicks();
	secTime = SDL_GetTicks();

	loop();
}


Engine::~Engine()
{
}

void Engine::loop(){

	int fps = 0;

	while (running){

		now = SDL_GetTicks();

		if (now - 17 > time){
			time = now;

			if (!manager->update())
				running = false;


			window->clear();

			manager->render();

			window->flip();

			fps++;
		}
		else{
			Sleep(1);
		}
		
		if (now - 1000 > secTime){
			secTime = now;
			std::cout << "fps: " << fps << "\n";
			fps = 0;
		}

	}

}

int main(){

	Engine e;


	return 0;
}