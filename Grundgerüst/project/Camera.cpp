#include "Camera.h"


Camera::Camera(glm::vec3 pos) : GameObject(pos)
{
	lookAt = glm::vec3(0.f, 0.f, -1.f);
	up = glm::vec3(0.f, 1.f, 0.f);

	speed = 0.2f;
}


Camera::~Camera()
{
}

glm::mat4 Camera::get_proj(){

	this->proj = glm::perspective(45.f, 1.f, 0.1f, 50.f);

	return this->proj;
}

glm::mat4 Camera::get_view(){

	view = glm::lookAt(
		this->position,
		this->lookAt + position,
		this->up
	);

	return this->view;
}

void Camera::update(bool keys[], int distX, int distY){
	
	

	if (distX > 0){
		glm::mat4 rot = glm::rotate(-0.002f * distX, up);
		this->lookAt = this->lookAt * glm::mat3(rot);
	}
	if (distX < 0){
		glm::mat4 rot = glm::rotate(-0.002f * distX, up);
		this->lookAt = this->lookAt * glm::mat3(rot);
	}
	
	if (distY > 0){
		glm::mat4 rot = glm::rotate(0.002f * distY, glm::cross(up, lookAt));
		this->lookAt = this->lookAt * glm::mat3(rot);
	}
	if (distY < 0){
		glm::mat4 rot = glm::rotate(0.002f * distY, glm::cross(up, lookAt));
		this->lookAt = this->lookAt * glm::mat3(rot);
	}
	if (keys[0]){ //w
		this->position += lookAt * speed;
	}
	if (keys[2]){ //a
		this->position -= lookAt * speed;
	}
	if (keys[1]){ //s
		this->position -= glm::cross(lookAt,up) * speed;
	}
	if (keys[3]){ //d
		this->position += glm::cross(lookAt,up) * speed;
	}


	if (keys[4]){ //space
		this->position += up * speed;
	}
	if (keys[5]){ //shift
		this->position -= up * speed;
	}


}