#pragma once
#include "glew.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Vertex{
public:

	Vertex::Vertex(glm::vec3 pos, glm::vec3 color, glm::vec3 normal){
		this->position = pos;
		this->color = color;
		this->normal = normal;
	}

private:
	glm::vec3 position;

	glm::vec3 color;
	glm::vec3 normal;


};

class Mesh
{
public:
	
	Mesh(glm::vec3 pos);
	~Mesh();

	void render(GLuint program);
	void load_obj(char*path);


	glm::mat4 get_model_matrix();

protected:
	glm::vec3 position;

private:
	
	GLuint vbo, vao, ibo;
	std::vector<GLushort> index;
	std::vector<Vertex> verts;

	glm::mat4 model;

	GLint modelMatrixLocation;
};

