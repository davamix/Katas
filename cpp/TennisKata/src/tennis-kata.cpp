#include <iostream>
#include "tennis-kata.h"
#include "player.h"

Player *Server;
Player *Receiver;

TennisKata::TennisKata(Player::Score server_score, Player::Score receiver_score){
    this->Server = new Player(server_score);
    this->Receiver = new Player(receiver_score);
}

std::string TennisKata::ServerWins(){
    this->Server->WinsPoint();

    if(HasServerWon())
        return "Server wins!";
    
    ApplyDeuceConditions();

    return GetScore();
}

std::string TennisKata::ReceiverWins(){
    this->Receiver->WinsPoint();

    if(HasReceiverWon())
        return "Receiver wins!";
    
    ApplyDeuceConditions();

    return GetScore();
}

std::string TennisKata::GetScore(){

    return this->Server->GetPersonalScore() + ":" + this->Receiver->GetPersonalScore();
}


bool TennisKata::HasServerWon(){
    Player::Score server_score = this->Server->GetScore();
    Player::Score receiver_score = this->Receiver->GetScore();

    // Server win rules
    return ((server_score == Player::Score::advantage && server_score - receiver_score >= 2) ||
            (server_score == Player::Score::advantage_2));
}

bool TennisKata::HasReceiverWon(){
    Player::Score server_score = this->Server->GetScore();
    Player::Score receiver_score = this->Receiver->GetScore();

    // Receiver win rules
    return ((receiver_score == Player::Score::advantage && receiver_score - server_score >= 2) ||
            (receiver_score == Player::Score::advantage_2));
}

void TennisKata::ApplyDeuceConditions(){
    Player::Score server_score = this->Server->GetScore();
    Player::Score receiver_score = this->Receiver->GetScore();

    // Move scores to fourty
    if(server_score == Player::Score::advantage && receiver_score == Player::Score::advantage){
        this->Server->SetScore(Player::Score::fourty);
        this->Receiver->SetScore(Player::Score::fourty);
    } 
}