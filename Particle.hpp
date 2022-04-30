#ifndef Particle_hpp
#define Particle_hpp

#include<bits/stdc++.h>
using namespace std;

class Particle{
    public:
        vector<double> position;
        double currentFitness;
        vector<double> pbest;
        double bestFitness;
        vector<double> velocity;
    
        void printPosition(){
            for(int i=0; i<position.size(); i++){
                cout << position[i] << " ";
            }
            cout << endl;
        }
};
#endif // Particle_hpp
