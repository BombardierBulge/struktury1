#include "random_generator.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


RandomNumberGenerator::RandomNumberGenerator(int minRange, int maxRange, const std::string& fileName)
    : minRange(minRange), maxRange(maxRange), fileName(fileName) {}


void RandomNumberGenerator::generateFile(int count) {
    srand(static_cast<unsigned>(time(0))); 

    std::ofstream outFile(fileName);
    if (!outFile) {
        std::cout << "Nie można otworzyc pliku: " << fileName << std::endl;
        return;
    }

    
    for (int i = 0; i < count; ++i) {
        int randomNumber = minRange + (rand() % (maxRange - minRange + 1));
        outFile << randomNumber << "\n";
    }

    outFile.close();
    
}
