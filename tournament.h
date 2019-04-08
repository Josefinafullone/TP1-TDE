#ifndef GALE_SHAPLEY_TOURNAMENT_H
#define GALE_SHAPLEY_TOURNAMENT_H

#include <vector>
#include <map>
#include "player.h"
#include "safeStream.h"

class tournament {

    std::map<std::string,player> players;
    std::vector<player*> proposers; // paso punteros para usar los jugadores ya guardados en players y no tener que buscarlos en map al iterar
   	safeStream players_file;

public:
    tournament();
    ~tournament();
	bool allMatched();
	void addPlayer(player aPlayer);
	void findPartner(player * aPlayer);
	tournament(size_t nPlayers, std::string fileName);
    const std::vector<player*>& getProposers();

};
#endif //GALE_SHAPLEY_TOURNAMENT_H
