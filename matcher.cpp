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

void matcher::createTournament() {
    std::string pj;
    while (std::getline(*(my_parser.getStream()), pj)) {
        player aPlayer = my_tournament.createPlayer(pj);
        std::cout <<"aPlayer.rank = "<< aPlayer.getRanking() <<"; aPlayer.name = "<< aPlayer.getName() << std::endl;
        my_tournament.addPlayer(aPlayer);
    }
}

