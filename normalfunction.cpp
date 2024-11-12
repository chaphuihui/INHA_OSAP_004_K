#include "avltree.h"
#include "utility.h"
#include "insertion.cpp"

void AVLTree::Insert(int key) { root = Insert(root, key); };
bool AVLTree::Empty() {};
int AVLTree::Size() {};
int AVLTree::Height() {};
void AVLTree::Ancester() {};

void AVLTree::Average(int key) {
  AVLNode* subtree_root = Find(root_, key);

  int min_value_key = MinValueNode(subtree_root)->key;
  int max_value_key = MaxValueNode(subtree_root)->key;

  double subtree_min_max_average = (static_cast<double>(min_value_key) + static_cast<double>(max_value_key)) / 2.0;
  cout << subtree_min_max_average << "\n";

}

bool AVLTree::Find(int key) {};
