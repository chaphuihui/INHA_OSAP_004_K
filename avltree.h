#ifndef AVLTREE_H_
#define AVLTREE_H_

#include "AVLNode.h"

class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    void Insert(int key);
    bool Empty();
    int Size();
    int Height();
    void Ancester();
    void Average();
    void Rank();
    void Erase(int key);
    bool Find(int key);
  


private:
    AVLNode* DdeleteNode(AVLNode* node, int key);
    AVLNode* Insert(AVLNode* node, int key);
    AVLNode* root_;

};
#endif //AVLTREE_H_
