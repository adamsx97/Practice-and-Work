// 2016-03-31 19:58
// Author Chengeng Xiao and Srikanth Cherukuri 
// ECS60 HW1

#ifndef  LONGINT_H
#define  LONGINT_H
#include "StackLi.h"

using namespace std;

class LongInt
{
private:
  StackLi<int> data;
public:
  LongInt();
  ~LongInt();
  void insert(ListNode *newLN);
  friend ostream& operator<<(ostream& os, LongInt& obj);
  friend istream& operator>>(istream& is, LongInt& obj);
  void operator=(const LongInt& object);
  LongInt operator+(const LongInt& object);

}; // class LongInt a linked list
#endif
