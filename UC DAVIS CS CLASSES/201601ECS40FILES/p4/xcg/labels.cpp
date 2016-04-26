#include <iostream> 
#include <fstream> 
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "labels.h" 

  
int Labels::find(char *ptr) 
{ 
  int i = 0;

	for (int i=0; strcmp(ptr, labelines[i].getInfo()) ;i++);
	return labelines[i].getAddress();
}


ifstream& operator>> (ifstream &inf, Labels &labels)
{
	char line[256], *ptr;
  int address = 100;
	while(inf.getline(line, 256))
  {
    for(ptr = strchr(line, '\t'); ptr; ptr = strchr(line, '\t'))
      *ptr = ' ';  // replace all tabs with space characters
    
    for(ptr = line; *ptr == ' '; ptr++);  // get past leading spaces
    
    if((*ptr == '.' && *(ptr + 1) == 'L')|| *ptr == '_' )
    {
      ptr[strlen(ptr) -1] = '\0';
      labels.labelines[labels.count].setAddress(address);
      labels.labelines[labels.count++].setInfo(ptr);
    } // if not directive, nor main:
    else if(!(*ptr == '.' && *(ptr + 1) != 'L') && strstr(ptr, "main") == NULL) 
      address += 4;
  }  // while more in file
  return inf;
} // read in label 

 