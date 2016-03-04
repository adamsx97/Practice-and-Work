// author Chengeng Xiao, Version 2016, Feb, 29 17:12
#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

template <class T>
class List;

template <class T>
class ListNode
{

private:
  ListNode<T> *prev;
  ListNode<T> *next;
  T data;

public:
  ListNode(ListNode<T>* setPrev, ListNode<T>* setNext, T name);
  ~ListNode();
  friend class List<T>;

}; // template class ListNode

template <class T>
class List
{

private:
  ListNode<T> *head;
  ListNode<T> *curr;

public:
  List();
  ~List();
  bool find(const T data);
  void tresni(T node);
  void insert(T node);
  void print();

}; // template class List

#endif // list.h