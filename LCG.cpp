// LCG.cpp
#include "LCG.h"

LCG::LCG(int mod, int a, int c, int seed)
    : RNGBASE(mod), a(a), c(c), xi(seed) {}

int LCG::generateRandomIntegerNumberBack() {
    xi = (a * xi + c) % mod;
    return xi;
}

LCG::~LCG() = default;
