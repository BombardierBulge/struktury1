#include <fstream>
#include <stdexcept>
#include <string>
#include "Lista_jednokierunkowa_wczytaj.hpp"

void loadFileToSinglyLinkedList(const std::string& fileName, List& list) {
    std::ifstream inFile(fileName);
    if (!inFile) {
        throw std::runtime_error("Nie można otworzyć pliku: " + fileName);
    }

    int value;
    while (inFile >> value) {
        list.addLast(value);
    }

    inFile.close();
}
