#pragma once
#include "Window.h"
#include "GameObject.h"
#include <vector>

class Inputhandler
{
public:
	Inputhandler(Window *window);
	~Inputhandler();

	void register_observer(GameObject &o);
	void notify();

	bool get_input();

	bool w, a, s, d;
	int distX, distY;

private:
	Window *window;

	std::vector<GameObject*> observers;

	bool keys[6];
};

