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
 * - Who: Kim Dowon 
 *   Date: 2024/11/13
 *   Description: added the 'FindeNode' function
 *
 */

#ifndef UTILITY_H
#define UTILITY_H
#include "avltree.h"

class Utility
{
public:
	Utility();
	~Utility();
	int GetHeight(AVLNode* node);
	int GetDepth(AVLNode* node, int key, int currentDepth);
	int GetSize(AVLNode* node);
	int UpdateHeight(AVLNode* node);
	int UpdateSize(AVLNode* node);
	int GetBalance(AVLNode* node);
	AVLNode* MinValueNode(AVLNode* root);
	AVLNode* MaxValueNode(AVLNode* root);
	AVLNode* FindNode(AVLNode* root, int key);  // 키 값이 일치하는 노드의 포인터 반환
	AVLNode* LeftRotate(AVLNode* x);
	AVLNode* RightRotate(AVLNode* y);
};

#endif //UTILITY_H
