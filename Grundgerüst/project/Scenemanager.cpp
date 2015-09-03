#include "Scenemanager.h"


Scenemanager::Scenemanager(Window *window)
{
	currentScene = new Scene(window);

}


Scenemanager::~Scenemanager()
{
}

void Scenemanager::render(){
	currentScene->render();
}

bool Scenemanager::update(){
	return currentScene->update();
}