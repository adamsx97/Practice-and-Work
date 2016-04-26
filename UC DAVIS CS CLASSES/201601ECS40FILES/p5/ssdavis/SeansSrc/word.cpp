// Author: Sean Davis
#include <iostream>
#include "word.h"
using namespace std;

Word::Word(int addr): address(addr) 
{
  
} // Word()


Word::~Word()
{
} // ~Word()

bool Word::operator< (const Word &rhs) const
{
  return address < rhs.address;
}  // operator<()



