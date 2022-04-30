#ifndef FitnessFunction_hpp
#define FitnessFunction_hpp

#include<bits/stdc++.h>
using namespace std;

class FitnessFunction {
    public:
    double getFitness(vector<double> &position) {
        int dim = position.size();
        double fitnessValue = 10*dim;
        for(int i=0; i<dim; i++){
            double x = position[i];
            fitnessValue += (x*x) - (10*cos(2*M_PI*x));
        }
        return fitnessValue;
    }
};
#endif // FitnessFunction_hpp
