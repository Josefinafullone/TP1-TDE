#ifndef GALE_SHAPLEY_PARSER_H
#define GALE_SHAPLEY_PARSER_H

#include <fstream>
#include "player.h"

class safeStream {

    std::fstream* myfile;

public:

    safeStream();
    explicit safeStream(std::string file_path);
    std::fstream* getStream();
    ~safeStream();
};

#endif //GALE_SHAPLEY_PARSER_H
