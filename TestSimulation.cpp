//
// Created by alexa on 25/05/2018.
//


#include "TestSimulation.h"

TestSimulation::TestSimulation(std::vector<int> YourStrat_,
                std::vector<std::reference_wrapper<StratergyGeneratorMC>> OpponentStrats_)
{
    Wins=0;
    Losses=0;
    Draws=0;
    Errors=0;

    for (auto i : OpponentStrats_) // runs through every method of the opponent creating a strat
    {

        for ( int j = 0; j < i.get().GetNumTests(); j++) // loops for the number of strats being run
        {

            std::vector<int> tempOpponentStrat = i.get().GetRandStrat();

            int tempSum = 0;
            for (auto i : tempOpponentStrat) { tempSum += i; }

            CastleGame tempCastleGame(YourStrat_,tempOpponentStrat);

            if (tempCastleGame.GetResult() == 1) {
                Wins ++;
            } else if (tempCastleGame.GetResult() == 0) {
                Draws ++;
            } else if (tempCastleGame.GetResult() == -1) {
                Losses ++;
            } else {
                Errors ++;
            }
        }

    }
}

unsigned int TestSimulation::GetWins() { return Wins; }
unsigned int TestSimulation::GetDraws() { return Draws; }
unsigned int TestSimulation::GetLosses() { return Losses; }
unsigned int TestSimulation::GetErrors() { return Errors; }