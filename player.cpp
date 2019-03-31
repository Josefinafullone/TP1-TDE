#include <utility>
#include "player.h"

player::player(int rank, std::string name) {
    this->ranking = rank;
    this->name = std::move(name);
}

int player::getRanking() const {
    return ranking;
}

const std::string &player::getName() const {
    return name;
}

player::~player() {
}
