#ifndef DATA_H
#define	DATA_H

#include "word.h"

class Data : public  Word 
{
  int num;
public:
  Data(int addr);
  const int& get() const;
  int& get();
  Data& operator= (int value); 
}; // class Data 

#endif	// DATA_H

