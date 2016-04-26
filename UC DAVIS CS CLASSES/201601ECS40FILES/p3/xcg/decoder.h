//
//  decoder.h
//  p3
//
//  Created by Chengeng Xiao on 1/31/16.
//  Copyright © 2016 Chengeng Xiao. All rights reserved.
//

#ifndef decoderH
#define decoderH
#include "registers.h"
#include "instruction.h"

using namespace std;

class Decoder
{
private:
    char opcode[20]; // This is a string of the instruction opcode. å
    int *operand1;
    int *operand2; // The address for two operands. 
    void addl();
    void andl();
    void leave(Registers* registers, int memory[])const;
    void movl();
    void pushl(Registers* registers, int memory[])const;
    void ret(Registers* registers, int memory[])const;
    void subl();
public:
    void parse(Instruction* curInstruction, Registers* registers, \
               int memory[1001]);    
    void execute(Registers* registers, int memory[]);
}; //decoder class

#endif