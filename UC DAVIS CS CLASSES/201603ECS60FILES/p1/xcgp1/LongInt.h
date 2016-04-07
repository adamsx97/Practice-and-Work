// 2016-03-31 19:58
// Author Chengeng Xiao and Srikanth Cherukuri 
// ECS60 HW1

#ifndef  LONGINT_H
#define  LONGINT_H
#include "StackLi.h"
#include <iostream>

using namespace std;

class LongInt
{
private:
  StackLi<int> data;
public:
  friend ostream& operator<<(ostream &os, LongInt &obj);
  friend istream& operator>>(istream &is, LongInt &obj);
  LongInt operator=(const LongInt& obj);
  LongInt operator+(LongInt& obj);

}; // class LongInt a linked list

#endif
