#include "Animation.h"
#include <fstream>
#include <string>

Animation::Animation(char *path)
{

	playing = true; // die Animation wird standardmäßig auf playing gesetzt
	 
	load_animation(path); // die keyframes werden aus der .ani datei geladen

	// setzt die startKeyframes
	downerTrans = keyframes.at(keys.at(0)).first; 
	upperTrans = keyframes.at(keys.at(1)).first;

	downerRot = keyframes.at(keys.at(0)).second;
	upperRot = keyframes.at(keys.at(1)).second;

	// setzt den aktullen frame auf 0
	now = 0;
	// setzt den aktuellen index der unteren matrix auf 0 
	currentDowner = 0;
}


Animation::~Animation()
{
}

bool Animation::isPlaying(){
	return playing;
}

void Animation::toggle_animation(){
	playing = !playing;
}

void Animation::stop_animation(){
	playing = false;
}


glm::mat4 Animation::get_transform_matrix(){

	if (playing) // der frame wird nur dann erhöht, wenn die animation laufen soll
		now++;

	now = now % duration; // damit der aktuelle frame immer im bereich der animation liegt

	// percent gibt an bei wieviel prozent der aktuelle frame zwischen den keys der oberen und unteren matrix liegt
	// immer zwischen 0 - 1 (Interpolationswert)
	float percent = (float(now - keys.at(currentDowner))) / (float((keys.at(currentDowner + 1) - keys.at(currentDowner))));
	
	// Berechnung der endgültigen trasformationsMatrix am aktuellen frame (wahrscheinlich sind da fehler drin, funktioniert für den moment aber recht gut :D)
	transformMatrix = (downerTrans * glm::translate(glm::mat4(), glm::vec3((-percent))*positions.at(currentDowner)) *glm::translate(upperTrans, glm::vec3((-1 + percent))*positions.at(currentDowner + 1)))
		
		* ((glm::rotate(rotations.at(currentDowner).first*percent, rotations.at(currentDowner).second))*(glm::rotate(rotations.at(currentDowner + 1).first*(1 - percent), rotations.at(currentDowner + 1).second)));

	// wenn percent größer als (eigentlich 1) 0.92 wird, müssen upper und downer Matrix neu gewählt werden
	// aus einem noch nicht ganz gekärten grund funktioniert 1.f nicht wirklich, und manche werte für duration können hier probleme verursachen!
	// das hier ist quasi der schwachpunkt der geschichte, ich muss noch einen weg finden zu berechnen wie man die 0.92 unabhänging von der duration machen kann.
	if (percent >= 0.92f){ 
		if (currentDowner + 2 < keys.size()){ // schauen ob ich den index einfach erhöhen kann, oder ob dann der vector kein element mehr hat
			currentDowner++; // wenn man einfach die indexe um eins nach oben rutschen kann ++
		}
		else{
			currentDowner = 0;	// zurücksetzen auf 0 -> es wird wieder zwischen dem 0ten und 1ten keyframe interpoliert
		}
		
		// upper und downer matrizen nach dem neuen currentdowner-wert anpassen
		downerRot = keyframes.at(keys.at(currentDowner )).second;
		upperRot = keyframes.at(keys.at(currentDowner + 1)).second;

		upperTrans = keyframes.at(keys.at(currentDowner + 1)).first;
		downerTrans = keyframes.at(keys.at(currentDowner)).first;

	}
						  
	return this->transformMatrix; // returnt die berechnete matrix
}

void Animation::start_animation(){
	playing = true;
}

void Animation::load_animation(char*path){

	/*
		den part hier würde ich mal so zusammenfassen:

		die .ani datei wird geladen und zeile für zeile ausgelesen, dabei wird immer geschaut ob die zeile mit einem festgelegten "indicator" beginnt (per pattern-matching, bin ich ein fan von :D)
		"indicator" ist: 
		+ dur, für duration
		+ key, für den beginn eines neuen keyframes, gefolgt von der zeit zu er dargestellt werden soll
		+ p, für die position des akutellen keyframes
		+ r, für die rotation des aktuellen keyframes

		erst werden alle ausgelesenen positionen und rotationen in die vectoren geladen, und danach werden damit die keyframes gefüllt
	*/

	std::fstream aniFile;

	aniFile.open(path);

	if (!aniFile.good()){
		std::cout << "ERROR: .ani file couldnt be opened! filename: " << path << "\n";
	}

	std::string line;

	while (!aniFile.eof()){

		std::getline(aniFile, line);

		if (line.substr(0, 3) == "dur"){
			sscanf_s(line.c_str(), "dur %i", &duration);
		}

		if (line.substr(0, 3) == "key"){
			int keyTime;
			sscanf_s(line.c_str(), "key %i",&keyTime);
			keys.push_back(keyTime);
			std::cout << "keytime: " << keyTime << "\n";
		}

		if (line.substr(0, 2) == "p "){
			float x,y,z;
			sscanf_s(line.c_str(), "p %f/%f/%f", &x, &y,&z);
			positions.push_back(glm::vec3(x, y, z));
			std::cout << "p.x: " << x << "p.y: " << y << "p.z: " << z << "\n";
		}

		if (line.substr(0, 2) == "r "){
			float x, y, z, angle;
			sscanf_s(line.c_str(), "r %f/%f/%f/%f", &angle, &x, &y, &z);
			rotations.push_back({ angle, glm::vec3(x, y, z) });
		}
	}

	for (int i = 0; i < keys.size(); i++){

		std::cout << "pushback keyframe!\n";

		glm::mat4 rot = glm::rotate(rotations.at(i).first, rotations.at(i).second);

		keyframes.insert({ keys.at(i), std::pair<glm::mat4, glm::mat4>(glm::translate(glm::mat4(), positions.at(i)), rot) });

	}

}