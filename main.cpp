#include <iostream>
#include <fstream>
#include <string>
#include "matcher.h"


int main(int argc, char* argv[]) {

	int preference=atoi(argv[1]);
    if (argc != 3) {
        std::cerr << "Wrong input." << std::endl;
        return 1;
    }
    if(preference-argc == 0 || preference!=0)
    {

    	matcher my_match(static_cast<size_t>(strtol(argv[1], nullptr, 10)),
                     std::string(argv[2]));

   		 my_match.gale_shapley();
   		 my_match.printResults();

    } else std::cerr << "Wrong input. The number of prefence must be a positive number" << std::endl;


    
    return 0;
}