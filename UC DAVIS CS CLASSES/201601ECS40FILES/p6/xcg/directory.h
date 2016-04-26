// author Chengeng Xiao, Version 2016, Feb, 29 17:12
#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <iostream>
#include <fstream>
#include "list.h"
#include "list.cpp"

using namespace std;

class File
{
protected:
  char* name;
public:
  File(const char* path);
  virtual ~File();
  const char* getName() const;
  virtual bool find(File* file);
  virtual void insert(File* file);
  virtual bool operator== (const File& file) const;
  virtual bool operator< (const File& file) const;
  virtual bool operator> (const File& file) const;
}; // class File

class Directory : public File
{
private:
  List<File*> files;
public:
  Directory(const char* path);
  ~Directory();
  bool find(File* file);
  void insert(File* file);
  bool operator== (const File& directory) const;
  bool operator< (const File& directory) const;
  bool operator> (const File& directory) const; 
}; // class Directory

#endif // directory.h