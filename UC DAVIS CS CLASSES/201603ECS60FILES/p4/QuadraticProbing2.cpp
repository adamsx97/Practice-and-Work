#include "QuadraticProbing2.h"
#include "addressInfo.h"


QuadraticHashTable2::QuadraticHashTable2(int sz )
  : size(sz), currentSize(0)
{
  array = new AddressInfo[size];
}

/**
 * Insert item x into the hash table. If the item is
 * already present, then do nothing.
 */

void QuadraticHashTable2::insert( const AddressInfo& x )
{
  int currentPos = x.endAddress % size;

  while( array[ currentPos ].endAddress > 0 &&
     array[ currentPos ].endAddress != x.endAddress )
     currentPos = ++currentPos % size;
  
  if(array[currentPos].endAddress == -2)
    currentSize++;
  array[ currentPos ] = x;
  
}

void QuadraticHashTable2::remove( const AddressInfo& x )
{
  int currentPos = x.endAddress % size;

  while( array[ currentPos ].endAddress > -2 &&
     array[ currentPos ].endAddress != x.endAddress )
     currentPos = ++currentPos % size;

  if(array[ currentPos ].endAddress == x.endAddress)
    array[currentPos].endAddress = -1;
}

/**
 * Find item x in the hash table.
 * Return the matching item, or ITEM_NOT_FOUND, if not found.
 */

const AddressInfo& QuadraticHashTable2::find( const AddressInfo& x ) const
{
  int currentPos = x.endAddress % size;

  while( array[ currentPos ].endAddress > -2 &&
     array[ currentPos ].endAddress != x.endAddress )
     currentPos = ++currentPos % size;
  
  return array[currentPos];
}



