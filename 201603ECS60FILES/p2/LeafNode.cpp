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
  LeafNode* n = NULL;
  if (count < leafSize)
  {
    insertDirectly(value);
    return NULL;
  }
  else
  {
    if (leftSibling && leftSibling->getCount() < leafSize)
    {
        moveToLeft();
        insertDirectly(value);
      
    } // insert to left
    else if(rightSibling && rightSibling->getCount() < leafSize)
    {
      if (value > values[count - 1])
        rightSibling->insert(values[count--]);
      else // if value is not the biggest one
      {
        moveToRight();
        insertDirectly(value);
      }
    } // insert to right
    else // no place in current leaf node and left&right sibling
    {
      insertDirectly(value);
      n = split();
    }
  }
  return n; // to avoid warnings for now.
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
  LeafNode *newNode = new LeafNode(leafSize, parent, this, rightSibling);
  
  if(rightSibling)
    rightSibling->setLeftSibling(newNode);
  rightSibling=newNode;
  for (int i = (count) / 2; i <= leafSize; i++)
    newNode->insert(values[i]);
  count--;
  return newNode;
} // split()

void LeafNode::insertDirectly(int value)
{
  if (count == 0)
  {
    values[count] = value;
    count++;
    return;
  } // if no element in curr leaf node

  int flag = 1;
  for (int i = 0; i < count; i++)
    if (value < values[i])
    {
      for (int j = i; j < count; j++)
        values[j] = values[j + 1];
      values[i] = value;
      flag = 0;
      break;
    }
  if (flag)
    values[count] = value;
  count++;
  return;
} // insertDirectly()

  
void LeafNode::moveToLeft()
{
  leftSibling->insert(values[0]);
  for (int i = 0; i < count - 1; i++)
    values[i] = values[i + 1];
  count--;
} // insertToLeft()

void LeafNode::moveToRight()
{
  rightSibling->insert(values[count - 1]);
  count--;
} // moveToRight()
