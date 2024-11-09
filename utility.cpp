#include<iostream>
#include<algorithm>
#include"AVLNode.h"
#include"Utility.h"


int Utility::getHeight(AVLNode* node) {
    if (node != NULL) return node->height;
    else return 0;
};

int Utility::updateHeight(AVLNode* node) {
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
};

int Utility::getBalance(AVLNode* node) {
    if (node != NULL) {
        return getHeight(node->left) - getHeight(node->right);
    }
    else {
        return 0;
    }
};


AVLNode* Utility::minValueNode(AVLNode* node) {};
