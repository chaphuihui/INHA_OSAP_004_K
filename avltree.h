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
 *   Who: PAK DENIS
 *   Date: 2024/11/16
 *   Description: Added the `Rank` function.
 
 *   Who: Kim Dowon
 *   Date: 2024/11/17
 *   Description: Added the `Ancestor` function.
 *
 */

#ifndef AVLTREE_H
#define AVLTREE_H
#include "include.h"

struct AVLNode 	// AVL 트리의 노드를 나타내는 구조체
{
	int key;		// 노드의 키 값을 저장
	AVLNode* left;		// 왼쪽 자식 노드를 가리키는 포인터
	AVLNode* right;		// 오른쪽 자식 노드를 가리키는 포인터
	int height;		// 노드의 높이를 저장 (균형 검사 시 사용)
	int ranksize;		// 서브트리의 노드 개수를 저장 (Rank 계산 시 사용)

	int Height() 		// 현재 노드의 높이를 반환하는 멤버 함수
	{
		return height;
	}

	// 생성자: 키 값을 받아 노드를 초기화
    	// 왼쪽과 오른쪽 자식은 nullptr, 높이와 서브트리 크기는 1로 초기화
	AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1), ranksize(1) {};
};


class AVLTree	// AVL 트리 클래스: AVL 트리의 연산들을 제공
{
public:
	AVLTree();		// 초기화
	~AVLTree();		// 동적 할당된 메모리를 해제
	void Insert(int key);	// 키 값을 삽입하고 트리를 재구성
	void Empty();		// 트리가 비어있는지 확인하고 결과 출력
	void Size() const;	// 트리에 존재하는 노드의 개수를 출력
	void Height();		// 트리의 높이를 출력
	void Ancestor(int key); // 노드 key의 깊이와 높이의 합, key의 부모로부터 루트까지의 경로들의 key값들의 합 출력 
	void Average(int key);  // 입력 받은 키 값을 루트로 하는 서브트리에 대한 최대 최소의 평균을 출력
	void Rank(int key);	// 노드 x의 깊이와 높이의 합, 순위(rank)를 공백으로 구분하여 출력한다.
	void Erase(int key);	// 특정 키 값을 가진 노드를 삭제하고 트리를 재구성
	void Find(int key);	// 특정 키 값을 가진 노드를 찾고 결과 출력

private:
	AVLNode* DeleteNode(AVLNode* node, int key);	// 특정 키 값을 가진 노드를 삭제하고 트리 균형을 맞춤
	AVLNode* InsertNode(AVLNode* node, int key);	// 특정 키 값을 가진 노드를 삽입하고 트리 균형을 맞춤
	AVLNode* root_;					// 트리의 루트 노드를 가리키는 포인터
	int size_;					// 트리에 존재하는 노드의 총 개수
};

#endif //AVLTREE_H
