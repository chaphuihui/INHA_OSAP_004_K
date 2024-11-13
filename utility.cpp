#include <iostream>
#include <algorithm>
#include "avlnode.h"
#include "utility.h"


int Utility::GetHeight(AVLNode* node) {
    if (node != nullptr) return node->height;
    else return 0;
};

int Utility::GetSize(AVLNode* node) {
    if (node != NULL){
        return node->size;
    }
    else {
        return 0;
    }
};

int Utility::UpdateHeight(AVLNode* node) {
    return 1 + std::max(GetHeight(node->left), GetHeight(node->right));
};

int Utility::UpdateSize(AVLNode* node) 
{
    return 1 + getSize(node->left) + getSize(node->right);
}

int Utility::GetBalance(AVLNode* node) {
    if (node != nullptr) {
        return GetHeight(node->left) - GetHeight(node->right);
    }
    else {
        return 0;
    }
};

AVLNode* Utility::MinValueNode(AVLNode* node) {
    AVLNode* current_node = node;
    while (current_node->left != nullptr) {
        current_node = current_node->left;
    }
    return current_node;
};

AVLNode* Utility::MaxValueNode(AVLNode* node) {
    AVLNode* current_node = node;
    while (current_node->right != nullptr) {
        current_node = current_node->right;
    }
    return current_node;
};

AVLNode* Utility::FindNode(AVLNode* root, int key) {
    AVLNode* current_node = root;
    while (current_node != nullptr && current_node->key != key) {
        if (key < current_node->key) {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }
    }
    return current_node;

AVLNode* Utility::LeftRotate(AVLNode* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = updateHeight(x);
    y->height = updateHeight(y);
    
    x->size = getSize(x);
    y->size = getSize(y);

    return y;
}

AVLNode* Utility::RightRotate(AVLNode* y) {
    Node* y = x->right;
    Node* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = updateHeight(x);
    y->height = updateHeight(y);
    
    x->size = getSize(x);
    y->size = getSize(y);

    return x;
}
};
