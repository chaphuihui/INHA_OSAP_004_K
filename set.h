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
 *   Who: PAK DENIS
 *   Date: 2024/12/16
 *   Description: This file was created.
 *
 */
#ifndef SET_H
#define SET_H

#include "include.h"

class set //인터페이스
{
public:
	void Find(int key) 
    {
    		avl.Find(key);      // AVL 트리의 Find 메서드를 호출하여 키를 찾음
    };
  	void Insert(int key) 
    {
  		avl.Insert(key);      // AVL 트리의 Insert 메서드를 호출하여 키를 삽입
  	};
  	void Empty()
   {
  		avl.Empty();          // AVL 트리의 Empty 메서드를 호출하여 트리를 비움
  	};
  	void Size() const 
   {
  		avl.Size();          // AVL 트리의 Size 메서드를 호출하여 트리의 크기 출력
  	};
  	void Height() 
    {
  		avl.Height();        // AVL 트리의 Height 메서드를 호출하여 트리의 높이 출력
  	};
  	void Ancestor(int key) 
    {
  		avl.Ancestor(key);   // AVL 트리의 Ancestor 메서드를 호출하여 조상 정보 출력
  	};
  	void Average(int key)
    {
  		avl.Average(key);    // AVL 트리의 Average 메서드를 호출하여 평균 출력
  	};
  	void Rank(int key)   
    {
  		avl.Rank(key);       // AVL 트리의 Rank 메서드를 호출하여 순위 출력
  	};
  	void Erase(int key) 
    {
  		avl.Erase(key);      // AVL 트리의 Erase 메서드를 호출하여 키를 삭제
  	};

private:
	AVLTree avl;             // 내부적으로 사용하는 AVL 트리 객체
};

#endif //SET_H
