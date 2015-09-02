#pragma once
#include "Window.h"

class Inputhandler
{
public:
	Inputhandler(Window *window);
	~Inputhandler();

	bool get_input();

private:
	Window *window;

	

};

