#ifndef DataMemory_hpp
#define DataMemory_hpp

#include<bits/stdc++.h>
#include "Particle.hpp"

using namespace std;

class DataMemory {
public:
    int n;
    int dim;
    int epochs;
    double w, c1, c2;
    vector<Particle> Swarm;
    vector<double> gbest;
    double gbestFitness;
    double upperBound;
    double lowerBound;
    vector<vector<Particle>> history;

    double latest_output; // only for cpu
    
    void DataMemory_INIT(int n, int dim, int epochs, double w, double c1, double c2, double lowerBound, double upperBound) {
        for (int i = 0; i < n; i++) {
            Particle particle;
            Swarm.push_back(particle);
        }
        this->n = n;
        this->dim = dim;
        this->epochs = epochs;
        this->w = w;
        this->c1 = c1;
        this->c2 = c2;
        this->upperBound = upperBound;
        this->lowerBound = lowerBound;
        gbest = vector<double>(dim, 0);
        gbestFitness = INT_MAX;
    }

    Particle getParticle(int index) {
        return Swarm[index];
    }

    void setParticle(int index, Particle particle) {
        Swarm[index] = particle;
    }

    vector<double> getGBest() {
        return gbest;
    }

    void setGBest(vector<double> gbest) {
        this->gbest = gbest;
    }

    double getBestFitness() {
        return gbestFitness;
    }

    void setBestFitness(double bestFitness) {
        this->gbestFitness = bestFitness;
    }
};
#endif /* DataMemory_hpp */
