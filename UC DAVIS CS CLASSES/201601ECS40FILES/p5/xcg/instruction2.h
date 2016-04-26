// author: Sean Davis
// edited by Ziyue Gao, Chengeng Xiao, Feb. 16, 2016 01:44

#ifndef INSTRUCTION2_H
#define	INSTRUCTION2_H

using namespace std;

class Instruction2
{
private:

  int address;
  char *info;

public:
	
  Instruction2();
  ~Instruction2();
  int getAddress() const;
  const char* getInfo() const;
  void setAddress(int addr);
  void setInfo(const char* information);
  
}; //class Instruction

#endif	// INSTRUCTION2_H 

