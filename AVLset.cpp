#include <algorithm>

using namespace std;


class AVLset {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        int height;

        Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    int getHeight(Node* node) {
        if (node != NULL) return node->height;
        else return 0;
    };

    int updateHeight(Node* node) {
        return 1 + max(getHeight(node->left), getHeight(node->right));
    };

    int getBalance(Node* node) {
        if (node != NULL) {
            return getHeight(node->left) - getHeight(node->right);
        }
        else {
            return 0;
        }
    };

    Node* insert(Node* node, int key) {
        if (!node)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = updateHeight(node);

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    };
    Node* deleteNode(Node* root, int key);
    Node* minValueNode(Node* node);
    bool find(Node* node, int key);

public:
    AVLset() : root(nullptr) {};
    void insert(int key) { root = insert(root, key); };
    void deleteNode(int key);
    bool find(int key);
    bool isEmpty();
    int height();
    void Average();
    void Rank();
    void Erase();

};
