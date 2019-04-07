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
	player_preferences = std::vector< std::pair<size_t,std::string> >();
	partner = nullptr;
}

player::player(const std::string& str) {
    name = str;
    partner = nullptr;
}

const std::string& player::getName() const {
    return name;
}

player *player::getPartner() const {
	return partner;
}

bool player::isFree(){
	return partner == nullptr;
}

const vector<pair<size_t, string>> &player::getPlayer_preferences() const {
	return player_preferences;
}

void player::partnerUp(player *p) {
	std::cout << this->getName() << " and " << p->getName() << " are partners" << std::endl;
	partner = p;
	p->setPartner(this);
}

bool player::prefers(pair<size_t, string> p) {
	if (this->isFree())
		return true;

	size_t new_partner_priority = p.first;
	size_t actual_partner_priority = 0;
	std::string actual_partner = this->getPartner()->getName();
	for (const auto &each : this->getPlayer_preferences()){
		if (actual_partner == each.second) {
			actual_partner_priority = each.first;
			break;
		}
	}

	return new_partner_priority < actual_partner_priority;
}

player::~player() {
//	delete player_preferences;
}

void player::setPartner(player *partner) {
	player::partner = partner;
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
		file >> preference;	//hay quilombo con los /r/n a partir del segundo nombre
		if(!file.good()){
			std::cerr << "Error preferences file format" << std::endl; //tmb super hardcodeado
			exit(1);
		}
		pair = make_pair(preference, name);
		player_preferences.push_back(pair);
	}
	make_heap(player_preferences.begin(),player_preferences.end(),sortByPreferences);  //O(3n)
}

void player::losePartner() {
	std::cout << this->getName() << " and " <<
			  this->getPartner()->getName() << " are no longer partners" << std::endl;
	this->partner->partner = nullptr;
	this->partner = nullptr;
}

