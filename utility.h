#ifndef UTILITY_H_
#define UTILITY_H_

class Utility {
public:
    Utility();
    ~Utility();
    int GetHeight(AVLNode* node);
    int GetSize(AVLNode* node);
    int UpdateHeight(AVLNode* node);
    int UpdateSize(AVLNode* node);
    int GetBalance(AVLNode* node);
    AVLNode* MinValueNode(AVLNode* root);
    AVLNode* MaxValueNode(AVLNode* root);
    AVLNode* FindNode(AVLNode* root, int key);
    AVLNode* LeftRotate(AVLNode* x);
    AVLNode* RightRotate(AVLNode* y);
};
#endif UTILITY_H_
