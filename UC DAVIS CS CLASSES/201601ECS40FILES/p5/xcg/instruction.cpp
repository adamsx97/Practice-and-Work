// Author: Sean Davis
// Edited by Ziyue Gao, Chengeng Xiao, Feb. 16, 2016 02:21

#include "instruction.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include "word.h"

using namespace std;

Instruction::Instruction(int addresTook) : Word(addresTook), info(NULL)
{
}  // Instruction()


Instruction::~Instruction()
{
  if(info)
    delete [] info;
}  // ~Instruction

const char* Instruction::getInfo() const
{
  return info;
} // get()

void Instruction::operator= (const char* infoTook)
{
  this->info = new char[strlen(infoTook) + 1];
  strcpy(this->info, infoTook);
} // setInfo() by assignment overloaded operator

ostream& operator<< (ostream &os, const Instruction &instruction)
{
    os << left << setw(20) << instruction.info;
    return os;
} // cout instruction Information Line.
