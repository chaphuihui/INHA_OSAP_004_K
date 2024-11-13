#include "avltree.h"
#include "utility.h"

AVLNode* AVLTree::DeleteNode(AVLNode* root, int key) {
    if (!root)
        return root;

    if (key < root->key)
        root->left = DeleteNode(root->left, key);
    else if (key > root->key)
        root->right = DeleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            AVLNode* temp = root->left ? root->left : root->right;
            if (!temp)
                root = nullptr;
            else
                *root = *temp;
            delete temp;
        }
        else {
            AVLNode* temp = MinValueNode(root->right);
            root->key = temp->key;
            root->right = DeleteNode(root->right, temp->key);
        }

        if (!root)
        {
            return root;
        }
    
        node->height = UpdateHeight(node);
        node->size = GetSize(node);
        
        int balance = GetBalance(node);
        
        if (balance > 1 && GetBalance(node->left) >= 0)
        {
            return RightRotate(node);
        }
    
        if (balance > 1 && GetBalance(node->left) < 0)
        {
            node->left = LeftRotate(node->left);
            return RightRotate(node);
        }
    
        if (balance < -1 && GetBalance(node->right) <= 0)
        {
            return LeftRotate(node);
        }
        
        if (balance < -1 && GetBalance(node->right) > 0)
        {
            node->right = RightRotate(node->right);
            return LeftRotate(node);
        }
        
        return root;
}
