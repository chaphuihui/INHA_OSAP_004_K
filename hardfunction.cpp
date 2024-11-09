#include "avltree.h"
#include "utility.h"
#include "deletion.cpp"

void AVLTree::Rank() {};
void AVLTree::Erase(int key) { deleteNode(root, key); };
