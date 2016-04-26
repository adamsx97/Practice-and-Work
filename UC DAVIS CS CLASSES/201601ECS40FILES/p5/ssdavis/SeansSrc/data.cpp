// Author: Sean Davis

#include "data.h"

Data::Data(int addr) : Word(addr)
{
} // Data()


const int& Data::get() const
{
  return num;
}  // get()

int& Data::get()
{
  return num;
}  // get()


Data& Data::operator=(int value)
{
  num = value;
  return *this;
}  // set()
