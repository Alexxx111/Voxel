#include "GameObject.h"


GameObject::GameObject()
{
	verts.push_back(Vertex(glm::vec3(0.1f, 1.f, -2.f), glm::vec3(1.f, 0.f, 0.f), glm::vec3(1.f, 0.f, 0.f)));
	verts.push_back(Vertex(glm::vec3(0.f, -1.f, 0.f), glm::vec3(1.f, 0.f, 0.f), glm::vec3(1.f, 0.f, 0.f)));
	verts.push_back(Vertex(glm::vec3(1.f, 1.f, 0.f), glm::vec3(1.f, 0.f, 0.f), glm::vec3(1.f, 0.f, 0.f)));
	verts.push_back(Vertex(glm::vec3(1.f, -1.f, 0.f), glm::vec3(1.f, 0.f, 0.f), glm::vec3(1.f, 0.f, 0.f)));
	

	index = { 0,1,2};

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)* verts.size(), &verts[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float)));

	glBindVertexArray(0);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort)*index.size(), &index[0], GL_STATIC_DRAW);


}


GameObject::~GameObject()
{
	glDeleteBuffers(1,&ibo);
	glDeleteBuffers(1, &vao);
	glDeleteBuffers(1, &vbo);
}

void GameObject::render(){
	
	std::cout << "xee\n" << std::endl;

	glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	
	glDrawElements(GL_TRIANGLES, index.size(), GL_UNSIGNED_SHORT, (void*)0 );

	
}
