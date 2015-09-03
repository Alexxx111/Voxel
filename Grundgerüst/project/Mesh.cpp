#include "Mesh.h"

Mesh::Mesh(glm::vec3 pos)
{
	

	this->position = pos;

	load_obj("..\\res\\cube.obj");

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)* verts.size(), &verts[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (void*)(3 * (sizeof(GLfloat))));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (void*)(6 * (sizeof(GLfloat))));

	glBindVertexArray(0);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort)*index.size(), &index[0], GL_STATIC_DRAW);


}


Mesh::~Mesh()
{
	glDeleteBuffers(1,&ibo);
	glDeleteBuffers(1, &vao);
	glDeleteBuffers(1, &vbo);
}

void Mesh::render(GLuint program){

	
	//std::cout << "rendering mesh\n";

	model = glm::translate(glm::mat4(), this->position);

	modelMatrixLocation = glGetUniformLocation(program, "modelMatrix");

	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &model[0][0]);


	glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	
	glDrawElements(GL_TRIANGLES, index.size(), GL_UNSIGNED_SHORT, (void*)0 );

	

	
}



glm::mat4 Mesh::get_model_matrix(){

	

	return this->model;
}

void Mesh::load_obj(char*path){

	std::vector<glm::vec3> positions;
	std::vector<glm::vec3> normals;

	std::ifstream objFile;

	objFile.open(path);

	if (!objFile.good()){

		std::cout << "ERROR: obj file couldnt be read\n";

	}

	std::string line;

	int i = 0;

	while (!objFile.eof()){

		std::getline(objFile, line);

		if (line.substr(0, 2) == "v "){

			float x, y, z;

			sscanf_s(line.c_str(), "v %f %f %f", &x, &y, &z);

			positions.push_back(glm::vec3(x, y, z));
			
		}
	
	
		if (line.substr(0, 2) == "vn"){

			float x, y, z;

			sscanf_s(line.c_str(), "vn %f %f %f", &x, &y, &z);

			normals.push_back(glm::vec3(x, y, z));
		}

		if (line.substr(0, 2) == "f "){
		

			int v1, v2, v3, normal;

			sscanf_s(line.c_str(), "f %i//%i %i//%i %i//%i", &v1, &normal, &v2, &normal, &v3, &normal);

		


			verts.push_back(Vertex(positions.at(v1-1), glm::vec3(0.4f, 0.4f, 1.), normals.at(normal-1)));
			verts.push_back(Vertex(positions.at(v2-1), glm::vec3(0.4f, 0.4f, 0.8f), normals.at(normal-1)));
			verts.push_back(Vertex(positions.at(v3-1), glm::vec3(0.4f, 0.4f, 0.6f), normals.at(normal-1)));

			index.push_back(i);
			i++;
			index.push_back(i);
			i++;
			index.push_back(i);
			i++;
			
			
		}


	}

}