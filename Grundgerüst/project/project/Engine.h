#pragma once
#include "Window.h"
#include "Scenemanager.h"

class Engine
{
public:
	Engine();
	~Engine();



private:
	void loop();
	bool running;

	Window* window;
	Scenemanager *manager;

};

