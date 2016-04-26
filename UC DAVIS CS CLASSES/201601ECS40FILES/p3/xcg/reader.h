//
//  reader.h
//  p3
//
//  Created by Ziyue Gao on 1/31/16.
//  Copyright © 2016 Chengeng Xiao. All rights reserved.
//

#ifndef readerH
#define readerH
#include "registers.h"
#include "instruction.h"

using namespace std;


class Reader
{
private:
    Instruction lines[1000];
public:
    void reading(char* filename);
    void fetch(Instruction* curInstruction, Registers* registers);
}; //Define Reader class type, containing 1000 Lines of instructions

#endif
