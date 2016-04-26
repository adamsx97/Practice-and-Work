//
//  decoder.h
//  p1
//
//  Created by Chengeng Xiao on 1/19/16.
//  Copyright © 2016 Chengeng Xiao. All rights reserved.
//

#ifndef instructionH
#define instructionH

typedef struct Instruction
{
    char *info; //  String of instruction's content. 
    int address; // Instruction's address 
} Instruction; // Define the Instruction struct type, containing a string of
               // instruction information and a integer of the addrees.

#endif //Define decoder.h
