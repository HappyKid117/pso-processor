#ifndef RegisterFile_hpp
#define RegisterFile_hpp

#include<bits/stdc++.h>
using namespace std;

class Register{
public:
    double data;
};

class RegisterFile {
public:
    vector<Register> registers;
    int MAX_NUM_OF_REGISTERS = 32;
    
    RegisterFile(){
        for(int i=0; i<MAX_NUM_OF_REGISTERS; i++){
            Register r;
            registers.push_back(r);
        }
    }
};
#endif // RegisterFile_hpp
