// author Ziyue Gao, Chengeng Xiao, Feb. 17, 2016 02:59

#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "data.h"
#include "word.h"
#include "instruction.h"

class Memory;
class Registers;

class ListNode
{

    friend class Memory;

public:
    Word* word;
    ListNode* next;
    ListNode(Word* wordTook, ListNode* lnTook);
    ~ListNode();
    
}; // class ListNode

class Memory
{
    ListNode* head;

public:
    Memory();
    ~Memory();
    Word& operator[](int address);
    const Word& operator[] (int address) const;
    void insert(Word* words);
    const Instruction& fetch(Registers *registers);
    friend istream& operator>> (istream &is, Memory &Memory);
}; // class Memory

#endif
