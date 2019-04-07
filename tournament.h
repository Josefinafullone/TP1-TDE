#ifndef GALE_SHAPLEY_TOURNAMENT_H
#define GALE_SHAPLEY_TOURNAMENT_H

#include <vector>
#include <map>
#include "player.h"

class tournament {

    std::map<std::string,player> players;
    std::vector<player*> list; // paso punteros para usar los jugadores ya guardados en players y no tener que buscarlos en map al iterar
   	std::string file_dir;

public:
    void addPlayer(player aPlayer);
    tournament();
    ~tournament();
    tournament(size_t nPlayers, std::string fileName);
    std::vector<player*>& getList();

};
#endif //GALE_SHAPLEY_TOURNAMENT_H
