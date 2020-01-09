#include <iostream>
#include <array>
#include "player.h"

int score_index;
std::array<std::string, 6> score_values; // string representation of Score enum

Player::Player(Score initial_score){
    score_index = initial_score;
    score_values = {"0", "15", "30", "40", "A", "Win"};
}

void Player::WinsPoint(){
    if(score_index < score_values.size()-1)
        score_index++;
}

std::string Player::GetPersonalScore(){
    return score_values[score_index];
}

Player::Score Player::GetScore(){
    return static_cast<Player::Score>(score_index);
}

void Player::SetScore(Player::Score score){
    score_index = score;
}
