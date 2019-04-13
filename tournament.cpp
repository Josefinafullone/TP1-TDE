#include "tournament.h"
#include <string>
#include <fstream>
#include <map>

tournament::tournament() {}

tournament::~tournament(){}

void tournament::addPlayer(player* aPlayer) {
    players.insert(std::pair<std::string, player*>(aPlayer->getName(),aPlayer));
}

void tournament::findPartner(player* aPlayer) {
	for (auto p : aPlayer->getPlayer_preferences()) {
		player* candidate = players[p.second];
		size_t my_pref = candidate->getPriorityOf(aPlayer);
		 if (candidate->isFree()) {
			 aPlayer->partnerUp(candidate, p.first, my_pref);
			return;
		} else {
			if (candidate->prefers(my_pref)) {
				candidate->losePartner();
				aPlayer->partnerUp(candidate, p.first, my_pref);
				return;
			}
		}
	}
}

tournament::tournament(size_t nPlayers, std::string fileName) : players_file(fileName){
   	player * aPlayer = new player;
    std::fstream file;
    file.open(players_file);
    size_t i = 0;

    while (file >> *aPlayer) {
        aPlayer->setPreferences();
        addPlayer(aPlayer);
        if (i < nPlayers/2)   //guardo solo la mitad mejor rankeada
            proposers.push_back(aPlayer);
        i++;
        aPlayer = new player;
	}
}

bool tournament::allMatched() {
	for (const auto &each : proposers){
		if (!each->getPartner())
			return false;
	}
	return true;
}

const std::vector<player*>& tournament::getProposers(){
   	return proposers;
}
