#ifndef MEMORY_H
#define	MEMORY_H

#include <iostream>
#include "word.h"
#include "instruction.h"
using namespace std;


class Registers;
class Memory;

class ListNode
{
  Word *word;
  ListNode *next;
  ListNode(Word *wrd, ListNode *n);
  ~ListNode();
  friend class Memory;
};  // class ListNode


class Memory
{
  ListNode *head;
public:
  Memory();
  ~Memory();
  const Instruction& fetch(Registers *registers);
  void insert(Word *word);
  const Word& operator[] (int address)const;
  Word& operator[] (int address);
  friend istream& operator>> (istream &is, Memory &memory);
}; // class memory 

#endif	// MEMORY_H

