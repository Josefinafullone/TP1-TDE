#ifndef GALE_SHAPLEY_MATCHER_H
#define GALE_SHAPLEY_MATCHER_H

#include <string>
#include <vector>
#include "parser.h"
#include "player.h"
#include "tournament.h"

class matcher {

    parser my_parser;
    tournament my_tournament;

public:
    matcher() = delete;
    ~matcher();
    matcher(long players_amount, std::string players_file);

    void createTournament();
};


#endif //GALE_SHAPLEY_MATCHER_H
