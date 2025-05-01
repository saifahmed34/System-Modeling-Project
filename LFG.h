//
// Created by Mostafa on 4/30/2025.
//

#ifndef LFG_H
#define LFG_H
#include <algorithm>

#include "RNGBASE.h"
#include <deque>
#include <functional>

class LFG : public RNGBASE {
private:
    std::deque<int> xTableHolder;
    int k;
    int j;
    std::function<int(int, int)> mergeFunction = [](int a, int b) { return a + b; };

    int generateRandomIntegerNumberBack() override;

public:
    LFG(int mod, int k, int j, int x0Seed, int x1Seed);

    void setMergeFunction(const std::function<int(int, int)> &f);


    ~LFG() override;
};


#endif //LFG_H
