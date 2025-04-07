#include "dynamic_array_read_from_file.hpp"
#include <fstream>
#include <string>

void loadFileToArrayList(const std::string& fileName, ArrayList& arrayList) {
    std::ifstream inFile(fileName); 
    if (!inFile) {
        throw std::runtime_error("Nie można otworzyć pliku: " + fileName);
    }

    int value;
    while (inFile >> value) { 
        arrayList.add(value); 
    }

    inFile.close();
}