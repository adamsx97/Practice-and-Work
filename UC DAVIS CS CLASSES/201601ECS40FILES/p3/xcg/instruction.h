//
//  instruction.h
//  p3
//
//  Created by Chengeng Xiao on 1/30/16.
//  Copyright © 2016 Chengeng Xiao. All rights reserved.
//

#ifndef instructionH
#define instructionH

using namespace std;

class Instruction
{
private:
    int address; // Instruction's address
    char* info; //  String of instruction's content. 
public:
    Instruction();
    ~Instruction();
    char* getInfo()const;
    int getAddress()const;
    void setInfo(const char* InfoPtr);
    void setAddress(int AddressPtr);
}; // Define the Instruction private class, containing a string
   // of instruction Information and a integer of the Addrees.

#endif //Define decoder.h
