// 2016-03-31 19:58
// Author Chengeng Xiao and Srikanth Cherukuri 
// ECS60 HW1

#include <iostream>
#include "LongInt.h"

using namespace std;

LongInt LongInt::operator+(LongInt& obj)
{
  LongInt int3;
  int flag = 0;
  int ans;

  while (!this->data.isEmpty() && !obj.data.isEmpty())
  {
    ans = 0;
    if (flag == 1)
       ans = 1;
    flag = 0;
    ans += this->data.top() + obj.data.top();

    if (ans > 9)
    {
        flag = 1;
        ans -= 10;
    }

    int3.data.push(ans);
    this->data.pop();
    obj.data.pop();
  }
  if (!this->data.isEmpty())
  {
    while(!this->data.isEmpty())
    {
      if (flag == 1)
      {
        int3.data.push(this->data.top() + 1);
        flag = 0;
      }
      else
        int3.data.push(this->data.top());
      this->data.pop();
    }
  }
  else
    {
    while(!obj.data.isEmpty())
    {
      if (flag == 1)
      {
        int3.data.push(obj.data.top() + 1);
        flag = 0;
      }
      else
        int3.data.push(obj.data.top());
      obj.data.pop();
    }
  }
  if (flag == 1)
  {
    int3.data.push(1);
  }
  return int3;
} //Overloaded operator + for push the ans into int3.

LongInt LongInt::operator=(const LongInt& obj)
{
  this->data = obj.data;
  return *this;
} // Overloaded operator = for assign the ans into int3.

istream& operator>>(istream &is, LongInt &obj)
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

ostream& operator<<(ostream &os, LongInt &obj)
{
  while(!obj.data.isEmpty())
  {
    os << obj.data.top();
    obj.data.pop();
  } // while(): print sum one by one
  return os;
} // overload output operator
