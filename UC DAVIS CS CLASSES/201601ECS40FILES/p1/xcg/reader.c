//
//  reader.c
//  p1
//
//  Created by Chengeng Xiao on 1/19/16.
//  Copyright © 2016 Chengeng Xiao. All rights reserved.
//

#include "main.h"
#include "reader.h"
#include "registers.h"
#include "instruction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reading(Reader* reader, char* filename)
{
    FILE* fp = fopen(filename, "r"); // Open file, use file pointer point to it.
    
    if (fp == NULL) // If file pointer is null, then show error info.
       printf("fp fail\n");
    
    int sma = 100, lbuf; // sma is the simulated address, lbuf is the length of
                        // the reading string buffer.
    
    char buf[100]; // buf is the reading string buffer.
    int index = 0;
    
    while (fgets(buf, 100, fp))
    {
      if (buf[0] == '.' || buf[1] == '.' || strstr(buf, "main:"))
      // If input line start with '.' or contains word "main", then skip them.
      continue;
      lbuf = (int) strlen(buf);
      buf[lbuf-1] = '\0';
      reader->lines[index].address = sma;
      reader->lines[index].info = (char*)malloc(strlen(buf));
      strcpy(reader->lines[index].info, buf);
      index++;
      sma += 4;
    } // This while loop reads the Instructions line by line into lines[].info 
      // and put the simulated eip address into lines[].address.
    fclose(fp);
} // This function open the .s file and read instruction lines in.

void fetch(Instruction* curInstruction, Registers* registers, Reader* reader)
{
    int i;
    
    for (i = 0; i < 1000; ++i)
    {
      if(reader->lines[i].address == registers->regs[eip])
      {
         curInstruction->info = reader->lines[i].info;
         curInstruction->address = reader->lines[i].address;
         registers->regs[eip] += 4;
         return;
      } // If the line's address matches eip, pass it to current Instruction.
    } // Fetch current instruction from first to last line.
} // This function fetches the current instruction from reader instruction lines
  // according to eip address.
