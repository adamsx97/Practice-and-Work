// 2016-03-31 19:58
// Author Chengeng Xiao and Srikanth Cherukuri 
// ECS60 HW1

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
    buf = new ListNode(this->pop_back() + addl.pop_back());
    ans->insertH(buf);
  } // do addings

  if (!this->isempty())
    while(addl.isempty())
    {
      buf = new ListNode(addl.pop_back());
      ans->insertH(buf);
    } // do the unequal length parts
  else // ditto
    while(this->isempty())
    {
      buf = new ListNode(this->pop_back());
      ans->insertH(buf);
    } // do the unequal length parts
    
  return ans;
} // Overloaded operator + for push the ans into int3.

void LongInt::operator = (LongInt& ans)
{
  head = ans.head;
  tail = ans.tail;
} // Overloaded operator = for push the ans into int3.

ostream& LongInt::operator<<(std::ostream& os, LongInt& obj)
{
  curr = head;
  while (curr != NULL)
  {
    os << curr->num;
    curr = curr -> next;
  } // print()
  os << endl;
  return os;
}
istream& LongInt::operator>>(std::istream& is, LongInt& obj)
{
  char c;
  int a;
  ListNode* newLN;
  while( is.get(c)){
      if(!isdigit(c)) {
            break;
        }

      a = c-48;
      newLN = new ListNode(a);
      this -> insertT(newLN);
    }

    return is;
}
