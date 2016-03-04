#ifndef LABELS_H
#define	LABELS_H
using namespace std; 

#include "instruction.h"
#include <iostream> 
#include <fstream> 
#include <iomanip>
#include <cstdlib>
#include <cstring>

class Labels 
{
    Instruction labelines[100];
    int count; 

public: 
	  friend ifstream& operator>> (ifstream &inf, Labels &labels); 
	  int find(char *string);
    

}; // class labels

#endif	// LABELS_H 
