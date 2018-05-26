//
// Created by alexa on 25/05/2018.
//

#ifndef CASTLEGAME_TESTSIMULATION_H
#define CASTLEGAME_TESTSIMULATION_H

#include <vector>
#include <functional>
#include "StratergyGenerator.h"
#include "CastleGame.h"

class TestSimulation {

public:
    TestSimulation(std::vector<int> YourStrat_, std::vector<std::reference_wrapper<StratergyGeneratorMC>> OpponentStrats_);
    unsigned int GetWins();
    unsigned int GetDraws();
    unsigned int GetLosses();
    unsigned int GetErrors();

private:
    unsigned int Wins;
    unsigned int Losses;
    unsigned int Draws;
    unsigned int Errors;

};


#endif //CASTLEGAME_TESTSIMULATION_H
