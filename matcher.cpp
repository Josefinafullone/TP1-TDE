#include <utility>

#include <utility>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include "matcher.h"

matcher::matcher(long players_amount, std::string players_file): my_parser(std::move(players_file)){
    matcher::my_tournament = tournament();
}

matcher::~matcher() {
}

void matcher::createTournament(size_t const & nPlayers) {
    player aPlayer(nPlayers);
    while (player_file >> aPlayer) { //probar ciclo
    	if(!player_file.good()){
    		std::cerr << "Error database" << std::endl; //super hardcodeado
    		exit(1);
    	}
        aPlayer.setPreferences();
        my_tournament.addPlayer(aPlayer);
    }
    return;
}

