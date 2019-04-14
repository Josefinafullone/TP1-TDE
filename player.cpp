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
	partner = nullptr;
	partner_pref = 0;
}

player::player(const std::string& str) {
    name = str;
    partner = nullptr;
    partner_pref = 0;
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

void player::partnerUp(player *p, size_t pref, size_t my_pref) {
	std::cout << this->getName() << " and " << p->getName() << " are partners" << std::endl;
	partner = p;
	partner_pref = pref;
	p->partner = this;
	p->partner_pref = my_pref;
}

bool player::prefers(size_t p) {
	if (this->isFree())
		return true;

	size_t new_partner_priority = p;
	size_t actual_partner_priority = this->partner_pref;

	return new_partner_priority < actual_partner_priority;
}

player::~player(){}

void player::setPreferences(){
	std::fstream file;
	std::string name,aux;
	int preference;
	std::pair<size_t, std::string> pair;

	file.open(file_dir);
	if(!file.is_open()){
		std::cerr << "Error opening preferences file of: " << this->getName() << std::endl; //tmb super hardcodeado
		exit(1);
	}

	while(!file.eof()){
		std::getline(file,name,',');
		if(file.fail()){
			std::cerr << "Error preferences file format of: " << this->getName() << std::endl; //tmb super hardcodeado
			exit(1);
		}
		file >> preference;
		if(file.fail()){
			std::cerr << "Error preferences file format of: " << this->getName() << std::endl; //tmb super hardcodeado
			exit(1);
		}
		std::getline(file,aux); //clear line
		pair = make_pair(preference,name);
		player_preferences.push_back(pair);
	}
	sort(player_preferences.begin(),player_preferences.end(),sortByPreferences);
	file.close();
}

void player::losePartner() {
	std::cout << this->getName() << " and " <<
			  this->getPartner()->getName() << " are no longer partners" << std::endl;
	this->partner->partner = nullptr;
	this->partner->partner_pref = 0;
	this->partner = nullptr;
	this->partner_pref = 0;
}

size_t player::getPartnerPref() const{
	return partner_pref;
}


size_t player::getPriorityOf(player *pPlayer) {
	size_t pref = 0;
	for (const auto &each : this->getPlayer_preferences()) {
		if (pPlayer->getName() == each.second){
			pref = each.first;
			break;
		}
	}
	return pref;
}
