#pragma once
#include "glew.h"
#include "glm.hpp"
#include <vector>
#include <iostream>


class Vertex{
public:

	Vertex::Vertex(glm::vec3 pos, glm::vec3 color, glm::vec3 normal){
		this->color = color;
		this->position = pos;
		this->normal = normal;
	}

private:

	glm::vec3 color;
	glm::vec3 position;
	glm::vec3 normal;


};

class GameObject
{
public:
	GameObject();
	~GameObject();

	void render();
	void update();

private:
	
	GLuint vbo, vao, ibo;
	std::vector<GLushort> index;
	std::vector<Vertex> verts;



};

