#include <iostream>
#include <string>
#include "matcher.h"

int main(int argc, char* argv[]) {

    if (argc != 3) {
        std::cerr << "Wrong input." << std::endl;
        return 1;
    }
    //Create players with preferences
    matcher my_matcher(strtol(argv[1], nullptr, 10), //argv[1] as long int (TODO: todavia no fue usado)
                        std::string(argv[2]));         //argv[2] as string
    my_matcher.createTournament(argv[1]);
    //Split players by ranking
    //Match players

    return 0;
}
