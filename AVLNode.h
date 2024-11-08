#ifndef AVLNODE_H
#define AVLNODE_H

struct AVLNode {
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int k);
};

#endif AVLNODE_H