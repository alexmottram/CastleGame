#include <iostream>
#include <vector>
#include <random>
#include "StratergyGenerator.h"
#include "TestSimulation.h"

int main() {

    std::vector<int> myStratergy1{1,1,1,3,4,8,13,18,23,28};
    std::vector<int> myStratergy{10,10,10,10,10,10,10,10,10,10};
    int mychecksum = 0;
    for (auto i : myStratergy) {mychecksum += i;}
    std::cout << "My sum is currently " << mychecksum << std::endl;

    InvertRandStratNOTOP MyRandomStrat(100,10);
    InvertRandStrat opponentStrat1(100,10000);
    RandAssignStrat opponentStrat2(100,10000);

    std::vector<std::reference_wrapper<StratergyGeneratorMC>> OpponentStrats;
    OpponentStrats.push_back(opponentStrat1);
    OpponentStrats.push_back(opponentStrat2);

    double MaxWinRatio = 0;
    std::vector<int> bestTestStrat{10,10,10,10,10,10,10,10,10,10};

    for (int k = 0; k < MyRandomStrat.GetNumTests(); k++)
    {
        std::vector<int> currentTestStrat = MyRandomStrat.GetRandStrat();
        TestSimulation Sim1(currentTestStrat,OpponentStrats);
        double currentWinRatio = 100 * Sim1.GetWins()/(Sim1.GetWins()+Sim1.GetDraws()+Sim1.GetLosses());

        if (currentWinRatio > MaxWinRatio) {
            MaxWinRatio = currentWinRatio;
            bestTestStrat = currentTestStrat;
            std::cout << "New best win ratio is: " << MaxWinRatio << " from strategy ";

            for (auto l : bestTestStrat ) { std::cout << l << " "; }
            std::cout <<  std::endl;

        }
    }

    std::cout << "Switching to improvement method." << std::endl;

    int NumRandomImprovements = 10000;

    for (int m = 0; m < NumRandomImprovements; m++)
    {
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> disChanges(1,3);
        std::uniform_int_distribution<> disRedistribute(-3,3);
        std::uniform_int_distribution<> disCycleSelect(0,100);

        int NoChanges = disChanges(gen);

        for (int n = 0; n < NoChanges; n ++)
        {
            std::vector<int> SwitchSelection{0,1,2,3,4,5,6,7,8};

            int FirstPoint = disRedistribute(gen) % SwitchSelection.size();
            int FirstVector = SwitchSelection[FirstPoint];
            SwitchSelection.erase(SwitchSelection.begin() + FirstVector);

            int SecondPoint = disRedistribute(gen) % SwitchSelection.size();
            int SecondVector = SwitchSelection[SecondPoint];
            SwitchSelection.erase(SwitchSelection.begin() + SecondVector);

            int Redist = disRedistribute(gen);

            std::vector<int> currentTestStrat = bestTestStrat;

            if (bestTestStrat[FirstVector]+Redist >= 0
                    && bestTestStrat[SecondVector]-Redist >= 0) {
                currentTestStrat[FirstVector] += Redist;
                currentTestStrat[SecondVector] -= Redist;

                TestSimulation Sim2(currentTestStrat,OpponentStrats);

                double currentWinRatio = 100 * Sim2.GetWins()/(Sim2.GetWins()+Sim2.GetDraws()+Sim2.GetLosses());

                if (currentWinRatio > MaxWinRatio) {

                    MaxWinRatio = currentWinRatio;
                    bestTestStrat = currentTestStrat;
                    std::cout << "New best win ratio from improvement is: " << MaxWinRatio << " from strategy ";

                    for (auto l : bestTestStrat ) { std::cout << l << " "; }
                    std::cout <<  std::endl;
                }
            }
        }
    }

    std::cout << "The final best win ratio is: " << MaxWinRatio << " from strategy ";
    for (auto l : bestTestStrat ) { std::cout << l << " "; }
    std::cout <<  std::endl;

    return 0;
}