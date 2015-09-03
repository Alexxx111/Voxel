#include "Floor.h"


Floor::Floor(glm::vec3 pos) : GameObject(pos)
{
	meshs.push_back(new Mesh(pos));
}


Floor::~Floor()
{
}

