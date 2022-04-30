#include<bits/stdc++.h>
using namespace std;

// INIT = 0
// CMP = 1
// ADD = 2
// MULT = 3
// Swap = 4
// RAND = 5
// CALC_FITNESS = 6
// MIN = 7
// MAX = 8

class InstructionMemory {
public:
    vector<double> instructions;
    InstructionMemory(){
        instructions = vector<double>(100);
        instructions[0] = 0; // INIT

        instructions[1] = 1; // Compare 24 and 26
        instructions[2] = 24; // 1st arg
        instructions[3] = 26; // 2nd arg
        
        instructions[4] = 2; // Add 50+50
        instructions[5] = 50; // 1st arg
        instructions[6] = 50; // 2nd arg
        
        instructions[7] = 3; // Multiply 50*50
        instructions[8] = 50; // 1st arg
        instructions[9] = 50; // 2nd arg
        
        instructions[10] = 5; // Get Random Number of Type 0
        instructions[11] = 0; // Type 0
        
        instructions[12] = 5; // Get Random Number of Type 1
        instructions[13] = 1; // Type 1
        
        instructions[14] = 6; // Calculate Fitness
        instructions[15] = 0; // 1st dim
        instructions[16] = 0; // 2nd dim
        
        instructions[17] = 7; // Min of 20 and 70
        instructions[18] = 20; // 1st arg
        instructions[19] = 70; // 2nd arg
        
        instructions[20] = 8; // Max of 20 and 70
        instructions[21] = 20; // 1st arg
        instructions[22] = 70; // 2nd arg

        instructions[23] = -1; // End of Program
    }

    double getInstruction(int index){
        return instructions[index];
    }
};
