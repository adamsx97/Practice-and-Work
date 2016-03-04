//
//  registers.cpp
//  p3
//
//  Created by Ziyue Gao & Chengeng Xiao on 1/31/16.
//  Copyright © 2016 Chengeng Xiao. All rights reserved.
//

#include "registers.h"
#include "instruction.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

void Registers::initialize(int* memory)
{
    regs[eax] = 0;
    // eax is the accumulator for all arithmetic/logic instructions.
    regs[eip] = 100;
    // eip is the instruction pointer which contains the addrees for next
    // instruction to be fetched-decoded-executed.
    regs[ebp] = 996;
    // ebp is the base pointer, which severs to hold addresses in simulated
    // memory.
    regs[esp] = 1000;
    // esp is the stack pointer, which serves to hold the current address in
    // simulated memory of bottom of the stack.
    memory[1000] = 0;  // memory is the stack. 
}// Initialize four registers with their initial value.

void Registers::print(Instruction* curInstruction) const
{
    cout << left << setw(20) << curInstruction->getInfo() + 1;
    cout << " eip: " << right << setw(3) << regs[eip];
    cout << " eax: " << right << setw(3) << regs[eax];
    cout << " ebp: " << right << setw(3) << regs[ebp];
    cout << " esp: " << right << setw(3) << regs[esp] << endl;
} // Print the answer here.

void Registers::set(RegName RN, int another)
{
    regs[RN] = another;
} // Set the value.

int Registers::get(RegName RN) const
{
    
    if (RN < 0 || RN > 3) return 0;
    else //else
        return regs[RN];
}  // Access regname and return the value.

int* Registers::address(char *operand, int memory[])
{
    static int value;
    char regNames[4][7] = {"eax", "ebp", "esp", "eip"};
    char *ptr;
    int regNum, index;
    
    if(operand == NULL)
        return NULL;
    
    if(operand[0] == '$')
    {  // immediate mode
        value = atoi(&operand[1]);
        return &value;
    }  // if immediate mode
    
    for(regNum = eax; regNum <= eip; regNum++)
        if(strstr(operand, regNames[regNum]))
            break;
    
    ptr = strchr(operand, '(');
        
    if(ptr) // some form of indirect addressing
    {
        *ptr = '\0'; // terminate operand string at first '('
        index = atoi(operand); 
        return  &memory[regs[regNum] + index];
    } // if ptr
    else // direct addressing
        return &(regs[regNum]);
} // address ()