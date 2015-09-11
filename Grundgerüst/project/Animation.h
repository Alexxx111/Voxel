#pragma once
#include "glm\glm.hpp"
#include "glm\gtx\transform.hpp"
#include "SDL.h"
#include <map>
#include <vector>

#include <iostream>

class Animation
{
public:
	Animation(char*path); // der path gibt an, wo die .ani datei liegt
	~Animation();

	glm::mat4 get_transform_matrix();

	void start_animation();		// setzt playing = true
	void stop_animation();		// setzt playing  = fasle
	void toggle_animation();	// wechselt zwischen plying = true und = false
	void load_animation(char *path); // lädt eine .ani datei

	bool isPlaying();	//returnt den wert von playing -> um festzustellen ob die Animation läuft

private:

	int duration;	// gibt die länge der animation an -> um den prozentwert zu berechnen
	int now;		// gibt den aktuellen frame der animation an

	bool playing;	//gibt an ob die Animation läuft

	// enthält die keyframes, dabei werden für alle festgelegten zeiten:
	// pro keyframe wird eine translate und eine rotation Matrix gespeichert
	std::map<int, std::pair<glm::mat4,glm::mat4> >keyframes; 

	// liste aller zeiten an denen keyframes festgelegt sind
	std::vector<int> keys;

	// die akutelle, interpolierte Transformationsmatrix
	glm::mat4 transformMatrix;

	// index der aktuellen "unteren" matrix
	int currentDowner;

	/* 
	am anfang ist currentDowner = 0, dann 1, und dann 2
	[] .. matrix

	1. [] --->	[] ---	[] ---	[] 
	2. [] ---	[] ---> [] ---	[]
	3. [] ---	[] ---	[] ---> []
	*/

	// enthält die positionen der keyframes
	std::vector<glm::vec3> positions;

	// enthält die rotationen der keyframes
	std::vector<std::pair<float, glm::vec3>> rotations;

	// gleiches prinzip wie mit currentDowner,
	// es wird zwischen einer downer und upper matrix interpoliert, daraus ergibt sich die transformationsmatrix
	// es wird von der downer zur upper matrix interpoliert
	glm::mat4 upperTrans, downerTrans, upperRot, downerRot;
};

