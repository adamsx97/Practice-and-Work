//
//  registers.h
//  p3
//
//  Created by Ziyue Gao on 1/31/16.
//  Copyright © 2016 Chengeng Xiao. All rights reserved.
//

#ifndef registersH
#define registersH
#include "instruction.h"

using namespace std;

typedef enum RegName
{
    eax, ebp, esp, eip
} RegName; //regname

const int sizeMenmory = 1001;

class Registers
{
    int regs[4];
    
public:
    void initialize(int* memory);
    void print(Instruction* curInstruction) const;
    int* address(char *operand, int memory[]);
    void set(RegName RN, int another);
    int get(RegName RN) const;
};  // Define the register class, containing 4 ints which are
    // eax, ebp, esp and eip
    // also declared five

#endif  //Define registers.h