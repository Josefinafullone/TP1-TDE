#include <iostream>
#include <string>
#include "matcher.h"

int main(int argc, char* argv[]) {

    if (argc != 3) {
        std::cerr << "Wrong input." << std::endl;
        return 1;
    }
    
    int preference=atoi(argv[1]);
    if(preference-argc == 0 || argc==0)
    {   
        //Create players with preferences
         tournament my_tournament(strtol(argv[1], nullptr, 10), //argv[1] as long int (TODO: todavia no fue usado)
                               std::string(argv[2]));         //argv[2] as string
         //Split players by ranking
         //Match players
    } else std::cerr << "Wrong input. The number of prefence must be a positive number" << std::endl; 

    return 0;
}
