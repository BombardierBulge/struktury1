#ifndef RANDOM_NUMBER_FILE_GENERATOR_HPP
#define RANDOM_NUMBER_FILE_GENERATOR_HPP

#include <string>

class RandomNumberGenerator {
private:
    int minRange; // Minimalna
    int maxRange; // Maksymalna
    std::string fileName; // Nazwa pliku do zapisu

public:
    RandomNumberGenerator(int minRange, int maxRange, const std::string& fileName);

    // Metoda generująca plik z losowymi liczbami
    void generateFile(int count);
};

#endif // RANDOM_NUMBER_GENERATOR_HPP
