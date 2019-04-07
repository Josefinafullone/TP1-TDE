#include <vector>
#include <utility>
#include <iostream>
#include "safeStream.h"
#include "player.h"

safeStream::safeStream(std::string file_path) {
    myfile = new std::fstream();
    myfile->open(file_path);
}

safeStream::~safeStream() {
    myfile->close();
    delete(myfile);
}

std::fstream* safeStream::getStream() {
    return myfile;
}

safeStream::safeStream() {}
