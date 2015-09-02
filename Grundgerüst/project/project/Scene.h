#pragma once
#include "Inputhandler.h"
#include "GameObject.h"
#include "Shader.h"

class Scene
{
public:
	Scene(Window *window);
	~Scene();

	bool update();
	void render();

	Inputhandler *in;
	GameObject *g;

	GLuint program;
	Shader*vertexShader,* fragmentShader;
};

