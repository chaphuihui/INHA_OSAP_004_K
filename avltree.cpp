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
 * - Who: Kim Dowon
 *   Date: 2024/11/17
 *   Description: Added the `Ancestor` function.
 *
 */

#include "include.h"


AVLTree::AVLTree() :root_(nullptr)
{
}

AVLTree::~AVLTree()
{
}

void AVLTree::Insert(int key) { root_ = InsertNode(root_, key); };

bool AVLTree::Empty()
{
	return root_ == nullptr;
};

int AVLTree::Size()
{
	Utility util;
	return util.GetSize(root_);
};

void AVLTree::Height()
{
	Utility util;
	if (root_ == nullptr) { cout << -1 << "\n"; }
	else { cout << root_->height << "\n"; }
};

void AVLTree::Ancestor(int key) {
    Utility util;
    AVLNode* target_node = util.FindNode(root_, key);  // 타겟 노드 설정

    int sum = 0;  // 조상 노드들의 키 값의 합                                 
    AVLNode* current_node = root_;

    while (current_node->key != key)  // 타켓 노드에 도달할 때까지 루트부터 탐색
    {
        sum += current_node->key;     // 조상 노드의 키 값을 합산
        if (key < current_node->key) 
        {
            current_node = current_node->left;  // 키 값이 작으면 왼쪽 자식으로 이동
        }
        else 
        {
            current_node = current_node->right;  // 키 값이 크면 오른쪽 자식으로 이동
        }
    }

    int K = Find(key);  // 깊이와 높이의 합

    if (target_node == root_)  // 타겟 노드가 루트일 경우 "K 0" 출력
    {      
        std::cout << "K 0" << "\n";  
    }
    else                       
    {
         std::cout << K << " " << sum << "\n";  // K 값과 조상 노드들의 키 값들의 합을 출력 
    }
};

void AVLTree::Average(int key)
{
	Utility util;
	AVLNode* subtree_root = util.FindNode(root_, key);

	int min_value_key = util.MinValueNode(subtree_root)->key;
	int max_value_key = util.MaxValueNode(subtree_root)->key;

	double subtree_min_max_average = (static_cast<double>(min_value_key) + static_cast<double>(max_value_key)) / 2.0;
	cout << subtree_min_max_average << "\n";
};

int AVLTree::Rank(int key)
{
	Utility util;
	AVLNode* node = util.FindNode(root_, key);


	if (!node)
	{
		return 0;
	}

	if (key < node->key)
	{
		return Rank(key);
	}
	else if (key > node->key)
	{
		return 1 + util.GetSize(node->left) + Rank(key);
	}
	else
	{
		return util.GetSize(node->left) + 1;
	}
};

void AVLTree::Erase(int key)
{
	Utility util;
	AVLNode* node = util.FindNode(root_, key);
	if (node == nullptr) { cout << 0 << "\n"; }
	else {
		Find(key);
		DeleteNode(root_, key);
	}
};

void AVLTree::Find(int key)
{
	Utility util;
	AVLNode* node = util.FindNode(root_, key);
	if (node == nullptr) { cout << 0 << "\n"; }
	else {
		int height = node->height - 1;
		int depth = util.GetDepth(root_, key, 0);
		cout << height << "\n";
	}

};

AVLNode* AVLTree::DeleteNode(AVLNode* root, int key)
{
	Utility util;
	AVLNode* node = util.FindNode(root_, key);

	if (!root)
	{
		return root;
	}

	if (key < root->key)
	{
		root->left = DeleteNode(root->left, key);
	}
	else if (key > root->key)
	{
		root->right = DeleteNode(root->right, key);
	}
	else
	{
		if (!root->left || !root->right)
		{
			AVLNode* temp = root->left ? root->left : root->right;
			if (!temp)
				root = nullptr;
			else
				*root = *temp;
			delete temp;
		}
		else
		{
			AVLNode* temp = util.MinValueNode(root->right);
			root->key = temp->key;
			root->right = DeleteNode(root->right, temp->key);
		}

		if (!root)
		{
			return root;
		}

		root->height = util.UpdateHeight(root);
		root->size = util.GetSize(root);

		int balance = util.GetBalance(root);

		if (balance > 1 && util.GetBalance(root->left) >= 0)
		{
			return util.RightRotate(root);
		}

		if (balance > 1 && util.GetBalance(root->left) < 0)
		{
			root->left = util.LeftRotate(root->left);
			return util.RightRotate(root);
		}

		if (balance < -1 && util.GetBalance(root->right) <= 0)
		{
			return util.LeftRotate(root);
		}

		if (balance < -1 && util.GetBalance(root->right) > 0)
		{
			root->right = util.RightRotate(root->right);
			return util.LeftRotate(root);
		}

		return root;
	}
};

AVLNode* AVLTree::InsertNode(AVLNode* node, int key)
{

	Utility util;


	if (!node)
	{
		return new AVLNode(key);
	}

	if (key < node->key)
	{
		node->left = InsertNode(node->left, key);
	}
	else if (key > node->key)
	{
		node->right = InsertNode(node->right, key);
	}
	else
	{
		return node;
	}

	node->height = util.UpdateHeight(node);
	node->size = util.UpdateSize(node);

	int balance = util.GetBalance(node);

	if (balance > 1 && key < node->left->key)
	{
		return util.RightRotate(node);
	}

	if (balance < -1 && key > node->right->key)
	{
		return util.LeftRotate(node);
	}

	if (balance > 1 && key > node->left->key)
	{
		node->left = util.LeftRotate(node->left);
		return util.RightRotate(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = util.RightRotate(node->right);
		return util.LeftRotate(node);
	}

	return node;
};

