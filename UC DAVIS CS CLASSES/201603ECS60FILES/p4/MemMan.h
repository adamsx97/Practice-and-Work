#ifndef MemManH
#define MemManH
#include "mynew.h"
#include "MemCheck.h"
#include "SplayTree.h"

class MEMSPACE
{
	int address, size;
	MEMSPACE* next;
public:
	MEMSPACE(MEMSPACE* nextM, int address, int size);
	~MEMSPACE();
};

class MemMan
{
  private:
  	MEMSPACE** space;
  	int currAddress;
  public:
  MemMan(int ram, int proc, int op, MemCheck &memCheck);
  ~MemMan();
  bool access(int proc, int address, int opNum, MemCheck &memCheck, char print);
  void endProc(int proc, int opNum, MemCheck &memCheck, char print);
  int alloc(int proc, int opNum, int size, MemCheck &memCheck, char print);
  void deAlloc(int proc, int opNum, int startAddress, MemCheck &memCheck, char print );
}; // class MemMan

#endif
