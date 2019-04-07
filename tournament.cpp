#include "tournament.h"
#include <string>
#include <fstream>
#include <map>

tournament::tournament() {}

tournament::~tournament(){}

void tournament::addPlayer(player aPlayer) {
    players.insert(std::pair<std::string, player>(aPlayer.getName(),aPlayer));
}

void tournament::findPartner(player* aPlayer) {
	for (auto p : aPlayer->getPlayer_preferences()) {
		player candidate = players[p.second];	//chequear que objeto player en mapa sea mismo que el vector!
		if (candidate.isFree()) {
			aPlayer->partnerUp(&candidate);
			break;
		} else {
			std::string actual_partner = candidate.getPartner()->getName();
			if (candidate.prefers(p)) {
				candidate.losePartner();
				aPlayer->partnerUp(&candidate);
				break;
			}
		}
	}
}

tournament::tournament(size_t nPlayers, std::string fileName) : players_file(fileName){
   	player aPlayer;
    std::fstream* file = players_file.getStream();	//lo arme con el safeStream (ex parser) pa chequear que
    												//funcionaba con eso (de curioso), en la lectura del otro archivo
    												// no lo hice, de cualqueria de las 2 formas me da igual
    size_t i = 0;

    while (*file >> aPlayer) {
    	if(!file->good()){
    		std::cerr << "Error database" << std::endl; //super hardcodeado
    		exit(1);
    	}
        aPlayer.setPreferences();
        addPlayer(aPlayer);
        if (i < nPlayers/2)   //guardo solo la mitad mejor rankeada
            proposers.push_back(&aPlayer);
        i++;
	}
}

bool tournament::allMatched() {
	for (const auto &each : proposers){
		if (!each->getPartner())
			return false;
	}
	return true;
}

std::vector<player*>& tournament::getProposers(){
    	return proposers;
}

