#ifndef LIST_H
#define	LIST_H

template <typename T> class List;

template <typename T>
class ListNode 
{
  T data;
  ListNode <T> *prev;
  ListNode <T> *next;
  ListNode( T &d, ListNode <T> *p, ListNode <T> *n);
  ~ListNode();
  friend class List<T>;
};  // class ListNode


template <typename T>
class List 
{
  ListNode <T> *head;
  ListNode <T> *curr;
public:
  List();
  ~List();
  bool find(const T file);
  void insert(T file);
  void insertWithValidCurr(T file);
  void print();
}; // class List 


#include "list.cpp"

#endif	// LIST_H

