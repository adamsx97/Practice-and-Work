// author Chengeng Xiao, Version 2016, Feb, 29 17:12
#include <iostream>
#include <fstream>
#include <cstring>
#include "directory.h"

using namespace std;

File::File(const char* path)
{
  name = NULL;
  name = new char[strlen(path) + 1];

  strcpy(name, path);
} // constructor

File::~File()
{
  if (name != NULL)
  {
    delete name;
  } // if not NULL then delete name
} //destructor()

const char* File::getName() const
{
  char* rname = new char[strlen(name)];

  strcpy(rname, name);
  return rname;
} // getName()

bool File::find(File* file)
{
  if (name)
  {
    cout << name << endl;
    return true;
  } // if find print it
  else return false; // nizabushangtian
} // file find() print the path of file

void File::insert(File* file)
{
} // file insert() dose nothing

bool File::operator== (const File& file) const
{
  return strcmp(name, file.getName()) == 0;
  // if equal return true
} // operator==()

bool File::operator< (const File& file) const
{
  return strcmp(name, file.getName()) < 0;
  // if smaller return true
} // operator<()

bool File::operator> (const File& file) const
{
  return strcmp(name, file.getName()) > 0;
  // if great return true
} // operator>()

Directory::Directory(const char* path) : File(path)
{
} // constructor

Directory::~Directory()
{
} // destructor

bool Directory::find(File *file)
{
  if (!strcmp(name, file->getName()))
  {
    files.print();
    return true;
  }// if perfectly match then print
  else return files.find(file); // else call sublist to find file
} // find a directory

void Directory::insert(File* file)
{
  if (strcmp(this->name, file->getName()))
  {
    files.insert(file);
  } //if file under this directory in list than insert
} // insert a directory

bool Directory::operator== (const File& directory) const
{
  return (strncmp(name, directory.getName(), strlen(name)) == 0)
   && ( *(directory.getName() + strlen(name)) == '\0' 
     || *(directory.getName() + strlen(name)) == '/');
  // if equal return true
} // overload Directory operator ==

bool Directory::operator< (const File& directory) const
{
  return strncmp(name, directory.getName(), strlen(name)) < 0
     || (strncmp(name, directory.getName(), strlen(name)) == 0
        && *(directory.getName() + strlen(name)) != '\0' 
        && *(directory.getName() + strlen(name)) != '/');
  // if smaller return true
} // overload Directory operator <

bool Directory::operator> (const File& directory) const
{
  return strncmp(name, directory.getName(), strlen(name)) > 0;
  // if greater return true
} // overload Directory operator >