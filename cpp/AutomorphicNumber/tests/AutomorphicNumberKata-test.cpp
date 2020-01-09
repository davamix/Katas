#include <iostream>
#include "gtest/gtest.h"

#include "automorphic.h"

// your project includes

namespace{
    class AutomorphicNumberKata : public::testing::Test{

    };

    TEST(AutomorphicNumberKata, One_Digit_Number){
        Automorphic at;
        //bool result = at.IsAutomorphic(25);

        EXPECT_EQ(true, at.IsAutomorphic(1));
        EXPECT_EQ(false, at.IsAutomorphic(3));
        EXPECT_EQ(true, at.IsAutomorphic(6));
        EXPECT_EQ(false, at.IsAutomorphic(9));
    }

    TEST(AutomorphicNumberKata, Two_Digits_Number){
        Automorphic at;

        EXPECT_EQ(true, at.IsAutomorphic(25));
        EXPECT_EQ(false, at.IsAutomorphic(13));
        EXPECT_EQ(true, at.IsAutomorphic(76));
        EXPECT_EQ(false, at.IsAutomorphic(95));
    }

    TEST(AutomorphicNumberKata, Large_Number){
        Automorphic at;

        EXPECT_EQ(true, at.IsAutomorphic(625));
        EXPECT_EQ(false, at.IsAutomorphic(225));
        EXPECT_EQ(false, at.IsAutomorphic(425));
        EXPECT_EQ(false, at.IsAutomorphic(399));
    }
}
    
