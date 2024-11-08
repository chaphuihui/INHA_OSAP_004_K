#ifndef AVLTREE_H
#define AVLTREE_H

#include"AVLNode.h"
#include"AVLNode.h"

class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    void insert(int key);
    bool empty();
    int size();
    int height();
    void ancester();
    void average();
    void rank();
    void erase(int key);
    bool find(int key);
  


private:
    AVLNode* deleteNode(AVLNode* node, int key);
    AVLNode* insert(AVLNode* node, int key);
    AVLNode* root;

};
#endif AVLTREE_H