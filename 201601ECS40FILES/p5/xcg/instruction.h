// Author: Sean Davis
// Edited by Ziyue Gao, Chengeng Xiao, Feb. 16, 2016 02:21

#ifndef INSTRUCTION_H
#define	INSTRUCTION_H
#include "word.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Instruction : public Word
{
private:

  char *info;

public:

  Instruction(int addresTook);
  ~Instruction();
  const char* getInfo() const;
  void operator= (const char* infoTook);
  friend ostream& operator<< (ostream &os, const Instruction &instruction);

}; //class Instruction

#endif	// INSTRUCTION_H 

