#include<bits/stdc++.h>
#include "ExecutionUnit.hpp"
using namespace std;

class ExecutionControlUnit {
public:
    
    ExecutionUnit EU;

    void executeInstruction(vector<double> instruction, DataMemory &DM){
        double opcode = instruction[0];
        double res = -1;
        if(opcode == 0){ // INIT
            EU.INIT(DM);
            EU.ITER(DM);
        }else
        if(opcode == 1){ // CMP
            res = EU.CMP(instruction[1], instruction[2]);
        }else
        if(opcode == 2){ // ADD
            res = EU.ADD(instruction[1], instruction[2]);
        }else
        if(opcode == 3){ // MULT
            res = EU.MULT(instruction[1], instruction[2]);
        }else
        if(opcode == 4){ // SWAP
            EU.SWAP(instruction[1], instruction[2]);
        }else
        if(opcode == 5){ // RAND
            res = EU.RAND(instruction[1]);
        }else
        if(opcode == 6){ // CALC_FITNESS
            instruction.erase(instruction.begin());
            res = EU.CALC_FITNESS(instruction);
        }else
        if(opcode == 7){ // MIN
            res = EU.MIN(instruction[1], instruction[2]);
        }else
        if(opcode == 8){ // MAX
            res = EU.MAX(instruction[1], instruction[2]);
        }
        cout << "res: " << res << endl;
    }
};
