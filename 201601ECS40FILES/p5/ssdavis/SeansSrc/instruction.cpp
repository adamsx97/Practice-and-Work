// Author: Sean Davis
#include "instruction.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;



Instruction::Instruction(int addr) : Word(addr), info(NULL)
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


Instruction& Instruction::operator=(const char* information)
{
  info = new char[strlen(information) + 1];
  strcpy(info, information);
  return *this;
} // operator=()


 ostream& operator<< (ostream &os, const Instruction &rhs)
 {
   os << left << setw(20) << rhs.info; 
   return os;
 }  // operator<<()
