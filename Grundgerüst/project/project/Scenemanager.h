#pragma once
#include "Scene.h"

class Scenemanager
{
public:
	Scenemanager(Window *window);
	~Scenemanager();

	void render();
	bool update();

private:
	Scene *currentScene;

};

