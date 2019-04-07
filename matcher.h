#ifndef GALE_SHAPLEY_MATCHER_H
#define GALE_SHAPLEY_MATCHER_H

#include <string>
#include <vector>
#include "safeStream.h"
#include "player.h"
#include "tournament.h"

class matcher {
    tournament my_tournament;

  public:
    matcher(size_t nPlayers, std::string players_file);
    ~matcher();
    void gale_shapley();
};


#endif //GALE_SHAPLEY_MATCHER_H
