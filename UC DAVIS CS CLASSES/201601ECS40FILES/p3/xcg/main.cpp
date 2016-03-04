//
//  main.cpp
//  p3
//
//  Created by Chengeng Xiao on 1/31/16.
//  Copyright © 2016 Chengeng Xiao. All rights reserved.
//

#include "decoder.h"
#include "registers.h"
#include "reader.h"
#include "instruction.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
    Reader reader;
    Decoder decoder;
    Registers registers;
    int memory[sizeMenmory];
    Instruction curInstruction;
    
    registers.initialize(memory);
    reader.reading(argv[1]);
    
    while (registers.get(eip))
    //for (int i = 0; i < 15; i++)
    {
        reader.fetch(&curInstruction, &registers);
        decoder.parse(&curInstruction, &registers, memory);
        decoder.execute(&registers, memory);
        registers.print(&curInstruction);
    } // This loop fetch instructions from reader 1 line each time, then decode
      // and execute it until eip is zero.
    return 0;
} // main()