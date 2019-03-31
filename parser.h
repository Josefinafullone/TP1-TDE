#ifndef GALE_SHAPLEY_PARSER_H
#define GALE_SHAPLEY_PARSER_H

#include <fstream>
#include "player.h"

class parser {

    std::fstream* myfile;

public:

    parser(std::string file_path);
    std::fstream* getStream();
    ~parser();
};

#endif //GALE_SHAPLEY_PARSER_H
