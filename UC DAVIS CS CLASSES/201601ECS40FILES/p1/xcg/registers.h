//
//  registers.h
//  p1
//
//  Created by Chengeng Xiao on 1/19/16.
//  Copyright © 2016 Chengeng Xiao. All rights reserved.
//

#ifndef registersH
#define registersH
#include "instruction.h"

const int sizeMenmory = 1001;
typedef struct Registers
{
    int regs[4];
} Registers; // Define the register struct type, containing 4 ints which are
            // eax, ebp, esp and eip.
void initialize(Registers* registers, int* memory);
void print(Instruction* curInstruction, Registers* registers);

#endif //Define register.h