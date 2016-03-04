// Author: Sean Davis

#include <iostream> 
#include <fstream> 
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "registers.h"
using namespace std;
Labels labels;
 Registers::Registers()
{
  regs[esp] = 1000;
  regs[ebp] = 996;
  regs[eip] = 100;
  regs[eax] = 0;
  regs[edx] = 0; 
  regs[flags] = 0xC0; 
}  // initialize()

int* Registers::address(char *operand, int memory[], Labels *labels)
{
  static int value;
  char regNames[6][7] = {"eax", "ebp", "esp", "eip", "edx", "flags"};
  char *ptr;
  int regNum, index;

  if(operand == NULL)
    return NULL;

  if ((operand[0] == '.'&& operand[1]=='L')||operand[0] =='_') 
    return &memory[labels->find(operand)]; 

  if(operand[0] == '$') // immediate mode
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
    return  &memory[regs[regNum] + index];
  } // if ptr
  else  // direct addressing
    return &(regs[regNum]);
} // address ()

int* Registers::scaledindexMode(char *str, int memory[]) 
{ 
  int offset, scale,i; 
  char *ptr, *ptr1,str1[100];


for (i=0;i<strlen(str);i++)
{
  if (str[i] == '(')
    break;
  str1[i] = str[i];  
}
offset = atoi(str1);


stringToRegNum(strchr (str, ',')); 
scale = atoi(strchr (str, ')')); 

}// scaledindexmode

int * Registers::stringToRegNum(char* ptr) 
{
   int regNum; 
char regNames[6][7] = {"eax", "ebp", "esp", "eip", "edx", "flags"};
if(ptr) // some form of indirect addressing
  {
    *ptr= '\0';  // terminate operand string at first '('  
  for(regNum = eax; regNum <= eip; regNum++)
    if(strstr(ptr, regNames[regNum]))
      break;

    return &(regs[regNum]);

  }
}



int Registers::get(Registers::RegName regName) const
{
  if(regName < eax || regName > eip)
    return 0;
  
  return regs[regName];
}  // get()


  ostream& operator<< (ostream &out, Registers &registers) 
  {
    out << setw(3)  << " eip: " << setw(3) 
    << registers.regs[Registers::eip] << " eax: " << setw(3) << registers.regs[Registers::eax]
    << " ebp: " << setw(3) << registers.regs[Registers::ebp] << " esp: "
    << setw(3) << registers.regs[Registers::esp] << "edx: " << setw(3) << registers.regs[Registers::edx] << "flags: "
    << setw(3) << registers.regs[Registers::flags]<< endl; 
    return out;
  }

  int Registers::operator+= (int n)
    {
    regs[Registers::esp] = regs[Registers::esp] +n ;
    return regs[Registers::esp];
  }

 


void Registers::set(RegName regName, int value)
{
  if(regName >= eax && regName <= eip)
    regs[regName] = value;
} // set()

void Registers::setFlags (int n) 
{
  if (n <0) 
    {
      regs[flags] |= SF; 
    }
  
  else regs[flags] &= ~SF; 
  

  if (n ==0 )
    {
    regs[flags] |=ZF;  
    }
  else
    {
    regs[flags] &= ~ZF; 
    }
}

bool Registers::getSF() const 
{
  return  (regs[flags] & SF); 
}

bool Registers::getZF() const 
{
  return  (regs[flags] & ZF); 
} 