#pragma once
#include "glm\glm.hpp"
#include "glew.h"
#include "Mesh.h"

#include <iostream>

enum AnimationState{
	WALKING, STANDING
};

class GameObject
{
public:
	GameObject(glm::vec3 pos);
	~GameObject();

	glm::vec3 get_position();

	virtual void update(bool keys[10], int distX, int distY);
	virtual void draw(GLuint program);

	virtual void set_animation_state(AnimationState newState);

protected:
	glm::vec3 position;
	glm::vec3 orientation;
	float angle;

	std::vector<Mesh*> meshs;
	AnimationState animationState;

};

