#ifndef ExecutionUnit_hpp
#define ExecutionUnit_hpp

#include "RandomNumberGenerator.hpp"
#include "FitnessFunction.hpp"
#include "Particle.hpp"
#include "DataMemory.hpp"

using namespace std;

class ExecutionUnit {
public:
    RandomNumberGenerator rng;
    FitnessFunction fitnessFunction;

    void INIT(DataMemory &DM){
        int n = DM.n;
        int dim = DM.dim;
        for(int i=0; i<n; i++){
            Particle p = DM.getParticle(i);
            for(int i=0; i<dim; i++){
                p.position.push_back(rng.getRandomPosition());
                p.velocity.push_back(rng.getRandomPosition());
            }
            p.currentFitness = fitnessFunction.getFitness(p.position);
            p.pbest = p.position;
            p.bestFitness = p.currentFitness;
            DM.setParticle(i, p);

            if(CMP(DM.gbestFitness,p.bestFitness)){
                DM.gbestFitness = p.bestFitness;
                DM.gbest = p.position;
            }
        }


    }

    bool CMP(double a, double b){
        return a >= b;
    }

    double ADD(double a, double b){
        return a + b;
    }

    double MULT(double a, double b){
        return a * b;
    }

    void SWAP(double &a, double &b){
        double temp = a;
        a = b;
        b = temp;
    }

    double RAND(int type){
        if(type == 0){
            return rng.getRandomPosition();
        }
        else if(type == 1){
            return rng.getRandomCoefficient();
        }
        return 0;
    }

    double CALC_FITNESS(vector<double> &position){
        return fitnessFunction.getFitness(position);
    }

    double MIN(double a, double b){
        return a < b ? a : b;
    }

    double MAX(double a, double b){
        return a > b ? a : b;
    }

    void ITER(DataMemory &DM){
        for(int t=0; t<DM.epochs; t++){
            DM.history.push_back(DM.Swarm);
            double r1 = rng.getRandomCoefficient();
            double r2 = rng.getRandomCoefficient();

            for(int j=0; j<DM.n; j++){
                Particle p = DM.getParticle(j);
                // p.printPosition();
                for(int i=0; i<DM.dim; i++){
                    p.velocity[i] = MULT(DM.w,p.velocity[i])
                                  + MULT(DM.c1,MULT(r1,(ADD(p.pbest[i],-p.position[i]))))
                                  + MULT(DM.c2,MULT(r2,(ADD(DM.gbest[i],-p.position[i]))));

                    p.velocity[i] = MIN(p.velocity[i], DM.upperBound);
                    p.velocity[i] = MAX(p.velocity[i], DM.lowerBound);
                    p.position[i] = ADD(p.position[i], p.velocity[i]);
                }
                
                p.currentFitness = CALC_FITNESS(p.position);
                if(CMP(p.bestFitness,p.currentFitness)){
                    p.pbest = p.position;
                    p.bestFitness = p.currentFitness;
                }

                DM.setParticle(j, p);

                if(CMP(DM.gbestFitness,p.bestFitness)){
                    DM.setBestFitness(p.bestFitness);
                    DM.setGBest(p.position);
                }
            }
            
        }
    }
};
#endif /* ExecutionUnit_hpp */
