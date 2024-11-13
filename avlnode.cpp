struct AVLNode {
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;
    int size;

    AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1), size(1) {};
};
