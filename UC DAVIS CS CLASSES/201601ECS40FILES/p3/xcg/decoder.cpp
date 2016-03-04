//
//  decoder.cpp
//  p3
//
//  Created by Chengeng Xiao on 1/31/16.
//  Copyright © 2016 Chengeng Xiao. All rights reserved.
//

#include "decoder.h"
#include "registers.h"
#include "instruction.h"
#include <iostream>
#include <cstring>

using namespace std;

void Decoder::parse(Instruction* curInstruction, Registers* registers,
                    int memory[])
{
    char buffer[100], *seperator; // A pointer used for strtok 
                     //to seperate the instruction line.
    seperator = strstr (curInstruction->getInfo(), "\t");

    while (seperator)
    {
        *seperator = ' ';
        seperator = strstr (curInstruction->getInfo(), "\t");
    
    } // Change tabs into spaecs.
    
    strcpy(buffer, curInstruction->getInfo());
    seperator = strtok(buffer, " ");
    strcpy(opcode, seperator);
    seperator = strtok(NULL, " ");
    operand1 = registers->address(seperator, memory);
    seperator = strtok(NULL, " ");
    operand2 = registers->address(seperator, memory); 
} // The function parses a line of instruction in to opcode and operands. 

void Decoder::addl()
{
    *operand2 = *operand1 + *operand2;
} // Add *operand1 and operande2 and put the ans in *operand2.

void Decoder::andl()
{
    *operand2 = *operand1 & *operand2;
} // Bitwise AND *operand1 and *operand2 and put ans in *operand2. 

void Decoder::leave(Registers* registers, int memory[])const
{
    registers->set(esp, registers->get(ebp));
    registers->set(ebp, memory[registers->get(esp)]);
    registers->set(esp, registers->get(esp) + 4);
} // Copy value in ebp to esp, then copy value in memory specified by esp to
  // ebp, and add 4 to esp.

void Decoder::movl()
{
    *operand2 = *operand1;
} // Copy info from *operand1 into *operand2.

void Decoder::pushl(Registers* registers, int memory[])const
{
    registers->set(esp, registers->get(esp) - 4);
    memory[registers->get(esp)] = *operand1;
} // Subtract 4 from esp, place the *operand1 info at location specified by esp.

void Decoder::ret(Registers* registers, int memory[])const
{
    registers->set(eip, memory[registers->get(esp)]);  
    registers->set(esp, registers->get(esp) + 4);
} //  

void Decoder::subl()
{
    *operand2 = *operand2 - *operand1;
} // Subtract *operand1 from *operand2 and put the result in *operand2

void Decoder::execute(Registers* registers, int memory[])
{
    
    if (strstr(opcode, "addl")) addl(); // If opcode is "addl",
        // then call function addl.
    if (strstr(opcode, "andl")) andl(); // If opcode is "andl", 
        // then call function andl.
    if (strstr(opcode, "leave")) leave(registers, memory);  
        // If opcode is "leave", then call function leave.
    if (strstr(opcode, "movl")) movl(); // If opcode is "movl",
        //then call function movl. 
    if (strstr(opcode, "pushl")) pushl(registers, memory);
        // If opcode is "pushl", then call function pushl.
    if (strstr(opcode, "ret")) ret(registers, memory); // If opcode is
        // "ret", then call function ret.
    if (strstr(opcode, "subl")) subl(); // If opcode is "subl",
        //then call function subl.
} // This function simulates the CPU execution on memory based
  // on opcode and operands.
