#include "library_code.h"

//***AVLTree 클래스***
AVLTree::AVLTree() :root_(nullptr), size_(0)
{

}

AVLTree::~AVLTree()
{
	root_ = nullptr;
}

//Test에서도 root_를 접근하기 위해 새로 추가.
AVLNode* AVLTree::GetRoot() const {  
    return root_;
}

int AVLTree::Find(int key)
{
	Utility util;
	AVLNode* find_node = util.FindNode(root_, key);
	if (find_node == nullptr) {
		return 0;
	}
	return util.GetHeight(find_node) + util.GetDepth(root_, key, 0);
};

int AVLTree::Size() const
{
	return size_;
};

bool AVLTree::Empty()
{
	return root_ == nullptr;
};


int AVLTree::Height()
{
	Utility util;
	if (root_ == nullptr)
	{
		return -1;
	}
	return util.GetHeight(root_);

};

int AVLTree::Insert(int key) {
	Utility util;
	root_ = InsertNode(root_, key);
	size_++;
	AVLNode* find_node = util.FindNode(root_, key);
	return util.GetHeight(find_node) + util.GetDepth(root_, key, 0);

};

void AVLTree::Erase(int key)
{
	Utility util;
	AVLNode* node = util.FindNode(root_, key);
	if (node == nullptr) {
		std::cout << "0" << "\n";
		return;
}
	std::cout << util.GetHeight(node) + util.GetDepth(root_, key, 0) << "\n";
	root_ = DeleteNode(root_, key);
	size_--;
};

void AVLTree::Ancestor(int key)
{
	Utility util;

	AVLNode* current_node = util.FindNode(root_, key);
	if (current_node == root_) {
		std::cout << util.GetHeight(current_node) + util.GetDepth(root_, key, 0) << " " << 0 << "\n";
		return;
	}

	int sum = 0;
	AVLNode* ancestor_node = root_;
	while (ancestor_node != current_node) {
		sum += ancestor_node->key;
		if (ancestor_node->key > key) {
			ancestor_node = ancestor_node->left;
		}
		else {
			ancestor_node = ancestor_node->right;
		}
	}
	std::cout << util.GetHeight(current_node) + util.GetDepth(root_, key, 0) << " " << sum << "\n";
};

void AVLTree::Average(int key)
{
	Utility util;
	AVLNode* subtree_root = util.FindNode(root_, key);

	int min_value_key = util.MinValueNode(subtree_root)->key;
	int max_value_key = util.MaxValueNode(subtree_root)->key;

	int average = (min_value_key + max_value_key) / 2;
	std::cout << average << "\n";
};

void AVLTree::Rank(int key)
{
	Utility util;
	AVLNode* node = util.FindNode(root_, key);


	if (node == nullptr)
	{
		std::cout << 0 << "\n";
	}
	else
	{
		std::cout << util.GetDepth(root_, key, 0) + util.GetHeight(node) << " " << util.RankNode(root_, key) + 1 << "\n";
	}
};



AVLNode* AVLTree::InsertNode(AVLNode* root, int key)
{

	Utility util;

	if (root == nullptr)
	{
		return new AVLNode(key);
	}

	if (key < root->key)
	{
		root->left = InsertNode(root->left, key);
	}
	else if (key > root->key)
	{
		root->right = InsertNode(root->right, key);
	}
	else
	{
		return root;
	}



	root->height = util.UpdateHeight(root);
	root->size = util.UpdateSize(root);

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

AVLNode* AVLTree::DeleteNode(AVLNode* root, int key)
{
	Utility util;

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
			{
				temp = root;
				root = nullptr;
			}
			else
			{
				*root = *temp;
			}
			delete temp;
		}
		else
		{
			AVLNode* temp = root->right;
			while (temp->left)
				temp = temp->left;

			root->key = temp->key;
			root->right = DeleteNode(root->right, temp->key);
		}
	}

	if (!root)
	{

		return root;
	}



	root->height = util.UpdateHeight(root);
	root->size = util.UpdateSize(root);

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

	root->height = util.UpdateHeight(root);
	root->size = util.UpdateSize(root);



	return root;

};


// Utility 클래스
Utility::Utility()
{};
Utility::~Utility()
{};

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


int Utility::GetSize(AVLNode* node)
{

	if (node == nullptr)
	{
		return 0;
	}
	else
	{
		return node->size;
	}
};

int Utility::UpdateHeight(AVLNode* node)
{
	return 1 + std::max(GetHeight(node->left), GetHeight(node->right));
};

int Utility::UpdateSize(AVLNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}
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

int Utility::GetDepth(AVLNode* node, int key, int current_depth) {
	if (node == nullptr) return -1;

	if (key == node->key) return current_depth;
	if (key < node->key)
	{
		return GetDepth(node->left, key, current_depth + 1);
	}
	else
	{
		return GetDepth(node->right, key, current_depth + 1);
	}
}

AVLNode* Utility::MinValueNode(AVLNode* node)
{
	AVLNode* current_node = node;
	while (current_node->left != nullptr)
	{
		current_node = current_node->left;
	}
	return current_node;
};

AVLNode* Utility::MaxValueNode(AVLNode* node)
{
	AVLNode* current_node = node;
	while (current_node->right != nullptr)
	{
		current_node = current_node->right;
	}
	return current_node;
};

AVLNode* Utility::FindNode(AVLNode* root, int key)
{
	AVLNode* current_node = root;
	while (current_node != nullptr && current_node->key != key)
	{
		if (key < current_node->key)
		{
			current_node = current_node->left;
		}
		else
		{
			current_node = current_node->right;
		}
	}
	return current_node;

};


AVLNode* Utility::LeftRotate(AVLNode* x)
{

// ***테스트를 위해 추가 오른쪽 자식이 없으면 회전하지 않고 그대로 반환***
    if (x == nullptr || x->right == nullptr) {
        return x; 
    }

	AVLNode* y = x->right;
	AVLNode* T2 = y->left;

	y->left = x;
	x->right = T2;




	x->height = UpdateHeight(x);
	x->size = UpdateSize(x);

	y->height = UpdateHeight(y);
	y->size = UpdateSize(y);

	return y;
}

AVLNode* Utility::RightRotate(AVLNode* y)
{
// ***테스트를 위해 추가. 왼쪽 자식이 없으면 회전하지 않고 그대로 반환***
    if (y == nullptr || y->left == nullptr) {
        return y; 
    }

	AVLNode* x = y->left;
	AVLNode* T2 = x->right;

	x->right = y;
	y->left = T2;



	y->height = UpdateHeight(y);
	y->size = UpdateSize(y);

	x->height = UpdateHeight(x);
	x->size = UpdateSize(x);

	return x;
}

int Utility::RankNode(AVLNode* node, int key)
{
	if (node == nullptr) return 0;

	if (key < node->key)
	{
		return RankNode(node->left, key);
	}
	else if (key > node->key)
	{
		return 1 + GetSize(node->left) + RankNode(node->right, key);
	}
	else
	{
		return GetSize(node->left);
	}
};
