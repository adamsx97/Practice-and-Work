#ifndef DIRECTORY_H
#define	DIRECTORY_H

#include "list.h"

class File
{
protected:
  char *name;
public:
  File(const char* nam);
  virtual ~File();
  virtual bool find(File*);
  const char* getName() const;
  virtual void insert(File* file);
  virtual bool operator== (const File & rhs) const;
  virtual bool operator< (const File & rhs) const;
  virtual bool operator> (const File & rhs) const;
  
};  // class File



class Directory : public File
{
  List <File*> files;
public:
  Directory(const char *nam);
  ~Directory();
  bool find(File* file);
  void insert(File* file);
  bool operator== (const File & rhs) const;
  bool operator< (const File & rhs) const;
  bool operator> (const File & rhs) const;
}; // class Directory 

#endif	// DIRECTORY_H

