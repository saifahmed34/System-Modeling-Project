//
// Created by Mostafa on 4/30/2025.
//

#ifndef RNGBASE_H
#define RNGBASE_H
#include <cinttypes>
#include <iostream>
#include <vector>

class RNGBASE {
private:
    int lastRandomNumber;
    bool isThereNumberGenerated = false;

protected:
    int mod;

    // Implement this abstract function in your algorithm class
    virtual int generateRandomIntegerNumberBack() = 0;

public:
    RNGBASE(int mod);

    int generateRandomIntegerNumber();

    int getLastRandomNumber();

    double generateRandomRealNumber();

    double getLastRandomRealNumber();

    int generateSeedNumber();

    void printNTests(int n);

    std::vector<int> generateNRandomNumbers(int n);

    virtual ~RNGBASE() {
    }
};


#endif //RNGBASE_H
