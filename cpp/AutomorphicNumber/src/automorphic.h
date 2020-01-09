#ifndef AUTOMORPHIC_H
#define AUTOMORPHIC_H

#include <iostream>
#include <vector>

class Automorphic{
    public:
    bool IsAutomorphic(int number);

    private:
    std::vector<int> Vectorize(int value);
};


#endif