//
//  registers.c
//  p1
//
//  Created by Chengeng Xiao on 1/19/16.
//  Copyright © 2016 Chengeng Xiao. All rights reserved.
//

#include "registers.h"
#include "instruction.h"
#include "main.h"
#include <stdio.h>
void initialize(Registers* registers, int* memory)
{
    registers->regs[eax] = 0;
    // eax is the accumulator for all arithmetic/logic instructions. 
    registers->regs[eip] = 100;
    // eip is the instruction pointer which contains the addrees for next
    // instruction to be fetched-decoded-executed.
    registers->regs[ebp] = 996;
    // ebp is the base pointer, which severs to hold addresses in simulated
    // memory.
    registers->regs[esp] = 1000;
    // esp is the stack pointer, which serves to hold the current address in
    // simulated memory of bottom of the stack.
    memory[1000] = 0;   // memory is the stack. 
} // Initialize four registers with their initial value. 

void print(Instruction* curInstruction, Registers* registers)
{

    printf("%-20s", curInstruction->info + 1);
    printf(" eip:%4d eax:%4d ebp:%4d esp: %d\n", registers->regs[eip], \
    registers->regs[eax], registers->regs[ebp], registers->regs[esp]);
} // Print the answer here.
