#ifndef MemManH
#define MemManH
#include "mynew.h"
#include "MemCheck.h"
#include "SplayTree.h"
#include "addressInfo.h"
#include "QuadraticProbing.h"
#include "QuadraticProbing2.h"

class MemMan
{
  int RAM;
  int procs;
  int ops;
  SplayTree <AddressInfo> trees[100];
  AddressInfo *freeList;
  int freeCount;
  int maxFreeCount;
  QuadraticHashTable beginTable;
  QuadraticHashTable2 endTable;
  void endProc2(int proc, int opNum, MemCheck &memCheck, SplayBinaryNode<AddressInfo> *t );
public:
  MemMan(int ram, int proc, int op, MemCheck &memCheck);
  ~MemMan();
  bool access(int proc, int address, int opNum, MemCheck &memCheck, char print);
  void endProc(int proc, int opNum, MemCheck &memCheck, char print);
  int alloc(int proc, int opNum, int size, MemCheck &memCheck, char print);
  void deAlloc(int proc, int opNum, int startAddress, MemCheck &memCheck, char print );
}; // class MemMan

#endif
