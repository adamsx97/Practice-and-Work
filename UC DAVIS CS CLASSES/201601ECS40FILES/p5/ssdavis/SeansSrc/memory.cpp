// Author: Sean Davis

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "memory.h"
#include "instruction.h"
#include "word.h"
#include "data.h"
#include "registers.h"

using namespace std;

 ListNode::ListNode(Word *wrd, ListNode *n) : word(wrd), next(n) 
 {
 }  // ListNode
 
 
ListNode::~ListNode()
{
  delete word;
}  // ~ListNode()


Memory::Memory(): head(NULL) 
{
} // memory()

Memory::~Memory() 
{
  for(ListNode *ptr = head; ptr; ptr = head)
  {
    head = ptr->next;
    delete ptr;
  } // for each ListNode
} // ~Memory()



const Instruction& Memory::fetch(Registers *registers)
{
   const Instruction &instruction 
     = dynamic_cast <Instruction&> ((*this)[registers->get(Registers::eip)]);
   registers->set(Registers::eip, registers->get(Registers::eip) + 4);
   return instruction;
} // fetch()

void Memory::insert(Word *word)
{
  ListNode *ptr, *prev = NULL;

  for(ptr = head; ptr && *ptr->word < *word; ptr = ptr->next)
    prev = ptr;

  if(prev)
    prev->next = new ListNode(word, ptr);
  else  // inserting node at front of list
    head = new ListNode(word, ptr);
} // insert()


const Word& Memory::operator[] (int address)const
{
  ListNode *ptr;
  
  for(ptr = head; ptr && *ptr->word < Word(address); ptr = ptr->next);
    
  if(ptr && ! (Word(address) < *ptr->word))
    return *ptr->word;
  else  // address not found
  {
    cout << "Seg fault at address: " << address << endl;
    exit(1);
  }  // address not found
}  // const operator[]  
  

Word& Memory::operator[] (int address)
{
  ListNode *ptr;

  for(ptr = head; ptr && *ptr->word < Word(address); ptr = ptr->next);
   
  if(ptr && ! (Word(address) < *ptr->word))
    return *ptr->word;
  else  // address not found
  {
    Data *data = new Data(address);
    insert(data);
    return *data;
  }  // else not found
} // non-const operator[]




istream& operator>> (istream &is, Memory &memory)
{
  char line[256], *ptr;
  int address = 100;
  
  while(is.getline(line, 256))
  {
    for(ptr = strchr(line, '\t'); ptr; ptr = strchr(line, '\t'))
      *ptr = ' ';  // replace all tabs with space characters
    
    for(ptr = line; *ptr == ' '; ptr++);  // get past leading spaces
    
    if(isalpha(*ptr)  && !strchr(line, ':'))
    {
      Instruction *instruction = new Instruction(address);
      *instruction = ptr;
      memory.insert(instruction);
      address += 4;
    } // if not directive, nor main:
  }  // while more in file
  
  return is;
}  // operator>>)


