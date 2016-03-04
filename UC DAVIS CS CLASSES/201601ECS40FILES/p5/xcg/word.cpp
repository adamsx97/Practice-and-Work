// author Ziyue Gao, Chengeng Xiao, Feb. 15, 2016 23:23

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "word.h"

Word::Word(int addresstook)
{
    address = addresstook;
} // word constructor

Word::~Word()
{
} // destru

bool Word::operator< (const Word& word)
{

    if (word.address > address)
    {

        return true;
    
    } // if the word's address is gt address return true 

    return false;
} // check the value of word's address