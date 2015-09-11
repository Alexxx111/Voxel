#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(glm::vec3 pos);
	~Player();

	void update(bool keys[10], int distX, int distY) override;
	void set_animation_state(AnimationState newState) override;
};

