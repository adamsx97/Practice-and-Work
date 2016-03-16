// author Chengeng Xiao, Version 2016, Mar, 14 19:56
#ifndef INDEXPAGER_H
#define INDEXPAGER_H

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "pager.h"

using namespace std;

class IndexPager : public Pager
{
private:
  map<string, int>wordId;
  multimap<int, int>idLine;
public:
  IndexPager();
  ~IndexPager();
  void markFlag(map<string, int>::iterator itId, int* flag, int &maxLine);
  void pushToVector();
  void read(istream &inf);
};  // class IndexPager

#endif