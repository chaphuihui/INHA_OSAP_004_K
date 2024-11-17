#ifndef AVLTREE_H
#define AVLTREE_H
#include "include.h"

struct AVLNode {
	int key;
	AVLNode* left;
	AVLNode* right;
	int height;
	int size;

	AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1), size(1) {};
};


class AVLTree
{
public:
	AVLTree();
	~AVLTree();
	void Insert(int key);
	bool Empty();
	int Size();
	void Height();
	void Ancestor(int key);
	void Average(int key);
	int Rank(int key);
	void Erase(int key);
	void Find(int key);

private:
	AVLNode* DeleteNode(AVLNode* node, int key);
	AVLNode* InsertNode(AVLNode* node, int key);
	AVLNode* root_;
};

#endif //AVLTREE_H
