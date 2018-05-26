//
// Created by alexa on 21/05/2018.
//

#include "StratergyGenerator.h"

StratergyGeneratorMC::StratergyGeneratorMC(int MaxSum_, int NumTests_) :
MaxSum(MaxSum_), NumTests(NumTests_)
{

}

int StratergyGeneratorMC::GetMaxSum() { return MaxSum; }

int StratergyGeneratorMC::GetNumTests() { return NumTests; }

InvertRandStrat::InvertRandStrat(int MaxSum_, int NumTests_) :
        StratergyGeneratorMC(MaxSum_, NumTests_)
{}

std::vector<int> InvertRandStrat::GetRandStrat()
{
    int runningTotal = this->GetMaxSum();
    std::vector<int> invertedStrat;

    for(int i = 0; i < 10; i++){
        if(runningTotal > 0){

            std::random_device rd;  //Will be used to obtain a seed for the random number engine
            std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
            std::uniform_int_distribution<> dis(0, runningTotal);

            int tempValue = dis(gen);
            runningTotal -= tempValue;
            invertedStrat.push_back(tempValue);

        } else {
            invertedStrat.push_back(0);
        }
    }

    // Flips the strat to the correct order
    std::reverse(invertedStrat.begin(),invertedStrat.end());

    if(runningTotal > 0){
        int final_value = invertedStrat.back();
        final_value += runningTotal;
        runningTotal -= runningTotal;
        invertedStrat.back()=final_value;
    }

    return invertedStrat;
}

RandAssignStrat::RandAssignStrat(int MaxSum_, int NumTests_) :
        StratergyGeneratorMC(MaxSum_, NumTests_)
{}

std::vector<int> RandAssignStrat::GetRandStrat()
{
    int randomAssignments = this->GetMaxSum();

    std::vector<int> RandStrat;

    for (int i = 0; i < 10; i++)
    {
        RandStrat.push_back(1);
        randomAssignments --;
    }

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0, 9);

    for (int i = 0; i < randomAssignments; i++)
    {
        int tempCastleNumber = dis(gen);
        RandStrat[tempCastleNumber] ++;
    }

    return RandStrat;
}

InvertRandStratNOTOP::InvertRandStratNOTOP(int MaxSum_, int NumTests_) : StratergyGeneratorMC(MaxSum_, NumTests_)
{}

std::vector<int> InvertRandStratNOTOP::GetRandStrat()
{
    int runningTotal = this->GetMaxSum();
    std::vector<int> invertedStrat;

    for (int i = 0; i < 10; i++)
    {
        invertedStrat.push_back(1);
        runningTotal --;
    }

    for(int i = 8; i >= 0; i--){
        if(runningTotal > 0){

            std::random_device rd;  //Will be used to obtain a seed for the random number engine
            std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
            std::uniform_int_distribution<> dis(0, runningTotal);

            int tempValue = dis(gen);
            runningTotal -= tempValue;
            invertedStrat[i]+= tempValue;

        }
    }

    if(runningTotal > 0){
        int final_value = invertedStrat.back();
        final_value += runningTotal;
        runningTotal -= runningTotal;
        invertedStrat[8]+=final_value;
    }

    return invertedStrat;
}
