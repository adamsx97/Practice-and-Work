#include <iostream>
#include "MemMan.h"
#include "mynew.h"
#include "MemCheck.h"


using namespace std;


MemMan::MemMan(int ram, int proc, int op, MemCheck &memCheck) 
{
  currAddress = 0;
  space = new MEM_SPACE[100];
  for (int i = 0; i < 100; ++i)
  {
    space[i] = NULL;
  }
}// MemMan()


MemMan::~MemMan()
{
  
} // ~MemMan()



bool MemMan::access(int proc, int address, int opNum, MemCheck &memCheck, 
  char print)
{
  if(print != '0')
    cout << "Opnum: " << opNum << " access: proc: " << proc << " address: " << address << endl;
  
  // memCheck.printCurrentAllocations(proc);
 // memCheck.printOwner(address, address);
  

  MEM_SPACE *ptr = space[proc];
  while(ptr && ptr->address + ptr->size => address)
    ptr = ptr->next;
  if(ptr)
    return true;
  else
    endProc(proc, opNum, memCheck, print);
    return true;
  // If seg fault, then free all memory assigned to the process, and return false.
  // If legitimate access, then return true;
}  // access()

int MemMan::alloc(int proc, int opNum, int size, MemCheck &memCheck, char print)
{
  int address = 0;  // to avoid warnings 
  
  if(print != '0')
    cout << "Opnum: " << opNum << " alloc: proc: " << proc << " address: " 
      << address << " size: " << size << endl;
  address = currAddress;
  MEM_SPACE* newNode;
  newNode->size = size;
  newNode->address = address;
  splayTree.insert(newNode);
  // memCheck.printOwner(address, endAddress);
  // memCheck.printCurrentAllocations(proc);
  // allocates a block of the specified size, and returns its address.
  return address;
} // alloc()


void MemMan::deAlloc(int proc, int opNum, int startAddress, MemCheck &memCheck,
  char print)
{
  if (print != '0')
    cout << "Opnum: " << opNum << " daAlloc: proc: " << proc << " startAddress: " << startAddress << endl;
  MEM_SPACE nodeToDeAlloc;
  nodeToDeAlloc =  splayTree.find( );
  splayTree.remove(nodeToDeAlloc);
  //  memCheck.printCurrentAllocations(proc);
  // memCheck.printOwner(startAddress, endAddress);
 
} // deAlloc()


void MemMan::endProc(int proc, int opNum, MemCheck &memCheck, char print)
{
  if(print != '0')
    cout << "Opnum: " << opNum << " endProc: proc: " << proc << endl;
  splayTree.makeEmpty();
   // memCheck.printCurrentAllocations(proc);
  // free all memory assigned to proc.
} // endProc()


