// Author: Sean Davis

#include "decoder.h"
#include "registers.h"
#include "reader.h"
#include "instruction.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* address(Registers *registers, char *operand, int memory[])
{
    static int value;
    char regNames[4][7] = {"eax", "ebp", "esp", "eip"};
    char *ptr;
    int regNum, index;
    
    if(operand == NULL)
        return NULL;
    
    if(operand[0] == '$')
        
        // immediate mode
    {
        value = atoi(&operand[1]);
        return &value;
    } // if immediate mode
    
    for(regNum = eax; regNum <= eip; regNum++)
        if(strstr(operand, regNames[regNum]))
            break;
    
    ptr = strchr(operand, '(');
        
    if(ptr) // some form of indirect addressing
    {
        *ptr = '\0';  // terminate operand string at first '('
        index = atoi(operand);  // will return 0 if no number there!
        return  &memory[registers->regs[regNum] + index];
    } // if ptr
    else  // direct addressing
        return &(registers->regs[regNum]);
    
} // address ()

int main(int argc, char* argv[])
{
    Reader reader;
    Decoder decoder;
    Registers registers;
    int memory[sizeMenmory];
    Instruction curInstruction;
    
    initialize(&registers, memory);
    reading(&reader, argv[1]);
    
    while (registers.regs[eip])
    
    //for (int i = 0; i < 15; i++)
    {
        fetch(&curInstruction, &registers, &reader);
        parse(&decoder, &curInstruction, &registers, memory);
        execute(&decoder, &registers, memory);
        print(&curInstruction, &registers);
    } // This loop fetch instructions from reader 1 line each time, then decode
      // and execute it until eip is zero.
    return 0;
} // main()