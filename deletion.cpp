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
    
        node->height = UpdateHeight(root);
        node->size = GetSize(root);
        
        int balance = GetBalance(root);
        
        if (balance > 1 && GetBalance(root->left) >= 0)
        {
            return RightRotate(root);
        }
    
        if (balance > 1 && GetBalance(root->left) < 0)
        {
            node->left = LeftRotate(root->left);
            return RightRotate(root);
        }
    
        if (balance < -1 && GetBalance(root->right) <= 0)
        {
            return LeftRotate(root);
        }
        
        if (balance < -1 && GetBalance(root->right) > 0)
        {
            node->right = RightRotate(root->right);
            return LeftRotate(root);
        }
        
        return root;
}
