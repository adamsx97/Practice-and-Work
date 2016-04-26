// Author: Sean Davis

#include <iostream> 
#include <fstream> 
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstring>

#include "registers.h"
#include "decoder.h"
#include "reader.h"
#include "labels.h"
#include "instruction.h"


using namespace std; 


int main(int argc, char* argv[])
{
  Reader reader;
  Decoder decoder;
  Registers registers;
  Labels labels;
  Instruction instruction;
  int memory [1001];
  memory[1000] = 0;
  ifstream inf(argv[1]);
  inf >> reader;   
  inf.clear();
  inf.seekg (0); 
  inf >> labels;

while(registers.get(Registers::eip) != 0)
  {
    reader.fetch(&instruction, &registers);
    decoder.parse(&instruction, &registers, memory, &labels);
    decoder.execute(&registers, memory);
    printf("%s\n", instruction.getInfo());
    cout<<registers;
  } // while eip not zero
  

  return 0;
}  // main()

