// author Chengeng Xiao, Version 2016, Feb, 29 17:12
#include <iostream>
#include <fstream>
#include <cstring>
#include "directory.h"
#include "list.h"

using namespace std;

char* separate(char line[])
{
  char* path;
  path = strrchr(line, ' ');
  return path;
} // separate()

void reading(const char fileName[], List<File*>& list)
{
  char *path, line[200];
  File* ptr;
  ifstream inf(fileName);
  
  memset(line, 0, sizeof(line));
  
  while (inf.getline(line, 200))
  {
    path = separate(line);

    if (line[0] == 'd')
    {
      path++;
      ptr = new Directory(path);
      list.insert(ptr);
      
    } // dir

    if(line[0] == '-')
    {
      path++;
      ptr = new File(path);
      list.insert(ptr);

    } // file

    memset(line, 0, sizeof(line));
  } // reading line by line
} // reading()

int main(int argc, char const *argv[])
{
  List<File*> list;
  reading(argv[1], list);
  char input [500];

  while(1)
  {

    cout << "Please enter a file name (Done = exit): ";
    memset(input, 0, sizeof(input));
    cin >> input;

    if (strcmp(input, "Done") == 0)
    {
      break;
    } // if input is Done then quit loop
    
    File* fileNew = new File(input);

    if (!list.find(fileNew))
    {
      cout << "Not found." << endl;
    } // if not found output it
  } // finding files and directorys.

  return 0;
} // main()