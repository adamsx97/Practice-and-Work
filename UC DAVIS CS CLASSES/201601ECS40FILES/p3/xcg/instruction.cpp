//
//  instruction.cpp
//  p3
//
//  Created by Chengeng Xiao on 1/31/16.
//  Copyright © 2016 Chengeng Xiao. All rights reserved.
//

#include "instruction.h"
#include <iostream>
#include <cstring>

using namespace std;

char* Instruction::getInfo() const
{
    return info;
} //getInfo

int Instruction::getAddress() const
{
    return address;
}  // get adress

void Instruction::setInfo(const char* InfoPtr)
{
    
    if (InfoPtr != NULL)
    {
        info = new char[strlen(InfoPtr) + 1];
        strcpy(info, InfoPtr);
    } //if

    else //else
        info = NULL;
} //set info

void Instruction::setAddress(int AddressPtr) 
{
    address = AddressPtr;
} //set adress

Instruction::Instruction()
{
    info = NULL;
} //constructor

Instruction::~Instruction()
{
    
    if (info != NULL)
        delete[] info;
}  //distructor