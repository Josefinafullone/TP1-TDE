#include <vector>
#include <utility>
#include <iostream>
#include "parser.h"
#include "player.h"

parser::parser(std::string file_path) {
    myfile = new std::fstream();
    myfile->open("jugadores.rank");
}

parser::~parser() {
    myfile->close();
    delete(myfile);
}

std::fstream* parser::getStream() {
    return myfile;
}
