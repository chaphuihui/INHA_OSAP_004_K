#ifndef LIBRARY_CODE_H_
#define LIBRARY_CODE_H_

#include <algorithm>
#include <iostream>
#include "string"

// AVL 노드 구조체 정의
struct AVLNode {
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;
    int size;

    AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1), size(1) {}
};

// AVLTree 클래스 정의
class AVLTree
{
public:
	AVLTree();
	~AVLTree();
	int Find(int key);
	int Insert(int key);
	bool Empty();
	int Size() const;
	int Height();
	void Ancestor(int key);
	void Average(int key);
	void Rank(int key);
	void Erase(int key);
  AVLNode* GetRoot() const; // 루트 노드를 반환하는 메서드 추가

private:
	AVLNode* DeleteNode(AVLNode* node, int key);
	AVLNode* InsertNode(AVLNode* node, int key);
	AVLNode* root_ = nullptr;
	int size_;
};

// Utility 클래스 정의
class Utility {
public:
    Utility();
    ~Utility();

    int GetHeight(AVLNode* node);
    int GetSize(AVLNode* node);
    int UpdateHeight(AVLNode* node);
    int UpdateSize(AVLNode* node);
    int GetBalance(AVLNode* node);
    int GetDepth(AVLNode* node, int key, int current_depth);
    AVLNode* MinValueNode(AVLNode* node);
    AVLNode* MaxValueNode(AVLNode* node);
    AVLNode* FindNode(AVLNode* root, int key);
    AVLNode* LeftRotate(AVLNode* x);
    AVLNode* RightRotate(AVLNode* y);
    int RankNode(AVLNode* node, int key);
};

#endif // LIBRARY_CODE_H_
