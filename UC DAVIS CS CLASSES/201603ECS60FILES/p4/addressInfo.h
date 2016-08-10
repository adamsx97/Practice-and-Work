#ifndef ADDRESSINFO_H
#define	ADDRESSINFO_H



class AddressInfo {
public:
  static const int EMPTY = -2;
  static const int DELETED = -1;
  int address;
  int endAddress;
  AddressInfo(int addr = EMPTY, int endAddr = EMPTY) : address(addr), endAddress(endAddr){}
  bool operator< (const AddressInfo &rhs) const
  { return endAddress < rhs.address;}
   bool operator!= (const AddressInfo &rhs) const
  { return rhs.endAddress < address || endAddress < rhs.address;}
 
}; // class addressInfo 



class AddressInfo2 {
public:
  int address;
  int size;
  AddressInfo2(int addr = -1, int sz = -1) : address(addr), size(sz){}
  bool operator< (const AddressInfo2 &rhs) const
  { return size < rhs.size || (size == rhs.size && address < rhs.address);}
  bool operator!= (const AddressInfo2 &rhs) const
  { return size != rhs.size || (size == rhs.size && address != rhs.address);}
}; // class addressInfo2 




#endif	// ADDRESSINFO_H

