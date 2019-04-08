#include <iostream>
#include <string>
#include "matcher.h"

int main(int argc, char* argv[]) {

    if (argc != 3) {
        std::cerr << "Wrong input." << std::endl;
        return 1;
    }

    matcher my_match(static_cast<size_t>(strtol(argv[1], nullptr, 10)),
                     std::string(argv[2]));

    my_match.gale_shapley();
    return 0;
}