// Author: Sean Davis

#include <iostream>   // for NULL
#include "list.h"

using namespace std;

template <typename T>
ListNode<T>::ListNode( T &dat, ListNode <T> *p, ListNode <T> *n) : data(dat), 
  prev(p), next(n)
{
}  // ListNode()

template <typename T>
ListNode<T>::~ListNode()
{
  delete data;
}  // ~ListNode()


template <typename T>
List<T>::List() : head(NULL), curr(NULL)
{
} // List()


template <typename T>
List<T>::~List()
{
  for(ListNode <T> *ptr = head; ptr; ptr = head)
  {
    head = ptr->next;
    delete ptr;
  } // for each list node
}  // ~List()

template <typename T>
bool List<T>::find(const T file) 
{
  if(curr == NULL)
  {
    if(head)
      curr = head;
    else // empty list
      return false;
  }  // if curr is NULL
    
  if(*curr->data == *file)
    return curr->data->find(file);
  else // curr->data !=  file
    if(*curr->data > *file) 
    {
      while(curr && *curr->data > *file)
        curr = curr->prev;
    }  // if filename is less than curr's move forward
    else  // *file >= *curr->data
    {
      while(curr && *curr->data < *file)
        curr = curr->next;
    } // else *file >= *curr->data
 
  if(curr && *curr->data == *file)
    return curr->data->find(file);
  else // curr->data != file
    return false;
}  // find()


template <typename T>
void List<T>::insert(T file)
{
  if(curr == NULL)
  {
    curr = head;
  
    if(curr == NULL)
    {
      head = new ListNode <T> (file, NULL, NULL);
      return;
    }  // first item in list
  } // if curr is NULL
  
  insertWithValidCurr(file);
}  // insert()


template <typename T>
void List<T>::insertWithValidCurr(T file)
{
  if(*curr->data < *file) 
  {
    while(curr->next && *curr->data < *file)
      curr = curr->next;
    
    if(*curr->data < *file)  // none after
      curr->next = new ListNode<T>(file, curr, NULL);
    else  // not at end of list so must be less than or equal to curr
      if(*curr->data > *file)  // curr is after where it belongs
        curr->prev = curr->prev->next = new ListNode<T>(file, curr->prev, curr);
      else  // must == 
        curr->data->insert(file);
  }  // if filename is less than curr's move forward
  else  // *file >= *curr->data
    if(*curr->data > *file)
    {
      while(curr->prev && *curr->data > *file)
        curr = curr->prev;
    
      if(*curr->data > *file)  // none before so put at head of the list
        head = curr->prev = new ListNode<T>(file, NULL, curr);
      else  // not at beginning of list so must be greater than or equal to curr
        if(*curr->data < *file)  // curr is before where it belongs
          curr->next = curr->next->prev =  new ListNode<T>(file, curr, 
            curr->next);
        else  // must == 
          curr->data->insert(file);
    } // if file < curr->data
    else // *file == *curr->data
      curr->data->insert(file);
}  // insertWithValidCurr()


template <typename T>
void List<T>::print()
{
  for(curr = head; curr; curr = curr->next)
    cout << curr->data->getName() << endl;
} // print()

