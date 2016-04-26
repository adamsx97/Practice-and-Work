// Author: Sean Davis
#include <cstring>
#include <iostream>
#include "decoder.h"
#include "instruction.h"
#include "registers.h"
#include "labels.h"
using namespace std;

void Decoder::addl()
{
  *operand2 = *operand1 + *operand2;
}  // addl()

void Decoder::andl()
{
  *operand2 = *operand1 & *operand2;
}  // andl()

void Decoder::cmpl(Registers *registers)
{
	registers->setFlags(*operand2 - *operand1);
}

void Decoder::incl(Registers *registers)
{
	*operand1 ++;
	registers->setFlags(*operand1);
}

void Decoder::jg(Registers *registers)
{
	if (!registers->getSF() && !registers->getZF())
	{
		registers->set(eip, *operan1);
	}
}

void Decoder::jle(Registers *registers)
{
	if (registers->getSF() && registers->getZF())
	{
		registers->set(eip, *operand1);
	}
}

void Decoder::jmp(Registers *registers)
{
	registers->set(eip, *perand1);
}

void Decoder::leal(Registers *registers)
{
	registers->set(*operand2, *operand2);
}

void Decoder::execute(Registers *registers, int memory[1001])
{
  const char *opcodes[] = { "addl", "andl", "leave", "movl", "pushl", "ret",
    "subl","cmpl","incl","jg","jle","jmp","leal"};
  enum OpcodeNum {ADDL, ANDL, LEAVE, MOVL, PUSHL, RET, SUBL, CMPL, INCL, JG, JLE, JMP, LEAL};
  int opcodeNum;
  
  for(opcodeNum = ADDL; 
    strcmp(opcode, opcodes[opcodeNum]) != 0 || opcodeNum > SUBL;
    ++opcodeNum);
  
  switch (opcodeNum)
  {
    case ADDL: addl(); break;
    case ANDL: andl(); break;
    case LEAVE: leave(registers, memory); break;
    case MOVL: movl(); break;
    case PUSHL: pushl(registers, memory); break;
    case RET: ret(registers, memory); break;
    case SUBL: subl(); break;
    case CMPL: cmpl(Registers *registers); break;
    case INCL: incl(Registers *registers); break;
    case JG: jg(Registers *registers); break;
    case JLE: jle(Registers *registers); break;
    case JMP: jmp(Registers *registers); break;
    case LEAL: leal(Registers *registers); break;
    default: cout << "Invalid opcode!\n";
  } // switch on oncodeNum
 
}  // execute()

void Decoder::leave(Registers *registers, int memory[1001]) const
{
  //registers += (-1)*(registers+=0)+(registers->get(Registers::ebp)); //only god knows 
 // registers->set(Registers::esp, registers->get(Registers::ebp));
  registers->set(Registers::ebp, memory[registers->get(Registers::esp)]);
  registers +=4; 
  //registers->set(Registers::esp, registers->get(Registers::esp) + 4);
}  // leave()


void Decoder::movl()
{
  *operand2 = *operand1;
}  // movl()


void Decoder::parse(Instruction *instruction, Registers *registers, 
                    int memory[1001], Labels *labels)
{
  char *ptr, info[1000];
  
  strcpy(info, instruction->getInfo());
  strcpy(opcode, strtok(info, " "));
  ptr = strtok(NULL, " ");
  
  if(ptr)
  {
    operand1 = registers->address(ptr, memory, labels);
    ptr = strtok(NULL, " ");
    
    if(ptr)
      operand2 = registers->address(ptr, memory,labels);
  } // if there is at least one operand
}  // parse()





void Decoder::pushl(Registers *registers, int memory[1001]) const
{
  registers += -4; 
 // registers->set(Registers::esp, registers->get(Registers::esp) - 4);
  memory[registers->get(Registers::esp)] = *operand1;
}  // pushl()


void Decoder::ret(Registers *registers, int memory[1001]) const
{
  registers->set(Registers::eip, memory[registers->get(Registers::esp)]);
  registers += 4; 
  //registers->set(Registers::esp, registers->get(Registers::esp) + 4);
}  // ret()


void Decoder::subl()
{
  *operand2 = *operand2 - *operand1;
}  // subl()
