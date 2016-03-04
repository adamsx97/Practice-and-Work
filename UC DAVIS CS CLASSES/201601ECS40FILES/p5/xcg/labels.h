// Author: Sean Davis
// edited by Ziyue Gao, Chengeng Xiao, Feb. 16, 2016 01:46

#ifndef LABELS_H
#define	LABELS_H

#include <iostream>
#include "instruction2.h"
using namespace std;

class Labels 
{
private:

  Instruction2 addresses[100];
  int count;

public:
	
  Labels();
  int find(const char*) const;
  friend istream& operator>> (istream &is, Labels &labels);
}; // class Labels 

#endif	// LABELS_H

