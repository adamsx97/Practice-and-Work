#include <iostream>
#include "LongInt.h"

using namespace std;

void LongInt::insertT(ListNode *newLN)
{
  if (head == NULL)
  {
    head = newLN;
    tail = newLN;
    return;
  }
  tail->next = newLN;
  newLN->prev = tail;
  tail = newLN;
} // insert(): insert to tail

void LongInt::insertH(ListNode *newLN)
{
  if (head == NULL)
  {
    head = newLN;
    tail = newLN;
    return;
  }
  head->prev = newLN;
  newLN->next = head;
  head = newLN;
} // insert(): insert to head


bool LongInt::isempty()
{
  if(head)
    return 0;
  return 1;
} // isempty(): return 0 if is empty

int LongInt::pop_back()
{
  int buf;
  buf = tail->num;
  if(tail != head)
    tail = tail->prev;
  else
    head = NULL;
  return buf;
} // pop_back()

LongInt LongInt::operator + (LongInt& addl)
{
  LongInt ans;
  ListNode* buf;
  while(this->isempty() && addl.isempty())
  {
    buf = new ListNode(this->pop_back() + adds.pop_back);
    this->insertH
  } // 
  return ans;
} // Overloaded operator + for push the ans into int3.

void LongInt::operator = (LongInt& ans)
{
  head = ans.head;
  tail = ans.tail;
} // Overloaded operator = for push the ans into int3.

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
