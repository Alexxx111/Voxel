#pragma once
#include "Window.h"
#include "Scenemanager.h"
#include "SDL.h"
#include <Windows.h>

class Engine
{
public:
	Engine();
	~Engine();



private:
	void loop();
	bool running;

	long now, time, secTime;

	Window* window;
	Scenemanager *manager;

};

