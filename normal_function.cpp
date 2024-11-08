#include"AVLTree.h"
#include"Utility.h"
#include"Insertion.cpp"

void AVLTree::insert(int key) { root = insert(root, key); };
bool AVLTree::empty() {};
int AVLTree::size() {};
int AVLTree::height() {};
void AVLTree::ancester() {};
void AVLTree::average() {};
bool AVLTree::find(int key) {};