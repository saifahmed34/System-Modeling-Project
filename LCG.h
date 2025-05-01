// LCG.h
#ifndef LCG_H
#define LCG_H

#include "RNGBASE.h"

class LCG : public RNGBASE {
private:
    int a;
    int c;
    int xi;  //seed

    int generateRandomIntegerNumberBack() override;

public:
    LCG(int xi, int a, int c, int mod);
    ~LCG() override;
};

#endif // LCG_H
