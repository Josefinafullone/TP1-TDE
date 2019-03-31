#ifndef GALE_SHAPLEY_PLAYER_H
#define GALE_SHAPLEY_PLAYER_H

#include <string>

class player {
    int ranking;
    std::string name;

public:
    int getRanking() const;
    const std::string &getName() const;

    player(int rank, std::string name);
    ~player();
};


#endif //GALE_SHAPLEY_PLAYER_H
