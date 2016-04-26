// author Ziyue Gao, Chengeng Xiao, Feb. 17, 2016 02:59

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "memory.h"
#include "data.h"
#include "word.h"
#include "registers.h"
#include "instruction.h"

using namespace std;

Memory::Memory()
{
    head = NULL;
} // initialize Memory set head to NULL

Memory::~Memory()
{

    for(ListNode* curLN = head; curLN != NULL; curLN = curLN->next)
    {
        delete curLN;
    } // delete all the ListNode
} // destru the whole linked list

Word& Memory::operator[](int address)
{

    Word words (address);

    for(ListNode* curLN = head; curLN != NULL; curLN = curLN->next)
    {

        if (!(words < *(curLN->word)) && !(*(curLN->word) < words))
        {
            return *(curLN->word);
        } // if

    } // check each node

    Data *datas = new Data(address);
    insert(datas);
    return *datas;
} // reload

const Word& Memory::operator[] (int address) const
{
    Word words (address);
    
    for(ListNode* curLN = head; curLN != NULL; curLN = curLN->next)
    {

        if (!(words < *(curLN->word)) && !(*(curLN->word) < words))
        {
            return *(curLN->word);
        } // if

    } // check each node

    cerr << "Seg fault at address: <" << address << ">" << endl;
    exit(1);
} // reload

const Instruction& Memory::fetch(Registers *registers)
{
  int pos;
  pos = registers->get(Registers::eip);
  Word& word = (*this) [pos];
  registers->set(Registers::eip, registers->get(Registers::eip) + 4);
  
  return static_cast<Instruction&>(word); // duoxidie
} // fetch()

istream& operator>> (istream &is, Memory &memory)
{
  char line[256], *ptr;
  int address = 100;
  
  while(is.getline(line, 256))
  {
    for(ptr = strchr(line, '\t'); ptr; ptr = strchr(line, '\t'))
      *ptr = ' ';  // replace all tabs with space characters
    
    for(ptr = line; *ptr == ' '; ptr++);  // get past leading spaces
    
    if(*ptr != '.' && *ptr != '_' && !strstr(line, ":"))
    {
      Instruction *curInstruction = new Instruction(address);
      *curInstruction = ptr;
      memory.insert(curInstruction);
      address += 4;
    } // if not directive, nor main:
  }  // while more in file
  
  return is;
}  // operator>>

ListNode::ListNode(Word* wordTook, ListNode* lnTook)
{
    word = wordTook;
    next = lnTook;
} // initialize word and linked list next

ListNode::~ListNode()
{
    delete word;
} // delet Word*

void Memory::insert(Word* words)
{

    ListNode* prev = NULL;
    ListNode* curLN;
    
    for (curLN = head; (curLN != NULL) && (*curLN->word < *words);
     curLN = curLN -> next)
         {
            prev = curLN;
         }// find the node

    if (prev != NULL)
    {
        prev->next = new ListNode(words, curLN);
    } // if the node exist

    else // if the node do not exist, it is the head
        head = new ListNode(words, curLN);

    return;

} // insert
