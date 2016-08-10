#ifndef _QUADRATIC_PROBING2_H_
#define _QUADRATIC_PROBING2_H_

#include "addressInfo.h"




class QuadraticHashTable2
{
  public:
    explicit QuadraticHashTable2(int size);
    const AddressInfo& find( const AddressInfo& x ) const;
    void makeEmpty( );
    void insert( const AddressInfo& x );
    void remove( const AddressInfo& x );
    const QuadraticHashTable2 & operator=( const QuadraticHashTable2 & rhs );
    AddressInfo*array;
    int size;
    int currentSize;
    const AddressInfo ITEM_NOT_FOUND;
   
    int findPos( const AddressInfo& x ) const;
    void rehash( );
};

#endif
