#include <utility>
#include "player.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

bool sortByPreferences(const pair<size_t,std::string> & p1, const pair<size_t,std::string> & p2){
	return p1.first < p2.first;
}

player::player(){
	file_dir = name = "";
    matched = false;
    player_preferences = new std::vector< std::pair<size_t,std::string> >;
}

player::player(const std::string & str) {
    name = str;
    matched = false;
}

const std::string & player::getName() const {
    return name;
}

player::~player() {
	delete player_preferences;
}

void player::setPreferences(){
	std::fstream file;
	std::string name;
	size_t preference;
	std::pair<size_t, std::string> pair;

	file.open(file_dir);
	if(!file.good()){
		std::cerr << "Error opening preferences file" << std::endl; //tmb super hardcodeado
		exit(1);
	}

	while(!file.eof()){
		std::getline(file,name,',');
		if(!file.good()){
			std::cerr << "Error preferences file format" << std::endl; //tmb super hardcodeado
			exit(1);
		}
		file >> preference;
		if(!file.good()){
			std::cerr << "Error preferences file format" << std::endl; //tmb super hardcodeado
			exit(1);
		}
		pair = make_pair(preference,name);
		player_preferences->push_back(pair);
	}
	make_heap(player_preferences->begin(),player_preferences->end(),sortByPreferences);  //O(3n)
	return;
}

bool player::isMatched(){
	return matched;
}

	

