// 2016-03-31 19:58
// Author Chengeng Xiao and Srikanth Cherukuri 
// ECS60 HW1

#include <iostream>
#include "LongInt.h"

using namespace std;

LongInt operator+(const LongInt &add1, const LongInt &add2)
{
  ListNode* temp1, temp2, buf;
  LongInt ans;
  temp1 = add1.tail;
  temp2 = add2.tail;
  while (temp1 != NULL && temp2 != NULL)
  {
    buf = new ListNode(temp1->num + temp2->num);
    ans.insertH(buf);
    temp1 = temp1->prev;
    temp2 = temp2->prev;
  } // do addings

  if (temp1 == NULL)
    while (temp2 != NULL)
    {
      buf = new ListNode(temp2->num);
      ans.insertH(buf);
      temp2 = temp2->prev;
    }
  else
    while (temp1 != NULL)
    {
      buf = new ListNode(temp1->num);
      ans.insertH(buf);
      temp1 = temp1->prev;
    }
  return ans;
}

istream& LongInt::operator>>(istream& is, LongInt& obj)
{
  char c;
  obj.data.makeEmpty();

  while(is.get(c))
  {
    if(!isdigit(c)) break;
    obj.data.push(c - 48); 
  } // while(): read character by character break at the end of line

  return is;
} // overload input operator

ostream& LongInt::operator<<(ostream& os, LongInt& obj)
{
  while(!obj.data.isEmpty())
  {
    os << obj.data.top();
    obj.data.pop();
  } // while(): print sum one by one
  return os;
} // overload output operator
