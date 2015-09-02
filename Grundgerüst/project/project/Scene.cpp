#include "Scene.h"


Scene::Scene(Window *window)
{

	program = glCreateProgram();

	vertexShader = new Shader("..\\res\\vertex.glsl", GL_VERTEX_SHADER);
	fragmentShader = new Shader("..\\res\\fragment.glsl", GL_FRAGMENT_SHADER);

	glAttachShader(program, vertexShader->get_shader_ID());
	glAttachShader(program, fragmentShader->get_shader_ID());

	glLinkProgram(program);

	glUseProgram(program);


	in = new Inputhandler(window);
	g = new GameObject;

}


Scene::~Scene()
{
}

bool Scene::update(){
	return in->get_input();
		
}

void Scene::render(){
	g->render();
}