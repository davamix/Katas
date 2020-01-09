#include <iostream>
#include "gtest/gtest.h"
#include "calculator.h"

namespace{
    class CalculatorTest : public::testing::Test{
    //     protected:
    //     const Calculator c;
    
    //     CalculatorTest(){}

    //     virtual ~CalculatorTest(){}

    //     virtual void SetUp(){
    //         //const Calculator c;
    //     }
    };

    TEST(CalculatorTest, AddWithoutParameters){
        Calculator c;
        std::string s;
        EXPECT_EQ(0, c.Calculate(s));
    }

    TEST(CalculatorTest, AddOneParameter){
        Calculator c;
        EXPECT_EQ(1, c.Calculate("1"));
    }

    TEST(CalculatorTest, AddTwoParameters){
        Calculator c;
        EXPECT_EQ(3, c.Calculate("1,2"));
    }

    TEST(CalculatorTest, AddManyParameters){
        Calculator c;
        EXPECT_EQ(10, c.Calculate("1,2,3,4"));
    }

    TEST(CalculatorTest, AddParameterWithNewLines){
        Calculator c;
        EXPECT_EQ(6, c.Calculate("1\n2,3"));
    }

    TEST(CalculatorTest, AddWithCustomParameters){
        Calculator c;
        EXPECT_EQ(3, c.Calculate("//[;]\n1;2"));
    }

    TEST(CalculatorTest, AddNegativeParametersThrowAnException){
        // https://stackoverflow.com/a/23271110
        
        Calculator c;
        try{
            c.Calculate("-1,2,-3");
            FAIL();
        }catch(std::invalid_argument &exception){
            ASSERT_STREQ("Negative values not allowed: -1 -3", exception.what());
        }
    }

    TEST(CalculatorTest, NumbersBiggerThan1000AreIgnored){
        Calculator c;
        EXPECT_EQ(2, c.Calculate("2, 1001"));
    }
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}