#ifndef RandomNumberGenerator_hpp
#define RandomNumberGenerator_hpp

#include<bits/stdc++.h>
#include<random>
using namespace std;

class RandomNumberGenerator {
public:
    double upperBound = 10; // Appropriate boundaries
    double lowerBound = -10;
    random_device rd;
    uniform_real_distribution<> pos_distr;
    uniform_real_distribution<> coeff_distr;
    mt19937 gen;

    RandomNumberGenerator(){
        gen = mt19937(rd());
        pos_distr = uniform_real_distribution<>(lowerBound, upperBound);
        coeff_distr = uniform_real_distribution<>(0, 1);
    }

    RandomNumberGenerator(double lowerBound, double upperBound) {
        this->lowerBound = lowerBound;
        this->upperBound = upperBound;
        RandomNumberGenerator();
    }

    double getRandomPosition() {
        return pos_distr(gen);
    }

    double getRandomCoefficient() {
        return coeff_distr(gen);
    }
};
#endif // RandomNumberGenerator_hpp
