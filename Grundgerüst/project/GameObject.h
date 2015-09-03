#pragma once
#include "glm\glm.hpp"
#include "glew.h"
#include "Mesh.h"
#include <iostream>

class GameObject
{
public:
	GameObject(glm::vec3 pos);
	~GameObject();

	glm::vec3 get_position();

	virtual void update(bool keys[4], int distX, int distY);
	virtual void draw(GLuint program);



protected:
	glm::vec3 position;
	std::vector<Mesh*> meshs;
};

