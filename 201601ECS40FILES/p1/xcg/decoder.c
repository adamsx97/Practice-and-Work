//
//  decoder.c
//  p1
//
//  Created by Chengeng Xiao on 1/19/16.
//  Copyright © 2016 Chengeng Xiao. All rights reserved.
//

#include "decoder.h"
#include "registers.h"
#include "instruction.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse(Decoder* decoder, Instruction* curInstruction, Registers* registers,\
           int memory[])
{
    char buffer[100], *seperator; // A pointer used for strtok 
                     //to seperate the instruction line.
    seperator = strstr (curInstruction->info, "\t");

    while (seperator)
    {
        *seperator = ' ';
        seperator = strstr (curInstruction->info, "\t");
} // Change tabs into spaecs.
    strcpy(buffer, curInstruction->info);
    //printf("buffer: %s\n", buffer);
    seperator = strtok(buffer, " ");
    strcpy(decoder->opcode, seperator);
    seperator = strtok(NULL, " ");
    decoder->operand1 = address(registers, seperator, memory);
    seperator = strtok(NULL, " ");
    decoder->operand2 = address(registers, seperator, memory); 
} // The function parses a line of instruction in to opcode and operands. 

void addl(Decoder* decoder)
{
    *decoder->operand2 = *decoder->operand1 + *decoder->operand2;
} // Add operand1 and operande2 and put the ans in operand2.

void andl(Decoder* decoder)
{
    *decoder->operand2 = *decoder->operand1 & *decoder->operand2;
} // Bitwise AND operand1 and operand2 and put ans in operand2. 

void leave(Decoder* decoder, Registers* registers, int memory[])
{
    registers->regs[esp] = registers->regs[ebp];
    registers->regs[ebp] = memory[registers->regs[esp]];
    registers->regs[esp] += 4;
} // Copy value in ebp to esp, then copy value in memory specified by esp to
  // ebp, and add 4 to esp.

void movl(Decoder* decoder)
{
    *decoder->operand2 = *decoder->operand1;
} // Copy info from operand1 into operand2.

void pushl(Decoder* decoder, Registers* registers, int memory[])
{
    registers->regs[esp] -= 4;
    memory[registers->regs[esp]] = *decoder->operand1;
} // Subtract 4 from esp, place the operand1 info at location specified by esp.

void ret(Registers* registers, int memory[])
{
    registers->regs[eip] = memory[registers->regs[esp]];  
    registers->regs[esp] += 4;
} //  

void subl(Decoder* decoder)
{
    *decoder->operand2 = *decoder->operand2 - *decoder->operand1;
} // Subtract operand1 from operand2 and put the result in operand2

void execute(Decoder* decoder, Registers* registers, int memory[])
{
    
    if (strstr(decoder->opcode, "addl")) addl(decoder); // If opcode is "addl",
        // then call function addl.
    if (strstr(decoder->opcode, "andl")) andl(decoder); // If opcode is "andl", 
        // then call function andl.
    if (strstr(decoder->opcode, "leave")) leave(decoder, registers, memory);  
        // If opcode is "leave", then call function leave.
    if (strstr(decoder->opcode, "movl")) movl(decoder); // If opcode is "movl",
        //then call function movl. 
    if (strstr(decoder->opcode, "pushl")) pushl(decoder, registers, memory);
        // If opcode is "pushl", then call function pushl.
    if (strstr(decoder->opcode, "ret")) ret(registers, memory); // If opcode is
        // "ret", then call function ret.
    if (strstr(decoder->opcode, "subl")) subl(decoder); // If opcode is "subl",
        //then call function subl.
} // This function simulates the CPU execution on memory based
  // on opcode and operands.
