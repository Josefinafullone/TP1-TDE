#include <utility>
#include "player.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

player::player(){
	file_dir = name = "";
	ranking = 0;
}

player::player(const int & rank, const std::string & str) {
   	ranking = rank;
    name = str;
}

int player::getRanking() const {
    return ranking;
}

const std::string & player::getName() const {
    return name;
}

player::~player() {
}

player::player(size_t nPlayers){
	std::vector<std::string> aux(nPlayers);
	player_preferences = aux;
}


player::setPreferences(){
	std::fstream file;
	std::string name;
	size_t preference;

	file.open(file_dir);
	if(!file.good()){
		std::cerr << "Error opening preferences file" << std::endl; //tmb super hardcodeado
		exit(1);
	}

	while(!file.eof()){
		std::getline(file,name,",");
		if(!file.good()){
			std::cerr << "Error preferences file format" << std::endl; //tmb super hardcodeado
			exit(1);
		}
		file >> preference;
		if(!file.good()){
			std::cerr << "Error preferences file format" << std::endl; //tmb super hardcodeado
			exit(1);
		}

		player_preferences[ranking] = name; //O(1)
	}
	make_heap(player_preferences.begin(),player_preferences.end());  //O(3n)
	return;
}

	

