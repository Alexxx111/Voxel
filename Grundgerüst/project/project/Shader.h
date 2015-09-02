#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "glew.h"

class Shader
{
public:
	Shader(char *path, GLenum type);
	~Shader();

	GLuint get_shader_ID();

private:
	void check_compiling();
	std::string get_shader_source(char* path);

	GLuint shaderID;

};

