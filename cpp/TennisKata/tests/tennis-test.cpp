#include <iostream>
#include "gtest/gtest.h"

#include "tennis-kata.h"
#include "player.h"

namespace {
    class TennisKataTest : public::testing::Test{

    };

    TEST(TennisKataTest, Given_the_score_zero_zero_and_server_wins_a_point_the_score_is_fifteen_zero){
        TennisKata tk(Player::Score::zero, Player::Score::zero);
        
        std::string result = tk.ServerWins();

        EXPECT_EQ("15:0", result);
    }

    TEST(TennisKataTest, Given_the_score_fifteen_fifteen_and_receiver_wins_a_point_the_score_is_fifteen_thirty){
        TennisKata tk(Player::Score::fifteen, Player::Score::fifteen);

        std::string result = tk.ReceiverWins();

        EXPECT_EQ("15:30", result);
    }

    TEST(TennisKataTest, Given_the_score_thirty_thirty_and_server_wins_a_point_the_score_is_fourty_thirty){
        TennisKata tk(Player::Score::thirty, Player::Score::thirty);

        std::string result = tk.ServerWins();

        EXPECT_EQ("40:30", result);
    }

    TEST(TennisKataTest, Given_the_score_fourty_fourty_and_receiver_wins_a_point_the_score_is_fourty_Advantage){
        TennisKata tk(Player::Score::fourty, Player::Score::fourty);

        std::string result = tk.ReceiverWins();

        EXPECT_EQ("40:A", result);
    }

    TEST(TennisKataTest, Given_the_score_Advantage_fourty_and_receiver_wins_a_point_the_score_is_fourty_fourty){
        TennisKata tk(Player::Score::advantage, Player::Score::fourty);

        std::string result = tk.ReceiverWins();

        EXPECT_EQ("40:40", result);
    }

    TEST(TennisKataTest, Given_the_score_fourty_thirty_and_server_wins_a_point_then_server_wins){
        TennisKata tk(Player::Score::fourty, Player::Score::thirty);

        std::string result = tk.ServerWins();

        EXPECT_EQ("Server wins!", result);
    }

    TEST(TennisKataTest, Given_the_score_fourty_Advantage_and_receiver_wins_a_point_then_receiver_wins){
        TennisKata tk(Player::Score::fourty, Player::Score::advantage);

        std::string result = tk.ReceiverWins();

        EXPECT_EQ("Receiver wins!", result);
    }
}