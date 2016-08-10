#ifndef _QUADRATIC_PROBING_H_
#define _QUADRATIC_PROBING_H_

#include "addressInfo.h"

class QuadraticHashTable
{
  public:
    explicit QuadraticHashTable(int size);
    const AddressInfo & find( const AddressInfo & x ) const;
    void makeEmpty( );
    void insert( const AddressInfo & x );
    void remove( const AddressInfo & x );
    const QuadraticHashTable & operator=( const QuadraticHashTable & rhs );
    AddressInfo *array;
    int size;
    int currentSize;
    int maxSize;
    const AddressInfo ITEM_NOT_FOUND;
   
    int findPos( const AddressInfo & x ) const;
    void rehash( );
};

#endif
