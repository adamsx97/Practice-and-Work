// Author: Sean Davis

#include <cstring>
#include "directory.h"



 File::File(const char* nam)
 {
   name = new char[strlen(nam) + 1];
   strcpy(name, nam);
 } // File()
 
 
 File::~File()
 {
   delete [] name;
 } // ~File()
 
 
 bool File::find(File*) 
 {
   cout << name << endl;
   return true;
 } // find()
 
 
 const char* File::getName() const
 {
   return name;
 }  // getName()
 
 
 void File::insert(File*)
 {
 } // insert()
 
 
 bool File::operator== (const File & rhs) const
 {
   return strcmp(name, rhs.name) == 0;
 } // operator==
 
 bool File::operator< (const File & rhs) const
 {
   return strcmp(name, rhs.name) < 0;
 }  // operator<
 
 
 bool File::operator> (const File & rhs) const
 {
   return strcmp(name, rhs.name) > 0;
 } // operator>



Directory::Directory(const char *nam) : File(nam)
{
  
} // Directory()


Directory::~Directory()
{
} // ~Directory()


bool Directory::find(File* file)
{
  if(strcmp(file->getName(), name) == 0)
  {
    files.print();
    return true; 
  } // if identical names
  else  // not a perfect match
    return files.find(file);
} // find()
 
 
void Directory::insert(File* file)
{
  if(strcmp(file->getName(), name) != 0)
    files.insert(file);
} // insert()
 
 
bool Directory::operator== (const File & rhs) const
{
  unsigned int length = strlen(name);
   
  return strncmp(name, rhs.getName(), length) == 0
    && ((strlen(rhs.getName()) == length) 
    || (strlen(rhs.getName()) > length && rhs.getName()[length] == '/'));
} // operator==

 
bool Directory::operator< (const File & rhs) const
{
  unsigned int length = strlen(name);
   
  if(strncmp(name, rhs.getName(), length) == 0
     && ((strlen(rhs.getName()) == length) 
     || (strlen(rhs.getName()) > length && rhs.getName()[length] == '/')))
    return false;  // Then ==
 
  return strcmp(name, rhs.getName()) < 0;
}  // operator<
 
 
bool Directory::operator> (const File & rhs) const
{
  unsigned int length = strlen(name);
   
  if(strncmp(name, rhs.getName(), length) == 0
     && ((strlen(rhs.getName()) == length) 
     || (strlen(rhs.getName()) > length && rhs.getName()[length] == '/')))
    return false;  // Then ==
  
  return strcmp(name, rhs.getName()) > 0;
} // operator>


