#ifndef AVLNODE_H_
#define AVLNODE_H_

struct AVLNode {
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int k);
};

#endif //AVLNODE_H_
