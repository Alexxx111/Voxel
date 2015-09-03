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
	
	c = new Camera(glm::vec3(0.f, 0.f, 1.f));
	f = new Floor(glm::vec3(0.f, 0.f, -4.f));

	objects.push_back(c);
	objects.push_back(f);

	in->register_observer(*c);
}


Scene::~Scene()
{
}

bool Scene::update(){
	if (!in->get_input())
		return false;


	glm::mat4 view = c->get_view();
	glm::mat4 proj = c->get_proj();

	projectionMatrixLocation = glGetUniformLocation(program, "projectionMatrix");
	viewMatrixLocation = glGetUniformLocation(program, "viewMatrix");


	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &proj[0][0]);
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &view[0][0]);

	return true;
}

void Scene::render(){

	for (int i = 0; i < objects.size(); i++){
		objects.at(i)->draw(program);
	}
	
}