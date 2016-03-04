#ifndef READER_H
#define	READER_H
// Author: Sean Davis

#include "instruction.h"
#include "registers.h"
#include <iostream> 
#include <fstream> 
#include <iomanip>
#include <cstdlib>
#include <cstring>
using namespace std; 


class Reader
{
  Instruction lines[1000];
public:
  void fetch(Instruction *instruction, Registers *registers);
  friend ifstream& operator>> (ifstream &inf, Reader &reader);
}; // Reader;


#endif	// READER_H 

