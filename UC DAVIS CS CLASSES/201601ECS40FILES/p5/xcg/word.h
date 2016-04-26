// author Ziyue Gao, Chengeng Xiao, Feb. 15, 2016 23:23

#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <cstdlib>

class Word
{
    int address;
    
public:
 	
    Word(int addresstook);
    virtual ~Word();
    bool operator< (const Word& word);
}; // class word

#endif