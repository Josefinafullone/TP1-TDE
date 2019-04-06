#ifndef GALE_SHAPLEY_TOURNAMENT_H
#define GALE_SHAPLEY_TOURNAMENT_H

#include <vector>
#include <map>
#include "player.h"

class tournament {

    std::map<std::string,player> players; //TODO: cambiar por mapa

public:
    /*player createPlayer(std::string file_line);*/
    void addPlayer(player aPlayer);
};


#endif //GALE_SHAPLEY_TOURNAMENT_H
