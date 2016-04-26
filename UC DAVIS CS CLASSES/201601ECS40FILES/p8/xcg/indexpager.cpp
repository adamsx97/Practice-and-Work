// author Chengeng Xiao, Version 2016, Mar, 14 19:56

#include <iostream>
#include <cctype>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <iterator>
#include <algorithm>
#include <list>
#include "indexpager.h"
#include "pager.h"

using namespace std;

IndexPager::IndexPager()
{
} // constructor

IndexPager::~IndexPager()
{
} // destructor

typedef map<string, int>::iterator MIT;
void IndexPager::markFlag(MIT itId, int* flag, int &maxLine)
{

    for(multimap<int, int>::iterator itLine = idLine.find(itId->second);
       itLine->first == itId->second; itLine++)
    {
      flag[itLine->second] = 1;
      
      if (maxLine < (itLine->second))
        maxLine = itLine->second;
    } // for() idLine
} // markFlag()

void IndexPager::pushToVector()
{
  string buf; int flag[10000], cflag, maxLine;
  buf.clear();

  for (map<string, int>::iterator itId = wordId.begin();
      itId != wordId.end(); itId++)
  {
    buf = itId->first + ' ';
    maxLine = -1; cflag = 0;
    memset(flag, 0, sizeof(flag));
    markFlag(itId, flag, maxLine);
    
    for (int i = 0; i <= maxLine; i++)
      
      if (flag[i])
      {
        if (!flag[i + 1])
          if (cflag == 0)
          { buf = buf + intToString(i); cflag = 1; } // if()
          else buf = buf + ", " + intToString(i); // else()
        else // else()
        {
          if (cflag == 0)
          { buf = buf + intToString(i) + "-"; cflag = 1; } // if()
          else buf = buf + ", " + intToString(i) + "-"; // else()
          
          while(flag[i] == 1) i++; i--;
          buf = buf + intToString(i);
        } // else()
      } // if()

    buf += "."; text.push_back(buf); buf.clear();
  } // for() wordId
} // pushToVector()

void IndexPager::read(istream &inf)
{
  string s, buf;
  string::iterator itr;
  int line = -1, id = 0;
  pair<map<string, int>::iterator, bool> ret;
  multimap<int, int>::iterator it;

  while(getline(inf, s, '\n'))
  {
    line++;

    for(itr = s.begin(); itr != s.end(); itr++)
    {

      if (isalpha(*itr))
        buf += *itr;

      if ((!isalpha(*itr) || itr + 1 == s.end()) && !buf.empty())
        {

          if (wordId.find(buf) != wordId.end())
            idLine.insert(pair<int, int>(wordId.find(buf)->second, line));
          else // else
          {
            wordId.insert(pair<string, int>(buf, id));
            idLine.insert(pair<int, int>(id, line));
            id++;
          } // else

          buf.clear();
        } // if()
    } // for()
  } // while()

  pushToVector();
} // read()