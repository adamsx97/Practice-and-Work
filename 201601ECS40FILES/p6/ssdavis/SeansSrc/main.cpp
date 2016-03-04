// Author: Sean Davis 
// Created on February 20, 2016, 9:59 AM

#include <iostream>
#include <fstream>
#include <cstring>
#include "list.h"
#include "directory.h"
using namespace std;

void read(List <File*> *list, const char *filename)
{
  char line[1000];
  File *filePtr;
  ifstream inf(filename);
  
  while(inf.getline(line, 1000))
  {
    char *ptr = strrchr(line, ' ');

    if(line[0] == 'd')
      filePtr = new Directory(ptr + 1);
    else // it is regular file
      filePtr = new File(ptr + 1);
    
    list->insert(filePtr);
  } // while more lines in the file
} // read



int main(int argc, char** argv) 
{
  char filename[256];
  List <File*> list;
  read(&list, argv[1]);
  
  while(1)
  {
    cout << "Please enter a file name (Done = exit): ";
    cin >> filename;
    
    if(strcmp(filename, "Done") == 0)
      break;
    
    File file(filename);
    
    if(! list.find(&file))
      cout << "Not found.\n";
  } // while "Done" not entered
  
  return 0;
} // main())

