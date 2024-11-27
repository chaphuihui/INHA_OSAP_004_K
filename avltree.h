/*
 * Copyright (C) 2024 INHA_OSAP_004_K
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *Authors:
 *   Who: Hwang minjun
 *   Date: 2024/11/13
 *   Description: Added the `Average` function.
 * 
 *   Who: Kim Dowon
 *   Date: 2024/11/17
 *   Description: Added the `Ancestor` function.
 *
 */

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
	void Ancestor(int key); // 노드 key의 깊이와 높이의 합, key의 부모로부터 루트까지의 경로들의 key값들의 합 출력 
	void Average(int key);  // 입력 받은 키 값을 루트로 하는 서브트리에 대한 최대 최소의 평균을 출력
	int Rank(int key);
	void Erase(int key);
	void Find(int key);

private:
	AVLNode* DeleteNode(AVLNode* node, int key);
	AVLNode* InsertNode(AVLNode* node, int key);
	AVLNode* root_;
};

#endif //AVLTREE_H
