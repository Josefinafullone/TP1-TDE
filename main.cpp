#include <iostream>
#include <fstream>
#include <string>
#include <chrono> // for high_resolution_clock
#include "matcher.h"


int main(int argc, char* argv[]) {

	long nPlayers = strtol(argv[1], nullptr, 10);
    if (argc != 3) {
        std::cerr << "Wrong input." << std::endl;
        return 1;
    }
    if(nPlayers-argc == 0 || nPlayers!=0) {
    	matcher my_match(static_cast<size_t>(nPlayers), std::string(argv[2]));

        // Record start time
        auto start = std::chrono::high_resolution_clock::now();
        my_match.gale_shapley();
        // Record end time
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;

   		my_match.printResults();
        std::cout << "Elapsed time: " << elapsed.count() << " s\n";
        std::cout << "Output stable check: ";
        if(my_match.is_stable())
           std::cout << "True" << std::endl;

        else std::cout << "False" << std::endl;

    } else std::cerr << "Wrong input. The number of prefence must be a positive number" << std::endl;

    return 0;
}