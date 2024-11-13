#include "avltree.h"
#include "utility.h"
#include "deletion.cpp"

void AVLTree::Rank(AVLNode* node, int key) {
   if (!node)
   {
       return 0;
   }
  
   if (key < node->key)
   {
       return rank(node->left, key);
   }
   else if (key > node->key) 
   {
       return 1 + GetSize(node->left) + rank(node->right, key);
   }
   else 
   {
       return getSize(node->left) + 1;
   }
};

void AVLTree::Erase(int key) { deleteNode(root, key); };
