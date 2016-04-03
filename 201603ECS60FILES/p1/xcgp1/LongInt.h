// 2016-03-31 19:58
// Author Chengeng Xiao and Srikanth Cherukuri 
// ECS60 HW1
#include <iostream>
#ifndef	 LONGINT_H
#define  LONGINT_H

class ListNode
{
public:
	ListNode *prev, *next;
	int num;
	ListNode(int n) : prev(NULL), next(NULL), num(n) {}
	friend class LongInt;
}; // class ListNode

class LongInt
{
	ListNode *head, *tail, *curr;
public:
	LongInt() : head(NULL), tail(NULL), curr(NULL) {}
	void insertT(ListNode *newLN);
	void insertH(ListNode *newLN);
	bool isempty();
	int pop_back();
	friend std::ostream& operator<<(std::ostream& os, LongInt& obj);
	friend std::istream& operator>>(std::istream& is, LongInt& obj);
	friend void operator=(const LongInt& object);
	friend LongInt operator+(const LongInt& object);

}; // class LongInt a linked list
#endif
