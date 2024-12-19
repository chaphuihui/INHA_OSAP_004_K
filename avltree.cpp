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
 *   Date: 2024/11/13
 *   Description: Added the `Average` function.
 *
 *   Who: PAK DENIS
 *   Date: 2024/11/16
 *   Description: Added the `Rank` function.
 *
 *   Who: Kim Dowon
 *   Date: 2024/11/17
 *   Description: Added the `Ancestor` function.
 *
 */

#include "include.h"


AVLTree::AVLTree() : root_(nullptr), size_(0) {};	// AVLTree 기본 생성자: 루트를 nullptr로 초기화하고 트리의 크기를 0으로 설정합니다.

AVLTree::~AVLTree() {};					// AVLTree 소멸자: 리소스를 정리합니다.	

void AVLTree::Insert(int key) 				// 키를 트리에 삽입하는 함수
{
	Utility util;					// 유틸리티 객체 생성
	
	root_ = InsertNode(root_, key);		 	// InsertNode 함수를 사용하여 노드를 삽입하고 균형을 맞추며 루트를 갱신
	size_++;					// 트리의 크기 증가
	AVLNode* find_node = util.FindNode(root_, key);	// 삽입된 노드를 다시 찾기
	cout << util.GetHeight(find_node) + util.GetDepth(root_, key, 0) << "\n";	// 삽입된 노드의 높이와 깊이 합 출력
};

void AVLTree::Empty()	// 트리가 비어있는지 확인하는 함수
{
	if (root_ == nullptr)
	{
		cout << 1 << "\n";	// 루트가 nullptr이면 트리가 비어있음을 의미하므로 1 출력
	}
	else 	 
	{
		cout << 0 << "\n";	// 트리가 비어있지 않으면 0 출력
	}
};

void AVLTree::Size() const	// 트리의 노드 개수(크기)를 출력하는 함수
{
	cout << size_ << "\n";  // 트리의 노드 수인 size_를 출력
};

void AVLTree::Height()	// 트리의 높이를 출력하는 함수
{
	if (root_ == nullptr)
	{
		cout << -1 << "\n";			// 루트가 nullptr이면 트리가 비어있으므로 높이는 -1
	}
	else 
	{
		cout << root_->height << "\n";	// 루트 노드의 높이를 출력
	}
};

void AVLTree::Ancestor(int key)	// 특정 키에 대한 조상 노드의 합을 계산하고 출력하는 함수
{
	Utility util;						// 유틸리티 객체 생성
	AVLNode* current_node = util.FindNode(root_, key);	// 키에 해당하는 노드 찾기
	
	if (current_node == root_)				// 노드가 루트일 경우
	{
		cout << util.GetHeight(current_node) + util.GetDepth(root_, key, 0) << " " << 0 << "\n";	// 루트 노드는 조상이 없으므로 0 출력
		return;
	}

	int sum = 0;						// 조상 노드 키의 합을 저장할 변수
	AVLNode* ancestor_node = root_;				// 루트에서 시작
	while (ancestor_node != current_node) 			// 조상 노드를 따라가며 합을 계산
	{
		sum += ancestor_node->key;			// 현재 노드의 키를 합에 더함
		if (ancestor_node->key > key) 
		{
			ancestor_node = ancestor_node->left;	// 왼쪽 서브트리로 이동
		}
		else 
		{
			ancestor_node = ancestor_node->right;	// 오른쪽 서브트리로 이동
		}
	}
	cout << util.GetHeight(current_node) + util.GetDepth(root_, key, 0) << " " << sum << "\n";	// 노드의 높이와 깊이, 조상 노드 키의 합을 출력
};

void AVLTree::Average(int key)	// 특정 키를 기준으로 서브트리의 최소, 최대 값을 구하고 평균을 출력하는 함수
{
	Utility util;							// 유틸리티 객체 생성
	AVLNode* subtree_root = util.FindNode(root_, key);		//입력 받은 키 값의 노드 찾기

	int min_value_key = util.MinValueNode(subtree_root)->key;	//노드를 기준으로한 서브트리의 최소노드
	int max_value_key = util.MaxValueNode(subtree_root)->key;	//노드를 기준으로한 서브트리의 최대노드

	int average = (min_value_key + max_value_key) / 2.0;		// 최소값과 최대값의 평균을 계산
	cout << average << "\n";					// 평균을 출력
};

void AVLTree::Rank(int key)	// 노드의 순위를 계산하여 출력하는 함수
{
	Utility util;					// 유틸리티 객체 생성
	AVLNode* node = util.FindNode(root_, key);	// 키에 해당하는 노드를 찾기


	if (node == nullptr)
	{
		cout << 0 << "\n";			// 노드가 존재하지 않으면 0 출력
	}
	else
	{
		cout << util.GetDepth(root_, key, 0) + util.GetHeight(node) << " " << util.RankNode(root_, key) + 1 << "\n";	// 노드의 깊이, 높이 합과 순위를 출력
	}
};

void AVLTree::Erase(int key)	// 특정 키를 삭제하는 함수
{
	Utility util;					// 유틸리티 객체 생성
	AVLNode* node = util.FindNode(root_, key);	// 키에 해당하는 노드를 찾기
	
	if (node == nullptr) 
	{
		cout << "0" << "\n";			// 노드가 존재하지 않으면 0 출력
		return;
	}
	cout << util.GetHeight(node) + util.GetDepth(root_, key, 0) << "\n";	// 노드의 높이와 깊이 출력
	root_ = DeleteNode(root_, key);			// DeleteNode 함수를 사용하여 노드 삭제 후 루트 갱신
	size_--;					// 트리 크기 감소
};

