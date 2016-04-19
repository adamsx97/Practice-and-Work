#ifndef LeafNodeH
#define LeafNodeH

#include "BTreeNode.h"

/*
  int count;
  int leafSize;
  InternalNode *parent;
  BTreeNode *leftSibling;
  BTreeNode *rightSibling;
*/

class LeafNode:public BTreeNode
{
  int *values;
public:
  LeafNode(int LSize, InternalNode *p, BTreeNode *left,
    BTreeNode *right);
  int getMinimum() const;
  LeafNode* insert(int value); // returns pointer to new Leaf if splits
  // else NULL
  void print(Queue <BTreeNode*> &queue);
  LeafNode* split();
  void insertDirectly(int value);
  void moveToLeft();
  void moveToRight();
}; //LeafNode class

#endif
