#ifndef Processor_hpp
#define Processor_hpp

#include<bits/stdc++.h>
#include "FitnessFunction.hpp"
#include "DataMemory.hpp"
#include "RegisterFile.hpp"
#include "ExecutionControlUnit.hpp"
#include "InstructionMemory.hpp"
using namespace std;

class Processor {
public:
    FitnessFunction fitnessFunction;
    DataMemory DM;
    RegisterFile RF;
    ExecutionControlUnit ECU;
    InstructionMemory IM;
    vector<double> instruction;

    int PC = 0;
    Processor(int n, int dim, int epochs, double w, double c1, double c2, double lowerBound, double upperBound) {
        DM.DataMemory_INIT(n, dim, epochs, w, c1, c2, lowerBound, upperBound);
    }

    void run(){
        while(1){
            fetchInstruction();
            if(instruction[0] == -1) break;
            executeInstruction();
            if(instruction[0] == 0) printHistory();
        }
    }

    void fetchInstruction() {

        instruction.clear();

        double opcode = IM.getInstruction(PC++);
        instruction.push_back(opcode);

        if(opcode == 0){ // INIT
            // do nothing
        }else
        if(opcode == 1 || opcode == 2 || opcode == 3 || opcode == 4){ // CMP ADD MULT SWAP
            double a = IM.getInstruction(PC++);
            double b = IM.getInstruction(PC++);
            instruction.push_back(a);
            instruction.push_back(b);
        }else
        if(opcode == 5){ // RAND Type 0  or Type 1
            double a = IM.getInstruction(PC++);
            instruction.push_back(a);
        }else
        if(opcode == 6){ // CALC_FITNESS of a particle of dimension dim
            for(int i=0; i<DM.dim; i++){
                double a = IM.getInstruction(PC++);
                instruction.push_back(a);
            }
        }else
        if(opcode == 7 || opcode == 8){ // MIN and MAX of 2 values
            double a = IM.getInstruction(PC++);
            double b = IM.getInstruction(PC++);
            instruction.push_back(a);
            instruction.push_back(b);
        }
    }

    void executeInstruction(){
        ECU.executeInstruction(instruction, DM);
    }

    // Print history to File "history.txt"
    void printHistory() {
        std::cout << std::fixed;
        std::cout << std::setprecision(6);
        cout << "Best fitness: " << DM.getBestFitness() << endl;
        cout << "Best particle: " << endl << "( ";
        for(int i=0; i<DM.dim; i++){
            cout << DM.gbest[i] << " ";
        }
        cout << ")" << endl;
        cout << endl;
        cout << "Printing history to file..." << endl;
        ofstream myfile;
        myfile.open("history.txt");
        myfile<<DM.epochs<<" "<<DM.n<<" "<<DM.dim<<" "<<DM.lowerBound<<" "<<DM.upperBound<<endl;
        for(int t=0; t<DM.epochs; t++){
            for (int i = 0; i < DM.n; i++) {
                for (int j = 0; j < DM.dim; j++) {
                    myfile << DM.history[t][i].position[j] << " ";
                }
                myfile << endl;
            }
        }
        myfile.close();
        cout << "Printing history to file... Done!" << endl << endl;
    }
};
#endif // Processor_hpp
