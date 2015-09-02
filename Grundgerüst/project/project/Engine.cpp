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

	loop();
}


Engine::~Engine()
{
}

void Engine::loop(){

	while (running){

		if (!manager->update())
			running = false;


		window->clear();

		manager->render();

		window->flip();

	}

}

int main(){

	Engine e;


	return 0;
}