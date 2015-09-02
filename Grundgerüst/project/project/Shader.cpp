#include "Shader.h"


Shader::Shader(char *path, GLenum type)
{

	shaderID = glCreateShader(type);

	std::string sourceString = get_shader_source(path);
	const GLchar *sourcePtr = sourceString.c_str();

	
	glShaderSource(shaderID, 1, &sourcePtr, NULL);

	glCompileShader(shaderID);

	check_compiling();

}


Shader::~Shader()
{
	glDeleteShader(shaderID);
}

GLuint Shader::get_shader_ID(){
	return shaderID;
}

void Shader::check_compiling(){

	GLint error = 0;

	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &error);



	if (error == GL_FALSE) {

		char msg[512];

		std::cout << "shader compiling failed!\n";
		glGetShaderInfoLog(shaderID, 512, NULL, &msg[0]);

		std::cout << msg << std::endl;

		glDeleteShader(shaderID);

		return;
	}

	std::cout << "compiling successfull!!\n";
}

std::string Shader::get_shader_source(char *path){

	std::ifstream file;

	file.open(path);

	if (!file.good()){
		std::cout << "could read file!" << std::endl; 
		return NULL;
	}

	std::string line, output;

	while (!file.eof()){
		std::getline(file, line);
		output.append(line + "\n");
	}

	file.close();

	std::cout << output << std::endl;

	return output;

}