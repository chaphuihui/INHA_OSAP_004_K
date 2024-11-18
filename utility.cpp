/*
 * Copyright (C) 2024 INHA_OSAP_003_K
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
 * - Who: Kim Dowon 
 *   Date: 2024/11/13
 *   Description: added the 'FindeNode' function
 *
 */

#include "include.h"

Utility::Utility()
{
};
Utility::~Utility()
{
};

int Utility::GetHeight(AVLNode* node)
{
	if (node != nullptr)
	{
		return node->height;
	}
	else
	{
		return 0;
	}
};

int Utility::GetDepth(AVLNode* node, int key, int current_depth) {
	if (!node) return -1;

	if (key == node->key) return current_depth;
	if (key < node->key) {
		return GetDepth(node->left, key, current_depth + 1);
	}
	else {
		return GetDepth(node->right, key, current_depth + 1);
	}
}

int Utility::GetSize(AVLNode* node) {
	if (node != nullptr)
	{
		return node->size;
	}
	else
	{
		return 0;
	}
};

int Utility::UpdateHeight(AVLNode* node)
{
	return 1 + max(GetHeight(node->left), GetHeight(node->right));
};

int Utility::UpdateSize(AVLNode* node)
{
	return 1 + GetSize(node->left) + GetSize(node->right);
}

int Utility::GetBalance(AVLNode* node)
{
	if (node != nullptr)
	{
		return GetHeight(node->left) - GetHeight(node->right);
	}
	else
	{
		return 0;
	}
};

AVLNode* Utility::MinValueNode(AVLNode* node)
{
	AVLNode* current_node = node;
	while (current_node->left != nullptr)				//nullptr을 만날때까지 서브트리의 왼쪽으로 이동
	{
		current_node = current_node->left;
	}
	return current_node;
};

AVLNode* Utility::MaxValueNode(AVLNode* node)			 		   
{
	AVLNode* current_node = node;
	while (current_node->right != nullptr)			//nullptr을 만날때까지 서브트리의 오른쪽으로 이동
	{
		current_node = current_node->right;
	}
	return current_node;
};

AVLNode* Utility::FindNode(AVLNode* root, int key) 
{
	AVLNode* current_node = root;
	while (current_node != nullptr && current_node->key != key)  //현재 노드가 nullptr가 아니고, 현재 노드의 키 값이 찾는 키 값과 다를 때까지 반복
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


AVLNode* Utility::LeftRotate(AVLNode* x)
{

	AVLNode* y = x->right;
	AVLNode* T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = UpdateHeight(x);
	y->height = UpdateHeight(y);

	x->size = GetSize(x);
	y->size = GetSize(y);

	return y;
}


AVLNode* Utility::RightRotate(AVLNode* y)
{

	AVLNode* x = y->left;
	AVLNode* T2 = x->right;

	x->left = y;
	y->right = T2;

	y->height = UpdateHeight(y);
	x->height = UpdateHeight(x);

	y->size = GetSize(y);
	x->size = GetSize(x);


	return x;
}
