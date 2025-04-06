all: program

program: *.cpp
    g++ -std=c++17 -o program *.cpp