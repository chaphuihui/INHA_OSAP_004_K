#include "Include.h"


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

void AVLTree::Ancester()
{
	cout << "none";
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

