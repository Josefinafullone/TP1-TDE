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
    // Iterator support
    typedef std::map<std::string,player>::iterator iterator;
    iterator begin();
    iterator end();
    // Const version
    iterator begin();
    iterator end();
};


#endif //GALE_SHAPLEY_TOURNAMENT_H
