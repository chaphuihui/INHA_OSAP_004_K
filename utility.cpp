#include "Include.h"

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
