//
//  reader.h
//  p1
//
//  Created by Chengeng Xiao on 1/19/16.
//  Copyright © 2016 Chengeng Xiao. All rights reserved.
//

#ifndef readerH
#define readerH
#include "registers.h"
#include "instruction.h" 

typedef struct Reader
{
    Instruction lines[1000];
} Reader; //Define Reader struct type, containing 1000 lines of instructions
void reading(Reader* reader, char* filename);
void fetch(Instruction* curInstruction, Registers* registers, Reader* reader);

#endif // Define reader.h 
