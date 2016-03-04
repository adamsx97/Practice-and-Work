// author Ziyue Gao, Chengeng Xiao, Feb. 15, 2016 23:23

#include "data.h"
#include "word.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

const int& Data::get() const
{
    return num;
} // return the const reference of num

int&  Data::get()
{
    return num;
} // return the reference of num

Data::Data(int addres) : Word(addres)
{
} // initialize Data

int Data::operator= (int numtook) 
{
    num = numtook;
    return num;
} // overloaded assignment operator set num