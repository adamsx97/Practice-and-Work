#ifndef REGISTERS_H
#define	REGISTERS_H

using namespace std;
#include "registers.h"
#include "labels.h"
#include <iostream> 
#include <fstream> 
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "labels.h"
// Author: Sean Davis

 
class Registers 
{
static const int ZF = 0x40, SF = 0x80;
public:
  int regs[6];
  typedef enum {eax, ebp, esp, eip, edx, flags} RegName;
  Registers();
  int* address(char *ptr, int memory[], Labels *labels);
  int get(Registers::RegName regName) const;
  friend ostream& operator<< (ostream &out, Registers &registers);
  int operator+= (int n); 
  void set(Registers::RegName regName, int value);
  int* scaledindexMode(char *str, int memory[]); 
  int* stringToRegNum(char* reg);  
  void setFlags (int n);  
  bool getSF() const;  
  bool getZF() const; 

 
}; // class Registers




#endif	// REGISTERS_H 

