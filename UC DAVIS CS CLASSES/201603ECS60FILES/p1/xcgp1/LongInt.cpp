// 2016-03-31 19:58
// Author Chengeng Xiao and Srikanth Cherukuri 
// ECS60 HW1

#include <iostream>
#include <string>
#include "LongInt.h"

using namespace std;

typedef string::iterator SIT;

LongInt::LongInt()
{
  head = NULL;
  tail = NULL;
  curr = NULL;
} //constructor

void LongInt::insert(ListNode *newLN)
{
  tail->next = newLN;
  newLN->prev = tail;
  tail = newLN;
} // insert()

bool LongInt::isempty()
{
  if(head)
    return 1;
  return 0;
} // isempty()

int LongInt::pop_back()
{
  int buf;
  if(tail != head)
    tail = tail->prev;
  else
    head = NULL;
  return buf;
} // pop_back()

int main() {
  LongInt int1, int2, int3;
  cout << "Please enter first long integer >> ";
  cin >> int1;
  cout << "Please enter second long integer >> ";
  cin >> int2;
  int3 = int1 + int2;
  cout << int3 << endl;
  return 0;
} // main()
