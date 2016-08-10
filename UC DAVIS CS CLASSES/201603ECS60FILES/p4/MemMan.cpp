#include <iostream>
#include "MemMan.h"
#include "mynew.h"
#include "MemCheck.h"


using namespace std;
#define MAX_RAM 1500000
#define MAX_HASH_SIZE 15000

MemMan::MemMan(int ram, int proc, int op, MemCheck &memCheck) : RAM(ram),
  procs(proc), ops(op), beginTable(MAX_HASH_SIZE), endTable(MAX_HASH_SIZE)
{
  freeList = new AddressInfo[55000];
  freeList[0] = AddressInfo(0, MAX_RAM);
  freeCount = 1;
  maxFreeCount = 1;
  beginTable.insert(AddressInfo(0, MAX_RAM));
  endTable.insert(AddressInfo(0, MAX_RAM));
}// MemMan()


MemMan::~MemMan()
{
//  cout << beginTable.maxSize << endl;
//  cout << "EndTable currentSize: " <<  endTable.currentSize << endl;
//  cout << maxFreeCount << endl;
} // ~MemMan()



bool MemMan::access(int proc, int address, int opNum, MemCheck &memCheck, 
  char print)
{
  if(print != '0')
    cout << "Opnum: " << opNum << " access: proc: " << proc << " address: " << address << endl;
  
  // memCheck.printCurrentAllocations(proc);
 // memCheck.printOwner(address, address);
  
  if(trees[proc].isEmpty())
    return false;
  
  const AddressInfo &info = trees[proc].find(AddressInfo(address, address));
  
  if(info.address < 0) // not_found
  {
    endProc(proc, opNum, memCheck, print);
    return false;
  }
  
  return true;
  // If seg fault, then free all memory assigned to the process, and return false.
  // If legitimate access, then return true;
}  // access()

int MemMan::alloc(int proc, int opNum, int size, MemCheck &memCheck, char print)
{
  int i = 0;
  AddressInfo info, info2;
  AddressInfo startInfo;
 
  while(1)
  {
    for(; freeList[i].endAddress - freeList[i].address + 1 < size; i++);
  
    startInfo = beginTable.find((AddressInfo)freeList[i]);
    if(startInfo.address == freeList[i].address 
      && startInfo.endAddress == freeList[i].endAddress)
      break;
    
    freeList[i] = freeList[--freeCount];  // found a removed 
  }  // while   
  
  info = freeList[i];
  freeList[i] = freeList[--freeCount];
  beginTable.remove(info);
  endTable.remove(info);
  
  if(info.endAddress - info.address + 1 > size)
  {
    info2 = AddressInfo(info.address + size, info.endAddress);
    info.endAddress = info.address + size - 1;
    freeList[freeCount++] = info2;
    if(freeCount > maxFreeCount)
      maxFreeCount = freeCount;
    beginTable.insert(info2);
    endTable.insert(info2);
  }  
  trees[proc].insert(info);
  
  if(print != '0')
    cout << "Opnum: " << opNum << " alloc: proc: " << proc << " address: " 
      << info.address << " size: " << size << endl;
  
//    memCheck.printOwner(address, endAddress);
  // memCheck.printCurrentAllocations(proc);
  return info.address;
} // alloc()


void MemMan::deAlloc(int proc, int opNum, int startAddress, MemCheck &memCheck,
  char print)
{
  if (print != '0')
    cout << "Opnum: " << opNum << " daAlloc: proc: " << proc << " startAddress: " << startAddress << endl;
  //  memCheck.printCurrentAllocations(proc);
  // memCheck.printOwner(startAddress, endAddress);
  AddressInfo info2, info = trees[proc].find(AddressInfo(startAddress, startAddress));
  trees[proc].remove(info);
  AddressInfo startInfo = beginTable.find(AddressInfo(info.endAddress + 1, 0));
  AddressInfo endInfo = endTable.find(AddressInfo(0,info.address - 1));

  if(startInfo.address == info.endAddress + 1)
   {
   beginTable.remove(startInfo);
   endTable.remove(startInfo);
   info.endAddress = startInfo.endAddress;
  }
  //else
    if(endInfo.endAddress == info.address - 1)
    {
      endTable.remove(endInfo);
      beginTable.remove(endInfo);
      info.address = endInfo.address;
    }  // if something adjacent after
       
  freeList[freeCount++] = info;
  if(freeCount > maxFreeCount)
    maxFreeCount = freeCount;
  endTable.insert(info);
  beginTable.insert(info);
} // deAlloc()


void MemMan::endProc(int proc, int opNum, MemCheck &memCheck, char print)
{
  if(print != '0')
    cout << "Opnum: " << opNum << " endProc: proc: " << proc << endl;
  
   // memCheck.printCurrentAllocations(proc);
   SplayBinaryNode<AddressInfo> *t = trees[proc].root;
   endProc2(proc, opNum, memCheck, t );
   trees[proc].makeEmpty();
  // free all memory assigned to proc.
} // endProc()


void MemMan::endProc2(int proc, int opNum, MemCheck &memCheck, 
  SplayBinaryNode<AddressInfo> *t )
{
  if( t != t->left )
  {
    endProc2(proc, opNum, memCheck, t->left );
    AddressInfo info2, info = t->element;
    memCheck.deAlloc(proc, info.address, opNum);
    AddressInfo startInfo = beginTable.find(AddressInfo(info.endAddress + 1, 0));
    AddressInfo endInfo = endTable.find(AddressInfo(0,info.address - 1));

    if(startInfo.address == info.endAddress + 1)
    {
      beginTable.remove(startInfo);
      endTable.remove(startInfo);
      info.endAddress = startInfo.endAddress;
    } // if something adjacent after
    
    if(endInfo.endAddress == info.address - 1)
    {
      endTable.remove(endInfo);
      beginTable.remove(endInfo);
      info.address = endInfo.address;
    }  // if something adjacent before
       
    endTable.insert(info);
    beginTable.insert(info);
    freeList[freeCount++] = info;
    endProc2(proc, opNum, memCheck, t->right ); 
  }
}  // endProc2


