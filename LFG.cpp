//
// Created by Mostafa on 4/30/2025.
//

#include "LFG.h"


LFG::LFG(int mod, int k, int j, int x0Seed, int x1Seed): RNGBASE(mod) {
    xTableHolder.push_back(x0Seed);
    xTableHolder.push_back(x1Seed);
    this->k = k;
    this->j = j;
}

void LFG::setMergeFunction(const std::function<int(int, int)> &f) {
    mergeFunction = f;
}

int LFG::generateRandomIntegerNumberBack() {
    while (xTableHolder.size() < std::max(k, j)) {
        xTableHolder.push_back(xTableHolder.back() + xTableHolder.at(xTableHolder.size() - 2));
    };
    int newX = mergeFunction(
                   xTableHolder.at(xTableHolder.size() - j),
                   xTableHolder.at(xTableHolder.size() - k)
               ) % mod;

    xTableHolder.push_back(newX);
    xTableHolder.pop_front();
    return newX;
}

LFG::~LFG() {
}
