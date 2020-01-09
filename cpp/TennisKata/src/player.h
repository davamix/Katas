#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <array>

class Player{
    public:
        enum Score {zero, fifteen, thirty, fourty, advantage, advantage_2};
        
        Player(Score initial_score);
        
        void WinsPoint();
        std::string GetPersonalScore();
        Score GetScore();
        void SetScore(Score score);

     private:
        int score_index;
        std::array<std::string, 6> score_values;
};

#endif