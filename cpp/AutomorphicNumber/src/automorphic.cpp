#include <iostream>
#include <vector>

#include "automorphic.h"

bool Automorphic::IsAutomorphic(int number){
    
    std::vector<int> square_vtr;
    std::vector<int> number_vtr;

    //save the square into a vector
    square_vtr = Automorphic::Vectorize(number * number);

    // save the number into a vector
    number_vtr = Automorphic::Vectorize(number);

    // Compare the digits
    for(int x=0; x<=number_vtr.size() - 1; x++){
        if(number_vtr[x] != square_vtr[x])
            return false;
    }

    return true;
}

std::vector<int> Automorphic::Vectorize(int value){
    std::vector<int> value_vtr;

    while(value){
        value_vtr.push_back(value%10);
        value /= 10;
    }

    return value_vtr;
}