#include "avltree.h"
#include "utility.h"

AVLNode* AVLTree::Insert(AVLNode* node, int key) {
    if (!node)
        return new AVLNode(key);

    if (key < node->key)
        node->left = Insert(node->left, key);
    else if (key > node->key)
        node->right = Insert(node->right, key);
    else
        return node;

    node->height = UpdateHeight(node);
    node->size = UpdateSize(node);

    int balance = GetBalance(node);

    if (balance > 1 && key < node->left->key)
        return RightRotate(node);

    if (balance < -1 && key > node->right->key)
        return LeftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = LeftRotate(node->left);
        return RightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }

    return node;
};
