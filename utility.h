#ifndef UTILITY_H_
#define UTILITY_H_

class Utility {
public:
    Utility();
    ~Utility();
    int GetHeight(AVLNode* node);
    int UpdateHeight(AVLNode* node);
    int GetBalance(AVLNode* node);
    AVLNode* MinValueNode(AVLNode* root);
    AVLNode* MaxValueNode(AVLNode* root);

};
#endif UTILITY_H_