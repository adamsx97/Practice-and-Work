//
//  reader.cpp
//  p3
//
//  Created by Ziyue Gao on 1/31/16.
//  Copyright © 2016 Chengeng Xiao. All rights reserved.
//

#include "reader.h"
#include "registers.h"
#include "instruction.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

void Reader::reading(char* filename)
{
    ifstream inf; // Use inf to get file input.
    inf.open(filename); // Open file, get input. 

    if (filename == NULL) // If filename is null, then show error info.
        cout << "file open fail" << endl;
    
    int sma = 100; // sma is the simulated address
    char buf[100]; // buf is the reading string buffer.
    int index = 0;
    
    while (inf. getline(buf, 100))
    {
      if (buf[0] == '.' || buf[1] == '.' || strstr(buf, "main:"))
      // If input line start with '.' or contains word "main", then skip them.
          continue;
      lines[index].setAddress(sma);
      lines[index].setInfo(buf);
      index++;
      sma += 4;
    }// This while loop reads the Instructions line by line into lines[].info 
     // and put the simulated eip address into lines[].address.
    //inf.close(filename);
} // This function open the .s file and read instruction lines in.

void Reader::fetch(Instruction* curInstruction, Registers* registers)
{
    int i;
    
    for (i = 0; i < 1000; ++i)
    {
      if(lines[i].getAddress() == registers->get(eip))
      {
         curInstruction->setInfo(lines[i].getInfo());
         curInstruction->setAddress(lines[i].getAddress());
         registers->set(eip, registers->get(eip) + 4);
         return;
      } // If the line's address matches eip, pass it to current Instruction.
    } // Fetch current instruction from first to last line.
} // This function fetches the current instruction from reader instruction lines
  // according to eip address.