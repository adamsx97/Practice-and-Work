#include "QuadraticProbing.h"
#include "addressInfo.h"

QuadraticHashTable::QuadraticHashTable(int sz )
  : size(sz), currentSize(0), maxSize(0)
{
  array = new AddressInfo[size];
  
}

/**
 * Insert item x into the hash table. If the item is
 * already present, then do nothing.
 */

void QuadraticHashTable::insert( const AddressInfo & x )
{
  int currentPos = x.address % size;

  while( array[ currentPos ].address > 0 &&
     array[ currentPos ].address != x.address )
     currentPos = ++currentPos % size;
  
  array[ currentPos ] = x;
  currentSize++;
  if(maxSize < currentSize)
    maxSize = currentSize;
}

/**
 * Expand the hash table.
 

void QuadraticHashTable::rehash( )
{
    vector<HashEntry> oldArray = array;

        // Create new double-sized, empty table
    array.resize( nextPrime( 2 * oldArray.size( ) ) );
    for( int j = 0; j < array.size( ); j++ )
        array[ j ].info = EMPTY;

        // Copy table over
    currentSize = 0;
    for( int i = 0; i < oldArray.size( ); i++ )
        if( oldArray[ i ].info == ACTIVE )
            insert( oldArray[ i ].element );
}
*/

/**
 * Remove item x from the hash table.
 */

void QuadraticHashTable::remove( const AddressInfo & x )
{
  int currentPos = x.address % size;

  while( array[ currentPos ].address > -2 &&
     array[ currentPos ].address != x.address )
     currentPos = ++currentPos % size;

  if(array[ currentPos ].address == x.address)
    array[currentPos].address = -1;
  
  currentSize--;
}

/**
 * Find item x in the hash table.
 * Return the matching item, or ITEM_NOT_FOUND, if not found.
 */

const AddressInfo & QuadraticHashTable::find( const AddressInfo & x ) const
{
  int currentPos = x.address % size;

  while( array[ currentPos ].address != AddressInfo::EMPTY &&
     array[ currentPos ].address != x.address )
     currentPos = ++currentPos % size;
  
  return array[currentPos];
}



