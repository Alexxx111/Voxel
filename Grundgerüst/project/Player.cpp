#include "Player.h"

Player::Player(glm::vec3 pos) : GameObject(pos)
{
	meshs.push_back(new Mesh(pos, "..\\res\\player\\head.obj"));
	meshs.push_back(new Mesh(pos, "..\\res\\player\\torso.obj"));
	meshs.push_back(new Mesh(pos, "..\\res\\player\\hand.obj"));
	meshs.push_back(new Mesh(pos, "..\\res\\player\\handRight.obj"));
	meshs.push_back(new Mesh(pos, "..\\res\\player\\foot.obj"));
	meshs.push_back(new Mesh(pos, "..\\res\\player\\foot.obj"));


//creating walking animation
	meshs.at(0)->animations.push_back(new Animation("..\\res\\player\\head.ani"));
	meshs.at(1)->animations.push_back(new Animation("..\\res\\player\\torso.ani"));
	meshs.at(2)->animations.push_back(new Animation("..\\res\\player\\handLeft.ani"));
	meshs.at(3)->animations.push_back(new Animation("..\\res\\player\\handRight.ani"));
	meshs.at(4)->animations.push_back(new Animation("..\\res\\player\\footLeft.ani"));
	meshs.at(5)->animations.push_back(new Animation("..\\res\\player\\footRight.ani"));

//creating standing animation
	meshs.at(0)->animations.push_back(new Animation("..\\res\\player\\head_stand.ani"));
	meshs.at(1)->animations.push_back(new Animation("..\\res\\player\\torso_stand.ani"));
	meshs.at(2)->animations.push_back(new Animation("..\\res\\player\\handLeft_stand.ani"));
	meshs.at(3)->animations.push_back(new Animation("..\\res\\player\\handRight_stand.ani"));
	meshs.at(4)->animations.push_back(new Animation("..\\res\\player\\footLeft_stand.ani"));
	meshs.at(5)->animations.push_back(new Animation("..\\res\\player\\footRight_stand.ani"));

	angle = 0.f;
	orientation = glm::vec3(0.f, 0.f, -1.f);

	set_animation_state(AnimationState::STANDING);
}


Player::~Player()
{
}

void Player::update(bool keys[10], int distX, int distY){

	if (keys[6]){
	
		meshs.at(0)->animations.at(0)->toggle_animation();
	}
	if (keys[9]){ // left key pressed
		
		angle += 0.05f;

		orientation = orientation * glm::mat3(glm::rotate(-0.05f, glm::vec3(0.f, 1.f, 0.f)));
	
		set_animation_state(AnimationState::STANDING);
	}

	if (keys[10]){ // right key pressed
	
		angle -= 0.05f ;

		orientation = orientation * glm::mat3(glm::rotate(0.05f, glm::vec3(0.f, 1.f, 0.f)));

		set_animation_state(AnimationState::STANDING);
	}

	if (keys[8]){
		
		this->position += orientation *0.04f;
		set_animation_state(AnimationState::WALKING);
	}
	

	if (keys[7]){ 

		this->position -= orientation * 0.04f;
		set_animation_state(AnimationState::WALKING);	
	}
	
	if(!keys[7] && !keys[8]){
		set_animation_state(AnimationState::STANDING);
	}

	// setze die position aller teile des players auf seine neue position:
	for (int i = 0; i < meshs.size(); i++){
		meshs.at(i)->set_position(this->position);
	}

}

void Player::set_animation_state(AnimationState newState){

		for (int i = 0; i < meshs.size(); i++){

			meshs.at(i)->animations.at(animationState)->stop_animation();
			meshs.at(i)->animations.at(newState)->start_animation();

		}
	
	this->animationState = newState;
}