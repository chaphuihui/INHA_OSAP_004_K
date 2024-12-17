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
 * Authors:
 *   Who: Hwang minjun 
 *   Date: 2024/11/12
 *   Description: added the 'MinValueNode' function and the 'MaxValueNode' function
 * 
 *   Who: PAK DENIS
 *   Date: 2024/11/12
 *   Description: added the 'LeftRotate' function and the 'RightRotate' function
 * 		  added the 'GetRankSize' function and the 'UpdateRankSize' function
 *		  added the 'GetDepth' function and the 'RankNode' function
 * 
 * - Who: Kim Dowon 
 *   Date: 2024/11/13
 *   Description: added the 'FindeNode' function
 *
 */

#include "include.h"

Utility::Utility() {};	// 생성자: Utility 객체를 초기화하는 기본 생성자
Utility::~Utility() {};	// 소멸자: Utility 객체가 소멸될 때 호출됨 (현재 특별한 작업은 없음)

int Utility::GetHeight(AVLNode* node)	// GetHeight 함수: 주어진 노드의 높이를 반환
{
	if (node != nullptr)		
	{
		return node->height;	// 노드가 nullptr이 아니면 노드의 height 값을 반환
	}
	else
	{
		return 0;		// 노드가 nullptr이면 높이는 0
	}
};

int Utility::GetDepth(AVLNode* node, int key, int current_depth) 	// GetRankSize 함수: 특정 노드를 루트로 하는 서브트리의 크기(노드의 개수)를 반환
{
	if (node == nullptr) return -1; // 노드가 비어 있으면 -1 반환

	if (key == node->key) return current_depth; // 키가 현재 노드의 키와 같으면 현재 깊이를 반환
	if (key < node->key) 
	{
		return GetDepth(node->left, key, current_depth + 1);   // 키가 현재 노드의 키보다 작으면 왼쪽 서브트리에서 탐색
	}
	else 
	{
		return GetDepth(node->right, key, current_depth + 1);  // 키가 현재 노드의 키보다 크면 오른쪽 서브트리에서 탐색
	}
};

int Utility::GetRankSize(AVLNode* node)	// GetRankSize 함수: 특정 노드를 루트로 하는 서브트리의 크기(노드의 개수)를 반환
{
	if (node == nullptr)		// 노드가 nullptr이면 크기는 0
	{
		return 0;
	}
	else
	{
		return node->size;	// 노드가 nullptr이 아니면 서브트리 크기 반환
	}
};

int Utility::UpdateHeight(AVLNode* node)  // UpdateHeight 함수: 주어진 노드의 높이를 갱신
{
	return 1 + max(GetHeight(node->left), GetHeight(node->right));
};

int Utility::UpdateRankSize(AVLNode* node)	// UpdateRankSize 함수: 주어진 노드의 서브트리 크기를 갱신
{
	if (node == nullptr)
	{
		return 0;			// 노드가 nullptr이면 서브트리 크기는 0
	}
	return 1 + GetSize(node->left) + GetSize(node->right);  // 서브트리의 크기 = 1 (자기 자신) + 왼쪽 서브트리 크기 + 오른쪽 서브트리 크기
};

int Utility::GetBalance(AVLNode* node)	// GetBalance 함수: 노드의 균형 인덱스를 계산하여 반환
{
	if (node != nullptr)
	{
		return GetHeight(node->left) - GetHeight(node->right);	// 왼쪽 자식 높이와 오른쪽 자식 높이의 차이를 계산하여 반환
	}
	else
	{
		return 0;			// 노드가 nullptr이면 균형 인덱스는 0
	}
};

AVLNode* Utility::MinValueNode(AVLNode* node)	// MinValueNode 함수: 주어진 서브트리에서 가장 작은 값을 가진 노드를 반환
{
	AVLNode* current_node = node;
	while (current_node->left != nullptr)			// nullptr을 만날때까지 서브트리의 왼쪽으로 이동
	{
		current_node = current_node->left;
	}
	return current_node;
};

AVLNode* Utility::MaxValueNode(AVLNode* node)	// MaxValueNode 함수: 주어진 서브트리에서 가장 큰 값을 가진 노드를 반환		 		   
{
	AVLNode* current_node = node;
	while (current_node->right != nullptr)			// nullptr을 만날때까지 서브트리의 오른쪽으로 이동
	{
		current_node = current_node->right;
	}
	return current_node;
};

AVLNode* Utility::FindNode(AVLNode* root, int key) 	// FindNode 함수: 주어진 키 값을 가진 노드를 찾아 그 노드의 포인터를 반환
{
	AVLNode* current_node = root;
	while (current_node != nullptr && current_node->key != key)  // 현재 노드가 nullptr가 아니고, 현재 노드의 키 값이 찾는 키 값과 다를 때까지 반복
	{
		if (key < current_node->key)
		{
			current_node = current_node->left;  // 찾는 키 값이 현재 노드의 키 값보다 작으면 왼쪽으로 이동
		}
		else
		{
			current_node = current_node->right;  // 찾는 키 값이 현재 노드의 키 값보다 크면 오른쪽 자식으로 이동
		}
	}
	return current_node;  // 찾으면 해당 노드의 포인터를 반환하고, 찾지 못하면 nullptr 반환
};


AVLNode* Utility::LeftRotate(AVLNode* x)	// LeftRotate 함수: 오른쪽 자식이 더 커서 트리를 균형있게 조정하는 왼쪽 회전
{

	AVLNode* y = x->right;  // x의 오른쪽 자식을 저장합니다 (새로운 서브트리 루트가 될 노드)
	AVLNode* T2 = y->left;  // y의 왼쪽 자식을 저장합니다 (x의 오른쪽 자식이 될 노드)

	// 회전 수행					
	y->left = x;
	x->right = T2;

	// 높이 갱신
	x->height = UpdateHeight(x);
	y->height = UpdateHeight(y);

	// 크기 갱신
	x->size = UpdateRankSize(x);
	y->size = UpdateRankSize(y);

	return y;  // 새로운 루트 반환
}


AVLNode* Utility::RightRotate(AVLNode* y)	// RightRotate 함수: 왼쪽 자식이 더 커서 트리를 균형있게 조정하는 오른쪽 회전
{

	AVLNode* x = y->left;	 // y의 왼쪽 자식을 저장합니다 (새로운 서브트리 루트가 될 노드)	
	AVLNode* T2 = x->right;  // x의 오른쪽 자식을 저장합니다 (y의 왼쪽 자식이 될 노드)

	// 회전 수행
	x->right = y;
	y->left = T2;

	// 높이 갱신
	y->height = UpdateHeight(y);
	x->height = UpdateHeight(x);

	// 크기 갱신
	y->size = UpdateRankSize(y);
	x->size = UpdateRankSize(x);


	return x;  // 새로운 루트 반환
}

int Utility::RankNode(AVLNode* node, int key)	// RankNode 함수: 주어진 키 값을 가진 노드의 순위를 계산하여 반환
{
	if (node == nullptr) return 0;  // 노드가 비어 있으면 0 반환

	if (key < node->key)
	{
		return RankNode(node->left, key);  // 키가 현재 노드의 키보다 작으면 왼쪽 서브트리에서 탐색
	}
	else if (key > node->key)
	{
		return 1 + GetRankSize(node->left) + RankNode(node->right, key);  // 왼쪽 서브트리와 현재 노드의 개수를 더함
	}
	else
	{
		return GetRankSize(node->left);   // 키가 현재 노드의 키와 같으면 왼쪽 서브트리의 크기를 반환
	}
};
