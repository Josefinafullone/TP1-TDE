cmake_minimum_required(VERSION 3.10)
project(Gale_Shapley)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Gale_Shapley
        .gitignore
        README.md main.cpp matcher.cpp matcher.h player.cpp player.h tournament.cpp tournament.h)
