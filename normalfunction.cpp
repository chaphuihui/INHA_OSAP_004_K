#include "AVLTree.h"
#include "Utility.h"
#include "Insertion.cpp"

void AVLTree::Insert(int key) { root = Insert(root, key); };
bool AVLTree::Empty() {};
int AVLTree::Size() {};
int AVLTree::Height() {};
void AVLTree::Ancester() {};
void AVLTree::Average() {};
bool AVLTree::Find(int key) {};
