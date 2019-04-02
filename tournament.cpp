//
// Created by sebas on 3/30/2019.
//

#include "tournament.h"
#include <string>
#include <iostream>
#include <map>

player tournament::createPlayer(std::string file_line) {
    std::string delimiter = ",";
    std::string priority = file_line.substr(0, file_line.find(delimiter));
    std::string name = file_line.substr(file_line.find(delimiter)+1, file_line.find_last_of(delimiter)-2);
    std::string pref_file = file_line.substr(file_line.find_last_of(delimiter)+1, file_line.size()); //TODO: agregar al jugador
    return player(std::stoi(priority, nullptr, 10), name);
}

void tournament::addPlayer(player aPlayer) {
    players.insert(std::pair<std::string, player>(aPlayer.getName(),aPlayer));
}
