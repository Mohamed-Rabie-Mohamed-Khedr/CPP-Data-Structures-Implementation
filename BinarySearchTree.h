#pragma once
#include <iostream>
struct BSTNode
{
	int value;
	BSTNode* left;
	BSTNode* right;
	BSTNode(int& v)
	{
		value = v;
		left = right = nullptr;
	}
};
class BinarySearchTree
{
	BSTNode* root = nullptr;
	BSTNode* newNode = nullptr;
	int* allValues = nullptr;
	size_t count = 0;
	void readValues(BSTNode* r, size_t& i)
	{
		if (r == nullptr) return;
		allValues[i++] = r->value;
		readValues(r->left, i);
		readValues(r->right, i);
	}
public:
	void add(int value)
	{
		if (getCount() > 0)
		{
			newNode = root;
			while (true)
			{
				if (value < newNode->value)
				{
					if (newNode->left == nullptr)
					{
						newNode->left = new BSTNode(value);
						break;
					}
					newNode = newNode->left;
				}
				else
				{
					if (newNode->right == nullptr)
					{
						newNode->right = new BSTNode(value);
						break;
					}
					newNode = newNode->right;
				}
			}
		}
		else root = new BSTNode(value);
		++count;
	}
	BSTNode* getMin()
	{
		return getMin(root);
	}
	BSTNode*& getMin(BSTNode*& r)
	{
		if (r == nullptr || r->left == nullptr) return r;
		else return getMin(r->left);
	}
	BSTNode* getMax()
	{
		return getMax(root);
	}
	BSTNode*& getMax(BSTNode*& r)
	{
		if (r == nullptr || r->right == nullptr) return r;
		else return getMax(r->right);
	}
	BSTNode* search(int value)
	{
		return search(root, value);
	}
	BSTNode*& search(BSTNode*& r, int& value)
	{
		if (r == nullptr || value == r->value) return r;
		else if (value < r->value) search(r->left, value);
		else search(r->right, value);
	}
	void remove(int value)
	{
		BSTNode*& n = search(root, value);
		if (n == nullptr) return;
		else
		{
			if (n->left == nullptr && n->right == nullptr)
			{
				delete n;
				n = nullptr;
			}
			else if (n->left != nullptr && n->right == nullptr)
			{
				BSTNode* n2 = n;
				n = n->left;
				delete n2;
				n2 = nullptr;
			}
			else if (n->left == nullptr && n->right != nullptr)
			{
				BSTNode* n2 = n;
				n = n->right;
				delete n2;
				n2 = nullptr;
			}
			else
			{
				BSTNode*& n2 = getMin(n->right);
				n->value = n2->value;
				delete n2;
				n2 = nullptr;
			}
			--count;
		}
	}
	int* getValues()
	{
		if (getCount() == 0) throw std::out_of_range("tree is empty");
		delete[] allValues;
		allValues = new int[getCount()];
		size_t index = 0;
		readValues(root, index);
		return allValues;
	}
	size_t getCount() const
	{
		return count;
	}
	void cleaning(BSTNode*& r)
	{
		if (r->left != nullptr) cleaning(r->left);
		if (r->right != nullptr) cleaning(r->right);
		delete r;
		r = nullptr;
	}
	~BinarySearchTree()
	{
		delete[] allValues;
		allValues = nullptr;
		cleaning(root);
	}
};