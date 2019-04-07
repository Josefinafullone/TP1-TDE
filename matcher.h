#ifndef GALE_SHAPLEY_MATCHER_H
#define GALE_SHAPLEY_MATCHER_H

#include <string>
#include <vector>
#include "parser.h"
#include "player.h"
#include "tournament.h"

class matcher {
  public:
    matcher();
    ~matcher();
    void gale_shapley(std::vector<player> & v);
};


#endif //GALE_SHAPLEY_MATCHER_H
