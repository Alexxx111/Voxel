#pragma once
#include "glew.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "Animation.h"

#include <random>
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
	
	Mesh(glm::vec3 pos, char* path);
	~Mesh();

	void render(GLuint program, float angle);
	void load_obj(char*path);

	void set_position(glm::vec3 pos);
	glm::mat4 get_model_matrix();

	std::vector<Animation*> animations;

	glm::vec3 orientation;

	float rotation;

protected:
	glm::vec3 position;

private:
	
	GLuint vbo, vao, ibo;
	std::vector<GLushort> index;
	std::vector<Vertex> verts;

	glm::mat4 model;


	GLint modelMatrixLocation;
};