void AVLTree::Find(int key)	// 주어진 키를 가진 노드를 찾고 깊이와 높이를 출력하는 함수
{
	Utility util;					// 유틸리티 객체 생성
	AVLNode* find_node = util.FindNode(root_, key);	// 유틸리티의 FindNode 함수를 사용하여 키에 해당하는 노드 찾기
	
	if (find_node == nullptr) 
	{
		cout << 0 << "\n";			// 노드가 존재하지 않으면 0 출력
	}
	else 
	{
		cout << find_node->height + util.GetDepth(root_, key, 0) << "\n";	// 노드가 존재하면 높이와 깊이의 합을 출력
	}
};

AVLNode* AVLTree::DeleteNode(AVLNode* root, int key)	// AVL 트리에서 특정 키를 삭제하는 함수 (재귀적 구현)
{
	Utility util;		 	// 유틸리티 객체 생성
	
	if (!root)		 	// 베이스 케이스: 루트가 nullptr이면 아무 작업도 하지 않고 nullptr 반환
	{
		return nullptr;
	}
	
	if (key < root->key)	 	// 삭제하려는 키가 현재 노드의 키보다 작으면 왼쪽 서브트리로 이동
	{
		root->left = DeleteNode(root->left, key);
	}
	else if (key > root->key)	// 삭제하려는 키가 현재 노드의 키보다 크면 오른쪽 서브트리로 이동
	{
		root->right = DeleteNode(root->right, key);
	}
	else				// 삭제하려는 키를 찾은 경우 (key == root->key)
	{
		if (!root->left || !root->right)	자식 노드가 하나이거나 없는 경우
		{
			AVLNode* temp = root->left ? root->left : root->right;	// 자식 노드 중 하나만 존재하면 그 자식을 temp에 저장
			if (!temp)						// 자식 노드가 없을 경우 (temp == nullptr)
			{
				temp = root;					// 현재 노드를 temp로 설정한 후 root를 nullptr로 설정
				root = nullptr;
			}
			else
			{
				*root = *temp;					// 자식 노드가 하나 있을 경우: 현재 노드의 값을 자식 노드 값으로 복사
			}
			delete temp;						// temp 노드를 삭제
		}
		else
		{
			AVLNode* temp = root->right;				// 오른쪽 서브트리에서 최소값 노드를 찾기
			while (temp->left)
				temp = temp->left;
	
			root->key = temp->key;					// 현재 노드의 키를 오른쪽 서브트리의 최소값 노드의 키로 교체
			root->right = DeleteNode(root->right, temp->key);	// 오른쪽 서브트리에서 최소값 노드를 삭제
		}
	}
	
	if (!root)								// 삭제 후 노드가 nullptr이면 반환
	{
		return nullptr;
	}
	
	
										// 높이와 서브트리 크기 업데이트
	root->height = util.UpdateHeight(root);
	root->ranksize = util.UpdateRankSize(root);

										// 불균형 확인 및 회전 수행
	int balance = util.GetBalance(root);
	
	if (balance > 1 && util.GetBalance(root->left) >= 0) {
		return util.RightRotate(root);
	}
	if (balance > 1 && util.GetBalance(root->left) < 0) {
		root->left = util.LeftRotate(root->left);
		return util.RightRotate(root);
	}
	if (balance < -1 && util.GetBalance(root->right) <= 0) {
		return util.LeftRotate(root);
	}
	if (balance < -1 && util.GetBalance(root->right) > 0) {
		root->right = util.RightRotate(root->right);
		return util.LeftRotate(root);
	}
	
	
	
	return root;
};

AVLNode* AVLTree::InsertNode(AVLNode* root, int key)		// AVL 트리에 키를 삽입하는 함수(재귀적으로 동작)
{

	Utility util;
	
	
	if (root == nullptr)
	{
		return new AVLNode(key);		// 노드가 nullptr이면 새 노드 생성
	}
	
	if (key < root->key)				// 키를 비교하여 왼쪽 또는 오른쪽으로 이동
	{
		root->left = InsertNode(root->left, key);	
	}
	else if (key > root->key)
	{
		root->right = InsertNode(root->right, key);
	}
	else
	{
		return root;				// 중복 키를 허용하지 않음
	}
	
	
							// 높이와 서브트리 크기 업데이트
	root->height = util.UpdateHeight(root);
	root->ranksize = util.UpdateRankSize(root);

							// 불균형 확인 및 회전 수행
	int balance = util.GetBalance(root);
	
	if (balance > 1 && key < root->left->key)
	{
		return util.RightRotate(root);
	}
	
	if (balance < -1 && key > root->right->key)
	{
		return util.LeftRotate(root);
	}
	
	if (balance > 1 && key > root->left->key)
	{
		root->left = util.LeftRotate(root->left);
		return util.RightRotate(root);
	}
	
	if (balance < -1 && key < root->right->key)
	{
		root->right = util.RightRotate(root->right);
		return util.LeftRotate(root);
	}
	
	return root;
};

