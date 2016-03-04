// author Ziyue Gao, Chengeng Xiao, Feb. 15, 2016 23:23

#ifndef DATA_H
#define DATA_H

#include <iostream>
#include "word.h"


class Data : public Word
{
    int num;

 public:
    Data(int addres);
    int operator= (int numtook);
    const int& get()const;
    int& get(); 
}; // data class;

#endif
