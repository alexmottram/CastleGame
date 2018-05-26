//
// Created by alexa on 21/05/2018.
//

#ifndef CASTLEGAME_CASTLEGAME_H
#define CASTLEGAME_CASTLEGAME_H

#include <vector>

class CastleGame {
public:
    enum Outcome{WIN=1,LOSS=-1,DRAW=0,ERROR};
    CastleGame(std::vector<int> myStrat_, std::vector<int> opponentStrat_);
    std::vector<int> GetDetailedResults();
    Outcome GetResult();
    int GetScoreDifference();

private:
    std::vector<int> DetailedResults;
    Outcome Result;
    int ScoreDifference;

};


#endif //CASTLEGAME_CASTLEGAME_H
