#include <iostream>
#include "LeafNode.h"
#include "InternalNode.h"
#include "QueueAr.h"

using namespace std;

/*
int count;
int leafSize;
int *values;
InternalNode *parent;
BTreeNode *leftSibling;
BTreeNode *rightSibling;
*/

LeafNode::LeafNode(int LSize, InternalNode *p,
  BTreeNode *left, BTreeNode *right) : BTreeNode(LSize, p, left, right)
{
  values = new int[LSize];
}  // LeafNode()



int LeafNode::getMinimum()const
{
  if(count > 0)  // should always be the case
    return values[0];
  else
    return 0;

} // LeafNode::getMinimum()


LeafNode* LeafNode::insert(int value)
{
  if (count < leafSize)
  {
    insertDirectly(value);
    return NULL;
  }
  else
  {
    if (leftSibling->count < leafSize)
    {
      if (value < this->getMinimum())
        leftSibling->insert(value);
      else
      {
        moveToLeft();
        insertDirectly();
      }
    }
  }
  return NULL; // to avoid warnings for now.
}  // LeafNode::insert()

void LeafNode::print(Queue <BTreeNode*> &queue)
{
  cout << "Leaf: ";
  for (int i = 0; i < count; i++)
    cout << values[i] << ' ';
  cout << endl;
} // LeafNode::print()

LeafNode* LeafNode::split()
{

} // split()

void LeafNode::insertDirectly(int value)
{
  if (count == 0)
  {
    values[0] = value;
    count++;
    return;
  } // if no element in curr leaf node

  for (int i = 0; i < count; i++)
    if (value < values[i])
    {
      for (int j = i; j < count; j++)
        values[j] = values[j + 1];
      values[i] = value;
    }
  count++;
  return;
} // insertDirectly()

  
void LeafNode::moveToLeft()
{

} // insertToLeft()