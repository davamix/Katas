#ifndef TENNISKATA_H
#define TENNISKATA_H

#include <iostream>
#include "player.h"

class TennisKata{
    private:
    Player *Server;
    Player *Receiver;

    std::string GetScore();
    void CheckScores();
    bool HasServerWon();
    bool HasReceiverWon();
    void ApplyDeuceConditions();
    
    public:
    TennisKata(Player::Score server_score = Player::Score::zero, Player::Score receiver_score = Player::Score::zero);

    std::string ServerWins();
    std::string ReceiverWins();  
};

#endif