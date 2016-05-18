#ifndef MemManH
#define MemManH
#include "mynew.h"
#include "MemCheck.h"
#include "SplayTree.h"

typedef struct
{
	int proc, address, opNum, size;
} MEM_SPACE;

class MemMan
{
  private:
  	SplayTree<MEM_SPACE> splayTree;
  public:
  MemMan(int ram, int proc, int op, MemCheck &memCheck);
  ~MemMan();
  bool access(int proc, int address, int opNum, MemCheck &memCheck, char print);
  void endProc(int proc, int opNum, MemCheck &memCheck, char print);
  int alloc(int proc, int opNum, int size, MemCheck &memCheck, char print);
  void deAlloc(int proc, int opNum, int startAddress, MemCheck &memCheck, char print );
}; // class MemMan

#endif
