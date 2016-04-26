#ifndef REGISTERS_H
#define	REGISTERS_H
// Author: Sean Davis

typedef struct 
{
  int regs[4];
} Registers;

void initialize(Registers *registers, int memory[1001]);
void print(Registers *registers, const char *instruction);


#endif	// REGISTERS_H 

