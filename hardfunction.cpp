#include "avltree.h"
#include "utility.h"
#include "deletion.cpp"

int AVLTree::Rank(int key) {
   
    Utility util;
    AVLNode* node = util.FindNode(root_, key);
   
   if (!node)
   {
       return 0;
   }
  
   if (key < node->key)
   {
       return Rank(node->left, key);
   }
   else if (key > node->key) 
   {
       return 1 + util.GetSize(node->left) + Rank(node->right, key);
   }
   else 
   {
       return util.GetSize(node->left) + 1;
   }
};

void AVLTree::Erase(int key) { DeleteNode(root, key); };
