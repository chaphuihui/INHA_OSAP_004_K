#include <iostream>
#include <algorithm>
#include "avlnode.h"
#include "utility.h"


int Utility::GetHeight(AVLNode* node) {
    if (node != NULL) return node->height;
    else return 0;
};

int Utility:UpdateHeight(AVLNode* node) {
    return 1 + std::max(GetHeight(node->left), GetHeight(node->right));
};

int Utility::GetBalance(AVLNode* node) {
    if (node != NULL) {
        return GetHeight(node->left) - GetHeight(node->right);
    }
    else {
        return 0;
    }
};


AVLNode* Utility::MinValueNode(AVLNode* node) {
    AVLNode* current_node = node;
    while (current_node->left != NULL) {
        current_node = current_node->left;
    }
    return current_node;
};
