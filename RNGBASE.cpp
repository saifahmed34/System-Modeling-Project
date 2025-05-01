//
// Created by Mostafa on 4/30/2025.
//

#include "RNGBASE.h"

#include <ctime>
#include <iomanip>
#include <vector>

double RNGBASE::generateRandomRealNumber() {
    return (double) generateRandomIntegerNumber() / mod;
}

RNGBASE::RNGBASE(const int mod): lastRandomNumber(0) {
    this->mod = mod;
}

int RNGBASE::generateSeedNumber() {
    return std::time(nullptr);
}

int RNGBASE::getLastRandomNumber() {
    if (!isThereNumberGenerated) {
        return generateRandomIntegerNumber();
    }
    return lastRandomNumber;
}

double RNGBASE::getLastRandomRealNumber() {
    if (!isThereNumberGenerated) {
        return generateRandomRealNumber();
    }
    return (double) lastRandomNumber / mod;
}

std::vector<int> RNGBASE::generateNRandomNumbers(int n) {
    std::vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = generateRandomIntegerNumber();
    }
    return result;
}


void RNGBASE::printNTests(int n) {
    std::cout << std::left
            << std::setw(10) << "|Iteration "
            << std::setw(20) << "|Random Number"
            << std::setw(20) << " |Random Real Number"
            << "\n";

    for (int i = 0; i < n; i++) {
        std::cout << "|";
        std::cout << std::left
                << std::setw(10) << i << "|"
                << std::setw(20) << generateRandomIntegerNumber() << "|"
                << std::setw(20) << getLastRandomRealNumber() << "|"
                << "\n";
    }
}

int RNGBASE::generateRandomIntegerNumber() {
    isThereNumberGenerated = true;
    return lastRandomNumber = generateRandomIntegerNumberBack();
}
