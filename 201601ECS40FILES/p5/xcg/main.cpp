// Author: Sean Davis
// Edited by Ziyue Gao, Chengeng Xiao, Feb. 16, 2016 02:21

#include <fstream>
#include <iomanip>
#include <iostream>
#include "registers.h"
#include "decoder.h"
#include "instruction.h"
#include "instruction2.h"
#include "labels.h"
#include "memory.h"
#include "word.h"
#include "data.h"

using namespace std;


int main(int argc, char* argv[])
{
    Decoder decoder;
    Registers registers;
    Labels labels;
    Memory memory;
    Data* data;

    data = new Data(1000);
    *data = 0;
    memory.insert(data);
    data = new Data(992);
    *data = 0;
    memory.insert(data);

    ifstream inf(argv[1]);
    inf >> memory;
    inf.clear();
    inf.seekg(0);
    inf >> labels;
    registers.set(Registers::eip, labels.find("main"));

    while(registers.get(Registers::eip) != 0)
    {
        
        const Instruction& instruction = memory.fetch(&registers);
        decoder.parse(instruction, &registers, memory, labels);
        decoder.execute(instruction, &registers, memory);
        cout << instruction << registers;
         
    } // while eip not zero

  return 0;
}  // main()