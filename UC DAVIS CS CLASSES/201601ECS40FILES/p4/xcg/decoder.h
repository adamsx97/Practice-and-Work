#ifndef DECODER_H
#define	DECODER_H
// Author: Sean Davis

#include "instruction.h"
#include "registers.h"
using namespace std; 


class Decoder
{
  char opcode[20];
  int *operand1;
  int *operand2;
  void addl();
  void andl();
  void leave(Registers *registers, int memory[1001]) const;
  void movl();
  void pushl(Registers *registers, int memory[1001]) const;
  void ret(Registers *registers, int memory[1001]) const;
  void subl();
  void cmpl(Registers *registers);
  void incl(Registers *registers);
  void jg(Registers *registers);
  void jle(Registers *registers);
  void jmp(Registers *registers);
  void leal(Registers *registers);
public:
  void execute(Registers *registers, int memory[1001]);
  void parse(Instruction *instruction, Registers *registers, int memory[1001], Labels *labels);
}; // class Decoder;



#endif	// DECODER_H 

