#ifndef INSTRUCTION_H
#define	INSTRUCTION_H
// Author: Sean Davis

#include <iostream>
#include "word.h"
using namespace std;

class Instruction : public Word
{
  char *info;
public:
  Instruction(int addr);
  ~Instruction();
  const char* getInfo() const;
  Instruction& operator= (const char* information);
  friend ostream& operator<< (ostream &os, const Instruction &rhs);
}; //class Instruction

#endif	// INSTRUCTION_H 

