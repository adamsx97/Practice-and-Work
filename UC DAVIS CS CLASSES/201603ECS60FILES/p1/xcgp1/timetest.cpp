#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.h"
#include "StackAr.h"
#include "CursorList.h"
#include "QueueAr.h"
#include "StackLi.h"
#include "SkipList.h"
#include "CPUTimer.h"
#include "vector.h"
vector<CursorNode <int> > cursorSpace(250000);

using namespace std;

int getChoice()
{

  int choice;
  cout<<"      ADT Menu" <<endl;
  cout<<"0. Quit \n1. LinkedList \n2. CursorList \n3. StackAr \n4. StackLi \n5. QueueAr \n6. SkipList" <<endl;
  cout<<"Your Choice >> ";
  cin>>choice;
  return choice;
}

void RunList(char *filename)
{
  char selection;
  int number=0;
  ifstream infile(filename);
  List <int> list;
  ListItr <int> itr=list.zeroth();
  char contain[500000]; //not sure about this
  infile.getline(contain, 500000);//not sure about this
  while (infile>>selection>>number)
  {
    if(selection=='i')
      list.insert(number,itr);
    else
      list.remove(number);

  }

}

void RunCursorList(char *filename)
{
  char selection;
  int number=0;
  ifstream infile(filename);
  CursorList <int> cursorlist(cursorSpace);
  CursorListItr <int> itr=cursorlist.zeroth();
  char contain[500000]; //not sure about this
  infile.getline(contain, 500000); //not sure about this
  while (infile>>selection>>number)
  {
    if(selection=='i')
      cursorlist.insert(number,itr);
    else
      cursorlist.remove(number);

  }

}
void RunStackAr(char *filename)
{
  char selection;
  int number=0;
  StackAr <int> runstackar(500100);
  ifstream infile(filename);
  char contain[500000]; //not sure about this
  infile.getline(contain, 500000);//not sure about this
  while(infile>>selection>>number)
  {
    if(selection=='i')
      runstackar.push(number);
    else
      runstackar.pop();
  }
}
void RunStackLi(char *filename)
{
  char selection;
  int number=0;
  StackLi <int> runstackli;
  ifstream infile(filename);
  char contain[500000];//not sure about this
  infile.getline(contain, 500000);//not sure about this
  while(infile>>selection>>number)
  {
    if(selection=='i')
      runstackli.push(number);
    else
      runstackli.pop();
  }
}

void RunQueueAr(char *filename)
{
  char selection;
  int number=0;
  Queue <int> runqueuear(500100);
  ifstream infile(filename);
  char contain[500000];//not sure
  infile.getline(contain, 500000);//not sure
  while(infile>>selection>>number)
  {
    if(selection=='i')
      runqueuear.enqueue(number);
    else
      runqueuear.dequeue();
    
  }
}
void RunSkipList(char *filename)
{
  char selection;
  int number=0;
  SkipList <int> runskiplist(0, 500000);
  ifstream infile(filename);
  char contain[500000];//not sure
  infile.getline(contain,500000);//not sure
  while(infile>>selection>>number)
  {
    if(selection=='i')
      runskiplist.insert(number);
    else
      runskiplist.deleteNode(number);
    
  }
}
int main()
{
  cout << "Filename >> ";
  int choice;
  char filename[10] = {0};
  cin >> filename;
  CPUTimer ct;
  do
  {
    choice=getChoice();
    ct.reset();
    switch (choice)
    {
      case 1: RunList(filename); break;
      case 2: RunCursorList(filename); break;
      case 3: RunStackAr(filename); break;
      case 4: RunStackLi(filename); break;
      case 5: RunQueueAr(filename); break;
      case 6: RunSkipList(filename); break;
    }
    cout <<"CPU time: " << ct.cur_CPUTime() <<endl;
  }   while(choice>0);
    return 0;

}
