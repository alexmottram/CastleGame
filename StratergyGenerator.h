//
// Created by alexa on 21/05/2018.
//

#ifndef CASTLEGAME_STRATERGYGENERATOR_H
#define CASTLEGAME_STRATERGYGENERATOR_H

#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

class StratergyGeneratorMC {
public:
    StratergyGeneratorMC(int MaxSum_, int NumTests_);
    virtual std::vector<int> GetRandStrat() = 0;
    int GetMaxSum();
    int GetNumTests();

private:
    int MaxSum;
    int NumTests;
};

class InvertRandStrat : public StratergyGeneratorMC
{
public:
    InvertRandStrat(int MaxSum_, int NumTests_);
    std::vector<int> GetRandStrat();
};



class RandAssignStrat : public StratergyGeneratorMC
{
public:
    RandAssignStrat(int MaxSum_, int NumTests_);
    std::vector<int> GetRandStrat();
};

class InvertRandStratNOTOP : public StratergyGeneratorMC
{
public:
    InvertRandStratNOTOP (int MaxSum_, int NumTests_);
    std::vector<int> GetRandStrat();
};


#endif //CASTLEGAME_STRATERGYGENERATOR_H
