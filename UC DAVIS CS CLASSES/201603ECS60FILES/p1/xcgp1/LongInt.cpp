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
while (!this->isEmpty() && !obj.isEmpty())
{
    if (flag == 1)
    {
        ans = 1;
    }
    flag = 0;
    int a = this->top();
    int b = obj.top();
    ans = ans + a + b;
    if (ans > 9)
    {
        flag = 1;
        ans -= 10;
    }
    int3.insert(ans);
    this->pop();
    obj.pop();
    return *this;
} // Overloaded operator + for push the ans into int3.

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
  os << endl;
  return os;
} // overload output operator
