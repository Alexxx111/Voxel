#pragma once
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtx\transform.hpp"

#include "GameObject.h"

class Camera : public GameObject{

public:
	Camera(glm::vec3 pos);
	~Camera();

	glm::mat4 get_view();
	glm::mat4 get_proj();

	void update(bool keys[], int mx, int my) override;

private:

	glm::mat4 view;
	glm::mat4 proj;

	glm::vec3 lookAt;
	glm::vec3 up;

	float speed;
};