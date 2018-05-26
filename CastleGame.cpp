//
// Created by alexa on 21/05/2018.
//

#include "CastleGame.h"

CastleGame::CastleGame(std::vector<int> myStrat_, std::vector<int> opponentStrat_)
{
    if(myStrat_.size()==10 && opponentStrat_.size()==10) {

        ScoreDifference = 0;

        for (int i = 0; i < 10 ; i++)
        {
            int tempScoreDiff = myStrat_[i] - opponentStrat_[i];
            DetailedResults.push_back(tempScoreDiff);

            if (tempScoreDiff > 0) {
                ScoreDifference += (i+1); // Add the castle number if win
            } else if (tempScoreDiff < 0) {
                ScoreDifference -= (i+1); // Substract score difference if loss
            } else if (tempScoreDiff == 0) {

            }
        }

        if(ScoreDifference > 0) {
            Result = WIN;
        } else if (ScoreDifference < 0) {
            Result = LOSS;
        } else if (ScoreDifference == 0) {
            Result = DRAW;
        }

    } else {
        Result = ERROR;
    }
}

std::vector<int> CastleGame::GetDetailedResults() { return DetailedResults; }

int CastleGame::GetScoreDifference() { return ScoreDifference; }

CastleGame::Outcome CastleGame::GetResult() { return Result; }
