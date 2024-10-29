#ifndef AVLTREE_H
#define AVLTREE_H

class AVLTree {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        int height;

        Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    int getHeight(Node* node);
    int updateHeight(Node* node);
    int getBalance(Node* node);
    Node* insert(Node* node, int key);
    Node* deleteNode(Node* root, int key);
    bool find(Node* node, int key);

public:
    AVLTree();
    void insert(int key);
    void deleteNode(int key);
    bool find(int key);
    bool isEmpty();
    int height();
};

#endif //2024-10-29 이형석 deleteNode때 필요한 leftRotate과 rightRotate, minValue는 추후에 추가할 예정
