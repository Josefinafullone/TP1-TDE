//
// Created by sebas on 3/30/2019.
//

#include "tournament.h"
#include <string>
#include <fstream>
#include <map>

tournament::tournament(){}


tournament::~tournament(){}


void tournament::addPlayer(player aPlayer) {
    players.insert(std::pair<std::string, player>(aPlayer.getName(),aPlayer));
}

tournament::tournament(size_t nPlayers, std::string fileName){
   	player aPlayer;
    std::fstream file;
    file.open(file_dir);

    while (file >> aPlayer) { //probar ciclo
    	if(!file.good()){
    		std::cerr << "Error database" << std::endl; //super hardcodeado
    		exit(1);
    	}
        aPlayer.setPreferences();
        addPlayer(aPlayer);
        list.push_back(&aPlayer);
	}
	return;
}

std::vector<player*>& tournament::getList(){
    	return list;
}