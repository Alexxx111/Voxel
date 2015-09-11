#pragma once
#include "Inputhandler.h"
#include "Floor.h"
#include "Shader.h"
#include "Camera.h"
#include "Player.h"

class Scene
{
public:
	Scene(Window *window);
	~Scene();

	bool update();
	void render();

	Inputhandler *in;
	Mesh *g;

	GLuint program;
	Camera *c;
	Floor *f;
	Player *p;
	Shader*vertexShader,* fragmentShader;

	GLint viewMatrixLocation, projectionMatrixLocation;

	std::vector<GameObject*> objects;
};

