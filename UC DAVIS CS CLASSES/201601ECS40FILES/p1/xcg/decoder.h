//
//  decoder.h
//  p1
//
//  Created by Chengeng Xiao on 1/19/16.
//  Copyright © 2016 Chengeng Xiao. All rights reserved.
//

#ifndef decoderH
#define decoderH
#include "registers.h"
#include "instruction.h"

typedef struct Decoder
{
    char opcode[20]; // This is a string of the instruction opcode. 
    int *operand1, *operand2; // The address for two operands. 
} Decoder; // Define the Decoder struct type, containing a string of opcode
          // and two integer type address of operands.
void parse(Decoder* decoder, Instruction* curInstruction, Registers* registers,\
           int memory[]);
void addl(Decoder* decoder);
void andl(Decoder* decoder);
void leave(Decoder* decoder, Registers* registers, int memory[]);
void movl(Decoder* decoder);
void pushl(Decoder* decoder, Registers* registers, int memory[]);
void ret(Registers* registers, int memory[]);
void subl(Decoder* decoder);
void execute(Decoder* decoder, Registers* registers, int memory[]);

#endif // Define decoder.h 
