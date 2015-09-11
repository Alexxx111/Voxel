#include "GameObject.h"


GameObject::GameObject(glm::vec3 pos)
{
	std::cout << "GO created!\n";
	this->position = pos;

	animationState = AnimationState::STANDING;
}


GameObject::~GameObject()
{
}

glm::vec3 GameObject::get_position(){
	return this->position;
}

void GameObject::set_animation_state(AnimationState newState){
	this->animationState = newState;
}

void GameObject::update(bool keys[], int distX, int distY){
	
	//std::cout << "standard empty update is beeing ex\n";

}

void GameObject::draw(GLuint program){

	//std::cout << "standard draw is beeing ex\n";

	for (int i = 0; i < meshs.size(); i++){
		meshs.at(i)->render(program, this->angle);
	}

}